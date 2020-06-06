#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "Node.hpp"


class BinarySearchTree {

  public:

    BinarySearchTree    ();
    BinarySearchTree    (int keys[], int arrSize);

    int   insert        (int key);
    void   remove       (int key);
    int   successor     (int key);
    int   predecessor   (int key);
    //int   getSize       (int key);
    void  find          (int key);
    int   size          ();
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
    //int     getSize     (Node* node);
    void    print       (Node* node);
    
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
void BinarySearchTree::remove(int key) {
  Node* node = this->search(key);
  if(node == nullptr) {
    std::cout << "not found" << std::endl;
  } this->remove(node);
  std::cout << key << " has been removed\n";
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
  } return key;
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
    return key;
  } return key;
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


void BinarySearchTree::print() {
  //print(root_, 0);
  print(root_);
}


int BinarySearchTree::size() {
  return size_;
}


void BinarySearchTree::find(int key) {
  Node* root = root_;
  while(root != nullptr and root->key != key) {
    if(key < root->key) {
      root = root->left;
    } else {
      root = root->right;
    }
  } std::cout << "Key " << root->key << " has been found, its address is " << root << std::endl;
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


int BinarySearchTree::remove(Node* node) {
  Node* deleteNode;
  if(node->left == nullptr and node->right == nullptr) {
    deleteNode = node;
  } else if(node->left != nullptr) {
    deleteNode = this->predecessor(node);
  } else if(node->right != nullptr) {
    deleteNode = this->successor(node);
  } Node* deleteNodeChild = nullptr;
  if(deleteNode->left != nullptr) {
    deleteNodeChild = deleteNode->left;
  } else if (deleteNode->right != nullptr) {
    deleteNodeChild = deleteNode->right;
  } if(deleteNodeChild != nullptr) {
    deleteNodeChild->parent = deleteNode->parent;
  } if(deleteNode->parent == nullptr) {
    root_ = deleteNodeChild;
    deleteNodeChild->parent = nullptr;
  } else if(deleteNode->parent->left == deleteNode) {
    deleteNode->parent->left = deleteNodeChild;
  } else {
    deleteNode->parent->right = deleteNodeChild;
  } if(deleteNode != node) {
    node->key = deleteNode->key;
  } --size_;
  return node->key;
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


void BinarySearchTree::print(Node* node) {
  if(root_ == nullptr || node == nullptr) {
    return;
  } print(node->left);
  std::cout << node->key << "  ";
  print(node->right);
}



#endif // BINARYSEARCHTREE_HPP

