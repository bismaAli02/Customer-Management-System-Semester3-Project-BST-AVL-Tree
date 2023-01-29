#include <iostream>
#include "E:\Semester3\DSA-Lab\Project\Struct\TreeNode.cpp"
#include <queue>
using namespace std;

class BinaryTree
{
public:
    TreeNode *search(TreeNode *root, int idx)
    {
        TreeNode *temp;
        temp = root;
        while (temp->idx != idx)
        {
            if (temp->idx > idx)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (temp->idx == idx)
        {
            return temp;
        }
        return NULL;
    }

    void bfs(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->idx;
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    void preOrder(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->idx;
        preOrder(node->left);
        preOrder(node->right);
    }
    void postOrder(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->idx;
    }

    void InOrder(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        InOrder(node->left);
        cout << node->idx;
        InOrder(node->right);
    }
};