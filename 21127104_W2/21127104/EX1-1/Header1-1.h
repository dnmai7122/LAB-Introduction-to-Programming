#pragma once
#include<iostream>
#include <chrono>
#include<random>
using namespace std;
using namespace std::chrono;

void insertion(int a[], int l, int r);

void merge(int a[], int aux[], int l, int m, int r);

void mergesort(int a[], int aux[], int l, int r);

int partition(int a[], int l, int r);

void quicksort(int a[], int l, int r);
