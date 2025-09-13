#include <iostream>
using namespace std;

class Node
{
    public:
        string data;
        Node* next;
        Node(string value)
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

        void addFront(string value)
        {
            Node* n = new Node(value);
            n->next = head;
            head = n;
        }

        void addEnd(string value)
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

        void insertAfter(string afterValue, string newValue)
        {
            Node* temp = head;
            while(temp != NULL && temp->data != afterValue)
            {
                temp = temp->next;
            }
            if(temp != NULL)
            {
                Node* n = new Node(newValue);
                n->next = temp->next;
                temp->next = n;
            }
        }

        bool search(string value)
        {
            Node* temp = head;
            while(temp != NULL)
            {
                if(temp->data == value)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void display()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList books;
    books.addEnd("Data Structures");
    books.addEnd("Operating Systems");
    books.addEnd("Computer Networks");
    books.addEnd("Database Systems");

    books.addFront("Artificial Intelligence");
    books.addEnd("Machine Learning");
    books.insertAfter("Operating Systems", "Cyber Security");

    cout << "Complete list of books:" << endl;
    books.display();

    cout << endl;
    if(books.search("Database Systems"))
    {
        cout << "FOUND!" << endl;
    }
    else
    {
        cout << "NOT FOUND!" << endl;
    }

    return 0;
}
