#include <iostream>
#include <vector>
#include <QCoreApplication>

using namespace std;


void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here

    vector<char> newgrid;

    for(int i=0;i<n;i++)
    {
        vector<char> v(grid[i].begin(), grid[i].end());
        newgrid.insert(newgrid.end(),v.begin(),v.end());
    }


    int mPos,pPos=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(newgrid[i*n+j]=='p')
            {
                pPos=i*n+j;
            }
            if(newgrid[i*n+j]=='m')
            {
                mPos=i*n+j;
            }
            //cout<<grid[i*n+j];
        }
        //cout<<endl;
    }

    if(pPos==0)
    {
        int left=mPos%n;
        for(int i = 0; i < left; i++)
        {
            cout << "LEFT" << endl;
        }

        int up=mPos/n;
        for(int i=0;i<up;i++)
        {
            cout<<"UP"<<endl;
        }
    }
    else if (pPos==n-1)
    {
        int right=((mPos/n)+1)*n-mPos-1;
        for(int i= 0;i<right;i++)
        {
            cout<<"RIGHT"<<endl;
        }


        int up=mPos/n;
        for(int i=0;i<up;i++)
        {
            cout<<"UP"<<endl;
        }
    }
    else if (pPos==n*n-n)
    {
        int left=mPos%n;
        for(int i = 0; i < left; i++)
        {
            cout << "LEFT" << endl;
        }

        int down=n-(mPos/n)-1;
        for(int i=0;i<down;i++)
        {
            cout<<"DOWN"<<endl;
        }
    }
    else if (pPos==n*n-1)
    {
        int right=((mPos/n)+1)*n-mPos-1;
        for(int i= 0;i<right;i++)
        {
            cout<<"RIGHT"<<endl;
        }

        int down=n-(mPos/n)-1;
        for(int i=0;i<down;i++)
        {
            cout<<"DOWN"<<endl;
        }
    }

}


int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);



    int m=3;
    vector <string> grid;

    grid.push_back("---");
    grid.push_back("-m-");
    grid.push_back("p--");


    displayPathtoPrincess(m,grid);

    return 1;
}
