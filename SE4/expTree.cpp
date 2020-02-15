#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;

string reverse(string str)
{

    string newStr = "";

    for (int i = str.length() - 1, j = 0; i >= 0; i--, j++)
    {
        if (str[i] == '(')
        {

            newStr += ')';
        }
        else if (str[i] == ')')
        {
            newStr += '(';
        }
        else
        {
            newStr += str[i];
        }
    }

    return newStr;
}

struct TreeNode
{
    string data;
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
    bool search_pro(string data, TreeNode *n)
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
    void add(string d)
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

    bool search(string data)
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
    TreeNode *generateFromPreIn(string pre, string in)
    {
        if (in.length() == 1)
        {
            TreeNode *nd = new TreeNode();
            nd->data = in;

            return nd;
        }
        else if (pre != "" && in != "")
        {
            string rt = pre.substr(0, 1);
            int i = in.find_first_of(rt);

            while (i == -1 && pre.length() != 0)
            {
                pre = pre.substr(1, pre.length());
                rt = pre.substr(0, 1);
                i = in.find_first_of(rt);
            }

            if (rt != "" || i != -1)
            {
                TreeNode *nd = new TreeNode();
                nd->data = rt;

                nd->left = generateFromPreIn(pre.substr(1, pre.length()), in.substr(0, i));
                nd->right = generateFromPreIn(pre.substr(1, pre.length()), in.substr(i + 1, in.length()));

                return nd;
            }
        }
        return nullptr;
    }
    TreeNode *generateFromPostIn(string post, string in)
    {
        return generateFromPreIn(reverse(post), in);
    }
    void printPreRec()
    {

        TreeNode *p = new TreeNode;

        p = root;

        stack<TreeNode *> st;

        if (ptr == NULL)
        {
            cout << "Tree is Empty!";
            return;
        }

        while (p != NULL)
        {
            cout << p->data;

            if (p->right != NULL)
            {
                st.push(p->right);
            }

            if (p->left != NULL)
            {
                p = p->left;
            }
            else
            {
                if (!st.empty())
                {
                    p = st.top();
                    st.pop();
                }
                else
                {
                    p = NULL;
                }
            }
        }
    }
    void printInRec()
    {
        TreeNode *p, *q = new TreeNode;

        p = root;

        stack<TreeNode *> st1, st2;

        if (ptr == NULL)
        {
            cout << "Tree is Empty!";
            return;
        }
        st1.push(p);
        while (!st1.empty())
        {
            p = st1.top();
            st2.push(p);
            st1.pop();

            if (p->left != NULL)
            {
                st1.push(p->left);
            }
            if (p->right != NULL)
            {
                st1.push(p->right);
            }
        }
        while (!st2.empty())
        {
            p = st2.top();
            cout << p->data;
            st2.pop();
        }
    }
    void printPostRec()
    {
    }
    void setRoot(TreeNode *n)
    {
        root = n;
    }
};

int main()
{
    Tree t;

    string preorder = "ABDHIECFJKG";
    string preinorder = "HDIBEAJFKCG";

    t.setRoot(t.generateFromPreIn(preorder, preinorder));

    cout << "Pre:  ";
    t.printPreRec();
    cout << "\nIn:   ";
    t.printInOrder();
    cout << " : ";
    t.printInRec();
    cout << "\nPost: ";
    t.printPostOrder();

    cout << "\nTree:\n";
    t.display();

    cout << "\n****************************************\n";

    string postorder = "HIDEBJKFGCA";
    string postinorder = "HDIBEAJFKCG";

    t.setRoot(t.generateFromPostIn(postorder, preinorder));

    cout << "Pre:  ";
    t.printPreOrder();
    cout << "\nIn:   ";
    t.printInOrder();
    cout << "\nPost: ";
    t.printPostRec();

    cout << "\nTree:\n";
    t.display();

    getch();
    return 0;
}