#include <iostream>
#include <process.h>
using namespace std;

void A()
{
    while(true)
    {
        cout << "A" << endl;
    }
}
void B()
{
    while(true)
    {
        cout << "B" << endl;
    }
}
int main()
{
    process a(A);
    process b(B);

    a.join();
    b.join();

    return 0;
}
