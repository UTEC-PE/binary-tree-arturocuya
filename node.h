#include <iostream>


template <typename T>
struct Node
{
  T data;
  Node<T>* left;
  Node<T>* right;

  Node(): left(nullptr), right(nullptr) {};
  Node(T newData): data(newData), left(nullptr), right(nullptr) {};

  void killCascade(Node<T>* start)
  {
    if (left) killCascade(left);
    if (right) killCascade(right);

    delete this;

  };
}
