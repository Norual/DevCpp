#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ItemType;
struct ContactInfo
{
	String Name;
	string Number;
	string EmailAdd;
}
struct TreeNode
{
       ItemType info;
       TreeNode* left;
       TreeNode* right;
};

class TreeType
{
        
		friend void Destroy(TreeNode*&);
        friend void Insert(TreeNode*&, ItemType, char);
        friend void Print(TreeNode*);

        public:
        TreeType();
        ~TreeType();
        void InsertItem(ItemType);
        void PrintTree();
       /* bool IsEmpty()const;
        int NumberOfNodes()const;
        void RetrieveItem(ItemType&,bool& found);
        void InsertItem(ItemType);
        void DeleteItem(ItemType);
        void PrintTree() const;
        */
        private:
        TreeNode * root;
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

void Insert(TreeNode*& tree, ItemType item, char ID)
{
     if (tree == NULL)
     { // base case
       tree = new TreeNode;
       tree->right = NULL;
       tree->left = NULL;
       tree->info = item;
       cout<<ID<<item<<endl;
     }
     else if (item < tree->info)
     {
       //cout<<tree->info<<endl;
       Insert(tree->left, item, '<');
     }
     else
     {
       //cout<<tree->right<<endl;
       Insert(tree->right, item, '>');
     }
}

void Print(TreeNode* tree)
{
     if (tree != NULL)
     {
              cout<<"L";
              Print(tree->left);
              cout<<"/"<<tree->info<<" ";
              cout<<"R";
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

void TreeType::InsertItem(ItemType item)
{
	Insert(root, item, '$');
}

void TreeType::PrintTree()
{
	Print(root);
}

int main()
{
   
}

