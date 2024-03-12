//* Heap sort
/*
Heap sort:
- B1 : build Max-Heap : a[i] >= (a[2i] and a[2*i + 1])
    -> build a tree which father node is no smaller than child node
    - start from i = a.size / 2 downto 1 (consider all of father node)
        => heapify(a, i)
- B2 : find exact value for node:
    => start : i from a.size downto 2
        + swap(a[i], a[1]) //(a[1] alway the max of heap)
        + --a.size() // not consider a[a.size]
        + heapify(a, 1) // find root of heap (max of head -> a[1])
*/
#include <iostream>
using namespace std;

void print_array(int *a, const int &len) // print array
{
    for (int i = 0; i <= len; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

void Swap(int &a, int &b) // swap 2 nodes in heap
{
    int c = a;
    a = b;
    b = c;
}

// heapify(a, i) => find suitable position for node i
// or find suitable value for node i (node i is no smaller than its child node)
void max_heapify(int *a, const int &i, const int &len)
{
    int exchange_node = i; // swap(a[i], a[exchange_node])
    // => right-child node or left-child node;
    int child_node = 2 * i + 1; // left-child node
    if (child_node <= len)      // check if child node is present in the heap
    {
        if (a[child_node] > a[exchange_node]) // check if child node is > father node
            exchange_node = child_node;       // update suitable node (suitable value for node i)

        ++child_node;                                              // right-child node
        if (child_node <= len && a[child_node] > a[exchange_node]) // check if child node is > father node
            exchange_node = child_node;                            // update suitable node (suitable value for node i)

        // check if node i is incorrect
        if (exchange_node != i)
        {
            Swap(a[i], a[exchange_node]);
            max_heapify(a, exchange_node, len); // find suitable position for node i
        }
    }
} // found suitable value for node i and suitable position for value of node i

// build max-heap function
// -> build a tree which father node is no smaller than child node
// => node(i) > (node(2 * i) and node(2*i + 1))
void build_max_heap(int *a, const int &len)
{
    // start from a.length/2 down to 1
    //-> consider all of father node ->max-heapify(a, father_node)
    for (int i = (len + 1) / 2; i >= 0; --i)
        max_heapify(a, i, len);
}

// heap_sort function
void heap_sort(int *a, int &len)
{
    // build a max-heap
    build_max_heap(a, len);

    // find exact value for each node
    for (int i = len; i >= 1; --i) // consider all of node except root node
    {
        // a[0] allways is the max of tree
        Swap(a[i], a[0]); // => found the suitable value of node i

        --len; // -> no consider a[i] more

        // find the root of new tree
        max_heapify(a, 0, len);
    }
} // sort complete

int main()
{
    int a[] = {2, 1, 1, 1, -1, -3};         // non-sorted array
    int len = sizeof(a) / sizeof(a[0]) - 1; // max index of a

    cout << "Before sorting: ";
    print_array(a, len);

    // call heapsort function
    heap_sort(a, len);

    // print array
    len = sizeof(a) / sizeof(a[0]) - 1;
    cout << "After sorting: ";
    print_array(a, len);
    system("pause");
    return 0;
}