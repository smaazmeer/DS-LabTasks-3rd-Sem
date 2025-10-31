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

int countNodes(Node* r)
{
    if(!r) return 0;
    return 1 + countNodes(r->left) + countNodes(r->right);
}

int countLeaves(Node* r)
{
    if(!r) return 0;
    if(!r->left && !r->right) return 1;
    return countLeaves(r->left) + countLeaves(r->right);
}

int height(Node* r)
{
    if(!r) return -1;
    int l = height(r->left);
    int rr = height(r->right);
    return (l > rr ? l : rr) + 1;
}

int main()
{
    Node* root = NULL;
    int ch;
    while(true)
    {
        cout << "\n1.Create root\n2.Add child\n3.Show properties\n4.Exit\nChoice: ";
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
            cout << "Parent value: "; cin >> p;
            cout << "Child value: "; cin >> c;
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
            if(!root) { cout << "Empty\n"; continue; }
            cout << "Total nodes: " << countNodes(root) << endl;
            cout << "Leaf nodes: " << countLeaves(root) << endl;
            cout << "Height: " << height(root) << endl;
        }
        else break;
    }
    return 0;
}
