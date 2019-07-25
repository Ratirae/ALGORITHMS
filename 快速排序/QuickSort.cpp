/**
 * \brief 快速排序的最大特征，快速体现在：在不知情的情况下做出选择，速度的快慢取决于选择的优劣，因此排序速度是不稳定。
 */

#include <iostream>
#include <vector>
using namespace std;

inline void Exchange(int &A, int &B)
{
    int tmp = A;
    A = B;
    B = tmp;
}

int Partition(vector<int> &vec, int p, int r)
{
    int key = vec[r];   //快速排序的最大特征，快速体现在：在不知情的情况下做出选择，速度的快慢取决于选择的优劣，因此排序速度是不稳定
    int i = p-1;
    int j = p;
    for(j = p; j <= r; ++j)
    {
        if(vec[j] <= key)
        {
            i++;
            Exchange(vec[i],vec[j]);
        }
    }
    //Exchange(vec[i+1],vec[r]);
    return i;
}

void QuickSort(vector<int> &vec, int p, int r)
{
    if(p<r)
    {
        int q = Partition(vec, p, r);
        QuickSort(vec, p, q-1);
        QuickSort(vec, q+1, r);
    }
}
//排序
void QuickSort(vector<int> &vec)
{
    int p = 0;
    int r = vec.size()-1;
    QuickSort(vec, p, r);
}
void Debug(vector<int> &vec)
{
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<int> vec = {0};
    Debug(vec);
    QuickSort(vec);
    Debug(vec);
    return 0;
}

