/*
Head -> node -> node -> node -> ... -> null
structure of node:

struct node{
    data;
    link; -> pointer
};

- singly linked list has only next pointer point to next element

*/

#include <iostream>
#include <string>
using namespace std;

// student class
class student
{
private:
    string id;
    float gpa;

public:
    string name, Class;
    // constructor
    student(string Name = "", string ID = "", string CLass = "", float GPA = 0)
    {
        this->name = Name;
        this->id = ID;
        this->Class = CLass;
        this->gpa = GPA;
    }
    // set student information
    friend istream &operator>>(istream &is, student &s)
    {
        cout << "--------------------\n";
        cout << "Student Information:\n";
        cout << "Enter student's name  : ";
        scanf("\n");
        getline(is, s.name);
        cout << "Enter student's ID    : ";
        is >> s.id;
        cout << "Enter student's class : ";
        is >> s.Class;
        cout << "Enter student's GPA   : ";
        is >> s.gpa;
        cout << "--------------------\n";
        return is;
    }
    // print student information
    friend ostream &operator<<(ostream &os, student &s)
    {
        cout << "--------------------\n";
        cout << "Student's name  : " << s.name << '\n'
             << "Student's ID    : " << s.id << '\n'
             << "Student's class : " << s.Class << '\n'
             << "Student's GPA   : " << s.gpa << '\n';
        return os;
    }
    // show private member
    string showID() { return this->id; }
    float showGPA() { return this->gpa; }
};

// struct node
struct Node
{
    student data;
    Node *next;
};

// define node*
typedef Node *node;

// make a new node in list
node makeNode(student &s)
{
    node newNode = new Node();
    newNode->data = s;
    newNode->next = nullptr;
    return newNode;
}

// get size of student's list
int getSize(node &nul)
{
    node head = nul->next;
    int sz = 0; // current size
    while (head != nul)
    {
        ++sz;
        head = head->next;
    }
    return sz;
}

// show list
void show(node &nul)
{
    if (nul->next == nul)
    {
        cout << "List student is EMPTY !\n";
        return;
    }
    cout << "List student: \n";
    node tmp = nul->next;
    while (tmp != nul)
    {
        cout << tmp->data;
        tmp = tmp->next;
    }
}

// insert
// at begin
void pushFirst(node &nul, student &s)
{
    node newNode = makeNode(s);
    newNode->next = nul->next;
    nul->next = newNode;
}
// at end
void pushEnd(node &nul, student &s)
{
    node newNode = makeNode(s);
    node tmp = nul->next;
    while (tmp->next != nul)
        tmp = tmp->next;
    newNode->next = nul;
    tmp->next = newNode;
}
void pushMiddle(node &nul, student &s, int &pos)
{
    node newNode = makeNode(s);
    node tmp = nul;
    while (--pos)
        tmp = tmp->next;
    newNode->next = tmp->next;
    tmp->next = newNode;
}
// push function
void push(node &nul, int pos = 0)
{
    int maxPos = getSize(nul) + 1; // insert position
    if (!pos)
    {
        cout << "Enter position : ";
        cin >> pos;
    }
    if (pos < 1 || pos > maxPos)
    {
        cout << "Can't insert at this position !\n";
        return;
    }
    student s;
    cin >> s;
    if (pos == 1)
        pushFirst(nul, s);
    else if (pos == maxPos)
        pushEnd(nul, s);
    else
        pushMiddle(nul, s, pos);
}

// Delete
// at begin
void deleteFirst(node &nul) { nul->next = nul->next->next; }
// at end
void deleteEnd(node &nul)
{
    node tmp = nul->next;
    while (tmp->next != nul)
        tmp = tmp->next;
    tmp = nul;
}
// at middle
void deleteMid(node &nul, int &pos)
{
    node tmp = nul;
    while (--pos)
        tmp = tmp->next;
    tmp->next = tmp->next->next;
}
// delete function
void deleteNode(node &nul, int pos = 0)
{
    int maxPos = getSize(nul);
    if (!maxPos)
    {
        cout << "List is EMPTY !\n";
        return;
    }
    if (!pos)
    {
        cout << "Enter position: ";
        cin >> pos;
    }
    if (pos < 1 || pos > maxPos)
    {
        cout << "Can't delete at this position !\n";
        return;
    }
    if (pos == 1)
        deleteFirst(nul);
    else if (pos == maxPos)
        deleteEnd(nul);
    else
        deleteMid(nul, pos);
}

// Search
string tolwr(string s)
{
    for (int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
    return s;
}
bool SearchName(node &nul)
{
    int have = 0;
    string name;
    cout << "Enter name: ";
    cin >> name;
    name = tolwr(name);
    // find
    node tmp = nul->next;
    while (tmp != nul)
    {
        if (tolwr(tmp->data.name).find(name) != string::npos)
        {
            ++have;
            cout << "Student " << have << ": ";
            cout << tmp->data.name << ' '
                 << tmp->data.showID() << '\n';
        }
        tmp = tmp->next;
    }
    return have;
}

// Sorting
void Sort(node nul)
{
    node tmp = new Node();
    student s;
    for (node nowNode = nul->next; nowNode != nul; nowNode = nowNode->next)
    {
        node min = nowNode;
        for (tmp = nowNode->next; tmp != nul; tmp = tmp->next)
            if (tmp->data.showGPA() > min->data.showGPA())
                min = tmp;
        if (min != nowNode)
        {
            s = min->data;
            min->data = nowNode->data;
            nowNode->data = s;
        }
    }
    show(nul);
}

// Menu
// choose
void choose(node &nul, int &n)
{
    while (n < 1 || n > 10)
    {
        cout << "Re-choose: ";
        cin >> n;
    }
    if (n == 1)
        push(nul, 1);
    if (n == 2)
        push(nul);
    if (n == 3)
        push(nul, getSize(nul) + 1);
    if (n == 4)
        deleteNode(nul, 1);
    if (n == 5)
        deleteNode(nul);
    if (n == 6)
        deleteNode(nul, getSize(nul));
    if (n == 7)
        Sort(nul);
    if (n == 8)
        if (!SearchName(nul))
            cout << "404 not found !\n";
    if (n == 9)
        cout << "Number student of list: " << getSize(nul) << '\n';
    if (n == 10)
        show(nul);
}
void Menu(node &nul)
{
    int ops;
    cout << "--------------Menu-------------\n";
    cout << "1. Insert at First\n";
    cout << "2. Insert at Middle\n";
    cout << "3. Insert at End\n";
    cout << "4. Delete at First\n";
    cout << "5. Delete at Middle\n";
    cout << "6. Delete at End\n";
    cout << "7. Show sorted list by GPA\n";
    cout << "8. Search student by name\n";
    cout << "9. Count number student of list\n";
    cout << "10.Show list\n";
    cout << "--------------Menu-------------\n";
    cout << "Your choose: ";
    cin >> ops;
    choose(nul, ops);
    cout << "Do u want to re-do this program (1/0) : \n";
    cin >> ops;
    if (ops)
    {
        system("cls");
        Menu(nul);
    }
}

int main()
{
    // first node of list
    // node end -> nul -> node begin
    node nul = new Node();
    nul->next = nul;
    Menu(nul);
    return 0;
}