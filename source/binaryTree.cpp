#include "binaryTree.hpp"
#include <stdexcept>
#include <iostream>


/* default constructor */
BinaryTree::BinaryTree(int key, BinaryTree* p) : 
  key     {key},    // node value
  left    {0},      // left child
  right   {0},      // right child
  p       {p} {}    // parent


/* constructor */
BinaryTree::BinaryTree(std::vector<int> keys) : 
  BinaryTree {0} {
    std::vector<int> newVector(keys.begin(), keys.end());
    if(newVector.size() > 0) {
      this->key = keys.at(0);
      newVector.erase(newVector.begin());
    } for(int key : newVector) {
      this->insert(key);
      }
  }


/* destructor */
BinaryTree::~BinaryTree() {
  if(this->left) {
    delete this->left;
  } if(this->right) {
    delete this->right;
  }
}

/* -----------------------------------------------------------------------*/

// A D D

/* adding a node */
void BinaryTree::insert(int key) {
  if(key == this->key) {
    throw std::invalid_argument("Error! No duplicate keys allowed");
    return;
  } else if(key < this->key) {
      if(this->left) {
        this->left->insert(key);
        return;
      } this->left = new BinaryTree(key, this);
    } else {
        if(this->right) {
        this->right->insert(key);
        return;
        } this->right = new BinaryTree(key, this);
      }
}


// R E M O V E

/* cancelling a node */
void BinaryTree::remove(int key) {
  BinaryTree* node = this->search(key);
  if(node) {
    BinaryTree* p = node->p;
    if(p) {
      if(node->left && node->right) {
        // replaces successor
        BinaryTree *successor = node->getSuccessor(node->key);
        BinaryTree *successorParent = successor->p;
        // removes successor node
        if(successorParent) {
          if(successorParent->left == successor) {
            successorParent->left = 0;
          } else {
            successorParent->right = 0;
            }
        } // adds to parent
          if(p->left == node) {
            p->left         = successor;
            successor->p    = p;
            successor->left = node->left;
          } else {
            p->right        = successor;
            successor->p    = p;
            successor->left = node->left;
            }
      } else if (node->left || node->right) {
          BinaryTree* newNode;
          if(node->left) {
            newNode = node->left;
          } else {
            newNode = node->right;
            } // bypass
              if(p->left == node) {
                p->left = newNode;
                newNode->p = p;
              } else {
                p->right = newNode;
                newNode->p = p;
                }
        } else {
        // deletes the leaf
        if(p->left == node) {
          p->left = 0;
        } else {
          p->right = 0;
          }
        }
    } // clears node
      node->left = 0;
      node->right = 0;
      delete node;
  } else {
    throw std::invalid_argument("Error! this key does not exist");
    return;
    }
}


// S E A R C H

/* returns a pointer to the node that has a given key value */
BinaryTree* BinaryTree::search(int key) {
  if (this->key == key) {
    return this;
  } else {
      if (this->left) {
      BinaryTree* tmpLeft = this->left->search(key);
        if (tmpLeft) {
        return tmpLeft;
        }
      } if (this->right) {
        BinaryTree* tmpRight = this->right->search(key);
        if (tmpRight) {
          return tmpRight;
        }
      } 
    }
  return 0;
}


// P R E D E C E S S O R

/* returns the node with the maximum smaller key in the Tree */
BinaryTree* BinaryTree::getPredecessor(int key) {
  BinaryTree* node = this->search(key);
  if (!node) {
    throw std::invalid_argument("Error! this key does not exist");
    return NULL;
  } if (node->left) {
    node = node->left;
    while (node->right) {
      node = node->right;
    } return node;
  } else {
      while (node->p) {
        if (node->p->key < node->key) {
        return node->p;
        } node = node->p;
      }
    } throw std::range_error("Error! no predecessor for key");
      return NULL;
}


// S U C C E S S O R

/* returns the node with the minimum bigger key in the Tree */
BinaryTree* BinaryTree::getSuccessor(int key) {
  BinaryTree* node = this->search(key);
  if (!node) {
    throw std::invalid_argument("Error! this key does not exist");
    return NULL;
  } if (node->right) {
    node = node->right;
      while (node->left) {
      node = node->left;
      } return node;
    } else {
        while (node->p) {
          if (node->p->key > node->key) {
            return node->p;
          } node = node->p;
        } throw std::range_error("Error! no successor for key");
          return NULL;
      }
}


// P R I N T

/* prints the Tree in in-order*/
void BinaryTree::printTree(BinaryTree* p) {
  BinaryTree* node = this->search(key);	
	if(node == NULL) {
		throw "Empty Tree, nothing to print";
		return;
	} if(node == NULL) {
		return;
		} printTree(node->left);
			std::cout << node->key << "  ";
			printTree(node->right);
}

