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



/*---  B A S I C   O P E R A T I O N S  ------------------------------------*/
 

/* adding a new Node into the Tree */
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


/* delete a node from the Tree */
int BinarySearchTree::remove(int key) {
  Node* node = this->search(key);
  if(node == nullptr) {
    std::cout << "not found" << std::endl;
    return 1;
  } this->remove(node);
  std::cout << "Node " << key << " has been removed" << std::endl;
  return key;
}


/* return the node with the minimum bigger key in the Tree */
int BinarySearchTree::successor(int key) {
  Node* pos = this->search(key);
  if(pos == nullptr) {
    std::cout << "not found" << std::endl;
    return 1;
  } Node* successorNode = this->successor(pos);
  if(successorNode != nullptr) {
    std::cout << "Successor to node " << key << " is " 
              << successorNode->key << std::endl;
  } else {
    std::cout << key << " has no successor, it is the maximum key" << std::endl;
    return key;
  }
}


/* return the node with the maximum smaller key in the Tree */
int BinarySearchTree::predecessor(int key) {
  Node* pos = this->search(key);
  if(pos == nullptr) {
    std::cout << "not found" << std::endl;
    return 1;
  } Node* predecessorNode = this->predecessor(pos);
  if(predecessorNode != nullptr) {
    std::cout << "Predecessor to node " << key << " is " 
              << predecessorNode->key << std::endl;
  } else {
    std::cout << key << " has no predecessor, it is the minimum key" << std::endl;
  }
}


/* return the rightmost in the Tree */
void BinarySearchTree::max() {
  Node* max = this->max(root_);
  std::cout << max->key << " is the maximum key" << std::endl;
}


/* returns the leftmost in the Tree */
void BinarySearchTree::min() {
  Node* min = this->min(root_);
  std::cout << min->key << " is the minimum key" << std::endl;
}


int BinarySearchTree::getSize(int key) {
  Node* node = this->search(key);
  return getSize(node);
}


void BinarySearchTree::print() {
  print(root_, 0);
}



/*---  I N T E R N   O P E R A T I O N S  ---------------------------------*/


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
    node       = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}


Node* BinarySearchTree::predecessor(Node* node) {
  if(node->left != nullptr) {
    return max(node->left);
  } Node* parentNode = node->parent;
  while(parentNode != nullptr and parentNode->left == node) {
    node       = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}


Node* BinarySearchTree::max(Node* node) {
  while(node->right != nullptr) {
    node = node->right;
  } return node;
}


Node* BinarySearchTree::min(Node* node) {
  while(node->left != nullptr) {
    node = node->left;
  } return node;
}


int BinarySearchTree::getSize(Node* node) {
  if(node == nullptr) {
    return 0;
  } if(node->left == nullptr and node->left == nullptr) {
    return 1;
  } else {
    return this->getSize(node->left) + 1 + this->getSize(node->right);
  }
}


void BinarySearchTree::print(Node* node, int spaces) {
  if(node != nullptr) {
    print(node->right, spaces+4);
    for(auto i = 0; i < spaces; ++i) {
      std::cout << ' ';
    } if(node->parent != nullptr) {
      std::cout << node->key << "[" << node->parent->key << "]" << std::endl;
    } else {
      std::cout << node->key << "[ROOT]" << std::endl;
    } print(node->left, spaces+4);
  }
}


#endif // BINARYSEARCHTREE_HPP

