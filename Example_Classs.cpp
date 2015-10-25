#include<iostream>
#include<conio.h>
using namespace std;
class HCN
{
    public:
        int dai,rong;
        int dienTich()
        {
            return dai*rong;
        }
        int chuVi()
        {
            return (dai+rong)*2;
        }
};

int main()
{
    HCN a;
    a.dai=5;
    a.rong=10;
    cout<<a.chuVi();
}
