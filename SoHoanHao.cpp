#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

bool CheckNumberPerfect(long n)
{
    long tg=0;
    for(long i = 1 ; i <=(n/2) ; i++)
    if(n % i==0)
    {
        tg+=i;
    }
    if(n==tg)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cout<<"Nhap so luong so hoan hao can tim: ";
    cin>>n;
    long i=2,dem=0;

    while(dem<=n)
    {
        if(CheckNumberPerfect(i)==true)
        {
            cout<<"So hoan hao :"<<i<<endl;
            dem++;
            getch();
        }
        i++;
        cout << i << endl;
    }
}
