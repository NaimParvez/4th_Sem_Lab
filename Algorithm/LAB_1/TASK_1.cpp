#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define fr(m) for (int i = 0; i < m; i++)
#define fro(m) for (int i = 1; i < m; i++)
#define frj(m) for (int j = 0; j < m; j++)
#define frr(n) for (int i = n; i >= 0; i--)
#define frxy(x, y) for (int i = x; i <= y; i++)
#define pb push_back
#define pf push_front
using namespace std;

void linear(int find, vector<int> &vec)
{
  int com = 0;
  int index = 1;
  for (auto i : vec)
  {
    com++;
    if (i == find)
    {
      cout << "Linear search:  took " << com + 1 << " steps ,found at index " << com << endl;
      index = 0;
      break;
    }
  }
  if (index)
  {
    cout << "NOT FOUND" << endl;
  }
}
void binary(int find, vector<int> &vec)
{
  int flag = 1;
  sort(vec.begin(), vec.end());
  int size = vec.size();
  int low = 0, high = size - 1;
  int mid;
  int com = 0;
  while (low <= high)
  {
    mid = (low + high) / 2;
    com++;
    if (vec[mid] == find)
    {
      cout << "Binary search:  took " << com << " steps ,found at index " << mid;
      flag = 0;
      break;
    }
    else if (vec[mid] > find)
    {
      high = mid - 1;
    }
    else if (vec[mid] < find)
    {
      low = mid + 1;
    }
  }
  if (flag)
  {
    cout << "NOT FOUND" << endl;
  }
}
int main()
{
  // srand(time(0));
  // fstream file;
  // //ofstream out;
  // file.open("search_1.txt");
  // for(int i=0;i<10000;i++)
  // {
  //   file<<rand()%100000<<endl;
  // }

  vector<string> name{"search_1.txt", "search_2.txt", "search_3.txt", "search_4.txt", "search_5.txt"};
  vector<int> vec;
  int x;
  cout << "How many data you want to work with :" << endl;
  cout << "\t\t1. 10000" << endl;
  cout << "\t\t2. 20000" << endl;
  cout << "\t\t3. 30000" << endl;
  cout << "\t\t4. 40000" << endl;
  cout << "\t\t5. 50000" << endl;
  cout << "Enter your choice: ";
  int choice;
  cin >> choice;
  string s = name[choice - 1];
  ifstream in(s);
  while (!in.eof())
  {
    in >> x;
    vec.push_back(x);
  }
  // for(auto i: vec){
  //   cout<<i<<endl;
  // }
  int find;
  cout << "enter the number you are looking for: ";
  cin >> find;
  linear(find, vec);
  binary(find, vec);

  return 0;
}
