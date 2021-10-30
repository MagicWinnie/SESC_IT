#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

template <class T>
class BinaryTree
{
private:
    typedef struct node
    {
        T data;
        struct node *left;
        struct node *right;
        long long num;
    } tree;
    tree *TREE;

    void destroyTree(tree *t)
    {
        if (t)
        {
            destroyTree(t->left);
            destroyTree(t->right);
            delete[] t;
        }
    }
    long long calc_eval(char oper, int a, int b)
    {
        switch (oper)
        {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            if (b == 0)
                throw  std::invalid_argument("division by zero");
            return a / b;
            break;
        default:
            throw;
        }
    }
    long long calcRunner(tree *t)
    {
        if (t->data == '+' || t->data == '-' || t->data == '*' || t->data == '/')
            return calc_eval(t->data, calcRunner(t->left), calcRunner(t->right));
        else
            return t->num;
    }
public:
    BinaryTree(std::string s)
    {
        std::stack<tree *> stck;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            tree *temp = new tree;
            if (s[i] >= '0' && s[i] <= '9')
            {    
                temp->num = s[i] - '0';
                temp->left = nullptr;
                temp->right = nullptr;

                stck.push(temp);
            }
            else
            {
                temp->data = s[i];
                
                temp->left = stck.top();
                stck.pop();

                temp->right = stck.top();
                stck.pop();
                
                TREE = temp;
                stck.push(TREE);
            }
        }
        TREE = stck.top();
    }
    ~BinaryTree()
    {
        destroyTree(TREE); 
    }
    long long calc()
    {
        return calcRunner(TREE);
    }
};

using namespace std;

int main()
{
    string temp;
    cin >> temp;

    BinaryTree<char> tree(temp);
    try 
    {
        cout << tree.calc() << endl;
    } catch (const invalid_argument& e)
    {
        cout << "NO" << endl;
    }
}