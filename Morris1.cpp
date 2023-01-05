#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
int main()
{
    Node *root = NULL;
    while (root != NULL)
    {
        Node *curr = root;
        Node *pred;
        if (curr->left == NULL)
        {
            curr = curr->right;
        }
        else
        {
            pred = curr->left;
        }
        while (pred->right && pred->right != curr)
        {
            pred = pred->right;
        }
        if (pred->right == NULL)
        {
            pred->right = curr;
        }
        else
        {
            pred->right = NULL;
            curr = curr->right;
        }
    }
}
