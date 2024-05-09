#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

typedef Node *node;

node insert(node root, int data)
{
    if (root == nullptr)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void traversal(node root)
{
    if (root == nullptr)
        return;
    cout << root->data << ' ';
    traversal(root->left);
    traversal(root->right);
}

void left_rotate(node &root)
{
    if (root == nullptr || root->right == nullptr)
        return;
    node newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;

    root = newroot;
}
int main()
{
    node root = nullptr;

    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 20);
    traversal(root);
    cout << '\n';
    left_rotate(root);
    traversal(root);
    return 0;
}