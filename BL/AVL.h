#include <iostream>
#include "BinaryTree.h"
#include <fstream>
#include <sstream>
#include <conio.h>
#include <stack>
#include "E:\Semester3\DSA-Lab\Project\Struct\TreeNode.cpp"
using namespace std;

class AVL : BinaryTree
{
public:
    TreeNode *root;
    TreeNode *createNode(int idx, string fName, string lName, string custID, string companyName, string cityName, string countryName, string phone1, string phone2, string email, string subDate, string website)
    {
        TreeNode *node = new TreeNode();
        node->idx = idx;
        node->fName = fName;
        node->lName = lName;
        node->custID = custID;
        node->companyName = companyName;
        node->cityName = cityName;
        node->countryName = countryName;
        node->phone1 = phone1;
        node->phone2 = phone2;
        node->email = email;
        node->subDate = subDate;
        node->website = website;
        return node;
    }
    void ReadFromFile(string filename)
    {
        ifstream file;
        file.open(filename);
        string line;
        while (getline(file, line))
        {
            int index;
            string custID, fName, lName, companyName, cityName, countryName, phone1, phone2, email, subDate, website;
            string idx;
            stringstream lineStream(line);
            getline(lineStream, idx, ',');
            index = stoi(idx);
            getline(lineStream, custID, ',');
            getline(lineStream, fName, ',');
            getline(lineStream, lName, ',');
            getline(lineStream, companyName, ',');
            getline(lineStream, cityName, ',');
            getline(lineStream, countryName, ',');
            getline(lineStream, phone1, ',');
            getline(lineStream, phone2, ',');
            getline(lineStream, email, ',');
            getline(lineStream, subDate, ',');
            getline(lineStream, website, ',');
            TreeNode *node = createNode(index, custID, fName, lName, companyName, cityName, countryName, phone1, phone2, email, subDate, website);
            node->height = 1;
            // Node Created
            insertionWithRotation(node);
        }
        file.close();
    }

    // this function return hieght
    int height(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    // this function subtract the hieght of left subtree from right subtree and return balance factor
    int getBalanceFactor(TreeNode *node)
    {
        if (node == NULL)
            return 0;

        return height(node->left) - height(node->right);
    }

    // this function return maximum between two numbers
    int max(int val1, int val2)
    {
        if (val1 > val2)
        {
            return val1;
        }
        return val2;
    }
    // this function performs right rotation of the node x with its left child
    TreeNode *rightRotate(TreeNode *x)
    {
        TreeNode *y = x->left;
        TreeNode *T2 = y->right;
        y->right = x;
        x->left = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    // this function performs left rotation of the node x with its right child
    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    // this function
    stack<TreeNode *> insert(TreeNode *node)
    {
        stack<TreeNode *> s;
        if (root == NULL)
        {
            root = node;
            return s;
        }
        TreeNode *prev = root;
        TreeNode *next = root;
        while (next != NULL)
        {
            prev = next;
            s.push(next);
            if (node->idx < prev->idx)
                next = prev->left;
            else
                next = prev->right;
        }
        s.push(node);
        if (node->idx >= prev->idx)
            prev->right = node;
        else
            prev->left = node;
        return s;
    }

    void rotate(stack<TreeNode *> s, TreeNode *node)
    {
        TreeNode *temp;
        TreeNode *temp1;
        while (!s.empty())
        {
            temp = s.top();
            bool isBalanceChanged = false;
            temp->height = max(height(temp->left), height(temp->right)) + 1;
            int balanceFactor = getBalanceFactor(temp);
            if (balanceFactor > 1)
            {
                if (node->idx < temp->left->idx)
                    temp1 = rightRotate(temp);
                else if (node->idx > temp->left->idx)
                {
                    temp->left = leftRotate(temp->left);
                    temp1 = rightRotate(temp);
                }
                isBalanceChanged = true;
            }
            if (balanceFactor < -1)
            {
                if (node->idx > temp->right->idx)
                    temp1 = leftRotate(temp);
                else if (node->idx < temp->right->idx)
                {
                    temp->right = rightRotate(temp->right);
                    temp1 = leftRotate(temp);
                }
                isBalanceChanged = true;
            }
            s.pop();
            if (isBalanceChanged)
            {
                if (s.empty())
                    root = temp1;
                else
                {
                    if (s.top()->left == temp)
                        s.top()->left = temp1;
                    else
                        s.top()->right = temp1;
                }
            }
        }
    }

    void insertionWithRotation(TreeNode *node)
    {
        stack<TreeNode *> s = insert(node);
        rotate(s, node);
    }

    void SwapNode(TreeNode *node1, TreeNode *node2)
    {
        node1->idx = node2->idx;
        node1->custID = node2->custID;
        node1->fName = node2->fName;
        node1->lName = node2->lName;
        node1->companyName = node2->companyName;
        node1->cityName = node2->cityName;
        node1->countryName = node2->countryName;
        node1->phone1 = node2->phone1;
        node1->phone2 = node2->phone2;
        node1->email = node2->email;
        node1->subDate = node2->subDate;
        node1->website = node2->website;
    }
    bool DeleteNodeAVL(TreeNode *node)
    {
        TreeNode *p = NULL;
        TreeNode *temp;
        temp = node->right;
        stack<TreeNode *> st;
        st.push(temp);
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
            st.push(temp);
        }
        if (p != NULL)
        {
            p->left = temp->right;
        }
        else
        {
            node->right = temp->right;
        }
        SwapNode(node, temp);
        delete temp;
        rotate(st, node);
        return true;
    }
};