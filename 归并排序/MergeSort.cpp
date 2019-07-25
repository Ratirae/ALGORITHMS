#include <iostream>
#include <vector>
#include "MergeSort.h"


using namespace std;



void ShowMergeSort()
{
    vector<int> ve = {1,5,4,6,3,8,4,3};
    PrintArray(ve);
    //vector<int> tmp = {ve.begin()+2, ve.begin()+4};
    MergeSort(ve);
    PrintArray(ve);
}



//归并排序
void Merge(vector<int> &ve, int l, int mid, int r)
{
    vector<int> tmp1 = {ve.begin()+l, ve.begin()+mid+1};
    vector<int> tmp2 = {ve.begin()+mid+1, ve.begin()+r+1};
    int len1 = tmp1.size();
    int len2 = tmp2.size();
    int i = 0;
    int j = 0;
    int k = l;
    for(k = l; k < r+1; ++k)
    {
        if(i == len1)
        {
            ve[k] = tmp2[j++];
        }
        else if(j == len2)
        {
            ve[k] = tmp1[i++];
        }
        else if(i < len1 && j < len2)
        {
            ve[k] = (tmp1[i] <= tmp2[j] ? tmp1[i++] : tmp2[j++]);
        }
    }
}

void MergeSort(vector<int> &ve)
{
    int l = 0;
    int r = ve.size()-1;
    MergeSort(ve, l, r);
}


void MergeSort(vector<int> &ve, int l, int r)
{
    if(l>=r) return;
    int mid = l + (r-l)/2;
    MergeSort(ve, l, mid);
    MergeSort(ve, mid+1, r);
    Merge(ve, l, mid, r);
    //vector<int> tmp = {ve.begin()+l, ve.begin()+r+1};
    //PrintArray(tmp);
}


void PrintArray(vector<int> &ve)
{
    if(ve.empty())
    {
        cout << "Array is empty!" << endl;
        return;
    }
    for(auto i : ve)
    {
        cout << i << "  ";
    }
    cout << endl;
}

















