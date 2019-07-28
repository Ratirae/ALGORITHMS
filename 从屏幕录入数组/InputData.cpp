/*
从屏幕录入数据，存入数组，录入时数据在一行
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "NormalTest.h"

using namespace std;

//从屏幕录入数据，数据个数未知
void InputVector(vector<int>& arry_a)
{
	char c;
	int tmp = 0;
	cin >> tmp;	//读取输入行的第一个字符(2)
	arry_a.push_back(tmp);
	while ((c = getchar()) != '\n') {	//读取输入行的第二个字符(“ ”)
		cin >> tmp;	//读取输入行的第三个字符(3)
		arry_a.push_back(tmp);
	}
}

//从屏幕录入数据，数据个数已知
void InputArray(int* arry, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> arry[i];
	}
}

//从屏幕录入数据并检查是否合法
void InputAndErease()		
{
	int a, b;	//如果数据值可能很大，int 考虑换成 long long
	while (scanf_s("%d %d", &a, &b) != EOF) 
	{
		//Do...
		cout << a << " " << b << endl;
		//if()
			//break;
	}
}