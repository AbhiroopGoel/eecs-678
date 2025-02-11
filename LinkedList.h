// Definition of a Node in the Linked List
struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node in the list
};

// Function to create a new node
typedef struct Node Node;
static Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
static Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print all elements in the linked list
static void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the entire linked list and free memory
static void deleteList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL;
}

#endif // LINKED_LIST_H
