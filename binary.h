/*

Edited By: Jordan Osman 

Description: file containting class defenition for BinaryTree and struct defenition BinaryNode

e-mail: jo982114@ohio.edu

Date: 10/3/2016

*/
struct BinaryNode{
	BinaryNode(int k) : key(k), left(NULL), right(NULL){}


	int key;
	BinaryNode *left;
	BinaryNode *right;

};

class BinaryTree {

public:
	BinaryTree() : root_(NULL) {}
	~BinaryTree();
	

  	void insert(const int key);
  	void remove(const int key);

  	void print_keys() const;
  	void print_heights();

	BinaryNode* rr_rotation(BinaryNode* ptr);
	BinaryNode* ll_rotation(BinaryNode* ptr);
	BinaryNode* rl_rotation(BinaryNode* ptr);
	BinaryNode* lr_rotation(BinaryNode* ptr);

	int balance_factor(BinaryNode* ptr);
	BinaryNode* balance_tree(BinaryNode* ptr);
	void in_order(BinaryNode* ptr);
	int Tree_Height(BinaryNode* ptr);



private:
	int key;
	BinaryNode *left;
	BinaryNode *right;


	BinaryNode* root_;



	void real_destructor(BinaryNode* node);  
	BinaryNode* insert_helper(const int key, BinaryNode* node);
	BinaryNode* real_remove(int key, BinaryNode* parent);
	void print_height_helper(BinaryNode* ptr);
	void print_keys_helper(BinaryNode* node) const;

};
