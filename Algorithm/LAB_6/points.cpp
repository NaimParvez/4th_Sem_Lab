#include<bits/stdc++.h>
#include<fstream>
#define ll long long
#define fr02m(m) for(int i=0; i<m; i++)
#define fr12m(m) for(int i=1; i<m; i++)
#define fr02j(m) for(int j=0; j<m; j++)
#define frn20(n) for(int i=n; i>=0; i--)
#define frxy(x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define pf push_front
using namespace std;
int main()
{
    ofstream fout;
    fout.open("points.txt");
    srand(time(0));
    int n;
    cout<<"Enter the number of points: ";
    cin>>n;
    fr02m(n)
    {
        fout << rand() % 1000 << " " << rand() % 1000 << endl;
    }
    fout.close();

  
return 0;
}