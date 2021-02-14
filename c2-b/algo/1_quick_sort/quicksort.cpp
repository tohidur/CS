#include<iostream>

using namespace std;

void swap(int *i, int *j) {
    int c = *i;
    *i = *j;
    *j = c;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}


int partition(int *arr, int l, int r)
{
    int pivot = arr[l];
    int i = l;
    int j = r;

    while (i < j)
    {
        do
        {
            i++;
        } while(arr[i] <= pivot);

        do
        {
            j--;
        } while(arr[j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[l]);
    return j;
}

void quicksort(int *arr, int l, int r)
{
    if (l < r)
    {
        int j = partition(arr, l, r);
        quicksort(arr, l, j);
        quicksort(arr, j+1, r);
    }
}

int main() {
    int arr[] = {3, 4, 1, 8, 6, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort:\n";
    printArray(arr, n);

    quicksort(arr, 0, n);

    cout << "After sort:\n";
    printArray(arr, n);

    return 0;
}


