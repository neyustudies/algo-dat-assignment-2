#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "Node.hpp"


class BinarySearchTree {

  public:

    BinarySearchTree    ();
    BinarySearchTree    (int keys[], int arrSize);

    int   insert        (int key);
    int   remove        (int key);
    int   successor     (int key) const;
    int   predecessor   (int key) const;
    int   find          (int key) const;
    int   size          ()        const;
    int   max           ()        const;
    int   min           ()        const;
    void  print         ()        const;


  private:

    int     size_;
    Node*   root_;
    Node*   search      (int   key)         const;
    Node*   successor   (Node* const& node) const;
    Node*   predecessor (Node* const& node) const;
    Node*   max         (Node* const& node) const;
    Node*   min         (Node* const& node) const;
    void    print       (Node* const& node) const;
    int     remove      (Node* const& node);
    
};


/* constructors for class BinarySearchTree */

BinarySearchTree::BinarySearchTree() :
  root_ {nullptr},
  size_ {0} {}


BinarySearchTree::BinarySearchTree(int keys[], int arrSize) :
  root_ {nullptr},
  size_ {0} {
    for(auto i = 0; i < arrSize; ++i) {
      insert(keys[i]);
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
      if(key < tmp->value) {
        prev = tmp;
        tmp  = tmp->left;
      } else if(key > tmp->value) {
        prev = tmp;
        tmp  = tmp->right;
      } else {
        std::cout << key << " is already existing\n";
        return 1;
      }
    } if(key < prev->value) {
      Node* newNode   = new Node(key);
      prev->left      = newNode;
      newNode->parent = prev;
    } else if(key > prev->value) {
      Node* newNode   = new Node(key);
      prev->right     = newNode;
      newNode->parent = prev;
    }
  } ++size_;
  return 0;
} 


/* delete a node from the Tree */
int BinarySearchTree::remove(int key) {
  Node* node = search(key);
  if(node == nullptr) {
    std::cout << key << " does not exist\n";
    return 1;
  } if(size_ == 1) {
    std::cout << key << " cannot be removed, it is the root\n";
    return 1;
  } remove(node);
    std::cout << key << " has been removed\n";
    std::cout << "The size of the tree now is " 
              << size() << std::endl;
    return key;
}


/* return the key 
with the minimum bigger value in the Tree */
int BinarySearchTree::successor(int key) const {
  Node* pos = search(key);
  if(pos == nullptr) {
    std::cout << key << " does not exist\n";
    return 1;
  } Node* successorNode = successor(pos);
  if(successorNode != nullptr) {
    std::cout << "Successor to node " << key << " is " 
              << successorNode->value << std::endl;
  } else {
    std::cout << key << " has no successor, it is the maximum key\n";
    return key;
  } return key;
}


/* return the key 
with the maximum smaller value in the Tree */
int BinarySearchTree::predecessor(int key) const {
  Node* pos = search(key);
  if(pos == nullptr) {
    std::cout << key << " does not exist\n";
    return 1;
  } Node* predecessorNode = predecessor(pos);
  if(predecessorNode != nullptr) {
    std::cout << "Predecessor to node " << key << " is " 
              << predecessorNode->value << std::endl;
  } else {
    std::cout << key << " has no predecessor, it is the minimum key\n";
    return key;
  } return key;
}


/* find the rightmost node in the Tree */
int BinarySearchTree::max() const {
  if(size_ == 0) {
    std::cout << "tree seems to be empty\n";
    return 1;
  } Node* maxNode = max(root_);
    std::cout << maxNode->value << " is the maximum key\n";
    return maxNode->value;
}


/* find the leftmost node in the Tree */
int BinarySearchTree::min() const {
  if(size_ == 0) {
    std::cout << "tree seems to be empty\n";
    return 1;
  } Node* minNode = min(root_);
    std::cout << minNode->value << " is the minimum key\n";
    return minNode->value;
}


/* print the Tree in in-order */
void BinarySearchTree::print() const {
  if(size_ == 0) {
    std::cout << "tree seems to be empty";
  } print(root_);
}


/* return the number of nodes in the Tree */
int BinarySearchTree::size() const {
  return size_;
}


/* search for a specific key in the Tree */
int BinarySearchTree::find(int key) const {
  Node* pos = search(key);
  if(pos == nullptr) {
    std::cout << key << " does not exist\n";
    return 1;
  } Node* ptr = root_;
  while(ptr != nullptr and ptr->value != key) {
    if(key < ptr->value) {
      ptr = ptr->left;
    } else {
      ptr = ptr->right;
    }
  } std::cout << "Key " << ptr->value 
              << " has been found, its address is " 
              << ptr << std::endl;
              return key;
}



/*------  I N T E R N   O P E R A T I O N S  --------------------------------------------------*/


/* intern search 
to return the node pointer to a key */
Node* BinarySearchTree::search(int key) const {
  Node* tmp = root_;
  bool found = false;
  while(tmp != nullptr and found == false) {
    if(tmp->value == key) {
      found = true;
    } else if(tmp->value > key) {
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
int BinarySearchTree::remove(Node* const& node) {
  Node* x;
  if(node->left == nullptr and node->right == nullptr) {
    x = node;
  } else if(node->left != nullptr) {         // if x has only one child 
    x = predecessor(node);                   // update its parent pointer
  } else if(node->right != nullptr) {        // and free the node
    x = successor(node);
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
    node->value = x->value;
  } --size_;
  return node->value;
  delete node;
}


/* intern procedure to return a 
pointer to the successor node */
Node* BinarySearchTree::successor(Node* const& node) const {
  Node* tmp = node;
  if(tmp->right != nullptr) {
    return min(tmp->right);
  } Node* parentNode = tmp->parent;
  while(parentNode != nullptr and parentNode->right == tmp) {
    tmp        = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}


/* intern procedure to return a 
pointer to the predecessor node */
Node* BinarySearchTree::predecessor(Node* const& node) const {
  Node* tmp = node;
  if(tmp->left != nullptr) {
    return max(tmp->left);
  } Node* parentNode = tmp->parent;
  while(parentNode != nullptr and parentNode->left == tmp) {
    tmp        = parentNode;
    parentNode = parentNode->parent;
  } return parentNode;
}


/* intern search for the 
pointer to the rightmost node */
Node* BinarySearchTree::max(Node* const& node) const {
  Node* tmp = node;
  while(tmp->right != nullptr) {
    tmp = tmp->right;
  } return tmp;
}


/* intern search for the
pointer to the leftmost node */
Node* BinarySearchTree::min(Node* const& node) const {
  Node* tmp = node;
  while(tmp->left != nullptr) {
    tmp = tmp->left;
  } return tmp;
}


/* intern procedure going through the 
Tree and printing the nodes in in-order */
void BinarySearchTree::print(Node* const& node) const {
  if(root_ == nullptr || node == nullptr) {
    return;
  } print(node->left);
  std::cout << node->value << "  ";
  print(node->right);
}



#endif // BINARYSEARCHTREE_HPP

