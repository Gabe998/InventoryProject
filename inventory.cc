#include "product.h"

#include <iostream>
#include <vector>
#include <map>

int main() {
  int ProductID;
  std::string product;
  int quantity;
  
  std::cout << "Hello! Welcome to your inventory!" << "\n";
  std::cout << "To get started, please enter: ProductID, Name, and Quantity" << "\n";
  std::cout << "Product ID: ";
  std::cin >> ProductID;
  std::cout << "Product Name: ";
  std::cin >> product;
  std::cout << "Quantity of your product: ";
  std::cin >> quantity;

  std::map<int, Product> inventory;
  
  Product first(product, quantity);
  inventory.insert({ProductID, first});
 // std::cout << inventory.at(ProductID).GetProduct(); Prints ProductId name 
 // std::cout << inventory.at(ProductID)
 // std::cout << <object>.GetProduct(); Returns objects name
 // std::cout << <object>.GetQuantity(); Returns objects quantity
  
  return 0;
}