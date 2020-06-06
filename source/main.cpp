#include "BinarySearchTree.hpp"


int main() {

  BinarySearchTree BST;
  bool quit = false;
  int  searched, removed, input, option, pred, succ;



  while(!quit) {
    std::cout << "\nSelect an action: \n"
              << "1. INSERT, 2. REMOVE, 3. FIND, 4. SUCC, 5. PRED, 6. MAX, 7. MIN, 8.QUIT\n";
    std::cin  >> option;
    std::cout << "\nOption " << option << " selected: ";



    switch(option) {

      case 1:     std::cout << "Enter the keys to be inserted, seperated by spaces\n"
                            << "To terminate the input, press any alphabet [Enter]\n";
                  while(std::cin >> input) {
                    BST.insert(input);
                  } std::cin.clear();
                    std::cin.ignore(1);
                    break;

      case 2:     std::cout << "Which node do you want to remove?\n";
                  std::cin  >> removed;
                  BST.remove(removed);
                  break;

      case 3:     std::cout << "Which node do you want to search?\n";
                  std::cin  >> searched;
                  break;

      case 4:     std::cout << "Whose successor are you looking for?\n";
                  std::cin  >> succ;
                  BST.successor(succ);
                  break;

      case 5:     std::cout << "Whose predecessor are you looking for?\n";
                  std::cin  >> pred;
                  BST.predecessor(pred);
                  break;

      case 6:     std::cout << "Searching for the rightmost key..\n";
                  BST.max();
                  break;

      case 7:     std::cout << "Searching for the leftmost key..\n";
                  BST.min();
                  break;

      case 8:     std::cout << "Goodbye! Exiting the program\n";


      default:    quit = true;
    }

  } return 0;

}

