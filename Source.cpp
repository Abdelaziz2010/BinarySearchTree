#include <iostream>
#include<exception>
using namespace std;
template <class T>
struct Node
{
	Node(T value)
	{
		this->value = value;
		left = right = NULL;
	}
	T value;
	Node* left;
	Node* right;
};
template<class T>
class BST
{
private:
	Node<T>* root;
public:
	BST()
	{
		root = NULL;
	}
	~BST()
	{

	}
	void Add(T item)
	{
		if (root == NULL)
		{
			Node<T>* n = new Node<T>(item);
			root = n;
		}
		else
		{
			Node<T>* temp = root;
			while (temp != NULL)
			{
				if (temp->value == item)
				{
					throw exception("Invalid item!!");
				}
				else if (temp->value < item)  //add in right side
				{
					if (temp->right != NULL)
					{
						temp = temp->right;   //go to the next node
					}
					else if (temp->right == NULL)
					{
						Node<T>* n = new Node<T>(item);
						temp->right = n;
						break;
					}
				}
				else if (temp->value > item)  //add in left side
				{
					if (temp->left != NULL)
					{
						temp = temp->left;   //go to the next node
					}
					else if (temp->left == NULL)
					{
						Node<T>* n = new Node<T>(item);
						temp->left = n;
						break;
					}
				}
			}
		}

	}
	bool Exist(T item)
	{
		Node<T>*temp =root;
		while (temp != NULL)
		{
			if (temp->value == item)
			{
				return true;
			}
			else if (temp->value < item)
			{
				temp = temp->right;
			}
			else if (temp->value > item)
			{
				temp = temp->left;
			}
		}
		return false;
	}
};
int main()
{
	BST<int> s;
	s.Add(8);
	s.Add(3);
	s.Add(10);
	s.Add(1);
	s.Add(6);
	s.Add(14);
	s.Add(4);
	s.Add(7);
	s.Add(13);

	cout <<"is the number exist "<<s.Exist(11);

	return 0;
}
