#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cstdlib>
#include <string>
#include <sstream>
#include "App.h"
using namespace std;



//�ַ���תdouble
void StrToD( )
{
	//�ַ���תdouble
	double d = 0.0;
	string str_to_d;
	cin >> str_to_d;
	d = stod(str_to_d);
	//12.3���12.3
	//012.3���12.3
	//0x123���291����ת����16����0x123��ת����ʮ��������
	cout << "double_type :" << d << endl;
	cout << hex << d << endl;		//����ת����16�������������ͽӹ�������һ��,���������ݲ����Զ�ת������������

	//�ַ���תfloat, ���������ƣ���stof
}
//�ַ���תfloat, ���������ƣ���stof
void StrToF( )
{
	//�ַ���תfloat, ���������ƣ���stof
}
//�ַ���תint,��stoi
void StrToI( )
{
	//�ַ���תint,��stoi
	int i = 0;
	string str_to_i;
	cin >> str_to_i;
	i = stoi(str_to_i);
	cout << "int_type: " << i << endl;
	cout << hex << "int_type: " << i << endl;
	//123���123,7b	��һ�������Զ�ת��
	//0123���123,7b
	//0x123 ���0,0,		�Ƿ����벻���Զ�ת��
	//1a���1,1		a�Ƿ�����
}
//�ַ���תint,��stol
void StrToL( )
{
	//�ַ���תint,��stol
	long l = 0;
	string str_to_l;
	cin >> str_to_l;
	l = stol(str_to_l);
	cout << "int_type: " << l << endl;
	cout << hex << "int_type: " << l << endl;
	//123���123,7b	��һ�������Զ�ת��
	//0123���123,7b
	//0x123 ���0,0,		�Ƿ����벻���Զ�ת��
	//1a���1,1		a�Ƿ�����
}

//�ַ���תunsigned long
void StrToUL( )
{
	//�ַ���תunsigned long,��stoul
	unsigned long ul = 0;
	string str_to_ul;
	cin >> str_to_ul;
	ul = stoul(str_to_ul);
	cout << "int_type: " << ul << endl;
	cout << hex << "int_type: " << ul << endl;
	//123���123,7b	��һ�������Զ�ת��
	//0123���123,7b
	//0x123 ���0,0,		�Ƿ����벻���Զ�ת��
	//1a���1,1		a�Ƿ�����
}

//��Ļ��16������ʽ�����ַ��������16������ʽ������
void StrToHex( )
{
	//�ַ���תdouble
	unsigned long h = 0;
	string str_to_d;
	cin >> str_to_d;
	h = stod(str_to_d);	//�Զ�ת�����������ݱ�����d
	cout << "double_type :" << h << endl;		//��ʮ�������
	cout << hex << h << endl;		//��16�������
	//12.3���12.3
	//012.3���12.3
	//0x123���291, 123
	//0xab���171�� ab
	//ab �Ƿ�����
}

/**
����ת����������string���еĺ����Զ�ת���ģ�����������ʽ�����룬��Ӧ������ַ��ж�
*/

//
void ToString( )
{
	unsigned long h = 0xab;
	cin>> hex >> h;		//16��������
	string str;

	//////////////////////////////////////////////////////////
	stringstream ioss;	//�����ַ�����
	ioss << hex << h << endl;
	ioss >> str;
	//////////////////////////////////////////////////////////

	cout << str << endl;
}