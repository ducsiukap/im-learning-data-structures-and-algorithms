/*
//* Doubly Linked List
structure:

struct node
{
    data_type data;
    node *next; -> point to next node
    node *prev; -> point to previous node
};
- tail node: final node of list
- head node: head node of list
- nul node: connect tail n head node
=> nul->prev = tail  || nul->next = head
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class student
{
private:
    string id;
    float gpa;

public:
    string name, cls;
    // constructor
    student(string N = "", string Id = "", string C = "", float GPA = 0)
    {
        this->name = N;
        this->id = Id;
        this->cls = C;
        this->gpa = GPA;
    }

    friend istream &operator>>(istream &is, student &s)
    {
        cout << "-------------------------\n";
        cout << "Student Information: \n";
        cout << "Enter name  : ";
        scanf("\n");
        getline(is, s.name);
        cout << "Enter ID    : ";
        is >> s.id;
        cout << "Enter class : ";
        is >> s.cls;
        cout << "Enter GPA   : ";
        is >> s.gpa;
        return is;
    }

    friend ostream &operator<<(ostream &os, student &s)
    {
        cout << s.name << ' ' << s.id << ' '
             << s.cls << ' ' << s.gpa << '\n';
        return os;
    }

    string getID() { return this->id; }
    float getGPA() { return this->gpa; }
};

struct Node
{
    student data;
    Node *next;
    Node *prev;

    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
};

typedef Node *node;
// make new node
node makenode(student &s)
{
    node newnode = new Node();
    newnode->data = s;
    return newnode;
}
// get size of list
int getsize(node &nul)
{
    int cnt = 0;
    for (node head = nul->next; head != nul; head = head->next)
        ++cnt;
    return cnt;
}
// show list
void show(node &nul)
{
    int i = 0;
    for (node head = nul->next; head != nul; head = head->next)
    {
        ++i;
        cout << "Student " << i << ": " << head->data;
    }
    if (i == 0)
        cout << "List is EMPTY !\n";
    cout << '\n';
}

// insert
void push(node &nul, int pos = 0)
{
    if (!pos)
    {
        cout << "Enter position: ";
        cin >> pos;
    }
    int maxPos = getsize(nul) + 1;
    if (pos < 1 || pos > maxPos)
    {
        cout << "Can't insert at this position !\n";
        return;
    }
    student s;
    cin >> s;
    node newNode = makenode(s);
    // insert at first
    if (pos == 1)
    {
        newNode->next = nul->next;
        nul->next->prev = newNode;
        nul->next = newNode;
        newNode->prev = nul;
    }
    // insert at end
    else if (pos == maxPos)
    {
        newNode->prev = nul->prev;
        nul->prev->next = newNode;
        nul->prev = newNode;
        newNode->next = nul;
    }
    // insert at mid
    else
    {
        node tmp = nul;
        while (--pos)
            tmp = tmp->next;
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    cout << "Insert new student successfully !\n\n";
}

// delete
void pop(node &nul, int pos = 0)
{
    if (!pos)
    {
        cout << "Enter position : ";
        cin >> pos;
    }
    if (pos < 1 || pos > getsize(nul))
    {
        cout << "Can't delete at this position !\n";
        return;
    }
    // delete at first
    if (pos == 1)
    {
        nul->next = nul->next->next;
        nul->next->prev = nul;
    }
    // delete at end
    else if (pos == getsize(nul))
    {
        nul->prev = nul->prev->prev;
        nul->prev->next = nul;
    }
    // delete at mid
    else
    {
        node tmp = nul->next;
        while (--pos)
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    cout << "Delete student successfully !\n";
}

// Searching
string tolwr(string s)
{
    for (int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
    return s;
}
// search
void searchByName(node &nul)
{
    string s;
    cout << "Enter student's name: ";
    cin >> s;
    s = tolwr(s);
    //
    node tmp = nul->next;
    bool has = false;
    while (tmp != nul)
    {
        if (tolwr(tmp->data.name).find(s) != string::npos)
        {
            has = true;
            cout << tmp->data;
        }
        tmp = tmp->next;
    }
    if (has == false)
        cout << "404 Not Found !\n";
}

// Sorting
void sort(node &nul)
{
    node max = new Node(), tmp = new Node();
    student s;
    for (node head = nul->next; head != nul; head = head->next)
    {
        max = head;
        for (tmp = head->next; tmp != nul; tmp = tmp->next)
            if (tmp->data.getGPA() > max->data.getGPA())
                max = tmp;
        if (max != head)
        {
            s = head->data;
            head->data = max->data;
            max->data = s;
        }
    }
    show(nul);
}

// Menu
void option(node &nul, int &n)
{
    if (n == 1)
        push(nul, 1);
    else if (n == 2)
        push(nul);
    else if (n == 3)
        push(nul, getsize(nul) + 1);
    else if (n == 4)
        pop(nul, 1);
    else if (n == 5)
        pop(nul);
    else if (n == 6)
        pop(nul, getsize(nul));
    else if (n == 7)
        searchByName(nul);
    else if (n == 8)
        show(nul);
    else if (n == 9)
        cout << "Number student in list: " << getsize(nul) << "\n\n";
    else if (n == 10)
        sort(nul);
}
void table()
{
    cout << "---------------Menu---------------\n";
    cout << "1. Insert at First\n";
    cout << "2. Insert at Middle\n";
    cout << "3. Insert at End\n";
    cout << "4. Delete at First\n";
    cout << "5. Delete at Middle\n";
    cout << "6. Delete at End\n";
    cout << "7. Search by name\n";
    cout << "8. Show current list\n";
    cout << "9. Show current size of list\n";
    cout << "10.Show sorted list (by student's GPA)\n";
    cout << "---------------Menu---------------\n";
}
// main menu
void menu(node &nul)
{
    int ops;
    table();
    // enter option
    do
    {
        cout << "Your choose: ";
        cin >> ops;
    } while (ops < 1 || ops > 10);
    //
    option(nul, ops);
    // continue this programe
    cout << "Do u want to continue this program (1/0) : ";
    cin >> ops;
    if (ops)
    {
        system("cls");
        menu(nul);
    }
}

int main()
{
    node nul = new Node();
    nul->next = nul->prev = nul;
    menu(nul);
    system("pause");
}