#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];   // static array for heap
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Helper: Heapify Up (for insertion)
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        if (i > 0 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    }

    // Helper: Heapify Down (for deletion)
    void heapifyDown(int i) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    // Insert element
    void push(int value) {
        arr[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    // Remove highest priority element (max element)
    void pop() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        cout << "Deleted element: " << arr[0] << endl;

        // Move last element to root
        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);
    }

    // Return highest priority element
    int top() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    // Display heap (priority queue)
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        cout << "Priority Queue (as Heap): ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n--- Priority Queue Using Heap ---\n";
        cout << "1. Insert (Push)\n";
        cout << "2. Delete Highest Priority (Pop)\n";
        cout << "3. Get Highest Priority (Top)\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            pq.push(value);
            break;

        case 2:
            pq.pop();
            break;

        case 3:
            cout << "Highest Priority = " << pq.top() << endl;
            break;

        case 4:
            pq.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

