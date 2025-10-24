#include <iostream>
#include <cmath>
using namespace std;

class Student
{
    public:
        string name;
        int score;
        Student* next;

        Student(string n = "", int s = 0)
        {
            name = n;
            score = s;
            next = nullptr;
        }
};

class LinkedList
{
    private:
        Student* head;

    public:
        LinkedList()
        {
            head = nullptr;
        }

        void insert(string name, int score)
        {
            Student* newNode = new Student(name, score);
            if (!head)
                head = newNode;
            else
            {
                Student* temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
            }
        }

        int getMaxScore()
        {
            int maxScore = 0;
            Student* temp = head;
            while (temp)
            {
                if (temp->score > maxScore)
                    maxScore = temp->score;
                temp = temp->next;
            }
            return maxScore;
        }

        void radixSort()
        {
            int maxScore = getMaxScore();
            for (int exp = 1; maxScore / exp > 0; exp *= 10)
                countingSort(exp);
        }

        void countingSort(int exp)
        {
            Student* buckets[10] = {nullptr};
            Student* bucketTails[10] = {nullptr};
            Student* temp = head;

            while (temp)
            {
                int digit = (temp->score / exp) % 10;
                Student* newNode = new Student(temp->name, temp->score);
                if (!buckets[digit])
                {
                    buckets[digit] = newNode;
                    bucketTails[digit] = newNode;
                }
                else
                {
                    bucketTails[digit]->next = newNode;
                    bucketTails[digit] = newNode;
                }
                temp = temp->next;
            }

            head = nullptr;
            Student* tail = nullptr;
            for (int i = 0; i < 10; i++)
            {
                if (buckets[i])
                {
                    if (!head)
                    {
                        head = buckets[i];
                        tail = bucketTails[i];
                    }
                    else
                    {
                        tail->next = buckets[i];
                        tail = bucketTails[i];
                    }
                }
            }
        }

        void display()
        {
            Student* temp = head;
            cout << "\nSorted Student List:\n";
            cout << "---------------------------\n";
            while (temp)
            {
                cout << "Name: " << temp->name << ", Score: " << temp->score << endl;
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList list;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cout << "\nStudent " << i + 1 << " name: ";
        cin >> name;
        cout << "Student " << i + 1 << " score: ";
        cin >> score;
        list.insert(name, score);
    }

    list.radixSort();
    list.display();

    return 0;
}
