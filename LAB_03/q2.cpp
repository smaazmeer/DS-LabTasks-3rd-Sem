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

        void addTail(string value)
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

        void deleteFront()
        {
            if(head == NULL)
            {
                cout << "Catalog EMPTY!" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void searchByTitle(string value)
        {
            Node* temp = head;
            int pos = 1;
            while(temp != NULL)
            {
                if(temp->data == value)
                {
                    cout << "Book found at POSITION " << pos << ": " << temp->data << endl;
                    return;
                }
                temp = temp->next;
                pos++;
            }
            cout << "Book NOT FOUND" << endl;
        }

        void searchByPosition(int position)
        {
            if(position <= 0)
            {
                cout << "INVALID POSITION" << endl;
                return;
            }
            Node* temp = head;
            int pos = 1;
            while(temp != NULL)
            {
                if(pos == position)
                {
                    cout << "Book at position " << position << ": " << temp->data << endl;
                    return;
                }
                temp = temp->next;
                pos++;
            }
            cout << "No book at that position" << endl;
        }

        void display()
        {
            if(head == NULL)
            {
                cout << "Catalog EMPTY!" << endl;
                return;
            }

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
    LinkedList catalog;
    catalog.addTail("Data Structures");
    catalog.addTail("Operating Systems");
    catalog.addTail("Computer Networks");
    catalog.addTail("Database Systems");

    cout << "Catalog:" << endl;
    catalog.display();

    cout << endl << "Deleting front book..." << endl;
    catalog.deleteFront();
    catalog.display();

    cout << endl;
    catalog.searchByTitle("Computer Networks");
    catalog.searchByTitle("Artificial Intelligence");

    cout << endl;
    catalog.searchByPosition(2);
    catalog.searchByPosition(5);

    return 0;
}
