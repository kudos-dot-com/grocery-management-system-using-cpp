#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include <vector>
#include "TextTable.h"
#include <conio.h>

using namespace std;

enum IN {
    IN_BACK = 8,
    IN_RET = 13
};

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

struct purchase{
        string name;
        string phone;
        double total;
        double profit;
        double pp;
}; 
class users: public admin
{   
    public:
    void addNewPurchase(string name, string phone,double total,double profit,double pp,vector<purchase>& purchases)
    {
        purchase p;
        p.name = name;
        p.phone = phone;
        p.total = total;
        p.profit = profit;
        p.pp = pp;
        purchases.push_back(p);

        
    }
};

std::string takePasswdFromUser(char sp = '*')
{
    string passwd = "";
    char ch_ipt;
    while (true) {
 
        ch_ipt = getch();
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() != 0) {
            passwd.pop_back();
            cout << "\b \b";
 
            continue;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0) {
            continue;
        }
 
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

struct prod{
        string sku;
        string name;
        double costprice;
        double sellingprice;
        int Stock;
}; 
class Inventory: public users
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
        TextTable t( '-', '|', '+' );

        t.add( "SL NO." );
        t.add( "SKU" );
        t.add( "NAME" );
        t.add( "COST PRICE" );
        t.add( "SELLING PRICE" );
        t.add( "STOCK" );
        t.endOfRow(); 

        for(auto i = 0; i < products.size(); i++)
        {
            t.add( to_string(i+1) );
            t.add( products[i].sku );
            t.add( products[i].name );
            t.add( to_string(products[i].costprice));
            t.add( to_string(products[i].sellingprice));
            t.add( to_string(products[i].Stock) );
            t.endOfRow(); 

        }

        t.setAlignment( 2, TextTable::Alignment::RIGHT );
        std::cout << t;
    }

   void allPurchases(vector<purchase>& purchases)
    {
        TextTable t( '-', '|', '+' );
        t.add("Name");
        t.add("Phone");
        t.add("Total");
        t.add("Profit Made");
        t.add("Profit percentage");
        t.endOfRow();
        for(int i = 0; i < purchases.size(); i++)
        {
            t.add(purchases[i].name);
            t.add(purchases[i].phone);
            t.add(to_string(purchases[i].total));
            t.add(to_string(purchases[i].profit));
            t.add(to_string(purchases[i].pp)+"%");
            t.endOfRow();
        }
        cout << t << endl;
    }   
   
};

class Billing:public users
{   public:
    struct items{
        string sku;
        string name;
        double price;
        double cprice;
        int quantity;
    }; 
    public:
    vector<items> cart;
    items item; 

    public:   
    auto getProducts(vector<prod>& products){
        cout << "<---------------------- ALL AVAILABLE PRODUCT IN THE SHOP---------------->" << endl;
        TextTable t( '-', '|', '+' );

        t.add( "SL NO." );
        t.add( "SKU" );
        t.add( "NAME" );
        t.add( "PRICE" );
        t.add( "STOCK" );
        t.endOfRow(); 
        cout << products.size() << endl;
        for(auto i = 0; i < products.size(); i++)
        {
            // cout << i << " " << products[i].sku << " " << products[i].name << " " << products[i].sellingprice << " " << products[i].Stock << endl;
            t.add( to_string(i+1) );
            t.add( products[i].sku );
            t.add( products[i].name );
            t.add( to_string(products[i].sellingprice) );
            t.add( to_string(products[i].Stock));

            t.endOfRow();
        }
        t.setAlignment( 2, TextTable::Alignment::RIGHT );
        std::cout << t;
    }    

    public:
    void addtocart(int sl,vector<prod>& products)
    {   int i=sl-1;

        cout << "ENTER THE QUANTITY: ";
        cin >> item.quantity;
        
        
        if(products[i].Stock == 0)
        {
             cout << "OUT OF STOCK" << endl;
        }
        else if(sl>products.size())
        {
            cout << "INVALID SKU ID" << endl;
        }
        else if((products[i].Stock-item.quantity)<0)
        {
            // system("Color 0A");
            cout << "SORRY YOU CAN ONLY BUY :"<< "" << products[i].Stock << ""<< endl;
        }else
        {
        item.name = products[i].name;
        item.price = products[i].sellingprice;
        item.cprice = products[i].costprice;

        item.sku = products[i].sku;

        products[i].Stock-=item.quantity;

        cart.push_back(item);
        cout<< cart.size() << endl;
        // system("Color 0A");
        cout << "PRODUCT ADDED TO CART SUCCESSFULLY" <<endl;
        }

        // cout << products[i].sku << " " << products[i].name << " " << products[i].costprice << " " << products[i].Stock << endl;
    }

    public:
    void deletefromcart(int n,int q,vector<prod>& products)
    {   n-=1;
        cout << "Enter the sl no: ";
        // cin >> product.sku;
        cart.erase(cart.begin() + n);
        products[n].Stock+=q;
        cout << "Product deleted successfully" << endl;

    }
    public:
    void viewcart()
    {
        // cout <<"\n" << endl;
        cout << "<---------------------- YOUR CART ---------------->" << endl;
        
        TextTable t( '-', '|', '+' );

        t.add( "SL NO." );
        t.add( "SKU" );
        t.add( "NAME" );
        t.add( "PRICE" );
        t.add( "QUANTITY" );
        t.endOfRow(); 

        for(auto i = 0; i < cart.size(); i++)
        {
            t.add( to_string(i+1) );
            t.add( cart[i].sku );
            t.add( cart[i].name );
            t.add( to_string(cart[i].price) );
            t.add( to_string(cart[i].quantity));
            t.endOfRow(); 

        }
        t.setAlignment( 2, TextTable::Alignment::RIGHT );
        std::cout << t;
    }
    void checkout(vector<purchase>& purchases)
    {   
        TextTable t( '-', '|', '+' );
        double sum = 0.0,profit,pp;
        string name,phone;
        for(auto i = 0; i < cart.size(); i++)
        {
            sum += cart[i].price * cart[i].quantity;
            profit += cart[i].cprice * cart[i].quantity;

        }
        // enter details
        cout << "ENTER YOUR NAME: ";
        cin >> name;
        cout << "ENTER YOUR PHONE NUMBER: ";
        cin >> phone;
        t.add( "NAME" );
        t.add( (name) );
        t.endOfRow(); 

        t.add( "PHONE" );
        t.add( (phone));
        t.endOfRow(); 

        t.add( "TOTAL" );
        t.add( to_string(sum));
        t.endOfRow(); 

        // t.setAlignment( 2, TextTable::Alignment::RIGHT );
        std::cout << t;
        cout <<"THANK YOU FOR SHOPPING WITH US!!!"<<endl;
        pp = (sum-profit)/100;
        addNewPurchase(name,phone,sum,profit,pp,purchases);
    
    }

};

int main()
{
    users user;
    Inventory stock;
    Billing bill;
    
    vector<prod> products;
    vector<purchase> purchases;
    
    auto adminCreds = user.adminCreds();

check:
string email,password;
int option;
cout << "Enter your choice: \n  1. LOGIN \n  2. BUY \n  3. EXIT\n";

cin >> option;

switch(option) {
      case 1:
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cout << "@root>>> ";
            password = takePasswdFromUser();
            cout << password << endl;
            if(email == adminCreds.email && password == adminCreds.password)
            {
                cout << "\n [ WELCOME ADMIN ] " << endl;
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
    cout << "ENTER YOUR CHOICE: \n 1. ADD NEW PRODUCT \n  2. GET ALL PRODUCT \n 3. DELETE A PRODUCT \n 4. UPDATE A PRODUCT \n 5. VIEW PURCHASE HISTORY \n 6. EXIT \n";

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
            stock.allPurchases(purchases);
            goto admin;
      case 6:
            goto check;
      default :
         cout << "Invalid choice" << endl;
    
    // CUSTOMER AREA

    buy:
        bill.getProducts(products);
        cout << "Enter your choice: \n  1. ADD TO CART \n  2. DELETE FROM CART \n 3. VIEW CART \n 4. CHECKOUT \n 5. EXIT \n";
        cin >> option;

    switch(option) {
      case 1:
            int n;
            cout << "ENTER SL. Number"<<endl;
            cin >> n;
            bill.addtocart(n,products);
            goto buy;
      case 2:
            int n1,q;
            cout << "ENTER SL. Number"<<endl;
            cin >> n1;
            cout << "ENTER QUANTITY"<<endl;
            cin >> q;
            bill.deletefromcart(n1,q,products);
            goto buy;
      case 3:
            bill.viewcart();
            goto buy;
      case 4:
            bill.checkout(purchases);
            goto check;
      case 5:
            goto check;
      default :
         cout << "Invalid option" << endl;
     
    }
    cout << adminCreds.email << endl;
    cout << adminCreds.password << endl;
    exit:
    cout << "THANKS FOR  USING OUR SERVICE" << endl;
    return 0;
}
}
