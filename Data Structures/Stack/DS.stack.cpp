//* Stack implements Last In First Out:
//* stack.top // now position
//* stack.empty() -> bool // check if stack is empty
//* stack.push(value) // insert value AT END of stack
//* stack.pop() // remove element FROM END of stack
//* stack.size() // number elements of stack
#include <iostream>
#include <stack>

using namespace std;

class plate
{
    int id;

public:
    plate(int &i)
    {
        id = i;
    }
    int getID()
    {
        return id;
    }
};

void addPlate(stack<plate> &stackPlate)
{
    int n, id;
    cout << "\nEnter number of plate: ";
    cin >> n;
    while (n)
    {
        --n;
        cout << "Enter ID: ";
        cin >> id;
        stackPlate.push(plate(id));
        cout << "Added successfully plate " << id << " to stack!\n";
    }
}

void removePlate(stack<plate> &stackPlate)
{
    int n;
    cout << "How many plate do u need: ";
    cin >> n;
    while (n)
    {
        if (stackPlate.empty())
        {
            cout << "Plate stack is Empty!\n";
            break;
        }
        else
        {
            cout << "Selected plate " << stackPlate.top().getID() << "!\n";
            stackPlate.pop();
        }
        --n;
    }
}

void Menu(stack<plate> &stackPlate)
{
    int opt;
    cout << "Add new plate to stack[1]\n";
    cout << "Select plate from stack[2]\n";
    cout << "Check number of Plate in stack[3]:\n";
    cout << "Choose what do u want to do:\n";
    do
    {
        cin >> opt;
    } while (opt < 1 || opt > 3);
    if (opt == 1)
        addPlate(stackPlate);
    else if (opt == 2)
        removePlate(stackPlate);
    else
        cout << "There are " << stackPlate.size() << " plates in the stack!\n";
    cout << "Do u want to do this program again(1/0) : ";
    cin >> opt;
    if (opt)
    {
        system("cls");
        Menu(stackPlate);
    }
}

int main()
{
    stack<plate> stackPlate;
    Menu(stackPlate);
    system("pause");
    return 0;
}