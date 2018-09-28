// #include "node.h"
#include <stack>

template <typename T>
struct Iterator
{
  Node<T>* current;
  Node<T>* stackBottom;
  stack<Node<T>*> myStack;
  bool checkedLeft;

  Iterator (): current(nullptr), checkedLeft(false) {};
  Iterator (Node<T>* startingNode): current(startingNode), checkedLeft(false) {
    myStack.push(startingNode);
    stackBottom = startingNode;
  };

  Iterator<T> operator=(Iterator<T> node)
  {
    current = node.current;
    return *this;
  };

  T operator*()
  {
    return current->data;
  };

  Iterator<T> step()
  {



    Node<T>* tmp = current;

    if (current == stackBottom)
    {
      if (!checkedLeft)
      {

        while (tmp->left)
        {
          tmp = tmp->left;
          myStack.push(tmp);

        }

        current = myStack.top();

      }
      else
      {


        myStack.pop();

        myStack.push(current->right);


        current = myStack.top();
        stackBottom = current;
        checkedLeft = false;

        tmp = current;
        while(tmp->left)
        {
          tmp = tmp->left;
          myStack.push(tmp);

        }
        current = myStack.top();





        return *this;
      }

    }
    else
    {


      myStack.pop();
      while (tmp->right)
      {
        tmp = tmp->right;
        myStack.push(tmp);

      }
      while (tmp->left)
      {
        tmp = tmp->left;
        myStack.push(tmp);

      }

      current = myStack.top();

      //if curr = back then checkLeft = true


      if (current == stackBottom) checkedLeft = true;
    }

    return *this;
  }
};
