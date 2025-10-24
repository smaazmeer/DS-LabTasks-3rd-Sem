#include <iostream>
using namespace std;

class Participant
{
    private:
        string name;
        int time;

    public:
        Participant() {}

        Participant(string n, int t)
        {
            name = n;
            time = t;
        }

        void input()
        {
            cout << "Name: ";
            cin >> name;
            cout << "Finish time: ";
            cin >> time;
        }

        string getName()
        {
            return name;
        }

        int getTime()
        {
            return time;
        }
};


void merge(Participant arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Participant* L = new Participant[n1];
    Participant* R = new Participant[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].getTime() <= R[j].getTime())
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Participant arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    const int size = 10;
    Participant par[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Participant " << i+1 << ": ";
        par[i].input();
    }
    
    mergeSort(par, 0, size-1);

    cout << "\nTop 5 Fastest Runners:\n";
    cout << "-------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << par[i].getName() << " - " << par[i].getTime() << " seconds" << endl;
    }

    return 0;
}