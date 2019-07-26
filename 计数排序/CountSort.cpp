#include <iostream>
#include <cstdlib>

using namespace std;

//打印数组.
void ShowArray(int *ary, int len)
{
    int i = 0;
    for(i = 0; i < len; ++i)
    {
        cout << ary[i] << "  ";
    }
    cout << endl;;
}

//计数排序
void CountSort(int *ary, int len)
{
    int tmp[len] = {0}; //保存原始数组，原数组用来保存最终结果
    int max_etem = INT_MIN;

    //初始化，及最大元素
    for(int i = 0; i < len; ++i)
    {
        if(max_etem < ary[i])
            max_etem = ary[i];
        tmp[i] = ary[i];
        ary[i] = 0;
    }

    //排序用的数组大小取决于元素的最大值，利用的是哈希表
    int index[max_etem+1] = {0};

    //数组下标是有序的，因此将元素大小作为下标，，在index数组中标记出来，那么元素的顺序也就确定了
    for(int i = 0; i < len; ++i)
    {
        index[tmp[i]] = index[tmp[i]] + 1;  //可能有重复的元素
    }

    //统计处这个元素前面有多少的元素
    for(int i = 1; i < max_etem+1; ++i)
    {
        index[i] = index[i] + index[i-1];
    }

    //保存结果，从后往前排是比较方便的，可以一次处理好重复元素的下标，否则从前往后排在处理重复元素时会比较麻烦
    for(int i = len-1; i >= 0; --i)
    {
        ary[index[tmp[i]]-1] = tmp[i];  //index中方的就是元素前面的元素的个数，减1就是下标
        index[tmp[i]]--;    //每存一个元素，那么这个元素重复的个数相应减1
    }
}

int main()
{
    int ary[] = {6,2,1,7,4,4,6,3, 0};
    int len = sizeof(ary)/sizeof(int);
    //cout << len << endl;
    ShowArray(ary, len);
    CountSort(ary, len);
    ShowArray(ary, len);
    return 0;
}
