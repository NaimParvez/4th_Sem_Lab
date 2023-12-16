#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
#include<cmath>
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
    int i,j,k,n;
    cout<<"\nEnter the no. of data: \n";       
    cin>>n;
    vector<double>x(n);
    vector<double>y(n);
    double a,b,c;

    cout<<"\nEnter the x-axis values: \n";                
    for (i=0;i<n;i++){
        cin>>x[i];    
    }
    cout<<"\nEnter the y-axis values: \n";
    for (i=0;i<n;i++){
        cin>>y[i];
    }
    double sum_x=0,sum_x2=0,sum_y=0,xysum=0;                
    for (i=0;i<n;i++)
    {
        sum_x=sum_x+x[i];                        
        sum_y=sum_y+y[i];                        
        sum_x2=sum_x2+pow(x[i],2);              
        xysum=xysum+x[i]*y[i];   
    }                 
    a=(n*xysum-sum_x*sum_y)/(n*sum_x2-sum_x*sum_x);           
    c= (sum_y/n) - (a*(sum_x/n));
    cout<<"\nThe linear fit line is of the form:\n\n"<<a<<" + x("<<c<<")"<<endl;        
    return 0;
} 