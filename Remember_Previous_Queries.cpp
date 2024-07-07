#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *prev;

  Node(int val)
  {
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

void print_normal(Node *head)
{
  Node *tmp = head;
  if (head != NULL)
  {
    cout << "L -> ";
    while (tmp != NULL)
    {
      cout << tmp->val << " ";
      tmp = tmp->next;
    }
    cout << endl;
  }
  else
  {
    cout << "L -> " << endl;
  }
}

void print_reverse(Node *tail)
{
  Node *tmp = tail;
  if (tail != NULL)
  {
    cout << "R -> ";
    while (tmp != NULL)
    {
      cout << tmp->val << " ";
      tmp = tmp->prev;
    }
    cout << endl;
  }
  else
  {
    cout << "R -> " << endl;
  }
}

int size(Node *head)
{
  Node *tmp = head;
  int cnt = 0;
  while (tmp != NULL)
  {
    cnt++;
    tmp = tmp->next;
  }
  return cnt;
}

void insert_head(Node *&head, Node *&tail, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void insert_tail(Node *&head, Node *&tail, int val)
{
  Node *newNode = new Node(val);
  if (tail == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

void delete_at_position(Node *&head, Node *&tail, int pos)
{
  if (head == NULL || pos < 0)
  {
    // cout << "Invalid" << endl;
    return;
  }

  Node *tmp = head;
  for (int i = 0; i < pos; ++i)
  {
    if (tmp == NULL)
    {
      // cout << "Invalid" << endl;
      return;
    }
    tmp = tmp->next;
  }

  if (tmp == NULL)
  {
    // cout << "Invalid" << endl;
    return;
  }

  if (tmp->prev != NULL)
  {
    tmp->prev->next = tmp->next;
  }
  else
  {
    head = tmp->next;
  }

  if (tmp->next != NULL)
  {
    tmp->next->prev = tmp->prev;
  }
  else
  {
    tail = tmp->prev;
  }

  delete tmp;
}

int main()
{
  int Q;
  cin >> Q;

  Node *head = NULL;
  Node *tail = NULL;

  for (int i = 0; i < Q; ++i)
  {
    int X, V;
    cin >> X >> V;

    if (X == 0)
    {
      insert_head(head, tail, V);
    }
    else if (X == 1)
    {
      insert_tail(head, tail, V);
    }
    else if (X == 2)
    {
      delete_at_position(head, tail, V);
    }

    print_normal(head);
    print_reverse(tail);
  }

  return 0;
}