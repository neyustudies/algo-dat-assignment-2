#include <vector>

class BinaryTree {

  public:
    int key;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree* p;
    BinaryTree(int key, BinaryTree* p = 0);
    BinaryTree(std::vector<int> keys);
    ~BinaryTree();
    BinaryTree* search(int key);
    BinaryTree* getPredecessor(int key);
    BinaryTree* getSuccessor(int key);
    int getMax();
    int getMin();
    void insert(int key);
    void remove(int key);
    void printTree(BinaryTree* p);
    void maximum(BinaryTree* p);
    void minimum(BinaryTree* p);

};

