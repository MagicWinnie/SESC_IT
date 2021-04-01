// Simple binary tree
#include <iostream>
#include <string>
#include <Windows.h>
#include "binary_tree.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    BinaryTree<string> tree;
    tree.add("23");
    tree.add("22");
    tree.add("32");
    tree.printTree();
}