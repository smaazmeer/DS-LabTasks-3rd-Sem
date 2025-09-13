#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int value)
        {
            data = value;
            prev = NULL;
            next = NULL;
        }
};

class DoublyLinkedList
{
    private:
        Node* head;
    public:
        DoublyLinkedList()
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
            n->prev = temp;
        }

        void removeFront()
        {
            if(head == NULL)
            {
                cout << "Train is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            if(head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
        }

        void search(int value)
        {
            Node* temp = head;
            int pos = 1;
            while(temp != NULL)
            {
                if(temp->data == value)
                {
                    cout << "Compartment " << value << " found at position " << pos << endl;
                    return;
                }
                temp = temp->next;
                pos++;
            }
            cout << "Compartment " << value << " not found" << endl;
        }

        void display()
        {
            if(head == NULL)
            {
                cout << "Train is empty" << endl;
                return;
            }
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main()
{
    DoublyLinkedList train;
    train.addEnd(101);
    train.addEnd(102);
    train.addEnd(103);
    train.addEnd(104);

    cout << "Train compartments:" << endl;
    train.display();

    cout << endl << "Removing first compartment..." << endl;
    train.removeFront();
    train.display();

    cout << endl;
    train.search(102);
    train.search(109);

    return 0;
}
