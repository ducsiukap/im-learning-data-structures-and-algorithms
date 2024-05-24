//* Binary Search Tree
// partition the tree to 2 subtree, one of them is smaller than root and other is bigger
/*
    * structure of a node:{
        / data
        *parent; -> parent of current node
        * left_child_node; -> root of the subtree smaller than current node
        * right_child_node; -> root of the subtree bigger than current node}
    -           parrent
                   |
              current node (h)
              /         \
            /            \
        left_node      right_node
*          < h             >= h
    - Traversal: from left leaves to root to right leaves
    Traversal(node root)
    {
        if(root == nullptr)
            return;

        Traversal(root->left)
        //*process current node
        Traversal(root->right)
    }
*/
#include <iostream>
using namespace std;

// defind structure of a node
struct Btree
{
    int data;
    Btree *parent;
    Btree *left, *right;
    // constructor
    Btree(const int &val) : data(val), parent(nullptr), left(nullptr), right(nullptr) {}
    // => make node: Btree(value)
};

// using "node" rather than "Btree *" (because my habit :)))
typedef Btree *node;

// defind class binary_search_tree
class binary_search_tree
{
private:
    node head; // root of tree
    int Size;  // number elements of the tree

    // replace node u in tree by another node (v)
    void replace(node u, node v = nullptr)
    {
        // if u is the head
        if (u->parent == nullptr)
            head = v;
        // find node u
        else if (u->parent->left == u)
            u->parent->left = v;
        else
            u->parent->right = v;
        // if replace_node isnt NULL
        if (v != nullptr)
            v->parent = u->parent;
    }

public:
    binary_search_tree() : Size(0), head(nullptr) {} // contructor

    // get size of head
    int get_size() { return Size; }

    // check empty
    bool isEmpty() { return head == nullptr; }

    // find maximum element from a root (default is head) in tree
    node maximum(node root = nullptr) // default passing
    {
        if (head == nullptr) // cant find if the tree is empty
            return nullptr;

        if (root == nullptr) // If no argument is passed,
            root = head;     // the search defaults to starting from head

        node tmp = root; // traversal variable
        while (tmp->right != nullptr)
            tmp = tmp->right; // find the last right leaves
        return tmp;           // return the result
    }

    // find the minimum element from a root(dafault is head) in tree
    node minimum(node root = nullptr) // dafault passing
    {
        if (head == nullptr) // cant find if the tree is empty
            return nullptr;

        if (root == nullptr) // If no argument is passed,
            root = head;     // the search defaults to starting from head

        node tmp = root; // traversal variable
        while (tmp->left != nullptr)
            tmp = tmp->left; // find the last right leave
        return tmp;          // return the result
    }

    // traversal the tree:
    // display tree
    void show_tree(const node root)
    {
        if (root == nullptr)
            return;
        // traversal from the last left leaves to the last right leaves
        show_tree(root->left);
        cout << root->data << ' '; // process
        show_tree(root->right);
    }

    // search a node in tree
    // from head
    node search_node(const int &val, node root)
    {
        if (root == nullptr) // root isnt appear in tree
            // had considered all of node at tree
            return nullptr;
        else if (root->data == val) // found
            return root;

        // have not considered all of node
        // considered the next node
        else if (root->data > val)
            return search_node(val, root->left);
        else
            return search_node(val, root->right);
    }

    // get the head node
    const node get_head() { return head; }

    // insert a node to the tree
    // new node insert at the leaves
    // the element can be doublicated
    void push(const int &val)
    {
        ++Size; // increase the size of tree
        // make new node
        node newNode = new Btree(val);

        // if the tree the empty
        // new node will be become the root of the tree
        if (head == nullptr)
        {
            head = newNode; // newNode become the head of tree
            return;         // stop insert process
        }

        // if tree is non-empty
        node par = nullptr;    // parent of newNode
        node cur = head;       // traversal var
        while (cur != nullptr) // cur go to the leaves
        {
            par = cur;           // update parent of newNode
            if (val < cur->data) // go to the next node
                cur = cur->left;
            else
                cur = cur->right;
        }

        newNode->parent = par; // parent of newNode
        if (val < par->data)   // find the position of newNode
            par->left = newNode;
        else
            par->right = newNode;
        // newNode is one of the leaves in the tree now
    }

    // delete a node in tree
    void pop(const int &val)
    {
        // find the node will be deleted
        node deleted_node = search_node(val, get_head());
        // if can not find
        if (deleted_node == nullptr)
        {
            cout << "can't delete " << val << "!\n";
            return;
        }
        cout << "deleted " << val << "!\n";

        --Size; // decrease the size of tree
        // if found
        // if deleted_node is parent of a leaves or is a leaves (*)
        if (deleted_node->left == nullptr)
            deleted_node = deleted_node->right;
        else if (deleted_node->right == nullptr)
            deleted_node = deleted_node->left;

        // if not (*)
        // replace node by the minimum element of subtree which root is deleted_node->right
        // (the smallest elememt which is bigger than delete_node)
        else
        {
            node replace_node = minimum(deleted_node->right);
            // if parent of replace node isnt deleted_node
            /*
            *example:
                    deleted_node
                    /   ^      \
                left    |    right
                  /\    |    /     \
                       replace_node  <---
                            \           |
                        right_child  --'
                             \....
            */
            // => we must replace the replace_node by its right child
            if (replace_node->parent != deleted_node)
            {
                replace(replace_node, replace_node->right);
                // now replace_node position in the tree is its right child

                // change replace node
                // gan' nhanh' right chilf of deleted node cho replace node
                replace_node->right = deleted_node->right;
                replace_node->right->parent = replace_node;
            }
            // then replace the deleted_node by replace_node
            replace(deleted_node, replace_node);
            replace_node->left = deleted_node->left;
            replace_node->left->parent = replace_node;
        }
    }
    // end of pop
}; //* end of binary_search_tree class

int main()
{
    binary_search_tree btree;
    // push
    btree.push(1);
    btree.push(3);
    btree.push(0);
    btree.push(3);
    btree.push(2);
    btree.push(0);
    btree.push(0);
    btree.push(4);

    // get_size()
    cout << "btree.get_size() : " << btree.get_size() << '\n';

    // traversal()
    cout << "\nbtree.show_tree(btree.get_head()) : ";
    btree.show_tree(btree.get_head());

    // maximum(), minimum()
    cout << "\n\nbtree.maximum() : " << btree.maximum()->data << '\n';
    cout << "btree.minimum(): " << btree.minimum()->data << '\n';

    // search()
    if (btree.search_node(6, btree.get_head()))
        cout << "\nbtree.search_node(6, btree.get_head()) : Found 6\n";
    else
        cout << "\nbtree.search_node(6, btree.get_head()) : Not Found 6\n";
    if (btree.search_node(3, btree.get_head()))
        cout << "btree.search_node(3, btree.get_head()) : Found 3\n";
    else
        cout << "btree.search_node(3, btree.get_head()) : Not Found 3\n";

    // pop()
    cout << "\nbtree.pop(val) :\n";
    btree.pop(5); // console: "cant delete !"
    btree.pop(2); // success
    btree.pop(3); // success

    // get_size()
    cout << "\nbtree.get_size() : " << btree.get_size() << '\n';

    // show tree after deleted
    cout << "\nbtree.show_tree(btree.get_head()) : ";
    btree.show_tree(btree.get_head());

    // isEmpty()
    cout << "\n\nbtree.isEmpty() : ";
    if (btree.isEmpty())
        cout << "Tree is Empty\n";
    else
        cout << "Tree is Not Empty\n";

    cin.get();
    return 0;
}