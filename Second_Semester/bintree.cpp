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
    tree.printTree('-', columns, true);
}