#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    // constructor
    Node() { next = prev = nullptr; }
};
typedef Node *node;

// make node
node make_node()
{
    int n;
    cout << "Enter new node :";
    cin >> n;
    node newNode = new Node();
    newNode->data = n;
    return newNode;
}
// size of list
int get_size(node &head)
{
    if (head == nullptr)
        return 0;
    node tmp = head;
    int cnt = 1;
    while (tmp->next != nullptr)
    {
        ++cnt;
        tmp = tmp->next;
    }
    return cnt;
}
// show list
void show_list(node &head)
{
    if (head == nullptr)
        cout << "List is EMPTY !\n";
    else
    {
        cout << "Current list: \n";
        node tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << '\n';
    }
}

//* insert
// at head
void pushHead(node &head, node &tail, node &newNode)
{
    // if list is empty
    if (head == nullptr)
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
// at tail
void pushTail(node &head, node &tail, node &newNode)
{
    if (head == nullptr)
        head = tail = newNode;
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
// at mid
void pushMid(node &head, int &pos, node &newNode)
{
    node tmp = head;
    while (--pos > 1)
        tmp = tmp->next;
    newNode->next = tmp->next;
    newNode->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}
// check valid  position
bool check_pos(node &head, int &pos)
{
    int maxPos = get_size(head) + 1;
    return (pos >= 1 && pos <= maxPos);
}
// Push function
void push(node &head, node &tail, int pos = 0)
{
    if (!pos)
    {
        cout << "Enter position : ";
        cin >> pos;
    }
    if (check_pos(head, pos))
    {
        node newNode = make_node();
        if (pos == 1)
            pushHead(head, tail, newNode);
        else if (pos == get_size(head) + 1)
            pushTail(head, tail, newNode);
        else
            pushMid(head, pos, newNode);
        cout << "\nInsert new node successfully !\n\n";
    }
    else
        cout << "\nCan't insert new node at this position !\n\n";
    show_list(head);
}

//* delete
// at head
void popHead(node &head, node &tail)
{
    if (get_size(head) == 1)
    {
        head = tail = nullptr;
        return;
    }
    head = head->next;
    head->prev = nullptr;
}
// at tail
void popTail(node &head, node &tail)
{
    if (get_size(head) == 1)
    {
        head = tail = nullptr;
        return;
    }
    // cout << tail->data << ' ';
    tail->prev->next = nullptr;
    tail = tail->prev;
}
// at mid
void popMid(node &head, int &pos)
{
    node tmp = head;
    while (--pos)
        tmp = tmp->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
}
// pop function
void pop(node &head, node &tail, int pos = 0)
{
    if (!pos)
    {
        cout << "Enter position : ";
        cin >> pos;
    }
    if (pos < 1 || pos > get_size(head))
        cout << "\nCan't delete at this position !\n\n";
    else
    {
        if (pos == 1)
            popHead(head, tail);
        else if (pos == get_size(head))
            popTail(head, tail);
        else
            popMid(head, pos);
        cout << "\nDelete node successfully !\n\n";
    }
    show_list(head);
}

//* sorting
void sort(node &head)
{
    node min, nowPos, tmp;
    int val;
    for (nowPos = head; nowPos != nullptr; nowPos = nowPos->next)
    {
        min = nowPos;
        for (tmp = nowPos->next; tmp != nullptr; tmp = tmp->next)
            if (min->data > tmp->data)
                min = tmp;
        if (min != nowPos)
        {
            val = min->data;
            min->data = nowPos->data;
            nowPos->data = val;
        }
    }
    cout << "Sorting successfully !\n\n";
    show_list(head);
}

//* Me n U == menu :))
int get_choose()
{
    int n;
    cout << "Your choose : ";
    cin >> n;
    return n;
}
// push menu
void pushMenu(node &head, node &tail)
{
    cout << "----------Menu----------\n";
    cout << "1. Push new node at head of list.\n";
    cout << "2. Push new node at end of list.\n";
    cout << "3. Push new node at middle of list.\n";
    cout << "----------Menu----------\n";
    int opt;
    do
    {
        opt = get_choose();
    } while (opt < 1 || opt > 3);
    if (opt == 1)
        push(head, tail, 1);
    else if (opt == 2)
        push(head, tail, get_size(head) + 1);
    else
        push(head, tail);
}
// delete menu
void popMenu(node &head, node &tail)
{
    cout << "----------Menu----------\n";
    cout << "1. Delete new node at head of list.\n";
    cout << "2. Delete new node at end of list.\n";
    cout << "3. Delete new node at middle of list.\n";
    cout << "----------Menu----------\n";
    int opt;
    do
    {
        opt = get_choose();
    } while (opt < 1 || opt > 3);
    if (opt == 1)
        pop(head, tail, 1);
    else if (opt == 2)
        pop(head, tail, get_size(head));
    else
        pop(head, tail);
}
// menu
void Menu(node &head, node &tail)
{
    cout << "----------Menu----------\n";
    cout << "1. Push new node into list.\n";
    cout << "2. Delete a node from list.\n";
    cout << "3. Sort current list increase.\n";
    cout << "4. Show current list.\n";
    cout << "5. Get size of list.\n";
    cout << "----------Menu----------\n";
    int opt;
    do
    {
        opt = get_choose();
    } while (opt < 1 || opt > 5);
    system("cls");
    if (opt == 1)
        pushMenu(head, tail);
    else if (opt == 2)
        popMenu(head, tail);
    else if (opt == 3)
        sort(head);
    else if (opt == 4)
        show_list(head);
    else
        cout << "Current size : " << get_size(head) << ".\n";
    cout << "\nBan co muon thuc hien lai chuong trinh (1/0)?\n";
    if (get_choose())
    {
        system("cls");
        Menu(head, tail);
    }
}
int main()
{
    node head, tail;
    head = tail = nullptr;
    Menu(head, tail);
    system("pause");
}