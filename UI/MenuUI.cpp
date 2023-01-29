#include <iostream>
#include <conio.h>
using namespace std;

char FirstMenu()
{
    cout << "1. Binary Search Tree" << endl;
    cout << "2. AVL Tree" << endl;
    cout << "3. exit" << endl;
    char op;
    cin >> op;
    return op;
}
char SecondMenu()
{
    cout << "1. load 100 records" << endl;
    cout << "2. load 1000 records" << endl;
    cout << "3. load 10000 records" << endl;
    cout << "4. load 100000 records" << endl;
    cout << "5. back" << endl;
    char op;
    cin >> op;
    return op;
}
char ThirdMenu()
{
    cout << "1. Insert a New Record" << endl;
    cout << "2. Retrieve a Record" << endl;
    cout << "3. Update a Record" << endl;
    cout << "4. Delete a Record" << endl;
    cout << "5. Traverse the Tree" << endl;
    cout << "6. back" << endl;
    char op;
    cin >> op;
    return op;
}
char FourthMenu()
{
    cout << "1. Breadth First traversal" << endl;
    cout << "2. InOrder traversal" << endl;
    cout << "3. PostOrder traversal" << endl;
    cout << "4. PreOrder traversal" << endl;
    cout << "5. back" << endl;
    char op;
    cin >> op;
    return op;
}
TreeNode *Input()
{
    int index;
    string custID, fName, lName, company, city, country, phone1, phone2, email, subscription, website;
    cout << "Enter the index oƒ the customer: ";
    cin >> index;
    cout << "Enter the ID oƒ the customer: ";
    cin >> custID;
    cout << "Enter the First Name oƒ the customer: ";
    cin >> fName;
    cout << "Enter the Last Name oƒ the customer: ";
    cin >> lName;
    cout << "Enter the Comapany Name oƒ the customer: ";
    cin >> company;
    cout << "Enter the City oƒ the customer: ";
    cin >> city;
    cout << "Enter the Country oƒ the customer: ";
    cin >> country;
    cout << "Enter the Phone number 1: ";
    cin >> phone1;
    cout << "Enter the Phone number 2: ";
    cin >> phone2;
    cout << "Enter the Email: ";
    cin >> email;
    cout << "Enter the Subscription Date: ";
    cin >> subscription;
    cout << "Enter the Website url: ";
    cin >> website;
    TreeNode *node = createNode(index, custID, fName, lName, company, city, country, phone1, phone2, email, subscription, website);
    return node;
}
int IndexNumber()
{
    cout << "Enter the index number of the customer: " << endl;
    int idx;
    cin >> idx;
    return idx;
}
void Update(TreeNode *node)
{
    // cout << "Enter the index oƒ the customer: ";
    // cin >> node->index;
    cout << "Enter the ID oƒ the customer: ";
    cin >> node->custID;
    cout << "Enter the First Name oƒ the customer: ";
    cin >> node->fName;
    cout << "Enter the Last Name oƒ the customer: ";
    cin >> node->lName;
    cout << "Enter the Comapany Name oƒ the customer: ";
    cin >> node->company;
    cout << "Enter the City oƒ the customer: ";
    cin >> node->city;
    cout << "Enter the Country oƒ the customer: ";
    cin >> node->country;
    cout << "Enter the Phone number 1: ";
    cin >> node->phone1;
    cout << "Enter the Phone number 2: ";
    cin >> node->phone2;
    cout << "Enter the Email: ";
    cin >> node->email;
    cout << "Enter the Subscription Date: ";
    cin >> node->subscription;
    cout << "Enter the Website url: ";
    cin >> node->website;
    // return node;
}
void ScreenCls()
{
    cout << "\nEnter any key to go back...";
    getch();
    system("cls");
}