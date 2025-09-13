#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = NULL;
        }
};

class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList()
        {
            head = NULL;
        }

        void addEnd(int value)
        {
            Node* n = new Node(value);
            if(head == NULL)
            {
                head = n;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

        void display()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void sort()
        {
            if(head == NULL) return;
            for(Node* i = head; i->next != NULL; i = i->next)
            {
                for(Node* j = i->next; j != NULL; j = j->next)
                {
                    if(i->data > j->data)
                    {
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }

        void concatenate(LinkedList& other)
        {
            if(head == NULL)
            {
                head = other.head;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = other.head;
        }

        void findMiddle()
        {
            if(head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }
            Node* slow = head;
            Node* fast = head;
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "Middle element: " << slow->data << endl;
        }

        void removeDuplicates()
        {
            Node* current = head;
            while(current != NULL && current->next != NULL)
            {
                Node* prev = current;
                Node* temp = current->next;
                while(temp != NULL)
                {
                    if(temp->data == current->data)
                    {
                        prev->next = temp->next;
                        delete temp;
                        temp = prev->next;
                    }
                    else
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                }
                current = current->next;
            }
        }
        
        static LinkedList mergeSorted(LinkedList& l1, LinkedList& l2)
        {
            LinkedList result;
            Node dummy(0);
            Node* tail = &dummy;
            Node* a = l1.head;
            Node* b = l2.head;
            while(a != NULL && b != NULL)
            {
                if(a->data <= b->data)
                {
                    tail->next = a;
                    a = a->next;
                }
                else
                {
                    tail->next = b;
                    b = b->next;
                }
                tail = tail->next;
            }
            if(a != NULL) tail->next = a;
            if(b != NULL) tail->next = b;
            result.head = dummy.next;
            return result;
        }
};

int main()
{
    LinkedList list1;
    list1.addEnd(4);
    list1.addEnd(2);
    list1.addEnd(5);
    list1.addEnd(2);
    list1.addEnd(1);

    cout << "Original list:" << endl;
    list1.display();

    cout << "Sorted list:" << endl;
    list1.sort();
    list1.display();

    cout << "Removing duplicates:" << endl;
    list1.removeDuplicates();
    list1.display();

    list1.findMiddle();

    LinkedList list2;
    list2.addEnd(3);
    list2.addEnd(6);
    list2.addEnd(7);

    cout << "Concatenated list:" << endl;
    list1.concatenate(list2);
    list1.display();

    LinkedList a;
    a.addEnd(1);
    a.addEnd(3);
    a.addEnd(5);

    LinkedList b;
    b.addEnd(2);
    b.addEnd(4);
    b.addEnd(6);

    cout << "Merging two sorted lists:" << endl;
    LinkedList merged = LinkedList::mergeSorted(a, b);
    merged.display();

    return 0;
}
