#pragma once
#include <iostream>
#include <string>

template <class T>
class BinaryTree
{
    private:
        typedef struct node
        {
            T data;
            struct node *left;
            struct node *right;
        } tree;
        tree *TREE;
        
        void PrintTreeRunner(tree *t, std::string prefix, bool side, bool UTF)
        {
            if ((t->left != NULL) || (t->right != NULL))
            {
                std::cout << prefix;
                
                if (UTF)
                    std::cout << (side ? "├── " : "└── ");
                else
                    std::cout << (side ? "|--- " : "|___ ");

                std::cout << t->data << std::endl;

                if (UTF)
                {
                    PrintTreeRunner(t->left, prefix + (side ? "│   " : "     "), true, UTF);
                    PrintTreeRunner(t->right, prefix + (side ? "│   " : "     "), false, UTF);
                } else {
                    PrintTreeRunner(t->left, prefix + (side ? "|   " : "     "), true, UTF);
                    PrintTreeRunner(t->right, prefix + (side ? "|   " : "     "), false, UTF);
                }
            }
        }
        void destroyTree(tree *t)
        {
            if (t != NULL)
            {
                destroyTree(t->left);
                destroyTree(t->right);
                delete t;
            }
        }
        void addRunner(T x, tree *t)
        {
            if ((t->left == NULL) && (t->right == NULL))
            {
                t->data = x;
                t->left = new tree;
                t->right = new tree;
                t->left->left = NULL;
                t->left->right = NULL;
            } else if (x < t->data)
            {   
                if (t->left != NULL)
                {
                    addRunner(x, t->left);
                } else {
                    t->left = new tree;
                    t->data = x;
                    t->left->left = NULL;
                    t->left->right = NULL;    
                }
            } else {
                if (t->right != NULL)
                {
                    addRunner(x, t->right);
                } else {
                    t->right = new tree;
                    t->data = x;
                    t->right->left = NULL;
                    t->right->right = NULL;
                }
            }
        }
        void printInfixRunner(tree *t)
        {
            if ((t->left != NULL) || (t->right != NULL))
            {
                printInfixRunner(t->left);
                std::cout << t->data << " ";
                printInfixRunner(t->right);
            }
        }
        void printPrefixRunner(tree *t)
        {
            if ((t->left != NULL) || (t->right != NULL))
            {
                std::cout << t->data << " ";
                printInfixRunner(t->left);
                printInfixRunner(t->right);
            }
        }
        void printPostfixRunner(tree *t)
        {
            if ((t->left != NULL) || (t->right != NULL))
            {
                printInfixRunner(t->left);
                printInfixRunner(t->right);
                std::cout << t->data << " ";
            }
        }
    public:
        BinaryTree()
        {
            TREE = new tree;
            TREE->left = NULL;
            TREE->right = NULL;
        }
        ~BinaryTree()
        {
            destroyTree(TREE);
        }
        void printTree(char delimeter = '-', size_t delimeterSize = 36, bool UTF = true)
        {
            std::cout << std::string(delimeterSize, delimeter) << std::endl;
            PrintTreeRunner(TREE, "", false, UTF);
            std::cout << std::string(delimeterSize, delimeter) << std::endl;
        }
        void add(T x)
        {
            addRunner(x, TREE);
        }
        void printPrefix(char delimeter = '-', size_t delimeterSize = 36)
        {
            std::cout << std::string(delimeterSize, delimeter) << std::endl;
            printPrefixRunner(TREE);
            std::cout << std::endl << std::string(delimeterSize, delimeter) << std::endl;
        }
        void printInfix(char delimeter = '-', size_t delimeterSize = 36)
        {
            std::cout << std::string(delimeterSize, delimeter) << std::endl;
            printInfixRunner(TREE);
            std::cout << std::endl << std::string(delimeterSize, delimeter) << std::endl;
        }
        void printPostfix(char delimeter = '-', size_t delimeterSize = 36)
        {
            std::cout << std::string(delimeterSize, delimeter) << std::endl;
            printPostfixRunner(TREE);
            std::cout << std::endl << std::string(delimeterSize, delimeter) << std::endl;
        }
};