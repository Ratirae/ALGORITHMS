#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED
#include <vector>

using namespace std;



void ShowMergeSort();

//归并排序
void Merge(vector<int> &ve, int l, int mid, int r);
void MergeSort(vector<int> &ve, int l, int r);
void MergeSort(vector<int> &ve);

//打印
void PrintArray(vector<int> &ve);

#endif // MERGESORT_H_INCLUDED
