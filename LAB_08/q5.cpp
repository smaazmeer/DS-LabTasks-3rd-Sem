#include <iostream>
using namespace std;

struct Node
{
    int id, qty;
    Node *left, *right;
};

Node* createNode(int i, int q)
{
    Node* t = new Node;
    t->id = i;
    t->qty = q;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* r, int i, int q)
{
    if(!r) return createNode(i, q);
    if(i == r->id) r->qty += q;
    else if(i < r->id) r->left = insert(r->left, i, q);
    else r->right = insert(r->right, i, q);
    return r;
}

Node* search(Node* r, int i)
{
    if(!r) return NULL;
    if(r->id == i) return r;
    if(i < r->id) return search(r->left, i);
    return search(r->right, i);
}

void inorder(Node* r)
{
    if(!r) return;
    inorder(r->left);
    cout << r->id << " " << r->qty << endl;
    inorder(r->right);
}

Node* maxQty(Node* r, Node* best)
{
    if(!r) return best;
    if(!best || r->qty > best->qty) best = r;
    best = maxQty(r->left, best);
    best = maxQty(r->right, best);
    return best;
}

int main()
{
    Node* root = NULL;
    int ch;
    while(true)
    {
        cout << "\n1.Add/Update product\n2.Search product\n3.Show highest qty\n4.Display all\n5.Exit\nChoice: ";
        cin >> ch;
        if(ch == 1)
        {
            int id, q;
            cout << "Enter id qty: ";
            cin >> id >> q;
            root = insert(root, id, q);
        }
        else if(ch == 2)
        {
            int id;
            cout << "Enter id: ";
            cin >> id;
            Node* f = search(root, id);
            if(f) cout << f->id << " " << f->qty << endl;
            else cout << "Not found\n";
        }
        else if(ch == 3)
        {
            Node* m = maxQty(root, NULL);
            if(m) cout << m->id << " " << m->qty << endl;
            else cout << "Empty\n";
        }
        else if(ch == 4)
        {
            if(!root) cout << "Empty\n";
            else inorder(root);
        }
        else break;
    }
    return 0;
}
