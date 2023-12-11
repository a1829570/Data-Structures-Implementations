#include <iostream>
#include <stdlib.h>


struct Node {

    int data; //specific data stored in node
    struct Node *next; // points to successor

};


class LinkedList {
   

    public:
    
    Node * listhead;

    LinkedList(int head_data) {
        this->listhead = new Node;
        listhead->data = head_data;
        listhead->next = NULL;
    }

    

    Node *search_list(Node *n, int x) {

        if (n == nullptr) {

            return nullptr;
        }
        
        if (n->data == x) {
            // if the key in current node matches, return current key
            return n;
        }

        else {
            //iterate to the next node of the linked list
            return search_list(n->next, x);
        }

    }

    void display(Node** head) {
        Node *current = *head;
        while(current != NULL) {

            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void insert_head_list(Node **head, int x) {

        Node * tempPtr; // Declare a temporary pointer for the new node
        tempPtr = new Node; // Allocate memory for the new node
        tempPtr->data = x; // Set the data of the new node to the provided value 'x'
        tempPtr->next = *head; // Set the 'next' pointer of the new node to point to the current head of the list
        *head = tempPtr; // Update the head pointer to point to the new node, making it the new head of the list. 
    }

    void insert_end_list(Node **head, int x) {

        Node * newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        //if list is empty, new node becomes first element (head)
        if (*head == nullptr) {
            *head = newNode;
        }

        else {
            //begin iterating through linked list from head until the last node is found
            Node *current = *head;
            while (current->next != nullptr) {
                current = current->next;
            }
            //add the new node to the end of the linked list (after the last element)
            current->next = newNode;

        }
    }


    

    void deletion(Node **head, int x) {
        
        Node *current = *head;

        if (current == NULL) {

            return; // if empty list, return to main


        }
        
        if (current->next == NULL) {

            delete_at_head(head);
            return;
        }

        while(current->next->data != x) {

            current = current->next; // iterate through the linked list until the predecessor
                                     // of the node to be deleted is reached.                  
        }

        Node* todelete = current->next; // point to node to be deleted
        current->next = current->next->next; // predecessor node points to the node after the node to be deleted.
        delete todelete; // delete node to be deleted
    
    }

    void delete_at_head(Node **head) {
        
        Node* todelete = *head; // initialise the current head to be deleted
        *head = (*head)->next; // new head is the node after the current head
        delete todelete; // delete the current head
    }

};

int main() {

    // Creating a linked list with an initial head value of 10
    LinkedList myList(10);

    // Inserting nodes at the head
    myList.insert_head_list(&myList.listhead, 5);
    myList.insert_head_list(&myList.listhead, 2);

    // Inserting nodes at the end
    myList.insert_end_list(&myList.listhead, 15);
    myList.insert_end_list(&myList.listhead, 20);

    // Displaying the list
    std::cout << "Original List: ";
    myList.display(&myList.listhead);

    // Searching for a node
    int searchValue = 15;
    Node* foundNode = myList.search_list(myList.listhead, searchValue);
    if (foundNode != nullptr) {
        std::cout << "Node with value " << searchValue << " found." << std::endl;
    } else {
        std::cout << "Node with value " << searchValue << " not found." << std::endl;
    }

    // Deleting a node
    int deleteValue = 5;
    myList.deletion(&myList.listhead, deleteValue);
    std::cout << "List after deleting node with value " << deleteValue << ": ";
    myList.display(&myList.listhead);

    // Deleting the head node
    myList.delete_at_head(&myList.listhead);
    std::cout << "List after deleting the head node: ";
    myList.display(&myList.listhead);

    return 0;
}
