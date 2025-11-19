#include <iostream>
using namespace std;

// ------------------------
// Heapify for MAX-HEAP
// ------------------------
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// ------------------------
// Heapify for MIN-HEAP
// ------------------------
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// ------------------------
// Heap Sort in Increasing Order (Max-Heap)
// ------------------------
void heapSortIncreasing(int arr[], int n) {
    // Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements from heap
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

// ------------------------
// Heap Sort in Decreasing Order (Min-Heap)
// ------------------------
void heapSortDecreasing(int arr[], int n) {
    // Build Min Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], arrCopy[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arrCopy[i] = arr[i];
    }

    cout << "\n1. Increasing Order (Max-Heap)";
    cout << "\n2. Decreasing Order (Min-Heap)";
    cout << "\nChoose option: ";

    int ch;
    cin >> ch;

    if (ch == 1) {
        heapSortIncreasing(arr, n);
        cout << "Sorted in Increasing Order: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    else if (ch == 2) {
        heapSortDecreasing(arrCopy, n);
        cout << "Sorted in Decreasing Order: ";
        for (int i = 0; i < n; i++) cout << arrCopy[i] << " ";
    }
    else {
        cout << "Invalid Choice!";
    }

    return 0;
}

