#include <iostream>
using namespace std;

template<typename T>
class BinaryTree
{
private:
  Node<T>* root;
  Node<T>* current;
public:
  List(): root(nullptr) current(nullptr) {};

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

  ~List() {
    clear();
    delete this;
  }

}
