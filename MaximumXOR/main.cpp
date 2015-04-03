#include <QCoreApplication>
#include <iostream>

using namespace std;

int MaxXOR(int L, int R)
{
    int max=-1;
    for(int i=L;i<=R;i++)
    {
        for(int j=i;j<=R;j++)
        {
            int xxor=0;
            xxor=i ^ j;
            if(xxor>max)
            {
                max=xxor;
            }
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<MaxXOR(10,15)<<endl;

    return 0;
}
