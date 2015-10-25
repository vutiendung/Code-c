#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int k = 3;

    int a[k];
    a[0] =1;
    for(int i = 1; i < k; i ++)
    {
        a[i] = a[i-1] +1;
    }

    while(a[0] < n -1)
    {
        for(int i = k-1; i > 0; i--)
        {
            if(a[i] != n-k +i)
            {
                a[i-1] += 1;
                a[i] = a[i-1];
                if(i != k-1)
                {
                    a[i] += 1;
                }
            }
        }

        for(int i = 0; i < k; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        a[k-1] += 1;
    }
}
