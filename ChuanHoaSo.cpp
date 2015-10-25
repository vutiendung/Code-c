#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double x=1000000;
    cout<<x<<endl;
    int n=6;


    if(x-int(x)==0)
    {
        //so khong co dau cham phay
        if(x>0)
        {
            x=pow(10,n)-1;
        }
        else
        {
            x=-(pow(10,n-1)-1);
        }
    }
    else
    {
        //so co dau cham phay

        double tg=int(x);
        if(tg<0)
        {
            tg=-tg;
        }
        int dem1=0;
//        cout<<"so truoc"<<tg<<endl;
        //dem so phan tu truoc dau phay
        while(tg>=1)
        {
            dem1++;
            tg=tg/10;
        }
//        cout<<"So luong so truoc: "<<dem1<<endl;
        //dem so phan tu sau dau phay
        int tem[10];
        int dem2=0;
        tg=x;
        if(tg<0)
        {
            tg=-tg;
        }
        while(tg-int(tg)>0)
        {
            dem2++;
            tg*=10;
        }

        long b=long(x)*pow(10,dem2);
        if(b<0)
        {
            b=-b;
        }
        long soSau=tg-b;
//        cout<<"So sau:"<<soSau<<endl;
//        cout<<"So luong so sau: "<<dem2<<endl;
        //tach ky tu trong so sau
        long l=dem2-1;
        while(soSau>=1)
        {
            tem[l]=soSau%10;
            soSau/=10;
            l--;
        }

        if(x<0)
        {
            dem1++;
        }

        long sl=n-dem1;
        for(int i=sl-1;i>=0;i--)
        {
            if(tem[i+1]>4)
            {
                tem[i]++;
                tem[i+1]=0;
            }
        }
//        //in mang sau khi lam tron
//        for(int i=0;i<sl;i++)
//        {
//            cout<<tem[i]<<" ";
//        }
//        cout<<endl;
        float kq=int(x);
        if(x<0)
        {
            //lam duong so
            kq=-kq;
        }
        if(tem[0]>9)
        {
            kq+=1;
            tem[0]=0;
        }
        for(int i=0;i<sl;i++)
        {
            kq+=pow(0.1,i+1)*tem[i];
        }
        if(x<0)
        {
            kq=-kq;
        }
        x=kq;
    }

    cout<<"Result="<<x;
    return 0;
}
