#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

void DebugPrint(vector<int>& ve) {
	for (auto& i : ve)
		cout << i << " ";
	cout << endl;
}

//容器形式
void Fun1() {
	vector<int> arry_a;
	//输入数组a, 数组长度未知
	//输入：2 3 4 5 6 7
	char c;
	int tmp = 0;
	cin >> tmp;	//读取输入行的第一个字符(2)
	arry_a.push_back(tmp);
	while ((c = getchar()) != '\n') {	//读取输入行的第二个字符(“ ”)
		cin >> tmp;	//读取输入行的第三个字符(3)
		arry_a.push_back(tmp);
	}
	
	//Debug
	//DebugPrint(arry_a);
}

//数组形式
void Fun2() {
	int a[500]; 
	int m = 0; 
	int temp; 
	char c;
	
	//输入数组a, 数组长度未知
	//输入：2 3 4 5 6 7
	cin>>a[m++]; //读取输入行的第一个字符(2)
	while ((c = getchar()) != '\n') //读取输入行的第二个字符(“ ”)
	{
      	cin >> temp;//读取输入行的第三个字符(3)
      	a[m++] = temp;
 	}
}

//数组长度已知
void Fun3() {
	int a[500]; int n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		a[i] = temp;
    }
}

//屏幕输入数据，同时判断是否合法，用scanf更加方便
void Fun4() {
	long long l,r;
	while(scanf("%d %d", &l, &r) != EOF ) {
		//Do...
	}
}

int main() {
	//输入：2 3 4 5 6 7
	Fun1();
	return 0;
}






