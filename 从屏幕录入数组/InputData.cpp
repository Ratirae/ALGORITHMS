/*
从屏幕录入数据，存入数组，录入时数据在一行
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "NormalTest.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
//从屏幕录入数据，数据个数已知
void InputArray(int* arry, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> arry[i];
	}
}
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
/** \brief从屏幕录入字符串，以某个字符分割字符串,如：qwe,asd,zxc    用逗号分隔，并存入数组
* \param str string 输入的字符串
* \param partern string 分隔符，上例中就是",",也可以是一个更长的字符串
*/
vector<string> DivStr(string str, string partern)
{
	str += partern;	//在尾部添加分割符，便于处理
	vector<string> result;	//保存分割后的字符串
	int pos = 0;	//标志分割符的位置
	int len = str.size( );
	for(int i = 0; i < len; ++i)
	{
		pos = str.find(partern, i);		//find(分割符字符串, 第i个分割符)返回的是位置，i从0开始，i=0代表第一个分割符
		if(pos < len)	//分割符的最大值处于字符串的尾部，该值得最大值=len-1，
		{
			string tmp = str.substr(i, pos-i);	//分割出子字符串，substr(首字符位置，要分割的长度)
			i = pos + partern.size( ) -1;	//更新i的值，是它处于第一个分割符处，partern.size( ) -1是为了防止分割符是多个字符的字符串
			result.push_back(tmp);
		}
	}
	return result;
}
//调用demo，输入：
//3
//qwe,asd,zxc
//ert,dfg,cvb,yui
//jmu,gbt
//连续输入，最后保存在一个二位数组中
int main()
{
	vector<vector<string>> all;
	int n = 0;
	cin >> n;
	while(n > 0)
	{
		string tmp_str;
		vector<string> family;
		cin>>tmp_str;
		family = DivStr(tmp_str, ",");	//以","为分割符，将每个字符串分割成字符串数组
		all.push_back(family);
		n--;
	}
	for(int i = 0; i < all.size(); ++i)
	{
		for(int j = 0; j < all[i].size(); ++j)
		{
			cout << all[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
//补充，string类中find()函数找不到是的应用
int main( )
{

	string str = "abcdefg";
	int p = str.find("o", 0);	//真实数据类型是size_t，但是用int代替没有问题
	if(p != string::npos)	//string::npos，是没有找到时的返回位置，是个特殊标志位，不加string::实测不可行
	{
		cout << p << endl;
	}
	else
	{
		cout << "没找到" << endl;	//将输出这条语句
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////




