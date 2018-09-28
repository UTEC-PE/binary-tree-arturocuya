#include <iostream>
#include "node.h"
using namespace std;

template<typename T>
class BinaryTree
{
private:
  Node<T>* root;
  Node<T>* current;
public:
  BinaryTree(): root(nullptr), current(nullptr) {};

  // Todo lo del print es copiado de internet, para fines estéticos :p
  #define COUNT 5
  void print2DUtil(Node<T> *root, int space){
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout<< "\n";
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data <<endl;

    print2DUtil(root->left, space);
  }

  void print2D(Node<T>* root){
     print2DUtil(root, 0);
  }

  void printTree(){
    print2D(root);
  }

  Node<T>* begin()
  {
    if (root)
    {
      return root;
    } else throw runtime_error("Empty tree");

  }

  void printInOrder(Node<T>* start)
  {
    if (start)
    {
      if (start->left) printInOrder(start->left);
      cout << start->data << " ";
      if (start->right) printInOrder(start->right);
    } else throw runtime_error("Start doesn't exist");

  }

  void printPreOrder(Node<T>* start)
  {
    if (start)
    {
      cout << start->data << " ";
      if (start->left) printInOrder(start->left);
      if (start->right) printInOrder(start->right);
    } else throw runtime_error("Start doesn't exist");
  }

  void printPostOrder(Node<T>* start)
  {
    if (start)
    {
      if (start->left) printInOrder(start->left);
      if (start->right) printInOrder(start->right);
      cout << start->data << " ";
    } else throw runtime_error("Start doesn't exist");

  }

  void add(T* data, int size)
  {
    for (int i = 0; i < size; i++) {
      add(data[i]);
    }
  }

  void add(T data)
  {
    Node<T>* newNode = new Node<T>(data);
    if (root)
    {
      if (data < current->data)
      {
        if (current->left)
        {
          current = current->left;
          add(data);
        }
        else
        {
          current->left = newNode;
          current = root;
        }
      }
      else if (data > current->data)
      {
        if (current->right)
        {
          current = current->right;
          add(data);
        }
        else
        {
          current->right = newNode;
          current = root;
        }
      }
      else throw runtime_error("Input already exists.");
    }
    else current = root = newNode;
  }

  void clear()
  {
    if (root) root->killCascade(root);
  }

  ~BinaryTree() {
    clear();
    delete this;
  }

};
