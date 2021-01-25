#include<iostream>
#include<queue>
using namespace std;
struct Node
{
 int data;
 Node*Left;
 Node*Right;
 Node()
 {
  this->Left = NULL;
  this->Right = NULL;
 }
};

Node* createNode(int x)
{
 Node*P = new Node;
 P->data = x;
 return P;
}
struct Tree
{
 Node*Root;
 Tree()
 {
  cout << "Tree is declared\n";
   this->Root = NULL;
 }
 void add(Node*&R, int x);
 void deleteTree(Node*&Root);
 int countNode(Node*&R);      //dem node
 Node*& search(Node*&R, int x);
};
void Tree::deleteTree(Node*&Root)
{
 if (Root)
 {
  deleteTree(Root->Left);
  deleteTree(Root->Right);
  delete Root;
 }
}
void Tree::add(Node*&R, int x)
{
 if (!R)
 {
  R = new Node;
  R->data = x;
 }
 else
 {
  if (R->data == x)
  {
   return;   //khong tiep tuc them nua
  }
  else
  {
   if (R->data < x)
   {
    add(R->Right, x);
   }
   else
   {
    add(R->Left, x);
   }
  }
 }
}

int Tree::countNode(Node*&R)
{
 if (!R) return 0;
 return (1 + countNode(R->Left) + countNode(R->Right));
}

Node*& Tree::search(Node*&R, int x)
{
 if (!R) return R;  //return ve null
 if (R->data > x)
 {
  return search(R->Left, x);
 }
 else
 {
  if (R->data < x)
  {
   return search(R->Right, x);
  }
  else
  {
   return R;
  }
 }
}
//main function
int main()
{
 Tree T;
 cout << "add node to Tree, enter 0 to finish\n";
 for (int i = 9; i != 0;)
 {
  cin >> i;
  if (i)   
  {
   T.add(T.Root, i);
  }
  cout << "continue adding\n";
 }
 return 0;
}

