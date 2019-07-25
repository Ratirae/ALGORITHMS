/**
 *  \brief 插入法从小到大排序.
 */

#include <iostream>
#include <vector>

using namespace std;

//从下标 l 打印到下标 r
void DebugPrint(vector<int> &ve, int l, int r)
{
    for(int k = l; k < r+1; ++k)
        {
            cout << ve[k] << "  ";
        }
        cout << endl;
}

//插入排序，时间复杂度是O(n^2)
void InsertionSor(vector<int> &ve)
{
    int len = ve.size();
    if(len <2)
        return;

    int key = 0;    //用于记录关键值
    for(int i = 1; i < len; ++i)
    {
        key = ve[i];
        int j = i;
        while(j > 0 && ve[j-1] > key )  //比关键值大就往后移动一位，为关键值空出位置
        {
            ve[j] = ve[j-1];
            j--;
        }
        ve[j] = key;    //放入关键值
        //DebugPrint(ve, j, i);
    }
}

//打印数组
void Print(vector<int> &ve)
{
    for(auto &i : ve)
    {
        cout << i << "  ";
    }
    cout << endl;
}
int main()
{
    vector<int> ve = {5,4,1,3,6,8,3,1,-4,-22,99};
    //Print(ve);
    InsertionSor(ve);
    Print(ve);
    return 0;
}
