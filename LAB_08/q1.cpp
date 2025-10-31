#include <iostream>
using namespace std;

struct Node
{
    char name[50];
    Node *left, *right;
};

Node* createNode(const char n[])
{
    Node* t = new Node;
    int i = 0;
    while(n[i] != '\0')
    {
        t->name[i] = n[i];
        i++;
    }
    t->name[i] = '\0';
    t->left = t->right = NULL;
    return t;
}

Node* find(Node* r, const char n[])
{
    if(!r) return NULL;
    int i = 0; bool same = true;
    while(r->name[i] != '\0' || n[i] != '\0')
    {
        if(r->name[i] != n[i]) { same = false; break; }
        i++;
    }
    if(same) return r;
    Node* l = find(r->left, n);
    if(l) return l;
    return find(r->right, n);
}

void print(Node* r, int space = 0)
{
    if(!r) return;
    space += 5;
    print(r->right, space);
    cout << endl;
    for(int i = 5; i < space; i++) cout << " ";
    cout << r->name << endl;
    print(r->left, space);
}

int main()
{
    Node* root = NULL;
    int ch;
    while(true)
    {
        cout << "\n1.Create root\n2.Add child\n3.Display\n4.Exit\nChoice: ";
        cin >> ch;
        if(ch == 1)
        {
            if(root) { cout << "Root exists\n"; continue; }
            char name[50];
            cout << "Enter root name: ";
            cin >> name;
            root = createNode(name);
        }
        else if(ch == 2)
        {
            if(!root) { cout << "Create root first\n"; continue; }
            char p[50], c[50]; char s;
            cout << "Enter parent name: "; cin >> p;
            cout << "Enter child name: "; cin >> c;
            cout << "Side (L/R): "; cin >> s;
            Node* par = find(root, p);
            if(!par) { cout << "Parent not found\n"; continue; }
            if(s == 'L' || s == 'l')
            {
                if(par->left) cout << "Left exists\n"; 
                else par->left = createNode(c);
            }
            else
            {
                if(par->right) cout << "Right exists\n"; 
                else par->right = createNode(c);
            }
        }
        else if(ch == 3)
        {
            if(!root) cout << "Empty tree\n"; 
            else print(root);
        }
        else break;
    }
    return 0;
}
