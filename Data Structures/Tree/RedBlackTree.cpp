//* Data Structure: Red Black Tree (RBT)
/*
* properties:
    - color: only black or red
    - The length of the path from the root to any leaf is not more than twice that of any other
    - the number black node in each path is the same
    - color of root always is black
    - if a node is red, then its childs will be black
*/
#include <iostream>
#include <vector>
using namespace std;

#define red 0
#define black 1

struct Node
{
    int data;
    bool color;
    Node *parent, *left, *right;
    // new node
    Node(int val) : data(val), color(red), parent(nullptr), left(nullptr), right(nullptr) {}
};

typedef Node *node;

class RedBlackTree
{
private:
    node root, nil; // T.root and T.nil
    int len;        // T.size()

    // rotate
    void left_rotate(node x)
    {
        /* left_rotate(a)
            a                   c
         b/    \c       =>   a/   \e
            d/    \e       b/ \d
       */
        node x_child = x->right;
        x->right = x_child->left; // d become a's child
        if (x_child->left != nil) // if d is a node
            x_child->left->parent = x;

        x_child->parent = x->parent; // c replace a
        if (x->parent == nil)
            root = x_child;
        else if (x == x->parent->left)
            x->parent->left = x_child;
        else
            x->parent->right = x_child;

        x_child->left = x;
        x->parent = x_child; // a become c's child
    }
    void right_rotate(node x) // same with left_rotate(Node *)
    {
        node x_child = x->left;
        x->left = x_child->right;
        if (x_child->right != nil)
            x_child->right->parent = x;

        x_child->parent = x->parent;
        if (x->parent == nil)
            root = x_child;
        else if (x == x->parent->left)
            x->parent->left = x_child;
        else
            x->parent->right = x_child;

        x_child->right = x;
        x->parent = x_child;
    }

    // helped function of insert
    void RB_insert_fixup(node x)
    {
        node uncle(nil); // uncle of x (x.parent's sibling)

        while (x->parent->color == red) // x.color = x.parent.color = red -> violating
        {
            // 3 case of violation
            // x.uncle = red
            // x.uncle = black (triangle) -> line
            // x.uncle = black (line)
            if (x->parent->parent->left == x->parent) // find x.uncle
            {
                uncle = x->parent->parent->right;
                if (uncle->color == red) // case 1 => recolor(x.p, x.p.p, x.u)
                {
                    x->parent->color = black;
                    uncle->color = black;           // recolor x.p, x.u
                    x->parent->parent->color = red; // recolor x.p.p

                    // now x.parent.parent.color is red -> can make violation
                    x = x->parent->parent;
                }
                else // case 2.1 & case 2.2
                {
                    if (x == x->parent->right) // case 2.1
                    {
                        x = x->parent;
                        /*     triangle
                                x.p.p (black)                   x.p.p(black)
                                /                                   /
                            x->p (red)                =>        x (red)     =>violation
                            /  \                         x.p (red)/\         (case 2.2 - line)
                                x(red)                        /\
                        */
                        left_rotate(x);
                    }
                    // case 2.2
                    // recolor(x.p, x.p.p)
                    x->parent->color = black;
                    x->parent->parent->color = red;
                    // rotate(x.p.p)
                    right_rotate(x->parent->parent);
                }
            }
            else
            {
                uncle = x->parent->parent->left;

                if (uncle->color == red)
                {
                    x->parent->color = uncle->color = black;
                    x->parent->parent->color = red;
                    x = x->parent->parent;
                }
                else
                {
                    if (x == x->parent->left)
                    {
                        x = x->parent;
                        right_rotate(x);
                    }
                    x->parent->color = black;
                    x->parent->parent->color = red;
                    left_rotate(x->parent->parent);
                }
            }
        }

        // ensure root always is a black node
        root->color = black;
    }

    // helped function for deletion
    void transplant(node u, node v) // replace node u by node v in tree
    {
        // v -> u.parent's child
        if (u == root)
            root = v;
        else if (u->parent->left == u)
            u->parent->left = v;
        else
            u->parent->right = v;

        // u.parent become v.parent
        v->parent = u->parent;
    }

    // fixup violation in deletion
    void RB_delete_fixup(node z)
    {
        node w(nil); // z's sibling
        while (z != root && z->color == black)
        {
            if (z->parent->left == z) // if z == its parent's left child
            // to find w position
            {
                w = z->parent->right;

                if (w->color == red) // case1, w is red -> its parent is black
                {
                    // recolor(w, z.p)
                    w->color = black;
                    z->parent->color = red;
                    // rotate(z.p)
                    left_rotate(z->parent);
                    w = z->parent->right; // find new sibling of z
                }                         // case 2 chac chan xay

                if (w->left->color == black && w->right->color == black) // case2.1
                {
                    // recolor(w) and continue check z.parent
                    w->color = red;
                    z = z->parent;
                }
                else // case 2.2 & case 2.3
                {
                    if (w->left->color == red) // case 2.2
                    {
                        // recolor(w, w.left)
                        w->color = red;
                        w->left->color = black;

                        // rotate(w) to such as case 2.3
                        right_rotate(w);
                        w = z->parent->right; // new sibling of z
                    }

                    // case 2.3 chac chan xay ra du case 2.2 co xay ra hay khong
                    // push z.parent.color to w.color
                    w->color = z->parent->color;
                    // make z.parent & w.right become black
                    z->parent->color = black;
                    w->right->color = black;
                    // rotate(z.p)
                    left_rotate(z->parent); // sau dong nay, cay da dam bao can bang

                    break; // end loop
                }
            }
            else // if z is its parent's right child
            // exchang "right" and "left"
            {
                w = z->parent->left;

                if (w->color == red) // case 1
                {
                    w->color = black;
                    z->parent->color = red;
                    right_rotate(z->parent);
                    w = z->parent->left;
                }
                // casw 2.1
                if (w->left->color == black && w->right->color == black)
                {
                    w->color = red;
                    z = z->parent;
                }
                else
                {
                    if (w->right->color == red) // case 2.2
                    {
                        w->right->color = black;
                        w->color = red;
                        left_rotate(w);
                        w = z->parent->left;
                    }
                    // case 2.3
                    w->color = z->parent->color;
                    z->parent->color = black;
                    w->left->color = black;
                    right_rotate(z->parent);
                    break;
                }
            }
        }

        root->color = black; // ensure that root always is a black node
    }

public:
    // constructor
    RedBlackTree()
    {
        this->len = 0;
        this->nil = new Node(0);
        this->nil->color = black;
        this->root = nil;
    }

    int Size() { return len; }        // T.size()
    bool Empty() { return len == 0; } // T.empty();
    node getRoot() { return root; }   // get root

    // traversal
    void showTree(node Root)
    {
        if (Root == nil)
            return;
        showTree(Root->left);      // show left subtree
        cout << Root->data << ' '; // show root
        showTree(Root->right);     // show right subtree
    }

    // search
    node search(node Root, int val)
    {
        if (Root == nil || Root->data == val)
            return Root;
        if (val < Root->data)
            return search(Root->left, val);
        else
            return search(Root->right, val);
    }

    // find minimum node in a tree
    node minimum(node Root)
    {
        node tmp = Root;
        while (tmp->left != nil)
            tmp = tmp->left;
        return tmp;
    }
    // find maximum node
    node maximum(node Root)
    {
        node tmp = Root;
        while (tmp->right != nil)
            tmp = tmp->right;
        return tmp;
    }

    // push new node to the tree at a leaf
    // new node always is red node
    void push(int val)
    {
        ++len; // increase T.size()

        node newNode = new Node(val); // newNode.data = val, newNode.color = red
        newNode->left = nil;
        newNode->right = nil;

        node par(nil), cur(root);
        // find parent of newNode
        while (cur != nil)
        {
            par = cur;
            if (val < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }

        newNode->parent = par;

        if (par == nil) // if Tree.empty()
            root = newNode;
        else if (val < par->data)
            par->left = newNode;
        else
            par->right = newNode;

        // fix violating
        // showTree(root);
        RB_insert_fixup(newNode);
    }

    void pop(int val)
    {
        node z = search(root, val); // deleted node
        if (z == nil)
            return; // if var is not in tree

        node y(nil), x(nil); // y replace z, x replace y
        bool original_color = z->color;

        // case 1: neu z chi co 1 con => replace it by its child
        // deleted color is z.color
        if (z->left == nil)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == nil)
        {
            x = z->left;
            transplant(z, z->left);
        }
        // case 2: z co day du 2 con
        // replace z by y = minimum(z.right)
        // deleted color is y.color
        else
        {
            y = minimum(z->right); // replace z's position
            // y's color will be romoved
            original_color = y->color;

            x = y->right; // x replace y's position

            if (y->parent == z)
                x->parent = y;
            else
            {
                transplant(y, y->right);
                y->right = z->right; // push right subtree of z to y.right
                y->right->parent = y;
            }
            transplant(z, y);  // replace z by y
            y->left = z->left; // push z.left_subtree to y.left
            y->left->parent = y;
            y->color = z->color; // push z.color to y.color
        }

        // if black node is deleted => violation
        if (original_color == black)
            RB_delete_fixup(x);

        --len; // decrease size of tree
        if (len == 0)
            root = nil;
    }
};

int menu();
void push_element(RedBlackTree &);
void pop_element(RedBlackTree &);
int process(RedBlackTree &);
int main() // main function
{
    int n;
    RedBlackTree rbt;
    while (process(rbt))
        system("cls");
    return 0;
}

void push_element(RedBlackTree &rbt)
{
    int n;
    cout << "enter number of element: ";
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    for (int &i : v)
        rbt.push(i);
    cout << "insert successfully\n";
}
void pop_element(RedBlackTree &rbt)
{
    int n;
    cout << "enter number of element: ";
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    for (int &i : v)
        rbt.pop(i);
    cout << "delete successfully\n";
}
int menu()
{
    int ops;
    cout << "------------------------------\n";
    cout << "1. push a new number\n";
    cout << "2. pop a number\n";
    cout << "3. get maximum element\n";
    cout << "4. get minimum element\n";
    cout << "5. get root\n";
    cout << "6. show red black tree\n";
    cout << "------------------------------\n";
    cout << "enter your option: ";
    cin >> ops;
    return ops;
}
int process(RedBlackTree &rbt)
{
    int n = menu();
    while (n < 1 || n > 6)
    {
        system("cls");
        n = menu();
    }
    if (n != 6)
    {
        switch (n)
        {
        case 1:
            push_element(rbt);
            break;
        case 2:
            pop_element(rbt);
            break;
        case 3:
            if (rbt.Empty())
                cout << "Empty tree\n";
            else
            {
                cout << "Maximum element in tree: ";
                cout << rbt.maximum(rbt.getRoot())->data << '\n';
            }
            break;
        case 4:
            if (rbt.Empty())
                cout << "Empty tree\n";
            else
            {
                cout << "Minimum element in tree: ";
                cout << rbt.minimum(rbt.getRoot())->data << '\n';
            }
            break;
        default:
            cout << "root of tree: " << rbt.getRoot()->data << '\n';
            cout << "color : " << (rbt.getRoot()->data ? "black\n" : "red\n");
            break;
        }
    }
    if (n == 6 && rbt.Empty())
        cout << "empty tree\n";
    if (!rbt.Empty())
    {
        cout << "\n\ncurrent list: ";
        rbt.showTree(rbt.getRoot());
    }

    cout << "\n\n\nBan co muon thuc hien tiep chuong trinh khong (1/0) : ";
    cin >> n;
    return n;
}
//* code by ducsjukapvippro
// 2:24am 07/03/24