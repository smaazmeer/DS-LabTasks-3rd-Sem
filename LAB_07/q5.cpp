#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

int partitionFunc(int arr[], int left, int right, int pivot)
{
    int leftPointer = left;
    int rightPointer = right - 1;

    while (true)
    {
        while (arr[++leftPointer] < pivot)
            comparisons++;
        while (rightPointer > 0 && arr[--rightPointer] > pivot)
            comparisons++;

        if (leftPointer >= rightPointer)
            break;
        else
        {
            int temp = arr[leftPointer];
            arr[leftPointer] = arr[rightPointer];
            arr[rightPointer] = temp;
        }
    }

    int temp = arr[leftPointer];
    arr[leftPointer] = arr[right];
    arr[right] = temp;
    return leftPointer;
}

void quickSort(int arr[], int left, int right, int mode)
{
    if (left >= right)
        return;

    int pivotIndex;
    if (mode == 1)
        pivotIndex = left;
    else if (mode == 2)
        pivotIndex = left + rand() % (right - left + 1);
    else if (mode == 3)
        pivotIndex = left + (right - left) / 2;
    else
    {
        int mid = left + (right - left) / 2;
        int a = arr[left], b = arr[mid], c = arr[right];
        if ((a > b) != (a > c))
            pivotIndex = left;
        else if ((b > a) != (b > c))
            pivotIndex = mid;
        else
            pivotIndex = right;
    }

    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[right];
    arr[right] = temp;

    int pivot = arr[right];
    int partitionIndex = partitionFunc(arr, left, right, pivot);

    quickSort(arr, left, partitionIndex - 1, mode);
    quickSort(arr, partitionIndex + 1, right, mode);
}

void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

int main()
{
    srand(time(0));
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 12, 6, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[10];

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 1);
    cout << "First element pivot comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 2);
    cout << "Random element pivot comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 3);
    cout << "Middle element pivot comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 4);
    cout << "Median of three pivot comparisons: " << comparisons << endl;

    return 0;
}
