#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include <vector>

using namespace std;

class admin{
 public:   
 auto adminCreds(){
     struct {
        string email;
        string password;
    } adminCredentials;
     
    adminCredentials.email = "john@gmail.com";
    adminCredentials.password = "password";

    return adminCredentials;
 }
};

class users: public admin
{   
    // bool checkAdmin(string email, string password)
    // {
    //     // if()
    // }

    void addNewUser(string email, string name, string mobile)
    {
        struct {
        string email;
        string password;
    } user;
    // vector<user> users
// 

    }

    auto getallusers()
    {
            
    }

};

// public:

struct prod{
        string sku;
        string name;
        double costprice;
        double sellingprice;
        int Stock;
}; 
class Inventory
{
    // product p;
    // public:
       
    public:
    vector<prod> products;
    prod product;

    public:   
    void addNewProduct(vector<prod>& products)
    {
        cout << "Enter the sku: ";
        cin >> product.sku;
        cout << "Enter the name: ";
        cin >> product.name;
        cout << "Enter the cost price: ";
        cin >> product.costprice;
        cout << "Enter the selling price: ";
        cin >> product.sellingprice;
        cout << "Enter the stock: ";
        cin >> product.Stock;
        products.push_back(product);
        cout << "Product added successfully" << endl;
    }
    public:   
    auto deleteProduct(vector<prod>& products){
        cout << "Enter the sku: ";
        cin >> product.sku;

        int f=0;
        for(auto i = 0; i < products.size(); i++)
        {
            if(products[i].sku == product.sku)
            {
                products.erase(products.begin() + i);
                f=1;
                break;
            }
        }
        if(f==1){
            cout << "Product deleted successfully" << endl;
        }
        else{
            cout << "Invalid SKU ID" << endl;
        }
    }
    public:   
    auto updateProduct(vector<prod>& products){
        cout << "Enter the sku: ";
        cin >> product.sku;
        int f=0;
        for(auto i = 0; i < products.size(); i++)
        {
            if(products[i].sku == product.sku)
            {
                cout << "Enter the new name: ";
                cin >> product.name;
                cout << "Enter the new price: ";
                cin >> product.costprice;
                cout << "Enter the new stock: ";
                cin >> product.Stock;
                products[i] = product;
                f=1;
                break;
            }
        }
        if(f==1){
            cout << "Product updated successfully" << endl;
        }
        else{
            cout << "Invalid SKU ID" << endl;
        }
    }
    public:   
    auto getProducts(vector<prod>& products){
        cout << "sku \t name \t price \t stock\t" << endl;

        for(auto i = 0; i < products.size(); i++)
        {
            cout << products[i].sku << " " << products[i].name << " " << products[i].costprice << " " << products[i].Stock << endl;
        }
    }
};

class Billing: public Inventory
{   public:
    struct items{
        string sku;
        string name;
        double price;
        int quantity;
    }; 
    vector<items> cart;
    items item; 
    public:   
    auto getProducts(vector<prod>& products){
        cout << "<----------------------ALL AVAILABLE PRODUCTS---------------->" << endl;
        
        cout << "sku \t name \t price \t stock\t" << endl;
        cout << products.size() << endl;
        for(auto i = 0; i < products.size(); i++)
        {
            cout << i+1 << " " << products[i].sku << " " << products[i].name << " " << products[i].sellingprice << " " << products[i].Stock << endl;
        }
    }    

    public:
    void addtocart(int sl,vector<prod>& products)
    {   int i=sl-1;

        cout << "Enter the quantity: ";
        cin >> item.quantity;
        
        if(products[i].Stock == 0)
        {
             cout << "out of stock" << endl;
        }
        else if((products[i].Stock-item.quantity)<0)
        {
            cout << "you can only buy"<< "" << products[i].Stock << ""<< endl;
        }else
        {
        item.name = products[i].name;
        item.price = products[i].sellingprice;
        item.sku = products[i].sku;

        products[i].Stock-=item.quantity;

        cart.push_back(item);

         
        cout << "Product added to cart successfully." <<endl;
        }

        // cout << products[i].sku << " " << products[i].name << " " << products[i].costprice << " " << products[i].Stock << endl;
    }

    public:
    void deletefromcart(int n)
    {
        cout << "Enter the sl no: ";
        // cin >> product.sku;
        cart.erase(cart.begin() + n);
        
        cout << "Product deleted successfully" << endl;

    }
    void viewcart()
    {
        
        cout << "<----------------------ALL AVAILABLE PRODUCTS---------------->" << endl;
        
        cout << "sku \t name \t price \t stock\t" << endl;

        for(auto i = 0; i < cart.size(); i++)
        {
            cout << i+1 << " " << cart[i].sku << " " << cart[i].name << " " << cart[i].price << " " << cart[i].quantity << " " << endl;
        }
    }
    void checkout()
    {   
        double sum = 0.0;
        for(auto i = 0; i < cart.size(); i++)
        {
            sum += cart[i].price * cart[i].quantity;
        }   
        cout << sum << endl;

    }

};

int main()
{
    users user;
    Inventory stock;
    Billing bill;
   
    vector<prod> products;
    // prods product;

    auto adminCreds = user.adminCreds();

check:
string email,password;
int option;
cout << "Enter your choice: \n  1. Login \n  2. Buy \n  3. Exit \n";

cin >> option;

switch(option) {
      case 1:
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;
            if(email == adminCreds.email && password == adminCreds.password)
            {
                cout << "Welcome Admin" << endl;
                goto admin;
            }
            else
            {
                cout << "Invalid Credentials" << endl;
                goto check;
            }
            break;
      case 2:
            goto buy;
            break;
      case 3:
            goto exit;
            break;
      default :
         cout << "Invalid option" << endl;
   }
    // ADMIN LOGIN PART
    admin:
    cout << "Enter your choice: \n  1. Add new product \n  2. Get all product \n 3. delete a product \n 4. update a product \n 5. Exit \n";

    cin >> option;

    switch(option) {
      case 1:
            stock.addNewProduct(products);
            goto admin;
      case 2:
            stock.getProducts(products);
             goto admin;
      case 3:
            stock.deleteProduct(products);
             goto admin;
      case 4:
            stock.updateProduct(products);
             goto admin;
      case 5:
            goto check;
      default :
         cout << "Invalid grade" << endl;
    
    // CUSTOMER AREA

    buy:
        bill.getProducts(products);
        cout << "Enter your choice: \n  1. Add to cart \n  2. delete item from cart \n 3. view cart \n 4. checkout \n 5. Exit \n";
        cin >> option;

    switch(option) {
      case 1:
            int n;
            cout << "Enter sl. Number"<<endl;
            cin >> n;
            bill.addtocart(n,products);
            goto buy;
      case 2:
            int n1;
            cout << "Enter sl. Number"<<endl;
            cin >> n1;
            bill.deletefromcart(n1);
            goto buy;
      case 3:
            bill.viewcart();
            goto buy;
      case 4:
            bill.checkout();
            goto buy;
      case 5:
            goto check;
      default :
         cout << "Invalid option" << endl;
     
    }
    cout << adminCreds.email << endl;
    cout << adminCreds.password << endl;
    exit:
    cout << "Thank you for using our service" << endl;
    return 0;
}
}
