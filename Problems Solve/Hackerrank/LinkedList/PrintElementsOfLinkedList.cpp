// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

class SinglyLinkedListNode // struct node{};
{
public:
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode(int node_data) : data(node_data), next(nullptr) {}
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
    // list.push(int val)
    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head) // if head == nullptr
            this->head = node;
        else
            this->tail->next = node; // insert at end
        this->tail = node;           // update tail
    }
};

// list.clear(head)
void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode *node)
{
    while (node != nullptr)
    {
        cout << node->data << '\n';
        node = node->next;
    }
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    printLinkedList(llist->head);

    return 0;
}
