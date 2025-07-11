#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node *next_ptr;

    Node(string name, Node *next_ptr = nullptr)
    { // Constructor with default nullptr
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue(Node *front = nullptr)
    { // Constructor takes Node* and initializes rear
        this->front = front;
        this->rear = front;
        if (front)
            front->next_ptr = nullptr;
    }

    void enqueue(Node *node)
    {
        if (!node)
            return; // Check for null pointer

        node->next_ptr = nullptr; // Set new node's next to nullptr

        if (!front)
        { // If list is empty
            front = node;
            rear = node;
        }
        else
        {
            rear->next_ptr = node; // Link current rear to new node
            rear = node;           // Update rear to new node
        }
    }

    void display_queue()
    {
        Node *current = front;
        if (!current)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        
        do {
            cout << current->name << " <- ";
            current = current->next_ptr;
        } while (current != front);

        cout << "Front (" << front->name << ")" << endl;
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next_ptr;
        cout << "Removing: " << temp->name << endl;
        delete temp;
    }
};

int main()
{
    // Create nodes dynamically
    Node *node1 = new Node("Ali");
    Node *node2 = new Node("Ahmed");
    Node *node3 = new Node("Alee");
    Node *node4 = new Node("Abu");

    // Create queue and add nodes
    Queue queue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3);
    queue.enqueue(node4);

    // Display the queue
    queue.display_queue();

    // Example of deletion
    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}
