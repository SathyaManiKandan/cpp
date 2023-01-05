#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = createBST(root->right, d);
        //  cout << d << " has been put in right side 0f " << root->data << endl;
    }
    if (d < root->data)
    {
        root->left = createBST(root->left, d);
        // cout << d << " has been put in left side 0f " << root->data << endl;
    }
    return root;
}
void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}
int mini(Node *root)
{
    if (root == NULL)
        return -1;
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
Node *deletenode(Node *root, int d)
{
    if (root == NULL)
        return NULL;
    if (root->data == d)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root->right;
            return temp;
        }
        else
        {
            int min = mini(root->right);
            root->data = min;
            root->right = deletenode(root->right, min);
            return root;
        }
        return root;
    }
    if (root->data > d)
    {
        deletenode(root->left, d);
        return root;
    }
    else
    {
        deletenode(root->right, d);
        return root;
    }
}
Node *findnodekey(Node *root, int key)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (root->data = key)
        {
            return root;
        }
        else if (root->data > key)
        {
            temp = root->left;
        }
        else
            temp = root->right;
    }
}
void pushroot(Node *root)
{
    stack<Node *> s;
    s.push(root);
    Node *temp;
    while (temp->left)
    {
        s.push(temp);
        temp = temp->left;
    }
}
int next()
{
    Node
}

int main()
{
    Node *root = NULL;
    cout << "Enter value for BST" << endl;
    int d;
    cin >> d;
    while (d != -1)
    {
        root = createBST(root, d);
        cout << "Enter the data" << endl;
        cin >> d;
    }
    levelordertraversal(root);
    cout << "Level Order Traversal" << endl;
    int min;
    min = mini(root);
    cout << "Minimum element " << min << endl;

    // int num;
    // cout << "Enter number for deletion " << endl;
    // cin >> num;
    // cout << "Level Order traversal" << endl;
    // deletenode(root, num);
    // cout << "Level Order traversal after deletion" << endl;
    Node *nodekey = findnodekey(root, 5);
    cout << nodekey->data << endl;
    int succ = mini(nodekey->right);
    cout << succ << endl;

    // levelordertraversal(root);
}