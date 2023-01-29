#include <iostream>
#include <fstream>
using namespace std;

struct TreeNode
{
    int idx;
    string fName;
    string lName;
    string custID;
    string companyName;
    string cityName;
    string countryName;
    string phone1;
    string phone2;
    string email;
    string subDate;
    string website;
    int height;
    TreeNode *left;
    TreeNode *right;
};

// TreeNode *createNode(int idx, string fName, string lName, string custID, string companyName, string cityName, string countryName, string phone1, string phone2, string email, string subDate, string website)
// {
//     TreeNode *node = new TreeNode();
//     node->idx = idx;
//     node->fName = fName;
//     node->lName = lName;
//     node->custID = custID;
//     node->companyName = companyName;
//     node->cityName = cityName;
//     node->countryName = countryName;
//     node->phone1 = phone1;
//     node->phone2 = phone2;
//     node->email = email;
//     node->subDate = subDate;
//     node->website = website;
//     return node;
// }
