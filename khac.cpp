#include<iostream.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<dos.h>

long kiemtra(long n)
{
	if(n<=2) return 1;
	else
	{
		int dem=0;
		for(int i=2;i<=(int)sqrt(n);i++)
			if(n%i==0)
			{
				dem=1;
            break;
			}
		if(dem==0) return 1; else return 0;
	}
}

long xetso(long n)
{
	long plus=0;
	while(n!=0)
	{
		plus++;
		n/=10;
	}
	return pow(10,plus);
}
void main()
{
	while(1==1)
	{
	struct time start,end;
	int k;
   cout<<"Nhap k=0 de ket thuc\n";
	cout<<"K="; cin>>k;
   if(k==0) break;
	long a;
	int i=1;
	long s1=2;
	gettime(&start);
	while(i<=k)
	{
		if(kiemtra(s1)==1)
		{
			long s2=s1+1;
			while(kiemtra(s2)!=1)
			{
				s2+=1;
			}
			long s=s1*xetso(s2)+s2;
			if(kiemtra(s)==1)
			{
				if(i==k)a=s;
				i++;
			}
			s1=s2+1;
		}
		else
			if(s1%2==0) s1+=1;
         	else s1+=2;
	}
	gettime(&end);
	cout<<"So can tim:            "<<a<<endl;
	int dff=(int)end.ti_sec-(int)start.ti_sec;
	cout<<"Thoi gian thuc hien:   "<<dff<<" s.";
	cout<<"\nStart at             "<<(int)start.ti_hour<<":"<<(int)start.ti_min<<":"<<(int)start.ti_sec;
	cout<<"\nEnd at               "<<(int)end.ti_hour<<":"<<(int)end.ti_min<<":"<<(int)end.ti_sec;
	cout<<"\nBam mot phim bat ky de tiep tuc ...";
	getch();
	clrscr();
	}
}
