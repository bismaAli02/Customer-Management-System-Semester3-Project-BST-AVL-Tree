#include <iostream>
#include "BinaryTree.h"
#include <fstream>
#include <sstream>
#include <conio.h>
#include "E:\Semester3\DSA-Lab\Project\Struct\TreeNode.cpp"
using namespace std;

class BST : BinaryTree
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
            insert(node);
        }
        file.close();
    }
    void insert(TreeNode *node)
    {
        TreeNode *prev;
        TreeNode *next;
        next = root;
        prev = next;
        while (next != NULL)
        {
            prev = next;
            if (node->idx < prev->idx)
            {
                next = prev->left;
            }
            else
            {
                next = prev->right;
            }
        }
        if (node->idx >= prev->idx)
        {
            prev->right = node;
        }
        else
        {
            prev->left = node;
        }
    }

    bool deleteNode(int idx)
    {
        if (root == NULL)
        {
            root = NULL;
            return false;
        }
        if (root->idx == idx && root->left == NULL && root->right == NULL)
        {
            root = NULL;
            return true;
        }
        TreeNode *p = root;
        TreeNode *n = root;
        while (n != NULL && n->idx != idx)
        {
            p = n;
            if (idx < p->idx)
                n = p->left;
            if (idx >= p->idx)
                n = p->right;
        }
        if (n == NULL)
        {
            return false;
        }
        else if (n->left == NULL && n->right == NULL)
        {
            if (n == p->left)
                p->left = NULL;
            else
                p->right = NULL;
            delete n;
        }
        else if ((n->left == NULL && n->right != NULL) || (n->left != NULL && n->right == NULL))
        {
            TreeNode *curr;
            if (n->left == NULL)
                curr = n->right;
            else
                curr = n->left;
            if (n == root)
            {
                if (root->left == NULL)
                    root = root->right;
                else
                    root = root->left;
                return true;
            }
            if (p == root)
            {
                // root=curr;
                if (root->left == n)
                    root->left = curr;
                else
                    root->right = curr;
                delete n;
                return true;
            }
            if (n == p->left)
                p->left = curr;
            else
                p->right = curr;
            delete n;
        }
        else if (n->left != NULL && n->right != NULL)
        {
            TreeNode *q = NULL;
            TreeNode *temp;
            temp = n->right;
            while (temp->left != NULL)
            {
                q = temp;
                temp = temp->left;
            }
            if (q != NULL)
                q->left = temp->right;
            else
                n->right = temp->right;
            n->idx = temp->idx;
            delete temp;
        }
        return true;
    }
};