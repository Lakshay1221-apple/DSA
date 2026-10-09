
Node* insertAtK(Node* head, int val, int k) {
    if (k <= 0) {
        return head;
    }

    // Insert at head
    if (k == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        return newNode;
    }

    Node* temp = head;

    // Find the node at position k - 1
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Position is out of range
    if (temp == nullptr) {
        return head;
    }

    Node* newNode = new Node(val);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}
