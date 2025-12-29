#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertStart(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "   [Success] " << val << " added to the START!\n";
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "   [Success] " << val << " added to the END!\n";
    }

    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "   [Error] Position must be 1 or greater!\n";
            return;
        }
        
        if (pos == 1) {
            insertStart(val);
            return;
        }
        
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp == tail) {
            insertEnd(val);
        } else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            cout << "   [Success] " << val << " placed at position " << pos << "!\n";
        }
    }

    void deleteStart() {
        if (!head) {
            cout << "   [Error] List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "   [Success] Removed " << head->data << " from the START!\n";
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteEnd() {
        if (!tail) {
            cout << "   [Error] List is empty!\n";
            return;
        }
        Node* temp = tail;
        cout << "   [Success] Removed " << tail->data << " from the END!\n";
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "   [Error] List is empty!\n";
            return;
        }
        
        if (pos < 1) {
            cout << "   [Error] Position must be 1 or greater!\n";
            return;
        }
        
        if (pos == 1) {
            deleteStart();
            return;
        }
        
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "   [Error] Position out of bounds!\n";
            return;
        }
        if (temp == tail) {
            deleteEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "   [Success] Removed " << temp->data << " from position " << pos << "!\n";
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "\n   Current List: (Empty)" << endl;
            return;
        }
        cout << "\n   Current List: ";
        Node* temp = head;
        while (temp) {
            cout << "[" << temp->data << "]";
            if (temp->next) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, pos, total;
    cout << "=================================================" << endl;
    cout << "   🌈  DOUBLY LINKED LIST SYSTEM 🌈      " << endl;
    cout << "=================================================" << endl;

    cout << "💭  First, how many numbers would you like to enter? ";
    cin >> total;
    
    if (total > 0) {
        for (int i = 1; i <= total; i++) {
            if (i == 1) {
                cout << "\n Enter the 1st number: ";
            } else if (i == total) {
                cout << "\n Finally, enter the last number: ";
            } else {
                cout << "\n Enter the next number: ";
            }
            
            cin >> val;
            dll.insertEnd(val);
            
            if (i == total) {
                cout << "   [Success] Setup complete! All numbers stored.\n";
            }
        }
    }

    while (true) {
        cout << "\n-------------------------------------------------" << endl;
        cout << " 1. Delete Start    2. Delete Pos     3. Delete End" << endl;
        cout << " 4. Insert Start    5. Insert Pos     6. Insert End" << endl;
        cout << " 7. Display List     8. Exit" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << " 🤔 Choose an operation (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: dll.deleteStart(); break;
            case 2:
                cout << " Enter position to delete: ";
                cin >> pos;
                dll.deleteAtPosition(pos);
                break;
            case 3: dll.deleteEnd(); break;
            case 4:
                cout << " Enter value to insert: ";
                cin >> val;
                dll.insertStart(val);
                break;
            case 5:
                cout << " Enter value: "; cin >> val;
                cout << " Enter position: "; cin >> pos;
                dll.insertAtPosition(val, pos);
                break;
            case 6:
                cout << " Enter value to insert: ";
                cin >> val;
                dll.insertEnd(val);
                break;
            case 7: dll.display(); break;
            case 8:
                cout << "\n Exiting... Have a wonderful day!\n" << endl;
                return 0;
            default:
                cout << " [!] Invalid choice. Please pick between 1 and 8." << endl;
        }
    }

    return 0;
}
