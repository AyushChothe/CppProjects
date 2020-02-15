#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

struct TreeRel
{
    TreeNode *child, *parent;
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
    TreeRel *search_pro(int data, TreeNode *n, TreeNode *p = nullptr)
    {

        if (n != NULL)
        {
            if (n->data == data)
            {
                TreeRel *rel = new TreeRel;
                rel->child = n;
                rel->parent = p;
                return rel;
            }
            else
            {
                if (search_pro(data, n->left, n) != nullptr)
                {
                    return search_pro(data, n->left, n);
                }
                else if (search_pro(data, n->right, n) != nullptr)
                {
                    return search_pro(data, n->right, n);
                };
            }
        }
        return nullptr;
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
    void printInOrderVector_pro(TreeNode *n, vector<TreeNode *> *v)
    {
        if (n != NULL)
        {
            printInOrderVector_pro(n->left, v);
            v->push_back(n);
            printInOrderVector_pro(n->right, v);
        }
    }
    void printMirror_pro(TreeNode *n, int space = 0)
    {
        if (n != NULL)
        {
            printMirror_pro(n->left, space + 5);

            cout << "\n";
            for (int i = 0; i < space; i++)
            {
                cout << " ";
            }
            cout << n->data;
            printMirror_pro(n->right, space + 5);
        }
    }
    void printLevel_pro(TreeNode *n, int l, int ol)
    {
        if (n != NULL)
        {
            if (l == ol)
            {
                cout << n->data;
            }
            else
            {
                printLevel_pro(n->left, l + 1, ol);
                printLevel_pro(n->right, l + 1, ol);
            }
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
    TreeNode *getRoot()
    {
        return root;
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

    TreeRel *search(int data)
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
    void displayLevelWise()
    {
        for (int i = 0; i <= depth(); i++)
        {
            printLevel_pro(root, 0, i);
            cout << "|";
        }
    }
    void displayMirror()
    {
        printMirror_pro(root);
    }

    void deleteNode(int data)
    {
        TreeRel *r = search(data);
        TreeNode *s = r->child;

        if (s != NULL)
        {
            if (s->right == NULL && s->left == NULL)
            {
                (r->parent->left == s) ? (r->parent->left = nullptr) : (r->parent->right = nullptr);
            }
            else if (s->right != NULL || s->left != NULL)
            {
                if (s->right != NULL && s->left != NULL)
                {
                    //Infix
                    vector<TreeNode *> v;
                    printInOrderVector_pro(root, &v);

                    for (int i = 0; i < v.size(); i++)
                    {
                        if (s->data == v.at(i)->data)
                        {
                            int d = s->data;
                            s->data = v.at(i + 1)->data;
                            v.at(i + 1)->data = d;
                            deleteNode(d);
                        }
                    }
                }
                else if (s->right != NULL)
                {
                    r->parent->right = s->right;
                }
                else if (s->left != NULL)
                {
                    r->parent->left = s->left;
                }
            }
        }
    }
};

int main()
{
    Tree t;
    TreeNode *s = new TreeNode;
    int ch, data;

    while (0 < 1)
    {
        int ch;
        cout << "\nEnter a Choice:\n1.Add Node\n2.Add Left Node\n3.Add Right Node\n4.Display Tree\n5.Search Tree\n6.Display Leafs\n7.Display Sorted\n8.Display Depth\n9.PreOrder\n10.InOrder\n11.PostOrder\n12.Print Level\n13.Mirror\n";
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

            s = t.search(data)->child;

            if (s != nullptr)
            {
                cout << s->data;
            }
            else
            {
                cout << "Not Found";
            }

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
        case 12:
            t.displayLevelWise();
            break;
        case 13:
            t.displayMirror();
            break;
        case 14:
            cout << "Enter Node to Delete: ";
            cin >> data;
            t.deleteNode(data);
            break;
        default:
            exit(0);
        }
    }

    getch();
    return 0;
}