#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "Node.hpp"


class BinarySearchTree {

  public:

    BinarySearchTree    ();
    BinarySearchTree    (int keys[], int arrSize);

    int   insert        (int key);
    int   remove        (int key);
    int   successor     (int key);
    int   predecessor   (int key);
    int   getSize       (int key);
    void  max           ();
    void  min           ();
    void  print         ();


  private:

    int     size_;
    Node*   root_;
    Node*   search      (int   key);
    Node*   successor   (Node* node);
    Node*   predecessor (Node* node);
    Node*   max         (Node* node);
    Node*   min         (Node* node);
    int     remove      (Node* node);
    int     getSize     (Node* node);
    void    print       (Node* node, int space);
    
};


/* constructors for class BinarySearchTree */

BinarySearchTree::BinarySearchTree() :
  root_ {nullptr},
  size_ {0} {}


BinarySearchTree::BinarySearchTree(int keys[], int arrSize) :
  root_ {nullptr},
  size_ {0} {
    for(auto i = 0; i < arrSize; ++i) {
      this->insert(keys[i]);
    }
  }



/*---  B A S I C   O P E R A T I O N S  ---------------------------*/


int BinarySearchTree::insert(int key) {
  if(root_ == nullptr) {
    root_ = new Node(key);
  } else {
    Node* tmp  = root_;
    Node* prev = nullptr;
    while(tmp != nullptr) {
      if(key < tmp->key) {
        prev = tmp;
        tmp  = tmp->left;
      } else if(key > tmp->key) {
        prev = tmp;
        tmp  = tmp->right;
      } else {
        std::cout << key << " is already existing" << std::endl;
        return 1;
      }
    }
    
  }
}
















#endif // BINARYSEARCHTREE_HPP