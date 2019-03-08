#include <iostream>
const double INFINITE = 9999;
using namespace std;
void Merge(double ary[], int n);
int main()
{
    double ary[]{ 89, 56.7, 12.7, 56.2, 3, 99, 0.8,4,3};
    int n = sizeof(ary)/sizeof(double);
    cout << "数组长度:" << n << endl;
    for(auto i:ary)
    {
        cout << i << endl;
    }
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    Merge(ary, n);  //调用
    for(auto i:ary)
    {
        cout << i << endl;
    }
    return 0;
}

void Merge(double ary[], int n)
{
    if(n < 2)
    { return; }

    int n1 = 0, n2 = 0; //分制数组长度
    int r = n/2;
    n1 = r;
    n2 = n-r;
    double ary1[n1+1] {0};
    double ary2[n2+1] {0};
    for(int i = 0; i < n1; ++i)
    {
        ary1[i] = ary[i];
    }
    ary1[n1] = INFINITE;
    for(int i = 0; i < n2; ++i)
    {
        ary2[i] = ary[r+i];
    }
    ary2[n2] = INFINITE;

    Merge(ary1, n1);
    Merge(ary2, n2);

    int p = 0, q = 0;
    for(int j = 0; j < n; ++j)
    {
        /*if(ary1[p] == INFINITE && ary2[q] == INFINITE)    //加上两个哨兵元素总长度为n+2,而执行n次循环就会退出,因此不需要这段代码
        {   break;   }*/

        if(ary1[p] <= ary2[q])
        {
            ary[j] = ary1[p];
            p++;
        }else
        {
            ary[j] = ary2[q];
            q++;
        }
    }

}
