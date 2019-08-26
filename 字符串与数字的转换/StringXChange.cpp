#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cstdlib>
#include <string>
#include <sstream>
#include "App.h"
using namespace std;



//字符串转double
void StrToD( )
{
	//字符串转double
	double d = 0.0;
	string str_to_d;
	cin >> str_to_d;
	d = stod(str_to_d);
	//12.3输出12.3
	//012.3输出12.3
	//0x123输出291，先转换成16进制0x123再转换成十进制数。
	cout << "double_type :" << d << endl;
	cout << hex << d << endl;		//不会转换成16进制输出，输出就接过与上面一样,浮点型数据不会自动转换成整形数据

	//字符串转float, 与上面类似，用stof
}
//字符串转float, 与上面类似，用stof
void StrToF( )
{
	//字符串转float, 与上面类似，用stof
}
//字符串转int,用stoi
void StrToI( )
{
	//字符串转int,用stoi
	int i = 0;
	string str_to_i;
	cin >> str_to_i;
	i = stoi(str_to_i);
	cout << "int_type: " << i << endl;
	cout << hex << "int_type: " << i << endl;
	//123输出123,7b	后一条语句会自动转换
	//0123输出123,7b
	//0x123 输出0,0,		非法输入不能自动转换
	//1a输出1,1		a非法报错
}
//字符串转int,用stol
void StrToL( )
{
	//字符串转int,用stol
	long l = 0;
	string str_to_l;
	cin >> str_to_l;
	l = stol(str_to_l);
	cout << "int_type: " << l << endl;
	cout << hex << "int_type: " << l << endl;
	//123输出123,7b	后一条语句会自动转换
	//0123输出123,7b
	//0x123 输出0,0,		非法输入不能自动转换
	//1a输出1,1		a非法报错
}

//字符串转unsigned long
void StrToUL( )
{
	//字符串转unsigned long,用stoul
	unsigned long ul = 0;
	string str_to_ul;
	cin >> str_to_ul;
	ul = stoul(str_to_ul);
	cout << "int_type: " << ul << endl;
	cout << hex << "int_type: " << ul << endl;
	//123输出123,7b	后一条语句会自动转换
	//0123输出123,7b
	//0x123 输出0,0,		非法输入不能自动转换
	//1a输出1,1		a非法报错
}

//屏幕以16进制形式输入字符串，输出16进制形式整形数
void StrToHex( )
{
	//字符串转double
	unsigned long h = 0;
	string str_to_d;
	cin >> str_to_d;
	h = stod(str_to_d);	//自动转换成整形数据保存在d
	cout << "double_type :" << h << endl;		//以十进制输出
	cout << hex << h << endl;		//以16进制输出
	//12.3输出12.3
	//012.3输出12.3
	//0x123输出291, 123
	//0xab输出171， ab
	//ab 非法报错。
}

/**
上述转换均是利用string类中的函数自动转换的，若是其他形式的输入，则应该逐个字符判断
*/

//
void ToString( )
{
	unsigned long h = 0xab;
	cin>> hex >> h;		//16进制输入
	string str;

	//////////////////////////////////////////////////////////
	stringstream ioss;	//定义字符串流
	ioss << hex << h << endl;
	ioss >> str;
	//////////////////////////////////////////////////////////

	cout << str << endl;
}