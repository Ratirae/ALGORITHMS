#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//结构
struct MaxSub
{
    vector<int> max_sub;
    int max_sum;
};


/** \brief 寻找最大子数组
 *
 * \param ve vector<int>& 目标数组
 * \return MaxSub 返回值
 */
MaxSub FindMaxSubarray(vector<int> &ve)
{
    MaxSub max_sub;
    int sum = 0;
    int max_sum = INT_MIN;
    int len = ve.size();
    int p = 0;    //首下标
    int q = 0;    //尾下标
    int tmp_p = 0;//首下标的临时量
    for(int i = 0; i < len; ++i)
    {
        sum += ve[i];
        if(sum > max_sum)   //出现更大的和值时，更新最大和，并更新子数组的尾下标
        {
            max_sum = sum;
            p = tmp_p;  //只有当最大值更新，才能保证队首下标真正的更新
            q = i;
        }
        if(sum < 0)     //当出现一个负数，绝对值比前面的最大和还要大时，那么代表前面的所有数对后续循环没有影响
        {
            sum = 0;
            tmp_p = i+1;//队尾下标更新后，可能出现和是负数，且一直循环玩都没有更新最大和，因此可能出现p>q的情况
        }
    }
    max_sub.max_sum = max_sum;
    max_sub.max_sub = {ve.begin()+p, ve.begin()+q+1};
    return max_sub;
}

int main()
{
    MaxSub s;
    vector<int> ve = {5,1,-1,6,5,-29,6,-3,3};
    s = FindMaxSubarray(ve);
    for(auto &i : s.max_sub)
    {
        cout << i << "  ";
    }
    cout << "\n" << s.max_sum << endl;

    return 0;
}
