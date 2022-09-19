#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int quantity;
int productID;
string productname;
string command;
string message = "What would you like to do next? Type /inventory to view inventory, type /add to add product, type /remove to remove a product";

string inventory = "/inventory";
string add = "/add";
string trash = "/remove";

vector<int> prod_id;
vector<int> prod_qty;
vector<string> prod_name;

bool toinventory = false;
bool toadd = false;
bool toremove = false;

bool commands = false;

void commandcall() {
  if (command == inventory) {
      toinventory = true;
    } else if (command == add) {
      toadd = true;
    } else if (command == trash) {
      toremove = false;
    } else {
      cout << "Invalid command \n";
    }
}


void addproduct() {
      cout << "Please enter the Product ID you would like to use: ";
      cin >> productID;
      prod_id.push_back(productID);
      cout << "Please enter the name of your product: ";
      cin >> productname;
      prod_name.push_back(productname);
      cout << "Please enter the amount of your product: ";
      cin >> quantity;
      prod_qty.push_back(quantity);
      cout << "Added " << quantity << " " << productname << "'s to your inventory" << endl << message << "\n";
      commands = true;
      cin >> command;
    }

int x;

string strproductID = to_string(productID); 

size_t product_count = prod_id.size();

void viewinventory() {
  cout << "Here is your inventory: \n";
  cout << prod_id.at(1) << "\n";
  /*
  for (x = 0; x <= product_count; x++) {
    cout << "Product ID: " << productID << " Product Name: " << productname << " Produce Quantity: " << quantity << "\n";
  }
  cout << message << "\n";
  cin >> command;
  */
}

int main(){
  cout << "Hello! Welcome to your Inventory!! Please add a few items to get started! \n";
  addproduct();

  prod_id.push_back(productID);
  prod_qty.push_back(quantity);
  prod_name.push_back(productname);

  if (commands == true) {
    commandcall();
    commands = false;
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
  return 0;
}
