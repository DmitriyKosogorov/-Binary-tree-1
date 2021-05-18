#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
class TreeNode
{
private:
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	const int NONE = 0;
public:
	TreeNode()
	{
		value = NONE;
		left = NULL;
		right = NULL;
	}
	TreeNode(int name)
	{
		value = name;
		left = NULL;
		right = NULL;
	}
	int getvalue()
	{
		return this->value;
	}
	TreeNode* get_left()
	{
		return this->left;
	}
	TreeNode* get_right()
	{
		return this->right;
	}
	TreeNode* get_parent()
	{
		return this->parent;
	}
	void give_left(TreeNode* newLeft)
	{
		left = newLeft;
		return;
	}
	void give_right(TreeNode* newRight)
	{
		right = newRight;
		return;
	}
	void give_parent(TreeNode* newParent)
	{
		parent = newParent;
		return;
	}
	~TreeNode()
	{

	}
	friend class Tree;
};
class Tree
{
private:
	TreeNode root;
public:
	Tree(TreeNode first)
	{
		root.value = first.value;
		root.left = first.left;
		root.right = first.right;
	}
	void delete_tree(TreeNode* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
				delete_tree(node->left);
			if (node->right != NULL)
				delete_tree(node->right);
			delete node;
		}
	}
	~Tree()
	{
		//	delete_tree(&root);
	}
	TreeNode* get_root()
	{
		TreeNode* a = &root;
		return a;
	}
	void insert(TreeNode* a, TreeNode* b)
	{
		if (a->value == b->value)
		{
			return;
		}
		else
			if (a->value > b->value)
			{
				if (a->left == NULL)
				{
					a->left = b;
					b->parent = a;
					return;
				}
				else
					insert(a->left, b);
			}
			else
			{
				if (a->right == NULL)
				{
					a->right = b;
					b->parent = a;
					return;
				}
				else
					insert(a->right, b);
			}
	}
	TreeNode* search(TreeNode* a, int b)
	{
		if (a->value == b)
		{
			return a;
		}
		else
			if (a->value > b)
			{
				if (a->left == NULL)
				{
					cout << "Search have no results" << endl;
					return NULL;
				}
				else
					search(a->left, b);
			}
			else
			{
				if (a->right == NULL)
				{
					cout << "Search have no results" << endl;
					return NULL;
				}
				else
					search(a->right, b);
			}
	}
	void remove(TreeNode* elem)
	{
		TreeNode* paren = elem->parent;
		if (elem->left == NULL && elem->right == NULL)
		{
			if (paren->value > elem->value)
			{
				paren->left = NULL;
				delete elem;
			}
			else
			{
				paren->right = NULL;
				delete elem;
			}
		}
		else
			if (elem->left != NULL && elem->right == NULL)
			{
				if (paren->value > elem->value)
				{
					paren->left = elem->left;
					elem->left->parent = paren;
					//delete elem;
				}
				else
				{
					paren->right = elem->left;
					elem->left->parent = paren;
					//delete elem;
				}
			}
			else
				if (elem->left == NULL && elem->right != NULL)
				{
					if (paren->value > elem->value)
					{
						paren->left = elem->right;
						elem->right->parent = paren;
						//delete elem;
					}
					else
					{
						paren->right = elem->right;
						elem->right->parent = paren;
						//delete elem;
					}
				}
				else
				{
					TreeNode* next = elem->right;
					while (next->left != NULL)
						next = next->left;
					if (paren->value > elem->value)
					{
						TreeNode* saveleft = next->left;
						TreeNode* saveright = next->right;
						TreeNode* saveparent = next->parent;
						paren->left = next;
						next->parent = paren;
						next->left = elem->left;
						next->right = elem->right;
						next->right->parent = next;
						next->left->parent = next;
						elem->left = saveleft;
						elem->right = saveright;
						elem->parent = saveparent;
						if (saveleft != NULL)
							saveleft->parent = elem;
						if (saveright != NULL)
							saveright->parent = elem;
						if (saveparent->value > elem->value)
							saveparent->left = elem;
						else
							saveparent->right = elem;
						remove(elem);
						//delete elem;
					}
				}
	}
	void remove(int val)
	{
		TreeNode* elem = search(&root, val);
		if (elem == NULL)
		{
			return;
		}
		TreeNode* paren = elem->parent;
		if (elem->left == NULL && elem->right == NULL)
		{
			if (paren->value > elem->value)
			{
				paren->left = NULL;
				delete elem;
			}
			else
			{
				paren->right = NULL;
				delete elem;
			}
		}
		else
			if (elem->left != NULL && elem->right == NULL)
			{
				if (paren->value > elem->value)
				{
					paren->left = elem->left;
					elem->left->parent = paren;
					//delete elem;
				}
				else
				{
					paren->right = elem->left;
					elem->left->parent = paren;
					//delete elem;
				}
			}
			else
				if (elem->left == NULL && elem->right != NULL)
				{
					if (paren->value > elem->value)
					{
						paren->left = elem->right;
						elem->right->parent = paren;
						//delete elem;
					}
					else
					{
						paren->right = elem->right;
						elem->right->parent = paren;
						//delete elem;
					}
				}
				else
				{
					TreeNode* next = elem->right;
					while (next->left != NULL)
						next = next->left;
					if (paren->value > elem->value)
					{
						TreeNode* saveleft = next->left;
						TreeNode* saveright = next->right;
						TreeNode* saveparent = next->parent;
						paren->left = next;
						next->parent = paren;
						next->left = elem->left;
						next->right = elem->right;
						next->right->parent = next;
						next->left->parent = next;
						elem->left = saveleft;
						elem->right = saveright;
						elem->parent = saveparent;
						if(saveleft!=NULL)
							saveleft->parent = elem;
						if(saveright!=NULL)
							saveright->parent = elem;
						if (saveparent->value > elem->value)
							saveparent->left = elem;
						else
							saveparent->right = elem;
						remove(elem);
						//delete elem;
					}
				}
	}
	void print_elem(TreeNode* elem, int n,char c)
	{
		if (elem == NULL)
			return;
		n = n + 1;
		print_elem(elem->right, n,'/');
		for (int i = 0; i < n; i++)
			cout << "\t";
		cout <<c<< elem->value << endl;
		print_elem(elem->left,n,'\\');

	}
	void print_tree()
	{
		print_elem(&root,0,' ');
	}
};
int main()
{
	TreeNode a(40),b(12),c(45),d(3),e(99);
	Tree tree(a);
	tree.insert(tree.get_root(),&b);
	tree.insert(tree.get_root(), &c);
	tree.insert(tree.get_root(), &d);
	tree.insert(tree.get_root(), &b);
	tree.insert(tree.get_root(), &e);
	tree.print_tree();
	TreeNode* boo=tree.search(tree.get_root(), 12);
	if (boo != NULL)
		cout << "search successfull" << endl;
	tree.remove(12);
	cout << "removing element 12" << endl;
	tree.print_tree();
	return(0);
}