#include <iostream>
using namespace std;

int main()
{
    int teams;
    cout << "Enter number of teams: ";
    cin >> teams;

    int** scores = new int*[teams];
    int* teamSizes = new int[teams];

    for (int i = 0; i < teams; i++)
    {
        cout << "Enter number of players in team " << i + 1 << ": ";
        cin >> teamSizes[i];
        scores[i] = new int[teamSizes[i]];
        for (int j = 0; j < teamSizes[i]; j++)
        {
            cout << "Enter score of player " << j + 1 << " in team " << i + 1 << ": ";
            cin >> scores[i][j];
        }
    }

    for (int i = 0; i < teams; i++)
    {
        int sum = 0;
        for (int j = 0; j < teamSizes[i]; j++)
        {
            sum += scores[i][j];
        }
        cout << "Sum of team " << i + 1 << ": " << sum << endl;
    }

    for (int i = 0; i < teams; i++)
    {
        delete [] scores[i];
    }
    delete [] scores;
    delete [] teamSizes;

    return 0;
}
