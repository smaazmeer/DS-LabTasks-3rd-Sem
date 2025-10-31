#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *left, *right;
};

Node* createNode(int i)
{
    Node* t = new Node;
    t->id = i;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* r, int i)
{
    if(!r) return createNode(i);
    if(i < r->id) r->left = insert(r->left, i);
    else if(i > r->id) r->right = insert(r->right, i);
    return r;
}

bool exists(Node* r, int i)
{
    if(!r) return false;
    if(r->id == i) return true;
    if(i < r->id) return exists(r->left, i);
    return exists(r->right, i);
}

Node* lca(Node* r, int a, int b)
{
    if(!r) return NULL;
    if(a < r->id && b < r->id) return lca(r->left, a, b);
    if(a > r->id && b > r->id) return lca(r->right, a, b);
    return r;
}

int main()
{
    Node* root = NULL;
    int ch;
    while(true)
    {
        cout << "\n1.Insert ID\n2.Find LCA\n3.Exit\nChoice: ";
        cin >> ch;
        if(ch == 1)
        {
            int x;
            cout << "Enter ID: ";
            cin >> x;
            if(!exists(root, x)) root = insert(root, x);
            else cout << "Exists\n";
        }
        else if(ch == 2)
        {
            int a, b;
            cout << "Enter two IDs: ";
            cin >> a >> b;
            if(!exists(root, a) || !exists(root, b))
            {
                cout << "IDs not found\n";
                continue;
            }
            Node* ans = lca(root, a, b);
            if(ans) cout << "LCA: " << ans->id << endl;
        }
        else break;
    }
    return 0;
}
