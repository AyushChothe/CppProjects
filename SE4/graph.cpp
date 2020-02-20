// int graph[5][5] = {
//     //1  2  3  4  5
//     {0, 1, 0, 0, 10}, //1
//     {1, 0, 1, 0, 0},  //2
//     {0, 0, 0, 5, 0},  //3
//     {0, 0, 0, 0, 3},  //4
//     {10, 0, 0, 0, 0}, //5
// };

// for (int i = 0; i < 5; i++)
// {
//     for (int j = 0; j < 5; j++)
//     {
//         if (graph[i][j] != 0 && graph[j][i] != 0)
//         {
//             cout << i + 1 << "<-" << graph[i][j] << "->" << j + 1 << endl;
//         }
//         else if (graph[i][j] != 0)
//         {
//             cout << i + 1 << "-" << graph[i][j] << ">" << j + 1 << endl;
//         }
//     }
// }

#include <iostream>
#include <conio.h>
#include <vector>
#include <stack>
using namespace std;

class Person
{
public:
    string name, dob;
    int comments;

    string getData()
    {
        return name + "|" + dob + "|" + to_string(comments);
    }

    Person() {}

    Person(string n, string d, int c)
    {
        name = n;
        dob = d;
        comments = c;
    }

    void setData()
    {
        cout << "Name: ";
        cin >> name;
        cout << "DOB: ";
        cin >> dob;
        cout << "Comments: ";
        cin >> comments;
    }
};

class Vertex
{
public:
    Person data;
    vector<Vertex *> *links;

    Vertex() {}

    Vertex(Person d)
    {
        data = d;
        links = new vector<Vertex *>;
    }

    //Dir non Weight
    bool addLink(Vertex *v)
    {
        for (int i = 0; i < links->size(); i++)
        {
            if (links->at(i)->data.name == v->data.name)
            {
                return false;
            }
        }
        links->push_back(v);
        return true;
    }
    void displayLinks()
    {
        for (int i = 0; i < links->size(); i++)
        {
            cout << data.getData() << "->" << links->at(i)->data.getData();
        }
        cout << "\n";
    }
};
class Queue
{
    typedef struct node
    {
        Vertex *data;
        node *next = NULL;
    } node;

    node *front, *rear, *p;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(Vertex *data)
    {
        p = new node;
        p->data = data;

        if (front == NULL)
        {
            front = new node;
            rear = new node;
            front = p;
            rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }

    Vertex *pop()
    {
        Vertex *data = new Vertex;
        if (front != NULL)
        {
            if (front == rear)
            {
                rear = NULL;
            }

            p = new node;
            p = front;
            data = p->data;
            front = front->next;
            delete p;
        }

        return data;
    }

    void display()
    {
        p = new node;
        p = front;
        while (p != NULL)
        {
            Vertex *d = new Vertex;
            d = p->data;
            cout << d->data.getData();
            p = p->next;
        }
        cout << "\n";
    }

    bool contains(Vertex *s)
    {
        p = new node;
        p = front;
        while (p != NULL)
        {
            Vertex *d = new Vertex;
            d = p->data;

            if (d->data.name == s->data.name)
            {
                return true;
            }

            p = p->next;
        }
        return false;
    }

    bool isEmpty()
    {
        return front == NULL && rear == NULL;
    }
};
class Graph
{
public:
    vector<Vertex *> vertices;

    bool addVertex(Person d)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i]->data.name == d.name)
            {
                return false;
            }
        }

        Vertex *v = new Vertex(d);

        vertices.push_back(v);

        return true;
    }

    Vertex *getVertex(string d)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i]->data.name == d)
            {
                return vertices[i];
            }
        }
        return nullptr;
    }

    bool addRel(string v1, string v2, bool dir = false)
    {
        Vertex *ve1 = getVertex(v1);
        Vertex *ve2 = getVertex(v2);
        if (ve1 && ve2)
        {
            if (dir)
            {
                ve1->addLink(ve2);
            }
            else
            {
                ve1->addLink(ve2);
                ve2->addLink(ve1);
            }
            return true;
        }
        return false;
    }

    void displayVertices()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            cout << vertices[i]->data.getData() << endl;
        }
    }
    void displayRel()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i]->displayLinks();
        }
    }
    void displayRelByName(string s)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i]->data.name == s)
            {
                vertices[i]->displayLinks();
                break;
            }
        }
    }

    void BFS()
    {
        Queue q, r;
        q.push(vertices.at(0));
        r.push(vertices.at(0));

        while (!q.isEmpty())
        {
            Vertex *ptr = q.pop();
            cout << ptr->data.getData() << "\n";

            for (int i = 0; i < ptr->links->size(); i++)
            {
                if (!r.contains(ptr->links->at(i)))
                {
                    q.push(ptr->links->at(i));
                    r.push(ptr->links->at(i));
                }
            }
        }
    }
    void DFS(Vertex *v)
    {
        static Queue r;
        if (v != nullptr)
        {
            r.push(v);
            cout << v->data.getData() << endl;

            if (v->links->size() > 0)
            {
                for (int i = 0; i < v->links->size(); i++)
                {
                    if (!r.contains(v->links->at(i)))
                    {
                        DFS(v->links->at(i));
                    }
                }
            }
        }
    }
    void getMutual(string p1, string p2)
    {
        Vertex *v1 = getVertex(p1);
        Vertex *v2 = getVertex(p2);

        Queue v;

        for (int i = 0; i < v1->links->size(); i++)
        {
            for (int j = 0; j < v2->links->size(); j++)
            {
                if (v1->links->at(i)->data.name == v2->links->at(j)->data.name && !v.contains(v1->links->at(i)))
                {
                    v.push(v1->links->at(i));
                }
            }
        }

        v.display();
    }
};

int main()
{
    Graph g;
    Person p;
    string s, d;
    int ch;

   /*  g.addVertex(Person("A", "50", 50));
    g.addVertex(Person("B", "50", 50));
    g.addVertex(Person("C", "50", 50));
    g.addVertex(Person("D", "50", 50));
    g.addVertex(Person("E", "50", 50));
    g.addVertex(Person("F", "50", 50));
    g.addVertex(Person("G", "50", 50));
    g.addRel("A", "B");
    g.addRel("A", "C");
    g.addRel("B", "D");
    g.addRel("B", "E");
    g.addRel("C", "F");
    g.addRel("C", "G");
 */
    while (0 < 1)
    {
        cout << "\n----------\n1.Add User\n2.Add Relation\n3.Display Users\n4.Display Relations By Name\n5.Display All relations\n6.BFS\n7.DFS\n8.Get Mutual Friends\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.setData();
            g.addVertex(p);
            cout << p.name << " Added!";
            break;
        case 2:
            cout << "Add Source and Destination: ";
            cin >> s >> d;
            g.addRel(s, d);
            cout << s + "<->" + d << " Relation Added!";
            break;
        case 3:
            g.displayVertices();
            break;
        case 4:
            cout << "Enter Username: ";
            cin >> s;
            g.displayRelByName(s);
            break;
        case 5:
            g.displayRel();
            break;
        case 6:
            g.BFS();
            break;
        case 7:
            g.DFS(g.vertices.at(0));
            break;
        case 8:
        cout<<"Enter Two Friends: "
        cin>>s>>d;
            g.getMutual(s,d);
            break;
        default:
            break;
        }
    }
    getch();
    return 0;
}
