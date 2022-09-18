#include <iostream>
#include <vector>
#include <map>
#include "products.h"

using namespace std;

int quantity;
int productID;
string productname;
string command;
string message = "What would you like to do next? Type /inventory to view inventory, type /add to add product, type /remove to remove a product";

string inventory = "/inventory";
string add = "/add";
string trash = "/remove";

void addproduct() {
      cout << "Please enter the Product ID you would like to use: ";
      cin >> productID;
      cout << "Please enter the name of your product: ";
      cin >> productname;
      cout << "Please enter the amount of your product: ";
      cin >> quantity;
      cout << "Added " << quantity << " " << productname << "'s to your inventory" << endl << message << "\n";
      cin >> command;
    }
  
void viewinventory() {
  cout << "Here is your inventory: \n";

}

int main(){
  map<int, map<string, int>> productIDs;

  map<int, map<string, int>>::iterator IDs;
  map<string,int>::iterator product;

  bool toinventory = false;
  bool toadd = false;
  bool toremove = false;


  cout << "Hello! Welcome to your Inventory!! Please add a few items to get started! \n";
  addproduct();

  if (command == inventory) {
    toinventory = true;
  } else if (command == add) {
    toadd = true;
  } else if (command == trash) {
    toremove = false;
  } else {
    cout << "Invalid command \n";
  }

  if (toinventory == true) {
    viewinventory();
    toinventory = false;
  } else if (toadd == true) {
    addproduct();
    toadd = false;
  } else if (toremove == true) {
    //Command
    toremove = false;
  } else {
    cout << "No commands found";
  }

  productIDs.insert(make_pair(productID, map<string, int>()));
  productIDs[productID].insert(make_pair(productname, quantity));

  for (IDs = productIDs.begin(); IDs != productIDs.end(); IDs++) {
    for (product = IDs ->second.begin(); product != IDs->second.end(); product++){
        cout << "The Product key is " << IDs->first << " The Product name is " << product->first << " with a total quantity of: " << product->second << "\n";
    }
  }
  return 0;
}
