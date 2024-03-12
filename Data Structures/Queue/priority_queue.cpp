//* Priority Queue
/*
 * STL Priority Queue is the implementation of Heap Data Structure.
 * in STL:
    - #include <queue>
    - priority_queue<type, [container(vector, ... )], [greater<int>]> q [(arr + begin, arr + end)];
    - feature:
        + pop(), top(), size(), push(), empty(),
 * built using a linked list as follows: (using Heap Data Struct)
            0
          /   \
        1       2
      /  \     /  \
    3     4   5    6
//* recommend:
    - using Doubly Linked List
    - using head, tail to control list easier :(
*/
#include <iostream>
using namespace std;

// structure of a node
struct Node
{
    int data;                                          // value of node
    Node *next;                                        // behind element
    Node(const int &val) : data(val), next(nullptr) {} // constructor
};
typedef Node *node;

// priority class
class priority_queue
{
private:
    node head; // head of queue
    int len;   // number of queue elements

    // add new node to the tree function
    // support to priority_queue::push(val) function
    void add_new_key(const int &key)
    {
        node tmp = head;
        // go to end of queue
        while (tmp->next != nullptr)
            tmp = tmp->next;
        // add new node to end of list
        tmp->next = new Node(key);

        // update tree
        tmp = tmp->next; // go to new node, now tmp is child node
        // find father node
        int i = len - 1; // position of child node
        int j;           // store father node's position
        node father = nullptr;
        while (i > 0)
        {
            j = (i - 1) / 2; // father node's position

            i = j; // i will be the child node position if the next loop turnx occurs
            father = head;
            // go to father node
            while (j-- > 0)
                father = father->next;
            // fix if fater node is smaller than child node
            if (father->data < tmp->data)
            {
                // swap father node and child node
                j = father->data;
                father->data = tmp->data;
                tmp->data = j;
                // continue compair child node with father of father node :_))
                tmp = father;
            }
            else
                break;
        }
    }

    // void heapify() => find the suitable value for ith node
    // in this case, heapify find new value for root (head->data)
    // support to priority_queue::pop()
    void heapify(const int &i)
    {
        int child_pos, j;      // child_pos is position of child node in heap
        child_pos = 2 * i + 1; // position of left child node
        if (child_pos < len)   // check if position is in the heap
        {
            node father = head; // father node (ith node)
            father = head;
            for (j = i; j > 0; --j)
                father = father->next; // goto father node

            node biggest = father; // store biggest node
            int largest = i;       // store biggest node position

            // consider left child node
            node child = father; // store child node
            for (j = i + 1; j <= child_pos; ++j)
                child = child->next;        // go to left child node
            if (child->data > father->data) // check if left child node is bigger than father
            {
                biggest = child; // update
                largest = child_pos;
            }
            // consider right child node
            ++child_pos;         //
            if (child_pos < len) // check if right child node is in heap
            {
                child = child->next;             // go to right child node
                if (child->data > biggest->data) // check if right child node is the biggest
                {
                    biggest = child; // update
                    largest = child_pos;
                }
            }

            // exchange
            if (biggest != father)
            {
                j = father->data;
                father->data = biggest->data;
                biggest->data = j;
                // continue loop
                heapify(largest);
            }
        }
    }

public:
    // cconstructor
    priority_queue() : len(0), head(nullptr) {}

    // priority_queue::top() -> return root of heap
    // return number will be remove from queue next
    int top() { return head->data; } // will error if head == nullptr

    // priority_queue::empty() -> return true if queue is empty (size == 0)
    bool empty() { return len == 0; }

    // priority_queue::size() -> return current number of queue elements
    int size() { return len; }

    // priority_queue::push(val) ->push a new node to heap
    // using add_new_node() function above
    void push(const int &key)
    {
        ++len;               // increase size of heap
        if (head == nullptr) // add first node if heap is empty
        {
            head = new Node(key);
            return;
        }
        // if node is not empty
        add_new_key(key); // add new key to the heap
    }

    // priority_queue::pop() -> delete head of heap
    void pop()
    {
        --len;        // decrease size of heap
        if (len == 0) // if current heap is empty
        {
            head = nullptr;
            return;
        }

        // if current if is not empty
        node tmp = head; // go to ending node of heap
        while (tmp->next != nullptr)
            tmp = tmp->next;
        // exchange head
        head->data = tmp->data;

        node tmp2 = head; // delete last node
        while (tmp2->next != tmp)
            tmp2 = tmp2->next;
        tmp2->next = nullptr; // delete last node

        // find new head
        heapify(0);
    }
};

int main()
{
    priority_queue p;
    // priority_queue::push(val)
    p.push(2);
    p.push(4);
    p.push(-1);
    p.push(-3);
    p.push(8);
    // p = {8, 4, -1, -3, 2}
    cout << "Top of current priority_queue p: " << p.top() << '\n'; // priority_queue::top()
    cout << "Current size: " << p.size() << '\n';
    cout << "Current priority_queue: ";
    while (!p.empty()) // priority_queue::empty()
    {
        cout << p.top() << ' '; // priority_queue::top()
        p.pop();                // priority_queue::pop()
    }
    if (p.empty())
        cout << "\nEmpty Priority Queue";
    cin.get();
    return 0;
}