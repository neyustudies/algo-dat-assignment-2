#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "binaryTree.hpp"


/*------ T E S T  C A S E S -------------------------------------------------------------*/


TEST_CASE("default binary search tree should be empty", "[default]") {
  BinaryTree tree(0);
  REQUIRE(tree.key == 0);
  REQUIRE((bool)tree.left == false);
  REQUIRE((bool)tree.right == false);
  REQUIRE((bool)tree.p == false);
}

TEST_CASE("create a new binary search tree", "[new]") {
  BinaryTree tree({3, 2, 1, 4, 6, 5});
  REQUIRE(tree.key == 3);
  REQUIRE(tree.left->key == 2);
  REQUIRE(tree.left->p);
  REQUIRE(tree.left->left->key == 1);
  REQUIRE(tree.right->key == 4);
  REQUIRE(tree.right->right->key == 6);
  REQUIRE(tree.right->right->left->key == 5);
}

TEST_CASE("get the predecessor of a node", "[predecessor]") {
  BinaryTree tree({3, 2, 1, 4, 6, 5});
  REQUIRE(tree.getPredecessor(3)->key == 2);
  REQUIRE(tree.getPredecessor(4)->key == 3);
  REQUIRE(tree.getPredecessor(5)->key == 4);
}

TEST_CASE("get the successor of a node", "[successor]") {
  BinaryTree tree({3, 1, 2, 4, 6, 5, 7});
  REQUIRE(tree.getSuccessor(3)->key == 4);
  REQUIRE(tree.getSuccessor(2)->key == 3);
  REQUIRE(tree.getSuccessor(6)->key == 7);
}

TEST_CASE("insert nodes into the tree", "[insert]") {
  BinaryTree tree(3);
  tree.insert(2);
  tree.insert(1);
  tree.insert(4);
  tree.insert(6);
  tree.insert(5);
  // Root
  REQUIRE(tree.key == 3);
  REQUIRE((bool)tree.left == true);
  REQUIRE((bool)tree.right == true);
  // Left
  REQUIRE(tree.left->key == 2);
  REQUIRE((bool)tree.left->left == true);
  REQUIRE((bool)tree.left->right == false);
  // Left left
  REQUIRE(tree.left->left->key == 1);
  REQUIRE((bool)tree.left->left->left == false);
  REQUIRE((bool)tree.left->left->right == false);
  // Right
  REQUIRE(tree.right->key == 4);
  REQUIRE((bool)tree.right->right == true);
  REQUIRE((bool)tree.right->left == false);
  // Right right
  REQUIRE(tree.right->right->key == 6);
  REQUIRE((bool)tree.right->right->right == false);
  REQUIRE((bool)tree.right->right->left == true);
  // Right right left
  REQUIRE(tree.right->right->left->key == 5);
  REQUIRE((bool)tree.right->right->left->right == false);
  REQUIRE((bool)tree.right->right->left->left == false);
}

TEST_CASE("remove nodes from the tree", "[remove]") {
  BinaryTree tree({3, 2, 1, 4, 6, 5, 7});
  // Remove leaf
  tree.remove(5);
  REQUIRE(tree.key == 3);
  REQUIRE(tree.left->key == 2);
  REQUIRE(tree.left->left->key == 1);
  REQUIRE(tree.right->key == 4);
  REQUIRE(tree.right->right->key == 6);
  REQUIRE(tree.right->right->right->key == 7);
  REQUIRE((bool)tree.right->right->left == false);
  // Bypass node
  tree.remove(2);
  REQUIRE(tree.key == 3);
  REQUIRE(tree.left->key == 1);
  REQUIRE(tree.right->key == 4);
  REQUIRE(tree.right->right->key == 6);
  REQUIRE(tree.right->right->right->key == 7);
  tree.insert(5);
  tree.remove(6);
  REQUIRE(tree.key == 3);
  REQUIRE(tree.left->key == 1);
  REQUIRE(tree.right->key == 4);
  REQUIRE(tree.right->right->key == 7);
  REQUIRE(tree.right->right->left->key == 5);
}

TEST_CASE("search a node", "[search]") {
  BinaryTree tree({3, 2, 1, 4, 6, 5, 7});
  REQUIRE(tree.search(3) == &tree);
  REQUIRE(tree.search(2) == tree.left);
  REQUIRE(tree.search(7) == tree.right->right->right);
} 

TEST_CASE("find the rightmost key", "[max]") {
  BinaryTree tree1({3, 2, 1, 4, 6, 5, 7});
  BinaryTree tree2({6, 2, 4, 8, 1, 5, 3});
  REQUIRE(tree1.getMax() == 7);
  REQUIRE(tree1.getMax() == tree1.right->right->right->key);
  REQUIRE(tree2.getMax() == 8);
  REQUIRE(tree2.getMax() == tree2.right->key);
} 

TEST_CASE("find the leftmost key", "[minimum]") {
  BinaryTree tree1({3, 5, 9, 4, 6, 2, 7});
  BinaryTree tree2({9, 6, 4, 8, 7, 5, 3});
  REQUIRE(tree1.getMin() == 2);
  REQUIRE(tree1.getMin() == tree1.left->key);
  REQUIRE(tree2.getMin() == 3);
  REQUIRE(tree2.getMin() == tree2.left->key);
}


/*--------- M A I N ------------------------------------------------------------------------*/


int main(int argc, char *argv[]) {

  BinaryTree bst(0);
  bool quit = false;
  int searched, removed, input, pred, succ, option;

  while(!quit) {
    std::cout << "\nSelect an action: \n" << 
    "1. insert, 2. remove, 3. search, 4. predecessor, 5. successor, 6. max, 7. min, 8. quit\n";
    std::cin  >> option;
    std::cout << "\nOption " << option << " selected: ";

	  
  switch(option) {

    case 1: 
		  
      		std::cout << "Enter the keys to be inserted - separated by spaces.. " 
	        << "\nTo terminate the input, press any alphabet [Enter]" 
	        << std::endl;	
      		while(std::cin >> input) {
      		  bst.insert(input);
      		} std::cin.clear();
		  			std::cin.ignore(1);
		  			break;

		  
    case 2:
		  
	    		std::cout << "Which node do you want to remove?" << std::endl;
	    		std::cin  >> removed;
	    		bst.remove(removed);
	    		std::cout << "The node with the value of " << removed 
                  	<< " has been removed from the tree..\n";
	    		break;
    
		  
    case 3:
		  
      		std::cout << "Which node do you want to search?" << std::endl;
      		std::cin  >> searched;
      		std::cout << "The pointer to " << bst.search(searched)->key 
                	  << " has been found.. its address is " 
                 	  << bst.search(searched) << std::endl;
      		break;

		  
    case 4:
		  
      		std::cout << "Whose predecessor are you looking for?" << std::endl;
      		std::cin  >> pred;
      		std::cout << "Predecessor to node " << pred << " is " 
                	  << bst.getPredecessor(pred)->key << std::endl;
      		break;

		  
    case 5:
		  
      		std::cout << "Whose successor are you looking for?" << std::endl;
      		std::cin  >> succ;
      		std::cout << "Successor to node " << succ << " is " 
                	  << bst.getSuccessor(succ)->key << std::endl;
      		break;

		  
    case 6:
		  
      		std::cout << "Searching for the rightmost key..." << std::endl;
      		std::cout << bst.getMax() << " is the maximum key" << std::endl;
      		break;

		  
    case 7:
		  
      		std::cout << "Searching for the leftmost key..." << std::endl;
      		std::cout << bst.getMin() << " is the minimum key" << std::endl;
      		break;

			
    case 8:
			
      		std::cout << "Goodbye! Exiting the program" << std::endl;
      		std::cout << "Please also take a look at the tests" << std::endl;

			
    default:
			
      		quit = true;
      		return Catch::Session().run(argc, argv);
			
   		}
  	}
  return 0;
}
