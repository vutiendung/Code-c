#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct largNum
{
    int countF,countB;
    int F[500],B[500];
    //bool isNegative;
};
int max(int a,int b)
{
    if(a>=b) return a;
        else return b;
}
void chuyenSoLonLen(largNum &a)
{
    int slCu=a.countF,n=a.countB;
    for(int i=499-a.countF-n+1;i<=499-n;i++)
    {
        a.F[i]=a.F[i+1];
    }
    a.countF=slCu+n;
    for(int i=499-n+1;i<=499;i++)
    {
        a.F[i]=a.B[499-i];
    }
    a.countB=0;
}
void chuyenSoNhoDi(largNum &a,int n)
{
    for(int i=499;i>499-n;i--)
    {
        a.B[499-i]=a.F[i];
        a.F[i]=a.F[i-n];
    }
    a.countB=n;
    a.countF=a.countF-n;

}

bool soSanh(largNum a,largNum b)
{
    if(a.countF<b.countF) return false;
    else
        if(a.countF>b.countF) return true;
        else
            {
                for(int i=a.countF;i<=499;i++)
                    if(a.F[i]>b.F[i])
                        return true;
                return false;
            }
}
void gan(largNum &a,int n)
{
    int i=0;
    while(n!=0)
    {
        a.F[499-i]=n%10;
        i++;
        n=n/10;
    }
    a.countF=i+1;
    a.countB=0;
}
void printNum(largNum a)
{
    if(a.countF==0)
        cout<<"0.";
    else
        for(int i=499;i>499-a.countF;i--)
            cout<<a.F[i];
    if(!a.countB==0)
    {
        if(a.countF!=0)
            cout<<".";
        for(int i=0;i<a.countB;i++)
            cout<<a.B[i];
    }
}
void scanfNum(largNum &a)
{
    cout<<"Nhap so: ";
    char s[256];
    gets(s);
    int vt=0,i=0,j=499;
    while(s[i]!='\0')
    {
        if(s[i]!='.')
        {
            a.F[j]=int(s[i])-48;
            a.countF=i+1;
            i++;
            j--;
        }
        else
        {
            vt=i+1;
            break;
        }
    }
    i=0;
    j=vt;
    while(s[j]!='\0')
    {
        if(s[j]!='\0')
        {
            a.B[i]=int(s[j])-48;
            a.countB=i+1;
            i++;
            j++;
        }
        else
            break;
    }
}
largNum cong(largNum a,largNum b)
{
    largNum result;
    int miss=0,tg;
    //cong phan thap phan
    result.countB=max(a.countB,b.countB);
    if(a.countB>b.countB)
    {
        for(int i=b.countB;i<=a.countB;i++)
        {
            b.B[i]=0;
        }

    }
    else
    {
        for(int i=a.countB;i<=b.countB;i++)
        {
            a.B[i]=0;
        }
    }
    for(int i=499;i>499-max(a.count,b.count);i--)
    {
        tg=a.var[i]+b.a.var[i]+miss;
        if(tg>=10)
        {
            miss=1;
            kq.var[i]=tg-10;
        }
        else
        {
            miss=0;
            kq.var[i]=tg;
        }
    }

    for(int i=max(a.countB,b.countB)-1;i>=0;i--)
    {
            int tg=a.B[i]+b.B[i]+miss;
            if(tg>=10)
            {
                miss=1;
                result.B[i]=tg-10;
            }
            else
            {
                result.B[i]=tg;
                miss=0;
            }
    }
    //cong phan nguyen
    if(a.countF>b.countF)
    {
        for(int i=499-a.countF;i<499-b.countF;i++)
        {
            b.F[i]=0;
        }

    }
    else
    {
        for(int i=499-b.countF;i<499-a.countF;i++)
        {
            a.F[i]=0;
        }
    }
    for(int i=499;i>499-max(a.countF,b.countF);i--)
    {
        int tg=a.F[i]+b.F[i]+miss;
        if(tg>=10)
        {
            miss=1;
            result.F[i]=tg-10;
        }
        else
        {
            miss=0;
            result.F[i]=tg;
        }
    }
    if(miss==1)
    {
        result.F[499-max(a.countF,b.countF)-1]=1;
        result.countF=max(a.countF,b.countF)+1;
    }
    else
    {
        result.countF=max(a.countF,b.countF);
    }
    return result;
}
largNum nhan(largNum a,largNum b)
{
    largNum kq,ii,them;
    gan(ii,0);
    gan(them,1);
    int aB=a.countB,bB=b.countB;
    chuyenSoLonLen(a);
    chuyenSoLonLen(b);
    while(soSanh(ii,a)==false)
    {
        kq=cong(kq,b);
        ii=cong(ii,them);
        printNum(ii);
        cout<<endl;
    }
    chuyenSoNhoDi(kq,aB+bB);
    return kq;
}

int main()
{
    largNum a,b,c;
    scanfNum(a);
    scanfNum(b);
    c=nhan(a,b);
    cout<<"--------------------";
    cout<<"Tich a x b:"<<endl;
    printNum(c);
    return 0;
}
