#include "product.h"

#include <iostream>
#include <vector>
#include <map>

int productid;
std::string product;
int quantity;

std::map<int, Product> inventory;

int main() {
  char input;
  
  std::cout << "Hello! Welcome to your inventory!" << "\n";
  std::cout << "To get started, please enter: ProductID, Name, and Quantity \n" <<
    "====================== \n";
    std::cout << "Product ID: ";
    std::cin >> productid;
    std::cout << "Product Name: ";
    std::cin >> product;
    std::cout << "Quantity of your product: ";
    std::cin >> quantity;
  
  Product add(product, quantity);
  inventory.insert({productid, add});
  
  std::cout << "You have added " 
            << inventory.at(productid).GetQuantity() << "x " 
            << inventory.at(productid).GetProduct() 
            << "'s with the Product ID: " << productid << "\n"
            << "===================== \n";
  
  while (true) {
    std::cout << "What would you like to do next? \n"
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
  
      Product add(product, quantity);
      inventory.insert({productid, add});
      
      std::cout << "You have added " 
            << inventory.at(productid).GetQuantity() << "x " 
            << inventory.at(productid).GetProduct() 
            << "'s with the Product ID: " << productid << "\n"
            << "===================== \n";
    } else if (input == 'V' || input == 'v') {
      for (int i = 0; i < inventory.size(); i++) {
        std::cout << productid << "\n";
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