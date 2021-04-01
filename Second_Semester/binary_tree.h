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
        
        void PrintTreeRunner(tree *t, std::string prefix, bool side)
        {
            if ((t->left != NULL) || (t->right != NULL))
            {
                std::cout << prefix;
                
                std::cout << (side ? "├── " : "└── ");

                std::cout << t->data << std::endl;

                PrintTreeRunner(t->left, prefix + (side ? "│   " : "    "), true);
                PrintTreeRunner(t->right, prefix + (side ? "│   " : "    "), false);
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
        void printTree()
        {
            std::cout << "-----------------------------------" << std::endl;
            PrintTreeRunner(TREE, "", false);
            std::cout << "-----------------------------------" << std::endl;
        }
        void add(T x)
        {
            addRunner(x, TREE);
        }
};