#include"Header5.1.h"
int main() {
    HashMapTable hash;
    HashMapTable_LP hashlp;
    HashTableDH* htdh=NULL;
    HashTable_QP* htqp = NULL;
    int k, v;
    int i = 1,j=1;
    int c;
    int ch = 0;
    do {
        cout << "\t==MENU=="
            << "\n1. Chaining Method"
            << "\n2. Linear Probing"
            << "\n3. Quadratic Probing"
            << "\n4. Double hashing"
            << "\n Enter your the number of conllision: ";
        cin >> ch;
    } while (ch < 0 || ch>4);
    switch (ch) {
    case 1:
        while (1) {
            cout << "1.Insert element into the table" << endl;
            cout << "2.Search element from the key" << endl;
            cout << "3.Delete element at a key" << endl;
            cout << "4.Exit" << endl;
            cout << "Enter your choice: ";
            cin >> c;
            switch (c) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> v;
                cout << "Enter key at which element to be inserted: ";
                cin >> k;
                hash.Insert(k, v);
                break;
            case 2:
                cout << "Enter key of the element to be searched: ";
                cin >> k;
                if (hash.SearchKey(k) == -1) {
                    cout << "No element found at key " << k << endl;
                    continue;
                }
                else {
                    cout << "Element at key " << k << " : ";
                    cout << hash.SearchKey(k) << endl;
                }
                break;
            case 3:
                cout << "Enter key of the element to be deleted: ";
                cin >> k;
                hash.Remove(k);
                break;
            case 4:
                exit(1);
            default:
                cout << "\nEnter correct option\n";
            }
        }
    case 2:
        while (1) {
            cout << "1.Insert element into the table" << endl;
            cout << "2.Search element from the key" << endl;
            cout << "3.Delete element at a key" << endl;
            cout << "4.Exit" << endl;
            cout << "Enter your choice: ";
            cin >> c;
            switch (c) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> v;
                cout << "Enter key at which element to be inserted: ";
                cin >> k;
                hashlp.Insert_LP(k, v);
                break;
            case 2:
                cout << "Enter key of the element to be searched: ";
                cin >> k;
                if (hashlp.SearchKey_LP(k) == -1) {
                    cout << "No element found at key " << k << endl;
                    continue;
                }
                else {
                    cout << "Element at key " << k << " : ";
                    cout << hashlp.SearchKey_LP(k) << endl;
                }
                break;
            case 3:
                cout << "Enter key of the element to be deleted: ";
                cin >> k;
                hashlp.Remove_LP(k);
                break;
            case 4:
                exit(1);
            default:
                cout << "\nEnter correct option\n";
            }
        }
    case 3:
        while (1) {
            cout << "1.Initialize size of the table" << endl;
            cout << "2.Insert element into the table" << endl;
            cout << "3.Display Hash Table" << endl;
            cout << "4.Rehash Hash Table" << endl;
            cout << "5.Exit" << endl;
            cout << "Enter your choice: ";
            cin >> c;
            switch (c) {
            case 1:
                int s;
                cout << "Enter size of the Hash TableL ";
                cin >> s;

                htqp = initiateTable_QP(s);
                break;
            case 2:

                if (j > htqp->s)
                {
                    cout << "\nTable is full\n" << endl;
                    continue;
                }
                cout << "\nEnter element to be inserted: ";
                cin >> v;
                Insert_QP(v, htqp);
                j++;
                break;
            case 3:
                display_QP(htqp);
                break;
            case 4:
                Rehash_QP(htqp);
                break;
            case 5:
                exit(1);
            default:
                cout << "\nEnter correct option\n";
            }
        }

    case 4:
        while (1) {
            cout << "1.Initialize size of the table" << endl;
            cout << "2.Insert element into the table" << endl;
            cout << "3.Display Hash Table" << endl;
            cout << "4.Rehash Hash Table" << endl;
            cout << "5.Exit" << endl;
            cout << "Enter your choice: ";
            cin >> c;
            switch (c) {
            case 1:
                int s;
                cout << "Enter size of the Hash TableL ";
                cin >> s;
        
                htdh=initiateTable(s);
                break;
            case 2:
                
                if (i > htdh->s)
                {
                    cout << "\nTable is full\n" << endl;
                    continue;
                }
                cout << "\nEnter element to be inserted: ";
                cin >> v;
                Insert(v, htdh);
                i++;
                break;
            case 3:
                display(htdh);
                break;
            case 4:
                Rehash(htdh);
                break;
            case 5:
                exit(1);
            default:
                cout << "\nEnter correct option\n";
            }
        }

    }
    
    return 0;
}