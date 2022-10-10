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
  
      
    } else if (input == 'V' || input == 'v') {
      std::cout << "Here is the list of your inventory:\n"
                << "=============================== \n"
                << "ID: " << std::setw(10)
                << "Name: " << std::setw(10)
                << "Quantity: \n";
      for (std::pair<int, Product> list: inventory) {
        std::cout << list.first << std::setw(10)
                  << list.second.GetProduct() << std::setw(10)
                  << list.second.GetQuantity() << "\n";
      }
      
    } else {
    std::cout << "Invalid Input!";
    }
 // std::cout << inventory.at(ProductID).GetProduct(); Prints ProductId name 
 // std::cout << inventory.at(ProductID)
 // std::cout << <object>.GetProduct(); Returns objects name
 // std::cout << <object>.GetQuantity(); Returns objects quantity
  
  }
  return 0;
}