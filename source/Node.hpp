#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>


struct Node {

  int     key;      // node value
  Node*   parent;   // parent pointer
  Node*   left;     // left child pointer
  Node*   right;    // right child pointer
  

  /* constructors for struct Node */

  Node() {

    left      = nullptr;
    right     = nullptr;
    parent    = nullptr;

  }
  
  Node(int key) {

    this->key = key;
    left      = nullptr;
    right     = nullptr;
    parent    = nullptr;

  }

};


#endif // NODE_HPP

