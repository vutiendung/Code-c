#include<iostream>
#include<math.h>
#include<fstream>
#include <cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;

struct Point
{
    int x,y;
};

struct Group
{
    Point ListPossMember[50];
    int NumberOfMember;
};

double Distance(Point A,Point B)
{
    return double(sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) ));
}

int main()
{
    ifstream _readFile("C:/Data2.txt");
    int sl;
    _readFile>>sl;

    int Data[50][50];

    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
        {
            Data[i][j]=-1;
        }

    //Read data from text file to array form: x y value

    for(int i=0;i<sl;i++)
    {
        int x,y,d;
        _readFile>>x>>y>>d;
        Data[x][y]=d;
    }

    int DataBin[52][52];
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
        {
            if(i==0|| i==51 || j==0 || j==51)
            {
                DataBin[i][j]=0;
            }
            else
            {
                DataBin[i][j]=Data[i-1][j-1];
            }
        }
    }

    int flagArray[52][52];
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
        {
            flagArray[i][j]=-1;
        }
    }

    int dem=0;
    for(int i=1;i<51;i++)
    {
        for(int j=1;j<51;j++)
        {
            if(DataBin[i][j]!=-1)
            {
                if(flagArray[i][j]==-1)
                {
                    //chua dc gan co
                    dem++;
                    flagArray[i][j]=dem;
                }

                //xet cac diem lan can
                if(DataBin[i-1][j]!=-1 && flagArray[i-1][j]==-1)
                {
                    flagArray[i-1][j]=flagArray[i][j];
                }

                if(DataBin[i+1][j]!=-1 && flagArray[i+1][j]==-1)
                {
                    flagArray[i+1][j]=flagArray[i][j];
                }

                if(DataBin[i][j-1]!=-1 && flagArray[i][j-1]==-1)
                {
                    flagArray[i][j-1]=flagArray[i][j];
                }

                if(DataBin[i][j+1]!=-1 && flagArray[i][j+1]==-1)
                {
                    flagArray[i][j+1]=flagArray[i][j];
                }

                if(DataBin[i-1][j-1]!=-1 && flagArray[i-1][j-1]==-1)
                {
                    flagArray[i-1][j-1]=flagArray[i][j];
                }

                if(DataBin[i+1][j+1]!=-1 && flagArray[i+1][j+1]==-1)
                {
                    flagArray[i+1][j+1]=flagArray[i][j];
                }
                if(DataBin[i-1][j+1]!=-1 && flagArray[i-1][j+1]==-1)
                {
                    flagArray[i-1][j+1]=flagArray[i][j];
                }

                if(DataBin[i+1][j-1]!=-1 && flagArray[i+1][j-1]==-1)
                {
                    flagArray[i+1][j-1]=flagArray[i][j];
                }
            }
        }
    }
    Group ListGroup[dem];
    for(int i=0;i<dem;i++)
    {
        ListGroup[i].NumberOfMember=0;
    }
    for(int i=1;i<51;i++)
    {
        for(int j=1;j<51;j++)
        {
            if(flagArray[i][j]!=-1)
            {
                int label=flagArray[i][j]-1;
                ListGroup[label].ListPossMember[ListGroup[label].NumberOfMember].x=i;
                ListGroup[label].ListPossMember[ListGroup[label].NumberOfMember].y=j;
                ListGroup[label].NumberOfMember++;
            }
        }
    }

    //printf databin
    cout<<"Print data of array flag ... "<<endl;
    for(int i=0;i<dem;i++)
    {
        cout<<"Group {"<<i<<"} number of member="<<ListGroup[i].NumberOfMember<<endl;
        for(int j=0;j<ListGroup[i].NumberOfMember;j++)
        {
            cout<<"\tMember{"<<j<<"}={"<<ListGroup[i].ListPossMember[j].x<<","<<ListGroup[i].ListPossMember[j].y<<"}"<<endl;
        }
    }

    int k=dem;
    int demOne=0;
    int demMany=0;
    Group ListMany[50];
    Group ListOne[50];
    for(int i=0;i<50;i++)
    {
        ListMany[i].NumberOfMember=0;
        ListOne[i].NumberOfMember=0;
    }

    for(int i=0;i<dem;i++)
    {
        if(ListGroup[i].NumberOfMember==1)
        {
            //them 1 nhom co sl phan tu nho hon 1 vao nhom
            ListOne[demOne].ListPossMember[ListOne[demOne].NumberOfMember].x=ListGroup[i].ListPossMember[0].x;
            ListOne[demOne].ListPossMember[ListOne[demOne].NumberOfMember].y=ListGroup[i].ListPossMember[0].y;
            ListOne[demOne].NumberOfMember++;
            demOne++;
        }
        else
        {
            //them 1 nhom co sl phan tu nho hon 1 vao nhom
            ListMany[demMany].ListPossMember[ListMany[demMany].NumberOfMember].x=ListGroup[i].ListPossMember[0].x;
            ListMany[demMany].ListPossMember[ListMany[demMany].NumberOfMember].y=ListGroup[i].ListPossMember[0].y;
            ListMany[demMany].NumberOfMember++;
            demMany++;
        }
    }



    Group ReMainListOne[demOne];
    int countReMain=0;
    for(int i=0;i<demOne;i++)
    {
        ReMainListOne[i].NumberOfMember=0;
    }

    for(int i=0;i<demOne;i++)//xet cac nhom co 1 thanh vien voi cac nhom co nhieu thanh vien
    {
        bool IsNoise=false;
        for(int j=0;j<demMany;j++)//duyet cac nhom co nhieu thanh vien
        {
            double minDistance=(double)Distance(ListOne[i].ListPossMember[0],ListMany[0].ListPossMember[0]);
            for(int h=1;h<ListMany[j].NumberOfMember;h++)
            {
                double tg=(double)Distance(ListOne[i].ListPossMember[0],ListMany[j].ListPossMember[h]);
                if(tg<minDistance)
                {
                    minDistance=tg;
                }
            }
            if(minDistance<=2)
            {
                IsNoise=true;
            }
            if(!IsNoise)//neu k la nhieu cho vao 1 nhom
            {
                ReMainListOne[countReMain].ListPossMember[ReMainListOne[countReMain].NumberOfMember].x=ListOne[i].ListPossMember[0].x;
                ReMainListOne[countReMain].ListPossMember[ReMainListOne[countReMain].NumberOfMember].y=ListOne[i].ListPossMember[0].y;
                ReMainListOne[countReMain].NumberOfMember++;
                countReMain++;
            }
            else
            {
                k--;
            }
        }
    }
    //xet cac nhom co 1 thanh vien voi nhau
    bool IsUser[countReMain];
    for(int i=0;i<countReMain;i++)
    {
        IsUser[i]=false;
    }

    for(int i=0;i<countReMain;i++)
    {
        if(!IsUser[i])
        {
            for(int j=0;j<countReMain;j++)
            {
                int minDistance=2000;
                int pos=0;
                if(i!=j && !IsUser[j])
                {
                    int tg=(double)Distance(ReMainListOne[i].ListPossMember[0],ReMainListOne[j].ListPossMember[0]);
                    if(tg<minDistance)
                    {
                        minDistance=tg;
                        pos=j;
                    }
                }
                cout<<minDistance<<endl;
                if(minDistance<=2)
                {
                    IsUser[i]=true;
                    IsUser[pos]=true;
                    k--;
                }
                else
                {
                    IsUser[i]=true;
                }
            }
        }
    }

    cout<<"k="<<k<<endl;
    return 0;
}
