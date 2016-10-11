#include <iostream>
#include "binary.h"
using namespace std;

int main() {

  BinaryTree* tree = new BinaryTree;

  char option; // Menu option
  int key; // Key for insert and remove

  do {
    cin >> option;
    switch(option) {
      case 'i':
        cin >> key;
        tree->insert(key);
        break;
      case 'r':
        cin >> key;
        tree->remove(key);
	cout<<endl;
        break;
      case 'p':
        tree->print_keys();
	cout<<endl;
        break;
      case 'h':
        tree->print_heights();
	cout<<endl;
        break;
      default:
        break;
    }
  } while(option != 'q');

  delete tree;

}
