#include <bits/stdc++.h>
using namespace std;
int main()
{
  list<int> linkedList;
  int value;

  while (true)
  {
    cin >> value;
    if (value == -1)
    {
      break;
    }
    linkedList.push_back(value);
  }

  linkedList.sort();
  linkedList.unique();

  for (int val : linkedList)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}