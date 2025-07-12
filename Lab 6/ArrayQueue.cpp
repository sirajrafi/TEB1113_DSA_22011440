#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    string *arr;     // Array to store queue elements
    int front;       // Index of front element
    int rear;        // Index of rear element
    int capacity;    // Maximum capacity of the queue
    int currentSize; // Current number of elements in the queue

public:
    Queue(int size = 100)
    { // Constructor with default size 100
        capacity = size;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    void enqueue(string name)
    {
        if (currentSize >= capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity; // Increment rear (using modulo for safety)
        arr[rear] = name;             // Add element to rear
        currentSize++;
    }

    void display_queue()
    {
        if (currentSize == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int count = 0;
        int index = front;
        while (count < currentSize)
        {
            cout << arr[index] << " <- ";
            index = (index + 1) % capacity;
            count++;
        }
        cout << "NULL" << endl;
    }

    void dequeue()
    {
        if (currentSize == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Removing: " << arr[front] << endl;
        front = (front + 1) % capacity; // Move front to next element
        currentSize--;
    }
};

int main()
{
    // Create queue
    Queue queue(100);

    // Add elements
    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");

    // Display the queue
    queue.display_queue();

    // Example of deletion
    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}
