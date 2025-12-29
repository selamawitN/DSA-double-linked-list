#include <iostream>
using namespace std;

struct node {
    int data; 
    node *prev;
    node *next;
};

node *head = NULL; 

node* getNewNode (int i){
    node *newNode = new node;  
    newNode->data = i;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//INSERTION

void InsertAtHead(int i){
    node *newNode = getNewNode(i);
    if (head == NULL){
        head =  newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;    
}

void InsertAtEnd(int i){
    node *newNode = getNewNode(i);
    if (head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void InsertAtPosition(int i, int pos){
    if (pos <= 1){
        InsertAtHead(i);
        return;
    }

    node *newNode = getNewNode(i);
    node *temp = head;
    for (int j = 1; j < pos - 1 && temp != NULL; j++){
        temp = temp->next;
    }

    if (temp == NULL){
        InsertAtEnd(i);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// DELETION

void DeleteAtBeginning(){
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void DeleteAtEnd(){
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    node *temp = head;
    if (temp->next == NULL){
        head = NULL;
        delete temp;
        return;
    }

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void DeleteAtPosition(int pos){
    if (head == NULL){
        cout << "List is empty!\n";
        return;
    }
    if (pos <= 1){
        DeleteAtBeginning();
        return;
    }

    node *temp = head;
    for (int j = 1; j < pos && temp != NULL; j++){
        temp = temp->next;
    }

    if (temp == NULL){
        cout << "Position does not exist!\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

void display (){
    node *temp = head;
    if (temp == NULL){
        cout << "List is empty!\n";
        return;
    }
    cout << "List: ";
    while (temp != NULL){
        cout  << temp->data << " ";
        temp = temp->next;    
    }
    cout << "\n";
}


int main (){
    int choice, value, pos;

    while (true){
        cout << "Operation you can perform\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "=================================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                InsertAtHead(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                InsertAtEnd(value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                InsertAtPosition(value, pos);
                break;

            case 4:
                DeleteAtBeginning();
                break;

            case 5:
                DeleteAtEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                DeleteAtPosition(pos);
                break;case 7:
                display();
                break;

            case 0:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice, try again!\n";
        }
    }
}
