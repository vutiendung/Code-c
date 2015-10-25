#include<iostream>
#include<math.h>
using namespace std;
struct result
{
    int last[200],current[200];
};
struct Point
{
    int x,y;
};
void Tru(int a[100][100],int m,int n)
{
    for(int i=0;i<m;i++)
       {
            int min=a[i][0];
            for(int j=0;j<n;j++)
                if(a[i][j]<min)
                    min=a[i][j];
            for(int j=0;j<n;j++)
                a[i][j]-=min;
       }
       for(int i=0;i<m;i++)
       {
            int min=a[i][0];
            for(int j=0;j<n;j++)
                if(a[j][i]<min)
                    min=a[j][i];
            for(int j=0;j<n;j++)
                a[j][i]-=min;
       }
}
void Re_Caculater_data(int a[100][100],int m,int n,int line[100][100])
{
    int min,i,j;
    i=j=0;
    while(i<m)
    {
        while(j<m)
        {
            if(j==m-1) cout<<endl;
            if(line[i][j]==0)
            {
                min=a[i][j];
                break;
            }
            j++;
        }
        i++;
        if(min!=0)
            break;
    }
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            if(line[i][j]==0 && a[i][j]<min)
                min=a[i][j];

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            if(line[i][j]==0)
                a[i][j]-=min;
            else
                if(line[i][j]==2)
                    a[i][j]+=min;
        }
}
int Find_line(int a[100][100],int m,int n,int line[100][100])
{
    int countLine=0,i,j;
    bool row[100],col[100];
    for(i=0;i<m;i++)
        row[i]=false;
    for(i=0;i<n;i++)
        col[i]=false;
    i=j=0;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0 && (col[j]==false || row[i]==false))
            {
                int countN=0;//dem ngang
                for(int k=0;k<n;k++)
                    if(a[i][k]==0)
                        countN++;
                int countD=0;//dem doc
                for(int k=0;k<=n;k++)
                    if(a[k][j]==0)
                        countD++;
                if(countN<countD)
                {
                    //ve cot
                    if(col[j]==false)
                    {
                        for(int r=0;r<m;r++)
                            line[r][j]+=1;
                        col[j]=true;
                    }
                }
                else
                {
                    //ve dong
                    if(row[i]==false)
                    {
                        for(int r=0;r<m;r++)
                            line[i][r]+=1;
                        row[i]=true;
                    }
                }
            }
        }
    //dem so line
    for(i=0;i<m;i++)
        if(row[i]==true)
            countLine++;
    for(i=0;i<n;i++)
        if(col[i]==true)
            countLine++;
        return countLine;
}
void Reset_line(int line[100][100],int m,int n)
{
   for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            line[i][j]=0;
}
void PhanCong(int a[100][100],int m,int n,int line[100][100],result &r)
{
    bool row[100],col[100];
    for(int i=0;i<m;i++)
    {
        row[i]=false;
        col[i]=false;
    }
    //tim so 0 uu tien truoc
    int dem=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(0==a[i][j] && !col[j] && !row[i])
            {
                int countN=0;
                for(int k=0;k<m;k++)
                    if(a[i][k]==0)
                        countN++;
                if(1==countN)
                    {
                        r.last[dem]=i;
                        r.current[dem]=j;
                        dem++;
                        col[j]=true;
                        row[i]=true;
                    }
            }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(0==a[i][j] && !col[j] && !row[i])
            {
                int countN=0;
                for(int k=0;k<m;k++)
                    if(a[k][j]==0)
                        countN++;
                if(1==countN)
                    {
                        r.last[dem]=i;
                        r.current[dem]=j;
                        dem++;
                        col[j]=true;
                        row[i]=true;
                    }
            }
    //tim uu tien muc 2
        for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    if(0==a[i][j] && !col[j] && !row[i])
                    {
                        r.last[dem]=i;
                        r.current[dem]=j;
                        dem++;
                        col[j]=true;
                        row[i]=true;
                    }
}

int KhoangCach(Point A,Point B)
{
    int kq=(int)sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

void TaoMangKhoangCach(int a[100][100],Point last[100],Point current[100],int m,int n)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            a[i][j]=KhoangCach(last[i],current[j]);
}
void Hunggary(Point last[100],Point current[100],int m,int n,result &r,int &sl)
{
    int a[100][100];
    int line[100][100];
    TaoMangKhoangCach(a,last,current,m,n);
    Reset_line(line,m,n);
    int i=0;
    Tru(a,m,n);
    while(true)
    {
        int b=Find_line(a,m,n,line);
        if(b<m)
        {
            Re_Caculater_data(a,m,n,line);
            i++;
            Reset_line(line,m,n);
        }
        else
        {
            sl=b;
            PhanCong(a,m,n,line,r);
            break;
        }
    }

}

