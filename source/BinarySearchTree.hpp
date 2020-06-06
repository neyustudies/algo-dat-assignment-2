#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Node.hpp"

class BinarySearchTree {

  public:

    BinarySearchTree    ();
    BinarySearchTree    (int keys[], int arraySize);

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


    
};

#endif // BINARYSEARCHTREE_HPP