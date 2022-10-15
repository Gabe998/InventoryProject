#include <iostream>


class Product {
  public:
    Product();
    Product(std::string product, int quantity);
    std::string GetProduct() { return product_; }
    int GetQuantity() {return quantity_; }

  private:
    std::string product_;
    int quantity_;
};