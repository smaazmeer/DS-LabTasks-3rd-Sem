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

int subtreeSum(Node* r, int target, bool &found, Node* &ans)
{
    if(!r) return 0;
    int l = subtreeSum(r->left, target, found, ans);
    int rr = subtreeSum(r->right, target, found, ans);
    int total = r->data + l + rr;
    if(!found && total == target)
    {
        found = true;
        ans = r;
    }
    return total;
}

void preorder(Node* r)
{
    if(!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if(n <= 0) return 0;
    Node* arr[100];
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = createNode(x);
    }
    for(int i = 0; i < n; i++)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(l < n) arr[i]->left = arr[l];
        if(r < n) arr[i]->right = arr[r];
    }
    Node* root = arr[0];
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    bool found = false;
    Node* ans = NULL;
    subtreeSum(root, target, found, ans);
    if(found)
    {
        cout << "Subtree found: ";
        preorder(ans);
        cout << endl;
    }
    else
    {
        cout << "No subtree found\n";
    }
    return 0;
}
