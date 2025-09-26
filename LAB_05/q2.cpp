#include <iostream>
using namespace std;

#define N 5

int maze[N][N] = 
{
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

int solution[N][N] = {0};

bool isSafe(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool solveMaze(int x, int y)
{
    if (x == N - 1 && y == N - 1)
    {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y))
    {
        solution[x][y] = 1;

        if (solveMaze(x + 1, y))
        {
            return true;
        }

        if (solveMaze(x, y + 1))
        {
            return true;
        }

        solution[x][y] = 0;
        return false;
    }

    return false;
}

void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Lion path in the maze:" << endl;
    if (solveMaze(0, 0))
    {
        printSolution();
    }
    else
    {
        cout << "No path found!" << endl;
    }

    return 0;
}
