#include<iostream>
#include<math.h>
#include<conio.h>
#include<time.h>
using namespace std;

int i=0,j=0;
const int n=500,m=500;
int a[m][n];
struct point
{
	int x,y;
};
struct obj
{
	point E[100];
};
void timTD(obj OB,int d)
{
	int Xmax,Ymax,Ymin,Xmin;
	Xmax=Xmin=OB.E[1].x;
	Ymax=Ymin=OB.E[1].y;
	for(int i=2;i<=d;i++)
	{
		if(OB.E[i].x>Xmax) Xmax=OB.E[i].x;
		if(OB.E[i].x<Xmin) Xmin=OB.E[i].x;
		if(OB.E[i].y>Ymax) Ymax=OB.E[i].y;
		if(OB.E[i].y<Ymin) Ymin=OB.E[i].y;
	}
	cout<<"    MIN["<<Xmin<<","<<Ymin<<"]"<<endl;
	cout<<"    MAX["<<Xmax<<","<<Ymax<<"]"<<endl;
	cout<<"---------------------------"<<endl;
}

obj ob[100];
int D[100];

int main()
{
	for (i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			a[i][j]=0;
		}

		//cac vat the
	a[0][1]=a[0][2]=a[0][3]=a[1][1]=a[1][2]=a[1][3]=1;
	a[0][9]=a[0][10]=a[0][11]=a[0][12]=a[1][13]=a[1][14]=1;
	a[20][20]=a[20][21]=1;
	a[30][30]=a[30][31]=a[31][30]=1;
	a[35][35]=a[35][36]=a[35][37]=a[36][36]=a[36][37]=1;
	a[25][25]=a[25][26]=a[26][26]=1;
   a[5][5]=a[5][6]=a[6][5]=1;

	int flag=255; //gan co


	//gan co
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			{
					if(a[i][j]==1)
					{
						flag++;
						a[i][j]=flag;
						if(i>0)
						{
							if(a[i-1][j]!=0)   a[i-1][j]=flag;
							if(j>0)
								if(a[i-1][j-1]!=0) a[i-1][j-1]=flag;
							if(j<m-1)
								if(a[i-1][j+1]!=0) a[i-1][j+1]=flag;
						}
						if(j>0)
							if(a[i][j-1]!=0)   a[i][j-1]=flag;
						if(j<m-1)
							if(a[i][j+1]!=0)   a[i][j+1]=flag;
						if(i<m-1)
						{
							if(a[i+1][j]!=0)   a[i+1][j]=flag;
							if(j<m-1)
								if(a[i+1][j+1]!=0) a[i+1][j+1]=flag;
							if(j>0)
								if(a[i+1][j-1]!=0) a[i+1][j-1]=flag;
						}
					}
					else
					if(a[i][j]>255)
					{
						int f=a[i][j];
						if(i>0)
						{
							if(j>0)
								if(a[i-1][j+1]==1 && a[i-1][j+1]!=f) a[i-1][j+1]=f;
							if(j<m-1)
								if(a[i-1][j-1]==1 && a[i-1][j-1]!=f) a[i-1][j-1]=f;
							if(a[i-1][j]==1 && a[i-1][j]!=f)   a[i-1][j]=f;

						}
						if(i<m-1)
						{
							if(j>0)
								if(a[i+1][j-1]==1 && a[i+1][j-1]!=f) a[i+1][j-1]=f;
						  if(a[i+1][j]==1 && a[i+1][j]!=f)   a[i+1][j]=f;
						  if(j<m-1)
							if(a[i+1][j+1]==1 && a[i+1][j+1]!=f) a[i+1][j+1]=f;

						}
						if(j>0)
							if(a[i][j-1]==1)   a[i][j-1]=f;
						if(j<m-1)
							if(a[i][j+1]==1)   a[i][j+1]=f;
				}
		}

		int count=flag-255;//nhung vat phat hien dc

		//cho toa do cua cac vat vao list
		for(int k=1;k<=count;k++)
		{
			int d=0;
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
				{
					if(a[i][j]==k+255)
						{
                  	d++;
							ob[k].E[d].x=i;
							ob[k].E[d].y=j;
						}
					if(a[i][j+1]==0 && a[i+1][j+1] && a[i+1][j-1]==0) break;
				}
				if(d!=0)
				{
					D[k]=d;
				}
		}


			//in ra
      //xuat toa do HCN cua cac vat tim thay
		for(i=1;i<=count;i++)
		{
			cout<<"Object "<<i<<endl;
			timTD(ob[i],D[i]);
		 }

}

