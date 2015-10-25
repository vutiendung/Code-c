#include <iostream>
#include <math.h>
using namespace std;

bool KTSoNguyenTo(int a)
{
    if(a <= 1)
    {
        return false;
    }
    else
    {
        for(int i = 2; i <= sqrt(a) ; i++)
        {
            if(a % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int SLSo(int a)
{
    int dem = 0;
    while(a > 0)
    {
        dem++;
        a/=10;
    }
    return dem;
}

int main()
{
    int k;
    cout << "Nhap k=";
    cin >> k;

    long a = 0;
    long b = 0;

    long dem = 0;
    long i=2;
    while(dem < k)
    {
        if(KTSoNguyenTo(i) == true)
        {
            a = i;
            i++;
            while(KTSoNguyenTo(i) == false)
            {
                i++;
            }
            b = i;
            double tg = a * pow(10, SLSo(b)) + b;
            if(KTSoNguyenTo(tg) == true)
            {
                dem ++;
                if(dem == k)
                {
                    cout << "So can tim :" << tg;
                    break;
                }
            }
        }
        i++;
    }
}
