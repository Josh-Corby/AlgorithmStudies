#include <iostream>

using namespace std;

void SelectionSort(int arr[], int arrSize)
{
    // variable to store the index of the minimum value
    // in each iteration
    int minIndex;

    // Iterate until N-1 elements
    // As last element will always be sorted when we would get to it
    for (int i = 0; i < arrSize - 1; ++i)
    {
        // Set the first unsorted element
        // as the minimum value
        minIndex = i;

        // Iterate through the unsorted elements only
        for (int j = i + 1; j < arrSize; ++j)
        {
            // set the new minimum value
            // if the saved minimum value is higher
            // than the current index value
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the first unsorted element
        // with the minimum value
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    cout << "Selection Sort" << endl;

    // Initialize a new array
    int arr[] = { 43, 21, 56, 78, 97, 30 };
    int arrSize = sizeof(arr) / sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < arrSize; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array with SelectionSort algorithm
    SelectionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i = 0; i < arrSize; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}