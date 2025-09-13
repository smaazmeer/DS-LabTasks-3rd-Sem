#include <iostream>

using namespace std;

class Node
{
    public:
        string song;
        Node* next;

        Node(string value)
        {
            song = value;
            next = NULL;
        }
};

class Playlist
{
    private:
        Node* head;
    public:
        Playlist()
        {
            head = NULL;
        }
        void addSong(string name)
        {
            Node* n = new Node(name);
            if(head == NULL)
            {
                head = n;
                head->next = head;
                return;
            }
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }
        void display()
        {
            if(head == NULL)
            {
                cout << "Playlist is empty" << endl;
                return;
            }
            Node* temp = head;
            do
            {
                cout << temp->song << endl;
                temp = temp->next;
            }
            while(temp != head);
        }
        void play(int rounds)
        {
            if(head == NULL)
            {
                cout << "Playlist is empty" << endl;
                return;
            }
            Node* temp = head;
            for(int i = 0; i < rounds; i++)
            {
                cout << "Playing: " << temp->song << endl;
                temp = temp->next;
            }
        }
};

int main()
{
    Playlist playlist;
    playlist.addSong("Secrets");
    playlist.addSong("Dirty Cash");
    playlist.addSong("OBVIOUS");
    playlist.addSong("Dawgs");

    cout << "Playlist:" << endl;
    playlist.display();

    cout << endl << "Simulating playback:" << endl;
    playlist.play(7);

    return 0;
}
