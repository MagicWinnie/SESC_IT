// Simple binary tree
#include <iostream>
#include <string>
#include <Windows.h>
#include "binary_tree.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    BinaryTree<string> tree;
    tree.add("23");
    tree.add("22");
    tree.add("32");
    tree.add("21");
    tree.add("08");
    tree.add("17");
    tree.printPrefix();
    // tree.add("4");
    // tree.add("*");
    // tree.add("7");
    // tree.add("1");
    // tree.add("6");
    // tree.add("-");
    // tree.add("5");
    // tree.add(12);
    // tree.add(87);
    // tree.add(5);
    // tree.add(2);
    // tree.add(32);
    tree.printTree('-', columns, true);
    tree.printPrefix();
    tree.printInfix();
    tree.printPostfix();
}