// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void topView(Node *root)
    {
        map<int, int> res;
        queue<pair<Node *, int>> q;
        int hd;
        Node *tmp = nullptr;
        q.push({root, 0});

        while (!q.empty())
        {
            tmp = q.front().first;
            hd = q.front().second;
            q.pop();

            if (!res[hd])
                res[hd] = tmp->data;
            if (tmp->left)
                q.push({tmp->left, hd - 1});
            if (tmp->right)
                q.push({tmp->right, hd + 1});
        }

        for (pair<int, int> x : res)
            cout << x.second << ' ';
    }
}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    return 0;
}
