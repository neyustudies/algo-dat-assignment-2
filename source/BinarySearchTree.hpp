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
    } if(key < prev->key) {
      Node* newNode   = new Node(key);
      prev->left      = newNode;
      newNode->parent = prev;
    } else if(key > prev->key) {
      Node* newNode   = new Node(key);
      prev->right     = newNode;
      newNode->parent = prev;
    }
  } ++size_;
  return 0;
} 


int BinarySearchTree::remove(int key) {
  Node* node = this->search(key);
  if(node == nullptr) {
    std::cout << "not found" << std::endl;
    return 1;
  } this->remove(node);
  std::cout << "Node " << key << " has been removed" << std::endl;
  return key;
}


int BinarySearchTree::successor(int key) {
  Node* pos = this->search(key);
  if(pos == nullptr) {
    std::cout << "not found" << std::endl;
    return 1;
  } Node* successorNode = this->successor(pos);
  if(successorNode != nullptr) {
    std::cout << "Successor to node " << key << " is " << successorNode->key << std::endl;
  } else {
    std::cout << key << " has no successor, it is the maximum key" << std::endl;
    return key;
  }
}





/*---  I N T E R N   O P E R A T I O N S  ---------------------------*/


Node* BinarySearchTree::search(int key) {
  Node* tmp = root_;
  bool found = false;
  while(tmp != nullptr and found == false) {
    if(tmp->key == key) {
      found = true;
    } else if(tmp->key > key) {
      tmp = tmp->left;
    } else {
      tmp = tmp-> right;
    }
  } if(found == true) {
    return tmp;
  } else {
    return nullptr;
  }
}

Node* BinarySearchTree::successor(Node* node) {
  if(node->right != nullptr) {
    return min(node->right);
  } Node* parentNode = node->parent;
  while(parentNode != nullptr and parentNode->right == node) {
    node = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}






#endif // BINARYSEARCHTREE_HPP