#include <iostream>
#include <graphics.h>

using namespace std;

struct NuocDi
{
    int n;//so nuoc co the di
    int x,y;// toa do
};

int x,y; //toa do ban dau cua quan ma
int _size; //kich thuoc ban co
bool run = true;
int Road[2501][2501]; //duong di intcua quan ma
int Current_Possition[2][2501]; //vi tri hien tai quan am
int Total_Possition[2][2501];
int Dx[8]; // do doi x
int Dy[8]; //do doi y
NuocDi temp[8];

//ham di tuan chinh
bool DiTuan()
{

}

// ham tinh so nuoc di
int TinhSoNuocDi(int _x, int _y)
{
    int i,j,n = 0;
    for(int k = 0; k < 8; k ++)
    {
        i = _x + Dx[k];
        j = _y + Dy[k];

        //o co the di la o nam trong ban co va chua di qua
        if(i > 1 && i < _size)
        {
            if(j >= 1 && j < _size)
            {
                n++;
            }
        }
    }
    return n;
}

void TimDuong(int _x, int _y, int step)
{
    //neu di het ban co
    if(step == _size * _size)
    {
        run = false;
        for(int i = 0; i < _size * _size ; i ++)
        {
            Current_Possition[0][i] = Total_Possition[0][i];
            Current_Possition[1][i] = Total_Possition[1][i];
        }
    }
    else
    {
        if(run)
        {
            int i,j,soNuocDi = 0;
            NuocDi luaChon[8];

            //tim nuoc di ke tiep
            for(int k = 0; k < 8; k ++)
            {
                i = _x + Dx[k];
                j = _y + Dy[k];

                //o co the di la o nam trong ban co va chua di qua
                if(i > 1 && i < _size)
                {
                    if(j >= 1 && j < _size)
                    {
                        luaChon[soNuocDi++].n = TinhSoNuocDi(i,j);
                        luaChon[soNuocDi++].x = i;
                        luaChon[soNuocDi++].y = j;
                        soNuocDi ++;
                    }
                }

                //
                if(soNuocDi > 0)
                {
                    //Sap xep cac nuoc di tang dan theo so o co the di tiep
                    for(i = 0; i <soNuocDi -1; i++)
                    {
                        for(j = i+1; j < soNuocDi; j ++)
                        {
                            if(luaChon[i].n > luaChon[j].n)
                            {
                                NuocDi tg = luaChon[i];
                                luaChon[i] = luaChon[j];
                                luaChon[j] = tg;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{



    //khoi tao gia tri ban dau
    cout << "Nhap kich thuoc ban co: ";
    cin >> _size;

    for(int i = 0 ; i < _size * _size; i++)
    {
        Current_Possition[0][i] = 0;
        Current_Possition[1][i] = 0;

        Total_Possition[0][i] = 0;
        Total_Possition[1][i] = 0;
    }

    //khoi tao  duong di cua quan ma
    for(int i = 0; i < _size; i ++)
    {
        for(int j = 0; j < _size; j ++)
        {
            Road[i][j] = 0;
        }
    }

    //mot quan ma co the di 8 nuc tiep theo
    Dx[0] = -2; Dx[1] = -2; Dx[2] = -1; Dx[3] = -1; Dx[4] = 1; Dx[5] = 1;   Dx[6] = 2; Dx[7] = 2;
    Dy[0] = 1;  Dy[1] = -1; Dy[2] = 2;  Dy[3] = -2; Dy[4] = 2; Dy[5] = -2;  Dy[6] = 1; Dy[7] = -1;

    return 0;
}
