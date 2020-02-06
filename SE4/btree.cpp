#include <iostream>
#include <conio.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

class Tree
{
    void printNode(TreeNode *n, int space)
    {
        if (n != NULL)
        {
            printNode(n->right, space + 5);

            cout << "\n";
            for (int i = 0; i < space; i++)
            {
                cout << " ";
            }
            cout << n->data;

            printNode(n->left, space + 5);
        }
    }
    bool search_pro(int data, TreeNode *n)
    {
        if (n != NULL)
        {
            if (n->data == data)
            {
                return true;
            }
            else
            {
                return search_pro(data, n->left) ||
                       search_pro(data, n->right);
            }
        }
        return false;
    }
    void leafs_pro(TreeNode *n)
    {
        if (n != NULL)
        {
            if (n->left == NULL && n->right == NULL)
            {
                cout << n->data << " ";
            }
            else
            {
                leafs_pro(n->left);
                leafs_pro(n->right);
            }
        }
    }
    int depth_pro(TreeNode *n, int d = 0)
    {
        if (n != NULL)
        {
            int d1 = depth_pro(n->left, d + 1);
            int d2 = depth_pro(n->right, d + 1);

            return max(d1, d2);
        }
        else
        {
            return d - 1;
        }
    }
    void printSorted_pro(TreeNode *n)
    {
        if (n != NULL)
        {
            printSorted_pro(n->left);
            cout << (n->data) << " ";
            printSorted_pro(n->right);
        }
    }
    void printPreOrder_pro(TreeNode *n)
    {
        if (n != NULL)
        {
            cout << (n->data) << " ";
            printPreOrder_pro(n->left);
            printPreOrder_pro(n->right);
        }
    }
    void printInOrder_pro(TreeNode *n)
    {
        if (n != NULL)
        {
            printInOrder_pro(n->left);
            cout << (n->data) << " ";
            printInOrder_pro(n->right);
        }
    }
    void printPostOrder_pro(TreeNode *n)
    {
        if (n != NULL)
        {
            printPostOrder_pro(n->left);
            printPostOrder_pro(n->right);
            cout << (n->data) << " ";
        }
    }
    TreeNode *root, *ptr;

public:
    Tree()
    {
        root = new TreeNode();
        ptr = new TreeNode();
        root = NULL;
    }
    void addL(int d)
    {
        TreeNode *t = new TreeNode;
        t->data = d;
        t->left = NULL;
        t->right = NULL;

        ptr->left = t;
        ptr = t;
    }
    void addR(int d)
    {
        TreeNode *t = new TreeNode;
        t->data = d;
        t->left = NULL;
        t->right = NULL;

        ptr->right = t;
        ptr = t;
    }
    void add(int d)
    {
        TreeNode *t = new TreeNode;
        t->data = d;
        t->left = NULL;
        t->right = NULL;

        if (root == NULL)
        {
            root = t;
            ptr = t;
        }
        else
        {
            TreeNode *p = new TreeNode;
            TreeNode *parent = new TreeNode;
            p = root;
            while (p != NULL)
            {
                if (d < p->data)
                {
                    parent = p;
                    p = p->left;
                }
                else if (d > p->data)
                {
                    parent = p;
                    p = p->right;
                }
            }
            if (d < parent->data)
            {
                parent->left = t;
                ptr = t;
            }
            else if (d > parent->data)
            {
                parent->right = t;
                ptr = t;
            }
        }
    }

    void display()
    {
        printNode(root, 0);
    }

    bool search(int data)
    {
        return search_pro(data, root);
    }

    void leafs()
    {
        leafs_pro(root);
    }

    int depth()
    {
        return depth_pro(root);
    }

    void printSorted()
    {
        printSorted_pro(root);
    }
    void printPreOrder()
    {
        printPreOrder_pro(root);
    }
    void printInOrder()
    {
        printInOrder_pro(root);
    }
    void printPostOrder()
    {
        printPostOrder_pro(root);
    }
};

int main()
{
    Tree t;
    int ch, data;

    while (0 < 1)
    {
        int ch;
        cout << "\nEnter a Choice:\n1.Add Node\n2.Add Left Node\n3.Add Right Node\n4.Display Tree\n5.Search Tree\n6.Display Leafs\n7.Display Sorted\n8.Display Depth\n9.PreOrder\n10.InOrder\n11.PostOrder\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Data(root): ";
            cin >> data;
            t.add(data);
            break;
        case 2:
            cout << "Enter Data(left): ";
            cin >> data;
            t.addL(data);
            break;
        case 3:
            cout << "Enter Data(right): ";
            cin >> data;
            t.addR(data);
            break;
        case 4:
            t.display();
            break;
        case 5:
            cout << "Enter Data to Search: ";
            cin >> data;
            cout << t.search(data);
            break;
        case 6:
            cout << "Leafs: ";
            t.leafs();
            break;
        case 7:
            cout << "Sorted: ";
            t.printSorted();
            break;
        case 8:
            cout << "Depth: " << t.depth();
            break;
        case 9:
            t.printPreOrder();
            break;
        case 10:
            t.printInOrder();
            break;
        case 11:
            t.printPostOrder();
            break;

        default:
            exit(0);
        }
    }

    getch();
    return 0;
}