#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>


struct Node {

  int     value;    // node value (key)
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

    value      = key;
    left       = nullptr;
    right      = nullptr;
    parent     = nullptr;

  }

};


#endif // NODE_HPP

