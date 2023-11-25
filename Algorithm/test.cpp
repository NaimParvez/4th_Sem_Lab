
#include<iostream>
#include<fstream>
using namespace std;


void Display(int *ax,int n){
 int i;
 for(i=0;i<n;i++)
    cout<<" "<<ax[i];
 cout<<endl;

}
int Partition(int *ax,int p,int r){
  int x=ax[r];
  int i,j,t;
  i=p-1;
  for(j=p;j<r;j++){
    if(ax[j]<=x){
       i++;
       //cout<<"swap("<<ax[i]<<","<<ax[j]<<")"<<endl;
        t=ax[j];
        ax[j]=ax[i];
        ax[i]=t;
    }

  }
        t=ax[i+1];
        ax[i+1]=ax[r];
        ax[r]=t;
        return(i+1);
}

void QS(int *ax,int p,int r){
    int q;
    cout<<"QS("<<p<<","<<r<<") is called"<<endl;
    if(p<r){
      q=Partition(ax,p,r);
      cout<<"Partition return q="<<q<<endl;
      //cout<<"Calling left"<<endl;

      QS(ax,p,q-1);
      //Display(ax,7);
     // cout<<"Calling Right"<<endl;

      QS(ax,q+1,r);
    //Display(ax,7);
    }

}


int main(){
   int ax[7]={5,7,6,1,3,2,4};
   int n=7;

   cout<<"Initial unsorted array:"<<endl;
   Display(ax,n);
   QS(ax,0,n-1);
   Display(ax,n);

}