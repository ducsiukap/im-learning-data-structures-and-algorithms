//* Queue: FIFO
//* queue::front(), queue::back()
//* queue::pop() // delete queue::front()
//* queue::push(value) // add value at end of queue
//* queue::empty()

#include <iostream>
#include <queue>

using namespace std;

void expandQueue(queue<int> &ds)
{
    int n, i;
    cout << "How many number addition to queue? ";
    cin >> n;
    while (n)
    {
        --n;
        cout << "Enter number want to add: ";
        cin >> i;
        ds.push(i);
    }
    cout << "Expand queue successfully!\n";
}

void takeQueue(queue<int> &ds)
{
    int n;
    cout << "How many number is taken: ";
    cin >> n;
    while (n)
    {
        --n;
        if (ds.empty())
        {
            cout << "Queue is EMPTY!\n";
            break;
        }
        else
        {
            cout << ds.front() << " is remove from queue!\n";
            ds.pop();
        }
    }
}

void showQueue(queue<int> ds)
{
    if (ds.empty())
        cout << "The queue is EMPTY!\n";
    else
    {
        cout << "Queue size: " << ds.size() << '\n';
        cout << "The queue is: [";
        while (1)
        {
            cout << ds.front();
            ds.pop();
            if (!ds.empty())
                cout << ", ";
            else
                break;
        }
        cout << "]\n";
    }
}

void Menu(queue<int> &ds)
{
    int opt;
    cout << "Expand queue[1]\n";
    cout << "Take number from queue[2]\n";
    cout << "Show queue[3]\n";
    do
    {
        cout << "Your choose: ";
        cin >> opt;
    } while (opt < 1 || opt > 3);
    if (opt == 1)
        expandQueue(ds);
    else if (opt == 2)
        takeQueue(ds);
    else
        showQueue(ds);
    cout << "Do u want to do this program again ? (1/0)\n";
    cin >> opt;
    if (opt)
    {
        system("cls");
        Menu(ds);
    }
}

int main()
{
    queue<int> ds;
    Menu(ds);
    system("pause");
}