#include "product.h"

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>


int productid;
std::string product;
int quantity;

std::map<int, Product> inventory;

int main() {
  char input;
  
  std::cout << "Hello! Welcome to your inventory!" << "\n";
  std::cout << "====================== \n";
  
  while (true) {
    std::cout << "What would you like to do? \n"
            << "- Press A to add product \n"
            << "- Press S to view product name and quantity \n"
            << "- Press R to remove product \n"
            << "- Press V to view inventory \n"
            << "- Press X to exit inventory \n"
            << "Input: ";
    std::cin >> input;

    if (input == 'X' || input == 'x') {
      std::cout << "Thank you for using the inventory!";
      break;
    }
    if (input == 'a' || input == 'A') {
      std::cout << "Product ID: ";
      std::cin >> productid;
      std::cout << "Product Name: ";
      std::cin >> product;
      std::cout << "Quantity of your product: ";
      std::cin >> quantity;
  
      Product y(product, quantity);
      inventory.insert({productid, y});
      
      std::cout << "You have added " 
            << inventory.at(productid).GetQuantity() << "x " 
            << inventory.at(productid).GetProduct() 
            << "'s with the Product ID: " << productid << "\n"
            << "===================== \n";
      
    } else if (input == 'S' || input == 's') {
      int id;
      std::cout << "Please enter Product ID to find its name and quantity: ";
      std::cin >> id;
      std::cout << "There are " << inventory.at(id).GetQuantity() 
                << "x " << inventory.at(id).GetProduct() << "'s in your inventory \n";

    } else if (input == 'V' || input == 'v') {
      if (inventory.size() == 0) {
        std::cout << "Here is the list of your inventory:\n"
                << "=============================== \n"
                << "Your inventory is empty!\n";
      } else if (inventory.size() > 0) { 
        std::cout << "Here is the list of your inventory:\n"
                << "=============================== \n"
                << "ID: " << "      "
                << "Name: " << "     "
                << "Qty: \n";
      for (std::pair<int, Product> list: inventory) {
        std::cout << list.first << "       "
                  << list.second.GetProduct() << "        "
                  << list.second.GetQuantity() << "\n";
        }
      }
    } else if (input == 'R' || input == 'r') {
      int user_remove; 
      std::cout << "Enter the product ID you would like to remove: ";
      std::cin >> user_remove;
      inventory.erase(user_remove);
      std::cout << "Processing... \n";
      std::cout << "The Product with the Product ID: " << user_remove << " has been removed from the inventory \n";
    } else {
      std::cout << "Invalid Input!";
    }
  }
  return 0;
}