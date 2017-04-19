#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

typedef int ItemType;
struct ContactInfo
{
	string Name;
	string Number;
	string Email;
};

struct TreeNode
{
       ContactInfo info;
       TreeNode* left;
       TreeNode* right;
};

class TreeType
{
		friend void Destroy(TreeNode*&);
        friend void Insert(TreeNode*&, ContactInfo, char);
        friend void Print(TreeNode*);

        public:
        TreeType();
        ~TreeType();
        void InsertItem(ContactInfo);
        void PrintTree();
       /* bool IsEmpty()const;
        int NumberOfNodes()const;
        void RetrieveItem(ItemType&,bool& found);
        void InsertItem(ItemType);
        void DeleteItem(ItemType);
        void PrintTree() const;
        */
        private:
        TreeNode* root;
};

void Destroy(TreeNode*& tree)
{
     if(tree != NULL)
     {
           Destroy(tree->left);
           Destroy(tree->right);
           delete tree;
     }
}

void Insert(TreeNode*& tree, ContactInfo item, char ID)
{
     if (tree == NULL)
     {
       tree = new TreeNode;
       tree->info = item;
       tree->right = NULL;
       tree->left = NULL;
     }
     else if (item.Name.compare(tree->info.Name) < 0)
     {
       Insert(tree->left, item, '<');
     }
     else
     {
       Insert(tree->right, item, '>');
     }
}

void Print(TreeNode* tree)
{
     if (tree != NULL)
     {
              Print(tree->left);
              cout<<endl<<endl;
              cout<<"Name: "<<tree->info.Name<<endl;
              cout<<"Phone No.: "<<tree->info.Number<<endl;
              cout<<"Email Address: "<<tree->info.Email<<endl;
              Print(tree->right);
     }
}


TreeType::TreeType()
{
   root = NULL;
}

TreeType::~TreeType()
{
	Destroy(root);
}

void TreeType::InsertItem(ContactInfo item)
{
	Insert(root, item, '$');
}

void TreeType::PrintTree()
{
	Print(root);
}


int main()
{
   char option = '1';
   TreeType b3;
   
   while(option != '0')
   {
    system("CLS");
    cout<<"Select an option below:"<<endl;
    cout<<"1 - Show All Contacts"<<endl;
    cout<<"2 - Add a Contact"<<endl;
    cout<<"3 - Remove a Contact"<<endl;
    cout<<"0 - Exit"<<endl;
    cout<<"What do you want to do? ";
    option = getche();
    
    cout<<endl;
    cout<<endl;
    
    ContactInfo contact;
    
    switch(option)
    {
                  case '1': 
                       cout<<"Show All Contacts"<<endl;
                       b3.PrintTree();
                       break;
                  case '2': 
                       cout<<"Add a Contact"<<endl;
                       cout<<"Name: ";
                       cin>>contact.Name;
                       cout<<"Phone No.: ";
                       cin>>contact.Number;
                       cout<<"Email Address: ";
                       cin>>contact.Email;
                       
                       b3.InsertItem(contact);
                       cout<<endl<<endl<<"Contact Successfully Added! "<<endl;
                       cout<<"Name: "<< contact.Name<<endl;
                       cout<<"Phone No.: "<< contact.Number<<endl;
                       cout<<"Email Address: "<< contact.Email<<endl;
                       break;
                  case '3': 
                       cout<<"Remove Contact"<<endl;
                       break;
                  default:  break;
    
   }
   
   getch();
   
   }   
}

