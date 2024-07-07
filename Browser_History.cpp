#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  string address;
  Node *next;
  Node *prev;

  Node(string address)
  {
    this->address = address;
    this->next = NULL;
    this->prev = NULL;
  }
};

void insert(Node *&head, Node *&tail, string address)
{
  Node *newNode = new Node(address);

  if (head == NULL)
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

void print_linked_list(Node *head)
{
  Node *tmp = head;

  while (tmp != NULL)
  {
    cout << tmp->address;
    if (tmp->next != NULL)
    {
      cout << " ";
    }
    tmp = tmp->next;
  }
  cout << endl;
}

Node *findNode(Node *head, string address)
{
  Node *current = head;
  while (current)
  {
    if (current->address == address)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void process_commands(Node *&current, Node *head, int Q)
{
  string command;
  for (int i = 0; i < Q; ++i)
  {
    cin >> command;

    if (command == "visit")
    {
      string address;
      cin >> address;
      Node *node = findNode(head, address);
      if (node != NULL)
      {
        current = node;
        cout << current->address << endl;
      }
      else
      {
        cout << "Not Available" << endl;
      }
    }
    else if (command == "next")
    {
      if (current && current->next)
      {
        current = current->next;
        cout << current->address << endl;
      }
      else
      {
        cout << "Not Available" << endl;
      }
    }
    else if (command == "prev")
    {
      if (current && current->prev)
      {
        current = current->prev;
        cout << current->address << endl;
      }
      else
      {
        cout << "Not Available" << endl;
      }
    }
  }
}

int main()
{
  Node *head = NULL;
  Node *tail = NULL;
  string address;
  while (true)
  {
    cin >> address;
    if (address == "end")
      break;
    insert(head, tail, address);
  }

  // print_linked_list(head);

  int Q;
  cin >> Q;
  cin.ignore();
  Node *current = head;

  process_commands(current, head, Q);

  return 0;
}