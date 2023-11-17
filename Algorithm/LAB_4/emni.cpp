#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int bx[5000000],k=0;
void Display(vector<int> &vec){
 int i;
 int n = vec.size();
 for(i=0;i<n;i++)
    cout<<" "<<vec[i]<<"    ";
 cout<<endl;

}

int Partition(vector<int> &vec,int p,int r){
    int x=vec[r];
    int i,j,t;
    i=p-1;
    k++;
    for(j=p;j<r;j++)
    {
       if(vec[j]<=x)
       {
          i++;
          t=vec[j];
          vec[j]=vec[i];
          vec[i]=t;
       }
    }
    t=vec[i+1];
    vec[i+1]=vec[r];
    vec[r]=t;
    return(i+1);
}


void QuickSort(vector<int> &vec,int p,int r){
    int q;
    if(p<r)
    {
      q=Partition(vec,p,r);
      cout<<"After "<<k<<" partitions :"<<endl;
      cout<<"Pivot : "<<vec[q]<<endl;
      Display(vec);
      QuickSort(vec,p,q-1);
      QuickSort(vec,q+1,r);
    }
}


int main()
{
  srand(time(0));
  /* fstream file;
   ofstream out;
   file.open("search_1.txt");
   for(int i=0;i<10000;i++)
   {
     file<<rand()%100000<<endl;
   }
  */
  vector<string> name{"search_1.txt", "search_2.txt", "search_3.txt", "search_4.txt", "search_5.txt"};
  vector<int> vec;
  vector<int> vec1;
  int x,y;
  /*cout<<"How many data you want to work with :" << endl;
  cout<<"\t\t1. 10000" << endl;
  cout<<"\t\t2. 20000" << endl;
  cout<<"\t\t3. 30000" << endl;
  cout<<"\t\t4. 40000" << endl;
  cout<<"\t\t5. 50000" << endl;
  cout<<"Enter your choice: ";
  int ch;
  cin >> ch;
  string s = name[ch - 1];
  ifstream file(s);
  while (!file.eof())
  {
    file >> x;
    vec1.push_back(x);
  }*/
  int m;
  cout<<"Enter the size of array : ";
  cin>>m;
  for(int i=0;i<m;i++)
   {
     long long int y=rand()%1000;
     vec.push_back(y);
   }
  int n=vec.size();
  cout<<endl;
  cout<<"Actual Array :"<<endl<<endl;
  Display(vec);
  QuickSort(vec,0,n-1);
  cout<<"\nAfter sorting :"<<endl;
  Display(vec);

  return 0;
}
