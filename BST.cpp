#include <iostream>
#include <vector>
using namespace std;
class nodeBST
{
	int key;
	nodeBST *lft, *rgt;
	
	public:
		nodeBST(): key(0), lft(NULL), rgt(NULL)
		{ }
		nodeBST(int value)
		{
			key = value;
			lft = rgt = NULL;
		}
		
		
		nodeBST* insertFunc(nodeBST*, int);

		bool search_new(nodeBST  *root, int val);      
};

nodeBST* nodeBST ::insertFunc(nodeBST* root, int value)
{
	if (!root)
	{
		return new nodeBST(value);
	}
	if (value > root->key)
	{
		root->rgt = insertFunc(root->rgt, value);
	}
	else
	{
		root->lft = insertFunc(root->lft, value);
	}
	return root;
}

bool nodeBST ::search_new(nodeBST  *root, int val) {
    if (root == NULL)
        return false;
    else
		if (root->key == val)
        	return true;
    	else
    		if (root->key < val)
        		return search_new(root->rgt, val);
    		else 
        		return search_new(root->lft, val);
}

int main()
{
	int n = 1000;                        ///////// size of elements vector                  
	vector <int> elements  ;
	
	for(int i = 0; i< n; i++)            /////////inputing 0 to 1000 to the elements vector as dummy data
	{
		elements.push_back(n-i);
	}
	
	//data insert to tree
	nodeBST node, *root = NULL;
	root = node.insertFunc(root, elements[0]);
	
	for(int i = 1; i < n ; i++)
	{
		node.insertFunc(root, elements[i]);
	}
	
	//searching function
	bool find_element = node.search_new(root, 3);       ///////// pass the value to be searched like-> 9
	cout<<find_element;
	
	return 0;

}
