/*

Edited By: Jordan Osman

e-mail: jo982114@ohio.edu

Description: Binary Tree converted into an AVL tree 

10/3/2016

*/


#include <iostream>
#include "binary.h"
using namespace std;






void BinaryTree::insert(const int key) {

	root_ = insert_helper(key, root_);

}

BinaryNode* BinaryTree::insert_helper(const int key, BinaryNode* node) {
					
	if(node == NULL){			//ready to insert
		node = new BinaryNode(key);
		return node;
	}

	else if(key < node -> key){					//going down left side of tree
		node -> left = insert_helper(key, node -> left);
		node = balance_tree(node);
	}

	else if(node -> key <= key){
		node -> right = insert_helper(key, node -> right);	//going down right side
		node = balance_tree(node);
	}
		

	return node;

}


void BinaryTree::remove(const int key) {

	if(root_ == NULL)	
		return;

	root_ = real_remove(key, root_);

}




void BinaryTree::print_keys() const {
	print_keys_helper(root_);
	cout << endl;
}

void BinaryTree::print_keys_helper(BinaryNode* node) const {
	if (node == NULL)
		return;

	print_keys_helper(node->left);
	cout << node->key << " ";
	print_keys_helper(node->right);
}

void BinaryTree::print_heights() {

	print_height_helper(root_);			
}

void BinaryTree::print_height_helper(BinaryNode* ptr){

	if(ptr == NULL)
		return;

	print_height_helper(ptr -> left);		//print height of left tree
	cout << Tree_Height(ptr) << " ";
	print_height_helper(ptr -> right);		//print height of right tree
	return;					
}

BinaryNode* BinaryTree::real_remove(int key, BinaryNode* parent){

	
	


	if(key < parent -> key){
		parent -> left = real_remove(key, parent -> left);		
		parent = balance_tree(parent);
	}

	else if (key > parent -> key){
		parent -> right = real_remove(key, parent -> right);
		parent = balance_tree(parent);		
	}


	BinaryNode* remover = parent;

	
	if(parent == NULL){
		delete parent;	//no children
	}
	

	if(parent -> left == NULL && parent -> right){	//nothing in left, something in right of what i am trying to delete
		parent = remover -> right;
		delete remover;
		parent = balance_tree(parent);

	}

	if(parent -> right == NULL && parent -> left){ //nothing in right, something in left of what i am trying to delete
		parent = remover -> left;
		delete remover;
		parent = balance_tree(parent);
	}
		

	if(remover -> left != NULL && remover -> right != NULL){	//2 children 

		BinaryNode* tmp = parent -> right;	//tmp variable points at right side of tree
				
		parent = remover -> left;	//parent == left which is still connected to previous node

		delete remover;			//delete what we want to delete
								
		if(parent -> right == NULL)		//since nothing is in the right i can attach the right side of the tree to the right of this 
							//node because it is still larger than the current node
			parent -> right = tmp;

		else
			while(parent -> right)			//there is something in the tree, go until null, then attach temp
				parent = parent -> right;
		

		parent -> right = tmp;

		parent = balance_tree(parent);		

	}

	return parent;

	
}


							//four types of rotations utilizing swap esque algorithms
BinaryNode* BinaryTree::rr_rotation(BinaryNode* ptr){

	BinaryNode *tmp;				
	tmp = ptr -> right;
	ptr -> right = tmp -> left;
	tmp -> left = ptr;
	return tmp;

}

BinaryNode* BinaryTree::ll_rotation(BinaryNode* ptr){

	BinaryNode *tmp;
	tmp = ptr -> left;
	ptr -> left = tmp -> right;
	tmp -> right = ptr;
	return tmp;
}


BinaryNode* BinaryTree::lr_rotation(BinaryNode* ptr){

	BinaryNode *tmp;
	tmp = ptr -> left;
	ptr -> left = rr_rotation(tmp);
	return ll_rotation(ptr);
}

BinaryNode* BinaryTree::rl_rotation(BinaryNode* ptr){

	BinaryNode *tmp;
	tmp = ptr->right;
	ptr->right = ll_rotation(tmp);
	return rr_rotation(ptr);

}

int BinaryTree::Tree_Height(BinaryNode* ptr){

	if(ptr == NULL)		//height of 0
		return 0;

	else										//utilizing c++ pre defined max function 
		return 1 + max(Tree_Height(ptr -> left), Tree_Height(ptr -> right));

}


int BinaryTree::balance_factor(BinaryNode *ptr){
								
	int height_left = Tree_Height(ptr -> left);		//returns the balance factor
	int height_right = Tree_Height(ptr -> right);
	int bf = height_left - height_right;
	return bf;
}

BinaryNode* BinaryTree::balance_tree(BinaryNode* ptr){		
								//balances the actual tree utilizing my four rotation functions
	int bf = balance_factor(ptr);
	if (bf > 1){
		if(balance_factor(ptr -> left) > 0)
			ptr = ll_rotation(ptr);

		else
			ptr = lr_rotation(ptr);
	}
	
	else if (bf < -1){
		if(balance_factor(ptr -> right) > 0)
			ptr = rl_rotation(ptr);

		else
			ptr = rr_rotation(ptr);
	}
	
	return ptr;	

}


BinaryTree::~BinaryTree(){
	real_destructor(root_); //passes root to begin deconstructing the tree recursively
}


void BinaryTree::real_destructor(BinaryNode* node){
	
	if(node == NULL)	//base case, done deconstructing the list
		return;
						
	real_destructor(node -> left);		//go to next nodes
	real_destructor(node -> right);

	delete node;	//start process all over again since delete calls deconstructor recursively
}






