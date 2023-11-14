#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    /*BinaryTree<int> vazia;
    BinaryTree<int> t4(4, vazia, vazia);
    BinaryTree<int> t5(5, vazia, vazia);
    BinaryTree<int> t3(3, t4, vazia);
    BinaryTree<int> t7(7, t3, t5);*/

    BinaryTree<int> t7("8 3 1 # # 6 4 # # 7 # # 10 # 14 13 # # #");

    t7.preOrder();
    cout << endl;

    cout << t7.contains(9) << endl;
    cout << "size = " << t7.size() << endl;
    cout << t7.serial() << endl;
}