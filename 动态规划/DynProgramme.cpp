/** 
 * \brief 自底向上动态规划，求解钢条切割问题
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;


inline int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

//动态规划
int DyProg(vector<int>& ve, int target)
{
	if (target == 0)
		return 0;
	const int len = ve.size();
	vector<int> get(len, 0);		//用于保存每一种最大收益

	//外循环，分别求出每一个长度的最大收益
	for (int i = 1; i < target+1; ++i)
	{
		int max_get = INT_MIN;

		//在长度为 i 时，求出其每一种收益可能，保留最大的
		for (int j = 1; j < i + 1; ++j)
		{
			int tmp = ve[j] + get[i - j];
			max_get = max(max_get, tmp);
		}

		get[i] = max_get;			//记录最大收益
	}

	//所有长度不超过target的最大收益都已经求出来了
	return get[target];
}


int main()
{
	vector<int> ve = { 0,1,5,8,9,10,17,17,20,24,30 };
	cout << DyProg(ve, 7) << endl;
}
