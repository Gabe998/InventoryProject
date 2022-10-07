#include "product.h"

#include <iostream>

Product::Product() {
  product_ = "void";
  quantity_ = 0;
}

Product::Product(std::string product, int quantity) {
  product_ = product;
  quantity_ = quantity;
}