#include <iostream>
#include "binarytree.h"
#include "iterator.h"
using namespace std;

int main(int argc, char const *argv[]) {
  BinaryTree<int>* bt = new BinaryTree<int>();
  // int myArr[8] = {4,8,1,13,7,9,0,5};
  int myArr[10] = {149, 98, 43, 167, 96, 175, 74, 65, 158, 11}; // 128, 192, 173, 129, 191, 136, 187, 198, 190, 137};
  bt->add(myArr, 10);

  bt->printTree();
  bt->printInOrder(bt->begin());
  cout << endl<<endl;

  Iterator<int>* it = new Iterator<int>(bt->begin()); // Así no se debe implementar el iterator

  for (int i = 0; i < 10; i++) {
    it->step();
    cout << **it << " ";

  }

  return 0;
}
