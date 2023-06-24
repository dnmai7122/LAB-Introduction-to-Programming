#pragma once
#include<iostream>
using namespace std;
#include<cstdlib>
#include<string>
#include<cstdio>

const int T_S = 10;

//Chaining Method
class HashTableEntry {
public:
    int k;
    int v;
    HashTableEntry(int k, int v) {
        this->k = k;
        this->v = v;
    }
};
class HashMapTable
{
private:
    HashTableEntry** t;
public:
    HashMapTable()
    {
        t = new HashTableEntry * [T_S];
        for (int i = 0; i < T_S; i++) {
            t[i] = NULL;
        }
    }
    int HashFunc(int k) {
        return k % T_S;
    }
    void Insert(int k, int v) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] != NULL)
            delete t[h];
        t[h] = new HashTableEntry(k, v);
    }
    int SearchKey(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
            return -1;
        else
            return t[h]->v;
    }
    void Remove(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL) {
            if (t[h]->k == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL) {
            cout << "No Element found at key " << k << endl;
            return;
        }
        else {
            delete t[h];
        }
        cout << "Element Deleted" << endl;
    }
    ~HashMapTable() {
        for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
                delete t[i];
            delete[] t;
        }
    }
};
//Linear Probling
class DelNode :public HashTableEntry 
{
private:
    static DelNode* en;
    DelNode() :HashTableEntry(-1, -1) 
    {}
public:
    static DelNode* getNode() {
        if (en == NULL)
            en = new DelNode();
        return en;
    }
};
DelNode* DelNode::en = NULL;
class HashMapTable_LP {
private:
    HashTableEntry** ht;
public:
    HashMapTable_LP() {
        ht = new HashTableEntry * [T_S];
        for (int i = 0; i < T_S; i++) {
            ht[i] = NULL;
        }
    }
    int HashFunc(int k) {
        return k % T_S;
    }
    void Insert_LP(int k, int v) {
        int hash_val = HashFunc(k);
        int init = -1;
        int delindex = -1;
        while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
            if (init == -1)
                init = hash_val;
            if (ht[hash_val] == DelNode::getNode())
                delindex = hash_val;
            hash_val = HashFunc(hash_val + 1);
        }
        if (ht[hash_val] == NULL || hash_val == init) {
            if (delindex != -1)
                ht[delindex] = new HashTableEntry(k, v);
            else
                ht[hash_val] = new HashTableEntry(k, v);
        }
        if (init != hash_val) {
            if (ht[hash_val] != DelNode::getNode()) {
                if (ht[hash_val] != NULL) {
                    if (ht[hash_val]->k == k)
                        ht[hash_val]->v = v;
                }
            }
            else
                ht[hash_val] = new HashTableEntry(k, v);
        }
    }
    int SearchKey_LP(int k) {
        int hash_val = HashFunc(k);
        int init = -1;
        while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
            if (init == -1)
                init = hash_val;
            hash_val = HashFunc(hash_val + 1);
        }
        if (ht[hash_val] == NULL || hash_val == init)
            return -1;
        else
            return ht[hash_val]->v;
    }
    void Remove_LP(int k) {
        int hash_val = HashFunc(k);
        int init = -1;
        while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
            if (init == -1)
                init = hash_val;
            hash_val = HashFunc(hash_val + 1);
        }
        if (hash_val != init && ht[hash_val] != NULL) {
            delete ht[hash_val];
            ht[hash_val] = DelNode::getNode();
        }
    }
    ~HashMapTable_LP() {
        delete[] ht;
    }
};
// Quandratic Probling
enum EntryType_QP {
    Legi, Emp, Del
};
struct HashTableEntry_QP {
    int e;
    enum EntryType_QP info;
};
struct HashTable_QP {
    int s;
    HashTableEntry_QP* t;
};
bool isPrime(int n) {
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
int nextPrime(int n) {
    if (n <= 0)
        n = 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime(n); n += 2);
    return n;
}
int HashFunc(int k, int s) {
    return k % s;
}
HashTable_QP* initiateTable_QP(int s) {
    HashTable_QP* ht;
    if (s < T_S) {
        cout << "Table Size is Too Small" << endl;
        return NULL;
    }
    ht = new HashTable_QP;
    if (ht == NULL) {
        cout << "Out of Space" << endl;
        return NULL;
    }
    ht->s = nextPrime(s);
    ht->t = new HashTableEntry_QP[ht->s];
    if (ht->t == NULL) {
        cout << "Table Size is Too Small" << endl;
        return NULL;
    }
    for (int i = 0; i < ht->s; i++) {
        ht->t[i].info = Emp;
        ht->t[i].e = NULL;
    }
    return ht;
}
int SearchKey_QP(int k, HashTable_QP* ht) {
    int pos = HashFunc(k, ht->s);
    int collisions = 0;
    while (ht->t[pos].info != Emp && ht->t[pos].e != k) {
        pos = pos + 2 * ++collisions - 1;
        if (pos >= ht->s)
            pos = pos - ht->s;
    }
    return pos;
}
void Insert_QP(int k, HashTable_QP* ht) {
    int pos = SearchKey_QP(k, ht);
    if (ht->t[pos].info != Legi) {
        ht->t[pos].info = Legi;
        ht->t[pos].e = k;
    }
}
HashTable_QP* Rehash_QP(HashTable_QP* ht) {
    int s = ht->s;
    HashTableEntry_QP* t = ht->t;
    ht = initiateTable_QP(2 * s);
    for (int i = 0; i < s; i++) {
        if (t[i].info == Legi)
            Insert_QP(t[i].e, ht);
    }
    free(t);
    return ht;
}
void display_QP(HashTable_QP* ht) {
    for (int i = 0; i < ht->s; i++) {
        int value = ht->t[i].e;
        if (!value)
            cout << "Position: " << i + 1 << " Element: Null" << endl;
        else
            cout << "Position: " << i + 1 << " Element: " << value << endl;
    }
}
//Double Hashing
enum EntryType { Legi1, Emp1 };
struct HashTableEntryDH {
    int e;
    enum EntryType info;
};
struct HashTableDH {
    int s;
    HashTableEntryDH* t;
};
int HashFunc1(int k, int s) {
    return k % s;
}
int HashFunc2(int k, int s) {
    return (k * s - 1) % s;
}
HashTableDH* initiateTable(int s) {
    HashTableDH* ht;
    if (s < T_S) {
        cout << "Table Size is Too Small" << endl;
        return NULL;
    }
    ht = new HashTableDH;
    if (ht == NULL) {
        cout << "Out of Space" << endl;
        return NULL;
    }
    ht->s = s;
    ht->t = new HashTableEntryDH[ht->s];
    if (ht->t == NULL) {
        cout << "Table Size is Too Small" << endl;
        return NULL;
    }
    for (int i = 0; i < ht->s; i++) {
        ht->t[i].info = Emp1;
        ht->t[i].e = NULL;
    }
    return ht;
}
int SearchKey(int k, HashTableDH* ht) {
    int hashVal = HashFunc1(k, ht->s);
    int stepSize = HashFunc2(k, ht->s);
    while (ht->t[hashVal].info != Emp1 &&
        ht->t[hashVal].e != k) {
        hashVal = hashVal + stepSize;
        hashVal = hashVal % ht->s;
    }
    return hashVal;
}
void Insert(int k, HashTableDH* ht) {
    int pos = SearchKey(k, ht);
    if (ht->t[pos].info != Legi1) {
        ht->t[pos].info = Legi1;
        ht->t[pos].e = k;
    }
}
void display(HashTableDH* ht) {
    for (int i = 0; i < ht->s; i++) {
        int v = ht->t[i].e;
        if (!v)
            cout << "Position: " << i + 1 << " Element: Null" << endl;
        else
            cout << "Position: " << i + 1 << " Element: " << v << endl;
    }
}
HashTableDH* Rehash(HashTableDH* ht) {
    int s = ht->s;
    HashTableEntryDH* t = ht->t;
    ht = initiateTable(2 * s);
    for (int i = 0; i < s; i++) {
        if (t[i].info == Legi1)
            Insert(t[i].e, ht);
    }
    free(t);
    return ht;
}
