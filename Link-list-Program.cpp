#include <iostream>
using namespace std;// Define the structure for a node
struct Node {
    int data;
    Node* next;
};// Function prototypes
void insertAtBeginning(Node*& head, int value);
void insertAtEnd(Node*& head, int value);
void deleteFromBeginning(Node*& head);
void deleteFromEnd(Node*& head);
void displayList(Node* head);
void search(Node* head, int value);
void menu();
int main() {
    Node* head = nullptr;
    int choice, value;
    do {
        menu();
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            insertAtBeginning(head, value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            insertAtEnd(head, value);
            break;
        case 3:
            deleteFromBeginning(head);
            break;
        case 4:
            deleteFromEnd(head);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            cout << "Enter value you want search: ";
            cin >> value;
            search(head,value);
            break;
        
       
        case 7:
            cout << "Exiting program . " << endl;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    } while (choice != 7);    // Free remaining memory
    while (head != nullptr) {
        deleteFromBeginning(head);
    }
    return 0;
}
void insertAtBeginning(Node* & head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning." << endl;
}
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end." << endl;
}
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. 'Underflow'" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from the beginning." << endl;
    delete temp;
}
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. 'overflow'" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Deleted the only node in the list." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = nullptr;
    cout << "Deleted " << toDelete->data << " from the end." << endl;
    delete toDelete;
}
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void search(Node* head, int value)
{
    Node* ptr; int count=1;
    if (head == nullptr)
    {
        cout << "Underflow \n";
        return;
    }
    else
    {
        ptr = head;
        while ((ptr != nullptr) && (value != ptr->data))
        {
            ptr = ptr->next;
            count++;
        }

        if (ptr != NULL and value == ptr->data)
        {
            cout << "Item found at node " << count;
        }
        else
        {
            cout << "Item not found \n";
            return;
        }
    }
}
void menu() {
    cout << "-------------------------------" << endl;
    cout << "Linked List Operations Menu:" << endl;
    cout << "1. Insert at Beginning" << endl;
    cout << "2. Insert at End" << endl;
    cout << "3. Delete from Beginning" << endl;
    cout << "4. Delete from End" << endl;
    cout << "5. Display List" << endl;
    cout << "6. Search an item" << endl;
    cout << "7. Exit" << endl;
    cout << "-------------------------------" << endl;
}
