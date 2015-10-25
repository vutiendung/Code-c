#include<iostream>
#include<math.h>
#include<fstream>
#include <cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;

struct Point
{
    int X;
    int Y;
};
struct Cluster
{
    Point Possition;
    int numberOfMember;
};

double Distance(Point A,Point B)
{
    return double(sqrt((A.X-B.X)*(A.X-B.X) + (A.Y-B.Y)*(A.Y-B.Y) ));
}

bool IsCluster(Cluster ArrayCluster[50],int k,int x,int y)
{
    for(int i=0;i<k;i++)
    {
        if(ArrayCluster[i].Possition.X==x && ArrayCluster[i].Possition.Y==y)
        {
            return true;
        }
        return false;
    }
}

bool CheckClusterDiff(Cluster ArrayCluster[50],int x,int y,int pos)
{
    //kiem tra cluster da co chua. neu co roi return false
    if(pos==0)
    {
        return true;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            if(x==ArrayCluster[i].Possition.X && y==ArrayCluster[i].Possition.Y)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    cout<<"                     Demo K-Mean!"<<endl;

    ifstream _readFile("C:/Data2.txt");
    int sl;
    _readFile>>sl;

    int k;
    cout<<"Please input number of cluster k=";
    cin>>k;

    Cluster ArrayCluster[k];
    int MarkUp[50][50];
    int Data[50][50];

    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
        {
            MarkUp[i][j]=-1;
            Data[i][j]=-1;
        }

    //Read data from text file to array form: x y value

    for(int i=0;i<sl;i++)
    {
        int x,y,d;
        _readFile>>x>>y>>d;
        Data[x][y]=d;
    }

    //search max x,y
    int maxx=0,maxy=0;
    int minx=51,miny=51;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            if(Data[i][j]!=-1)
            {
                //tim xy max;
                if(i>maxx)
                {
                    maxx=i;
                }

                if(j>maxy)
                {
                    maxy=i;
                }
                //tim min xy
                if(i<minx)
                {
                    minx=i;
                }
                if(j<miny)
                {
                    miny=j;
                }
            }
        }
    }
    int maxxy=(maxy>maxy)?maxx:maxy;
    int step=(int)maxxy/k;

    for(int i=0;i<k;i++)
    {
        if(i==0)
        {
            ArrayCluster[i].Possition.X=minx;
            ArrayCluster[i].Possition.Y=miny;
            ArrayCluster[i].numberOfMember=0;
        }
        else
        {
            ArrayCluster[i].Possition.X=ArrayCluster[i-1].Possition.X+step;
            ArrayCluster[i].Possition.Y=ArrayCluster[i-1].Possition.Y+step;
            ArrayCluster[i].numberOfMember=0;
        }

        cout<<"Cluster {"<<i<<"} \tx="<<ArrayCluster[i].Possition.X<<"\ty="<<ArrayCluster[i].Possition.Y<<endl;
    }

    bool change=true;
    int _lanThucHien=0;

    while(change==true)
    {
        _lanThucHien++;
        cout<<"Lan thuc hien thu: "<<_lanThucHien<<endl;

        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                if(Data[i][j]!=-1 && !IsCluster(ArrayCluster,k,i,j))
                {
                    Point tg;
                    tg.X=i;
                    tg.Y=j;
                    double m=(double)Distance(ArrayCluster[0].Possition,tg);
                    int pos=0;

                    //tim cluster gan nhat voi [i,j]
                    for(int ii=1;ii<k;ii++)
                        {
                            double _distance=(double)Distance(ArrayCluster[ii].Possition,tg);
                            if(m>_distance)
                            {
                                m=_distance;
                                pos=ii;
                            }
                        }

                    if(MarkUp[i][j]!=-1) //neu da duoc danh giau roi
                    {
                        ArrayCluster[MarkUp[i][j]].numberOfMember-=1;
                    }
                    MarkUp[i][j]=pos;
                    ArrayCluster[pos].numberOfMember+=1;
                    cout<<"|["<<i<<","<<j<<"]\t"<<"pos:"<<pos<<"|"<<endl;
                }

        change=false;
        //Caculater Possition of Cluster
        for(int i=0;i<k;i++)
        {
            int dem=ArrayCluster[i].numberOfMember;
            if(dem>0)
            {
                int tongx=0;
                int tongy=0;
                for(int ii=0;ii<50;ii++)
                    for(int jj=0;jj<50;jj++)
                        if(MarkUp[ii][jj]==i)
                        {
                            tongx+=ii;
                            tongy+=jj;
                        }
                double _x=ArrayCluster[i].Possition.X;
                double _y=ArrayCluster[i].Possition.Y;
                double x=_x;
                double y=_y;

                x=(int)tongx/dem;
                y=(int)tongy/dem;

                if(x!=_x || y!=_y)
                {
                    change=true;
                    ArrayCluster[i].Possition.X=x;
                    ArrayCluster[i].Possition.Y=y;
                    cout<<"|   Cluster: "<<i<<" ["<<x<<" "<<y<<"] thay doi|"<<endl;
                }
            }
        }

        for(int i=0;i<k;i++)
        {
            cout<<"Cluster: "<<i<<" \tVi tri tam: [";
            cout<<ArrayCluster[i].Possition.X<<","<<ArrayCluster[i].Possition.Y<<"]";
            cout<<"\tSo luong diem: "<<ArrayCluster[i].numberOfMember<<endl;
        }
        getch();
        cout<<"-------------------"<<endl;
    }
    cout<<"Press any key to view result ..."<<endl;
    getch();

    //Printf Data to screen.
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
        {
            if(MarkUp[i][j]<0)
                cout<<" ";
            else
                cout<<MarkUp[i][j];
            if(j==49)
                cout<<endl;
        }
        for(int i=0;i<k;i++)
        {
            cout<<"Cluster: "<<i<<" \tVi tri tam: [";
            cout<<ArrayCluster[i].Possition.X<<","<<ArrayCluster[i].Possition.Y<<"]";
            cout<<"\tSo luong diem: "<<ArrayCluster[i].numberOfMember<<endl;
        }
//    srand(time(NULL));
    return 0;
}
