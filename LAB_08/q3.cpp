#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int d)
{
    Node* t = new Node;
    t->data = d;
    t->left = t->right = NULL;
    return t;
}

Node* find(Node* r, int d)
{
    if(!r) return NULL;
    if(r->data == d) return r;
    Node* l = find(r->left, d);
    if(l) return l;
    return find(r->right, d);
}

bool isFull(Node* r)
{
    if(!r) return true;
    if(!r->left && !r->right) return true;
    if(r->left && r->right) return isFull(r->left) && isFull(r->right);
    return false;
}

int main()
{
    Node* root = NULL;
    int ch;
    while(true)
    {
        cout << "\n1.Create root\n2.Add child\n3.Check full\n4.Exit\nChoice: ";
        cin >> ch;
        if(ch == 1)
        {
            if(root) { cout << "Root exists\n"; continue; }
            int x; cout << "Enter root value: "; cin >> x;
            root = createNode(x);
        }
        else if(ch == 2)
        {
            if(!root) { cout << "Create root first\n"; continue; }
            int p, c; char s;
            cout << "Parent: "; cin >> p;
            cout << "Child: "; cin >> c;
            cout << "Side(L/R): "; cin >> s;
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
            if(!root) { cout << "Empty\n"; continue; }
            if(isFull(root)) cout << "Full Binary Tree\n";
            else cout << "Not Full Binary Tree\n";
        }
        else break;
    }
    return 0;
}
