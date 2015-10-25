//BMF Function matrix factorization
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
#include<conio.h>
using namespace std;

int main()
{
    double R[50][50];
    int N,M;

    ifstream readFile("C:/data.txt");
    readFile>>M>>N;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            {
                readFile>>R[i][j];
                cout<<R[i][j]<<" ";
                if(j==N-1)
                    cout<<endl;
            }
    int k=2;

    double P[M][k];
    double Q[k][N];
    int steps=5000;
    double alpha=0.002;
    double beta=0.02;

    //random values in P
    for(int i=0;i<M;i++)
        for(int j=0;j<k;j++)
            {
                P[i][j]=rand()%2;
            }

    //random values in Q
    for(int i=0;i<k;i++)
        for(int j=0;j<N;j++)
            {
                Q[i][j]=rand()%2;
            }
    //Main function BMF
    for(int s=0;s<steps;s++)
    {
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                if(R[i][j]>0)
                {
                    double sum=0;
                    for(int h=0;h<k;h++)
                        sum+=P[i][h]*Q[h][j];

                    double eij=R[i][j]-sum;
                    for(int h=0;h<k;h++)
                    {
                        P[i][h]+=alpha*(2*eij*Q[h][j]-beta*P[i][h]);
                        Q[h][j]+=alpha*(2*eij*P[i][h]-beta*Q[h][j]);
                    }
                }
            }
            //caculator error to break function
            double e=0;
            for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                if(R[i][j]>0)
                    {
                        double sum=0;
                        for(int h=0;h<k;h++)
                            sum+=P[i][h]*Q[h][j];
                        sum=R[i][j]-sum;
                        //e+=pow(sum,2);
                        for(int h=0;h<k;h++)
                            e+=(beta/2)*(pow(P[i][h],2)+pow(Q[h][j],2));
                        e=sqrt(e);
                    }
            }
            if(e<0.0001)
            {
                break;
            }
    }


    //Xuat ket qua P ra man hinh
    cout<<"----------------P----------------"<<endl;
    for(int i=0;i<M;i++)
        for(int j=0;j<k;j++)
        {
            cout<<(int)P[i][j]<<"\t";
            if(j==k-1)
                cout<<endl;
        }
    //Xuat ket qua Q ra man hinh
    cout<<"---------------Q------------------"<<endl;
    for(int i=0;i<k;i++)
        for(int j=0;j<N;j++)
        {
            cout<<(int)Q[i][j]<<"\t";
            if(j==N-1)
                cout<<endl;
        }
    return 0;
}
