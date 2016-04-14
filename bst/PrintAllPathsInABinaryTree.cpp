/*
Write a program to print all paths in a binary tree starting from the root
The approach:-
Initialize an array with size as maximum depth of the tree.

Fill the node details in this array as we traverse the tree.

If leaf node is reached a path is traversed and print the path.

Recursively scan the left and right sub tree.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
	private:
	int value;	
	public:
		Node* right;
		Node* left;
		Node(int v){value=v; right=NULL; left=NULL;}
		int getValue(){return value;}
};

class bst{
	public:
	Node* root;
	bst(vector<int> array){
		root=new Node(array[0]);
		for(int i=1;i<array.size();i++){
			Node* ptr=root;
			while(true){
				if(array[i]<ptr->getValue()){
					if(ptr->left==NULL){
						ptr->left=new Node(array[i]);
						break;
					}
					else
						ptr=ptr->left;	
				}
				if(array[i]>ptr->getValue()){
					if(ptr->right==NULL){
						ptr->right=new Node(array[i]);
						break;
					}
					else
						ptr=ptr->right;
				}
			
			}
		}
	}

};


void printBst(bst *tree){
	queue<Node*> q;
	q.push(tree->root);
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			cout<<q.front()->getValue()<<" ";
			if(q.front()->left!=NULL)
				q.push(q.front()->left);
			if(q.front()->right!=NULL)
				q.push(q.front()->right);
			q.pop();
		}
		cout<<endl;
	}
}

vector<string> findPaths(Node* root, string path, vector<string> paths){
	if(root->right==NULL && root->left==NULL){
		path+=to_string(root->getValue());
		paths.push_back(path);
		return paths;
	}
	if(root->right!=NULL)
		paths=findPaths(root->right, path+to_string(root->getValue())+"-", paths);
	if(root->left!=NULL)
		paths=findPaths(root->left, path+to_string(root->getValue())+"-", paths);

	return paths;
}

int main(){
	vector<int> list;
	list.push_back(4);
	list.push_back(2);
	list.push_back(6);
	list.push_back(1);
	list.push_back(3);
	list.push_back(5);
	list.push_back(7);

	bst* tree=new bst(list);
	printBst(tree);
	cout<<endl;
	vector<string> paths;
	paths=findPaths(tree->root, "", paths);

	for(int i=0;i<paths.size();i++)
		cout<<paths[i]<<endl;

	return 0;
}