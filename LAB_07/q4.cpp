#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = nullptr;
        }
};

void swap(Node* a, Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high)
{
    int pivot = high->data;
    Node* i = low->next;
    Node* j = low;

    for (; i != high; i = i->next)
    {
        if (i->data < pivot)
        {
            j = (j == nullptr) ? low : j->next;
            swap(i, j);
        }
    }

    j = (j == nullptr) ? low : j->next;
    swap(j, high);
    return j;
}

void quickSortRec(Node* low, Node* high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        Node* p = partition(low, high);
        quickSortRec(low, p);
        quickSortRec(p->next, high);
    }
}

void quickSort(Node* head)
{
    Node* high = head;
    while (high->next != nullptr)
        high = high->next;
    quickSortRec(head, high);
}

void printList(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    quickSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
