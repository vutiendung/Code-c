#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct IntNumLarg
{
    int var[500],count;
};

IntNumLarg scanfNum()
{
    IntNumLarg a;
    cout<<"Nhap so: ";
    char s[256];
    gets(s);
    int i=0,j=499;
    while(s[i]!='\0')
    {
        a.var[j]=int(s[i])-48;
        a.count=i+1;
        i++;
        j--;
    }
    return a;
}
void printNum(IntNumLarg a)
{
    for(int i=499;i>499-a.count;i--)
        cout<<a.var[i];
    cout<<"\tsl:"<<a.count;
}
int max(int a,int b)
{
    if(a>=b) return a;
        else return b;
}
bool soSanh(IntNumLarg a,IntNumLarg b)
{
    if(a.count>b.count) return true;
    else
        if(a.count<b.count) return false;
        else
        {
            for(int i=499-a.count+1;i<=499;i++)
                if(a.var[i]>b.var[i]) return true;
            return false;
        }
}
void gan(IntNumLarg &a,int n)
{
    int i=0;
    if(n==0)
    {
        a.count=1;
        a.var[499]=0;
    }
    else
    {
        while(n!=0)
        {
            a.var[499-i]=n%10;
            n/=10;
            a.count=i+1;
            i++;
        }
    }

}
IntNumLarg cong(IntNumLarg a,IntNumLarg b)
{
    IntNumLarg kq;
    int miss=0;
    //-------------------------
    if(a.count>b.count)
    {
        for(int i=499-a.count;i<=499-b.count;i++)
        {
            b.var[i]=0;
        }
    }
    else
    if(b.count>a.count)
    {
        for(int i=499-b.count;i<=499-a.count;i++)
        {
            a.var[i]=0;
        }
    }
    //-----------------------
     for(int i=499;i>499-max(a.count,b.count);i--)
    {
        int tg=a.var[i]+b.var[i]+miss;
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
    if(miss==1)
    {
        kq.count=max(a.count,b.count)+1;
        kq.var[499-kq.count]=1;
    }
    else
    {
        kq.count=max(a.count,b.count);
    }
    return kq;
}
IntNumLarg nhan(IntNumLarg a,IntNumLarg b)
{
    IntNumLarg i,add,kq;
    gan(i,0);
    gan(kq,0);
    gan(add,1);
    while(soSanh(a,i)==true)
    {
        kq=cong(kq,b);
        i=cong(i,add);
    }
    return kq;
}
int main()
{
    IntNumLarg a,b,c;
    gan(a,6);
    gan(b,6);
    c=cong(a,b);
    printNum(c);
    return 0;
}
