#include <iostream>
#include <limits>
using namespace std;
struct PositioASum {
    int low;
    int high;
    int sum;
};
//寻找包含中点位置的最大子数组函数
PositioASum MaxCrossingSubarray(int a[], int low, int mid, int high);
PositioASum FindMaxSubArray(int a[], int low, int high);
int main()
{
    int ary[]{-2,-4,-5,6,8,5,-9,-7,-1};
    int n = sizeof(ary) / sizeof(int);
    int sum = 0;
    int first_index = 0;
    int length = 0;
    PositioASum result = FindMaxSubArray(ary, 0, (n-1));
    cout << result.sum << "\t" << result.low << "\t" << result.high << endl;
    cout << "Hello world!" << endl;
    return 0;
}

//最大数组,需要确认首地址和数组长度
//分治法求最大子数组和问题
//寻找包含中点位置的最大子数组函数
PositioASum MaxCrossingSubarray(int a[], int low, int mid, int high)
{
    //求中点左边的最大值和最大位置
    int maxLeft;//记录左边的最大位置
    int maxSumLeft=-10000;//记录左边的最大和
    int sumLeft=0;
    for (int i = mid; i >= low; i--)
    {
        sumLeft += a[i];
        if (sumLeft > maxSumLeft)
        {
            maxSumLeft = sumLeft;
            maxLeft = i;
        }
    }
    //求中点右边的最大值和最大位置
    int maxRight=mid+1;//记录右边的最大位置
    int maxSumRight = -10000;//记录右边的最大和
    int sumRight = 0;//记录右边子数列的和
    for (int i = mid+1; i <= high; i++)
    {
        sumRight += a[i];
        if (sumRight > maxSumRight)
        {
            maxSumRight = sumRight;
            maxRight = i;
        }
    }
    PositioASum ps;
    ps.low = maxLeft;
    ps.high = maxRight;
    ps.sum = maxSumLeft + maxSumRight;
    return ps;
}
//分治法
PositioASum FindMaxSubArray(int a[], int low, int high)
{
    if (low == high)
    {
        PositioASum ps;
        ps.low = low;
        ps.high = high;
        ps.sum = a[low];
        return ps;
    }
    else{
        int mid = (low + high) / 2;
        PositioASum left = FindMaxSubArray(a, low, mid);
        PositioASum right = FindMaxSubArray(a, mid + 1, high);
        PositioASum cross = MaxCrossingSubarray(a, low, mid, high);
        if (left.sum >= cross.sum && left.sum >= right.sum)
        {
            return left;
        }
        else if (right.sum >= left.sum && right.sum >= cross.sum)
        {
            return right;
        }else{
            return cross;
        }
    }
}











