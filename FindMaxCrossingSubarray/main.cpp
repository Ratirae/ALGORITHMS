#include <iostream>
#include <limits>
using namespace std;
void FindMaxCrossingSubarry(int ary[], int n, int &sum, int &first_index, int &length);
void FindMaximumSubarray(int ary[], int low, int high, int &sum, int &first_index, int &length);
int main()
{
    int ary[]{-2,-4,-5,6,8,5,-9,-7,-1};
    int n = sizeof(ary) / sizeof(int);
    int sum = 0;
    int first_index = 0;
    int length = 0;
    FindMaxCrossingSubarry(ary, n, sum, first_index,length);
    cout << sum << "\t" << first_index << "\t" << length << endl;
    FindMaximumSubarray(ary, 0, (n-1), sum, first_index,length);
    cout << sum << "\t" << first_index << "\t" << length << endl;
    cout << "Hello world!" << endl;
    return 0;
}

//最大数组,需要确认首地址和数组长度
void FindMaxCrossingSubarry(int ary[], int n, int &sum, int &first_index, int &length)
{
    int sum1 = INT_MIN;
    int sum2 = INT_MIN;
    int mid = n/2;
    int sum_temp = 0;
    int left_index;
    int right_index;
    for(int i = mid; i >= 0; --i)
    {
        sum_temp = sum_temp + ary[i];
        if(sum_temp > sum1)
        {
            sum1 = sum_temp;
            left_index = i;
        }
    }
    sum_temp = 0;
    for(int i = (mid+1); i < n; ++i)
    {
        sum_temp = sum_temp + ary[i];
        if(sum_temp > sum2)
        {
            sum2 = sum_temp;
            right_index = i;
        }
    }
    sum = sum1 + sum2;
    first_index = left_index;
    length = right_index - left_index +1;
}

void FindMaximumSubarray(int ary[], int low, int high, int &sum, int &first_index, int &length)
{
    if(low == high)
        return;
    int mid = (low+high)/2;
    int left_sum = 0;
    int right_sum = 0;
    int cross_sum = 0;
    int left_index = 0;
    int right_index = 0;
    int cross_index = 0;
    int n1=0,n2=0,n3=0;
    FindMaximumSubarray(ary, low, mid, left_sum, left_index, n1);
    FindMaximumSubarray(ary, mid+1, high, right_sum, right_index, n2);
    //FindMaxCrossingSubarry(ary, (high-low+1), cross_sum, cross_index, n3);

    if(left_sum >= right_sum/* && eft_sum >= cross_sum*/)
    {
        sum = left_sum;
        first_index = left_index;
        length = n1;
    }else /*if(left_sum <= right_sum && right_sum >= cross_sum)*/
    {
        sum = right_sum;
        first_index = right_index;
        length = n2;
    }/*else
    {
        sum = cross_sum;
        first_index = cross_index;
        length = n3;
    }*/

}










