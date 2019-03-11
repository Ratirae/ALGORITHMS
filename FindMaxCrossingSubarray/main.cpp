#include <iostream>

using namespace std;
void FindMaxCrossingSubarry(int ary[], int n, int &sum, int &first_index, int &length);
int main()
{
    int ary[]{-2,-4,-5,6,8,5,-9,-7,-1};
    int n = sizeof(ary) / sizeof(int);
    int sum = 0;
    int first_index = 0;
    int length = 0;
    FindMaxCrossingSubarry(ary, n, sum, first_index,length);
    cout << sum << "\t" << first_index << "\t" << length << endl;
    cout << "Hello world!" << endl;
    return 0;
}

//最大数组,需要确认首地址和数组长度
void FindMaxCrossingSubarry(int ary[], int n, int &sum, int &first_index, int &length)
{
    int sum1 = -99;
    int sum2 = -99;
    int mid = n/2;
    int sum_temp = sum1;
    int left_index;
    int right_index;
    for(int i = mid; i >= 0; --i)
    {
        sum1 = sum_temp;
        sum_temp = sum_temp + ary[i];
        if(sum_temp < sum1)
        {
            left_index = i + 1;
            i = 0;
        }
    }
    sum_temp = sum2;
    for(int i = (mid+1); i < n; ++i)
    {
        sum2 = sum_temp;
        sum_temp = sum_temp + ary[i];
        if(sum_temp < sum2)
        {
            right_index = i-1;
            i = n;
        }
    }
    sum = sum1 + sum2;
    first_index = left_index;
    length = right_index - left_index +1;
}
