#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
void deleteAtEnd() {
   
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Last node deleted. List is now empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL; 
    delete temp;

    cout << "Last node deleted successfully." << endl;
}
