#include <iostream>
#include <string>
using namespace std;

struct node {
    string name;
    node* next_ptr;

    node(string name, node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class LinkedList {
private:
    node* head;
    node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next_ptr = newNode;
            tail = newNode;
        }
    }

    void display_list() {
        node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " -> ";
            currNode = currNode->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(string val) {
        node* curr = head;
        node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->name == val) {
                if (curr == head) {
                    head = head->next_ptr;
                } else {
                    prev->next_ptr = curr->next_ptr;
                }

                if (curr == tail) {
                    tail = prev;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next_ptr;
        }
    }
};

int main() {
    node* node1 = new node("ali");
    node* node2 = new node("ahmad");
    node* node3 = new node("abu");

    LinkedList linkedlst;
    linkedlst.add_element(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    linkedlst.display_list();

    linkedlst.delete_by_value("ahmad");
    linkedlst.display_list();

    return 0;
}
