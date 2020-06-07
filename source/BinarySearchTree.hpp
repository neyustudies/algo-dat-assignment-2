#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "Node.hpp"


class BinarySearchTree {

  public:

    BinarySearchTree    ();
    BinarySearchTree    (int keys[], int arrSize);

    int   insert        (int key);
    void  remove        (int key);
    int   successor     (int key);
    int   predecessor   (int key);
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



/*------  B A S I C   O P E R A T I O N S  -------------------------------------------*/
 

/* adding a new node into the Tree */
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
        std::cout << key << " is already existing\n";
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


/* return the key 
with the minimum bigger value in the Tree */
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
    std::cout << key << " has no successor, it is the maximum key\n";
    return key;
  } return key;
}


/* return the key 
with the maximum smaller value in the Tree */
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
    std::cout << key << " has no predecessor, it is the minimum key\n";
    return key;
  } return key;
}


/* find the rightmost node in the Tree */
void BinarySearchTree::max() {
  Node* max = this->max(root_);
  std::cout << max->key << " is the maximum key\n";
}


/* find the leftmost node in the Tree */
void BinarySearchTree::min() {
  Node* min = this->min(root_);
  std::cout << min->key << " is the minimum key\n";
}


/* print the Tree in in-order */
void BinarySearchTree::print() {
  print(root_);
}


/* return the number of nodes in the Tree */
int BinarySearchTree::size() {
  return size_;
}


/* search for a specific key in the Tree */
void BinarySearchTree::find(int key) {
  Node* ptr = root_;
  while(ptr != nullptr and ptr->key != key) {
    if(key < ptr->key) {
      ptr = ptr->left;
    } else {
      ptr = ptr->right;
    }
  } std::cout << "Key " << ptr->key 
              << " has been found, its address is " 
              << ptr << std::endl;
}



/*------  I N T E R N   O P E R A T I O N S  --------------------------------------------------*/


/* intern search 
to return the node pointer to a key */
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


/* intern procedure 
to delete node x from the Tree */
int BinarySearchTree::remove(Node* node) {
  Node* x;
  if(node->left == nullptr and node->right == nullptr) {
    x = node;
  } else if(node->left != nullptr) {         // if x has only one child 
    x = this->predecessor(node);             // update its parent pointer
  } else if(node->right != nullptr) {        // and free the node
    x = this->successor(node);
  } Node* x_child = nullptr;
  if(x->left != nullptr) {                                              
    x_child = x->left;
  } else if (x->right != nullptr) {
    x_child = x->right;
  } if(x_child != nullptr) {                 // if x has both left and right
    x_child->parent = x->parent;             // children, find the successor
  } if(x->parent == nullptr) {               // node that replaces x and 
    root_ = x_child;                         // update its pointers
    x_child->parent = nullptr;
  } else if(x->parent->left == x) {
    x->parent->left = x_child;
  } else {
    x->parent->right = x_child;
  } if(x != node) {
    node->key = x->key;
  } --size_;
  return node->key;
  delete node;
}


/* intern procedure to return a 
pointer to the successor node */
Node* BinarySearchTree::successor(Node* node) {
  if(node->right != nullptr) {
    return min(node->right);
  } Node* parentNode = node->parent;
  while(parentNode != nullptr and parentNode->right == node) {
    node       = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}


/* intern procedure to return a 
pointer to the predecessor node */
Node* BinarySearchTree::predecessor(Node* node) {
  if(node->left != nullptr) {
    return max(node->left);
  } Node* parentNode = node->parent;
  while(parentNode != nullptr and parentNode->left == node) {
    node       = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}


/* intern search for the 
pointer to the rightmost node */
Node* BinarySearchTree::max(Node* node) {
  while(node->right != nullptr) {
    node = node->right;
  } return node;
}


/* intern search for the
pointer to the leftmost node */
Node* BinarySearchTree::min(Node* node) {
  while(node->left != nullptr) {
    node = node->left;
  } return node;
}


/* intern procedure going through the 
Tree and printing the nodes in in-order */
void BinarySearchTree::print(Node* node) {
  if(root_ == nullptr || node == nullptr) {
    return;
  } print(node->left);
  std::cout << node->key << "  ";
  print(node->right);
}



#endif // BINARYSEARCHTREE_HPP

