#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    // srand(time(0));
     fstream f;
    // ofstream out("number.txt");
    // for(int i=0;i<1000;i++)
    // {
    //     out<<rand()<<endl;
    // }
    // out.close();
    ifstream in("number.txt");
    int x;
    while(!in.eof())
    {
        in>>x;
        cout<<x<<endl;
    }
     in.close();
     

}