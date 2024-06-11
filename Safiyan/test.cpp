// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

struct stock
{
  string item_Name;
  string item_category;
  int item_Quantity;
  double item_Price;
};

struct supplier_products
{
    string Supplier_item_Name;
    int Supplier_item_Quantity = 0;
    double Supplier_item_Price = 0;
};

class inventory
{
    private:
    //-------------------------
    // ADMIN LOGIN CREDIENTIALS
    //-------------------------
    string Admin_Username_Saved = "s"; 
    string Admin_Password_Saved = "s";

    //-------------------------
    // SUPPLIER LOGIN DETAILS
    //-------------------------
    map<string, pair<string,vector<supplier_products>>> customer; // New Map
    
    string current_user;
     
    //-------------------------
    //         ITEMS
    //-------------------------
vector <stock> product = { {"Beans"      , "Vegetable"  , 50  , 12.76 },
                           {"Bananas"    , "Fruit"      , 100 , 15.3  },
                           {"Potato"     , "Vegetable"  , 70  , 20.9  },
                           {"Mangoes"    , "Fruit"      , 90  , 25.1  },
                           {"Tomato"     , "Vegetable"  , 30  , 14    },
                           {"Strawberry" , "Fruit"      , 85  , 17.9  },
                           {"Shampoo"    , "Cosmetics"  , 90  , 25.1  },
                           {"Lotion"     , "Cosmetics"  , 30  , 14    },
                           {"Hair Oil"   , "Cosmetics"  , 85  , 17.9  }
                         };
//-------------------------
//    SUPPLIER ITEMS
//-------------------------
map<string, vector<supplier_products>> Supplier_items;
map<string, supplier_products> Supplier_cart;
  
public:
//-------------------------
//      ADMIN LOGIN
//-------------------------
   void Admin_Authorization() {
        system("cls");
        string Admin_Username; 
        string Admin_password;
        cout << "\t\t=================  "<<endl;
        cout << "\t\t   ADMIN LOGIN  "<<endl;
        cout << "\t\t=================  \n\n"<<endl;
        cout << "ENTER USERNAME : ";
        cin >> Admin_Username;
        cout << "ENTER PASSWORD : ";
        cin >> Admin_password;
        if (Admin_Username == Admin_Username_Saved &&
            Admin_password == Admin_Password_Saved) 
        {
            system("cls");
            cout << "\t\t\t==============" << endl ;
            cout << "\t\t\t  LOGIN DONE." << endl ;
            cout<< "\t\t\t=============="<<endl;
            cout << endl;
            cout << endl;
            system("pause");
            Admin_Menu();
        } else 
        {
            cout << "Wrong Info ! \nAccess Denied!"<<endl;
            cout << " 1) Try Again : "<<endl;
            cout << " 2) Exit : ";
            char choice;
            cin >> choice;
            switch (choice) 
            {
                case '1':
                    Admin_Authorization();
                    break;
                case '2':
                    execute();
                    break;
                default:
                    cout << "Invalid Choice : "<<endl;
                    cout << "Press Any Key to Exit  : "<<endl;
                    exit(0);
            }
        }
    }
//-------------------------
//      ADMIN MENU
//-------------------------
void Admin_Menu()
{
    system("cls");
    char choice;
    cout << "\t\t================" << endl;
    cout << "\t\t  WELCOME BACK" << endl;
    cout << "\t\t================\n\n" << endl;
    cout << "\t\t====================\n\n" << endl;
    cout << "\t\tAVAILABLE SUPPLIERS:\n";
    cout << "\t\t====================\n\n" << endl;
    cout<<" 1) VIEW STOCK : "<<endl;
    cout<<" 2) CHANGE AN EXISTING STOCK : "<<endl;
    cout<<" 3) ADD A NEW STOCK : "<<endl;
    cout<<" 4) DISPLAY CATOGRIZED STOCKS : "<<endl;
    cout<<" 5) LOGOUT : \n"<<endl;
    cout<<"ENTER A CHOICE : ";
    cin>>choice;
    switch(choice)
    {
        case '1':
        Display_Stock();
        break;
        case '2':
        Existing_Stock_Change();
        break;
        case '3':
        Add_New_Stock();
        break;
        case '4':
        Display_Categories();
        break;
        case '5':
        execute();
        break;
        default:
        system("cls");
        cout<<"Invalid Choice !";
        system("pause");
        execute();
        break;
    }
}
//-------------------------
//   STOCK MANIPULATION
//-------------------------
void Existing_Stock_Change()
{
    system("cls");
     cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
        << setw(15) << left <<"Category" << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;
         for (size_t i = 0; i < product.size(); i++)
        {
            cout<< setw(10) << left << i + 1 << setw(20) << left << product[i].item_Name
            << setw(15) << left << product[i].item_Quantity << fixed << setprecision(2)  << "$ "<< product[i].item_Price<<endl;
        }
    int stockitem;
    cout<<endl;
    cout<<endl;
    cout<<"Enter The Stock Number To Be Replaced : ";
    cin>>stockitem;
    if(stockitem < 1 || stockitem > product.size())
    {
        system("cls");
        char Verify;
        cout << "The Number Your Entered Is Out of Range ! " << endl;
              cout << " 1) Try Again : " ;
              cout << " 2) Exit : " ;
              cin >> Verify;
              if(Verify == '1')
              {
                  Existing_Stock_Change();
              }
              else if(Verify == '2')
              {
                  Admin_Menu();
              }
              else
              {
                  cout << "Wrong Choice ! "<<endl;
                  system("pause");
               Admin_Menu();              
              }
         }

        int i = stockitem -1; 
        string new_stock_name;
        string new_stock_category;
        int new_stock_quantity;
        double new_stock_price;
         cin.ignore();
               cout << "Enter The New Name For " << product[i].item_Name<< " : " ;
               getline(cin,new_stock_name);
               cout << "Enter The Category : ";
               cin>>new_stock_category;
               cout << "Enter The Quantity : ";
               cin>>new_stock_quantity;
               cout << "Enter The Price : ";
               cin>>new_stock_price;
         product[i].item_Name = new_stock_name;
         product[i].item_category = new_stock_category;
         product[i].item_Quantity = new_stock_quantity ;
        product[i].item_Price = new_stock_price;
        cout<<"NEW ITEM ADDED !! "<<endl;
        system("pause");
        Admin_Menu();
         
}
void Add_New_Stock()
{
    system("cls");
    string new_item_name;
    string new_item_category;
    int new_item_quantity;
    double new_item_price;

    cin.ignore();
    cout<<"ENTER A NEW STOCK NAME : " ;
    getline(cin,new_item_name); 
    cout<<"ENTER A NEW STOCK QUANTITY : " ; 
    cin >> new_item_quantity; 
    cout<<"ENTER A NEW STOCK CATEGORY : " ; 
    cin >> new_item_category; 
    cout<<"ENTER A NEW STOCK PRICE : " ; 
    cin >> new_item_price;

    stock values;
    values.item_Name = new_item_name;
    values.item_Quantity = new_item_quantity;
    values.item_category = new_item_category;
    values.item_Price = new_item_price;
    product.push_back(values);

    cout<<"STOCK ITEM ADDED SUCCESFULLY !! "<<endl;
    cout<<endl;
    system("pause");
    Admin_Menu();
}
//-------------------------
//     SUPPLIER MENU
//-------------------------
void Supplier_Menu() 
{
    system("cls");
    cout << "\t\t========================" << endl;
    cout << "\t\t    SUPPLIER MENU " << endl;
    cout << "\t\t========================\n\n" << endl;

    char choice;
    cout << "\n 1) SIGN UP" << endl;
    cout << " 2) LOGIN" << endl;
    cout << " 3) EXIT\n" << endl;
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice) 
    {
        case '1':
            supplier_Signup();
            break;
        case '2':
            supplier_Authorization();
            break;
        case '3':
            execute();
            break;
        default:
            system("cls");
            cout << "INVALID CHOICE!!\n\n";
            system("pause");
            Supplier_Menu();
            break;
    }
}

//-------------------------
//    SUPPLIER SIGNUP
//-------------------------
void supplier_Signup() 
{
    system("cls");
    string Supplier_Username; //Map Key
    string Supplier_Password; //Pair First
    supplier_products y; //Pair Second
    

    cout << "\t================================" << endl;
    cout << "\tWELCOME TO INVENTORY SIGNUP HERE" << endl;
    cout << "\t================================\n\n" << endl;

    cin.ignore();
    cout << "CHOOSE YOURSELF A USERNAME : ";
    getline(cin, Supplier_Username);
    cout << "CHOOSE YOURSELF A PASSWORD : ";
    cin >> Supplier_Password;

    supplier_products tmp_obj;
    vector<supplier_products> tmp_vec;
    tmp_obj.Supplier_item_Name = "test";
    tmp_obj.Supplier_item_Quantity = 0;
    tmp_obj.Supplier_item_Price = 0;
    tmp_vec.push_back(y);

    bool username_exists = false;

    for(auto &i : customer)
    {
        if (i.first == Supplier_Username)
        {
            username_exists = true;
        }
    }

    if (username_exists) 
    {
        cout << "\nUSERNAME ALREADY EXISTS!\nPlease try again with a different username." << endl;
        system("pause");
        supplier_Signup();
    }
    else 
    {
        system("cls");
    // customer[Supplier_Username] = make_pair(Supplier_Password, tmp_obj);
    customer[Supplier_Username] = make_pair(Supplier_Password, vector<supplier_products> {tmp_obj});
    // customer[Supplier_Username] = {Supplier_Password,tmp_vec};
        cout << "\n\nSIGNUP SUCCESSFUL ! \n\n" << endl;
        system("pause");
        Supplier_Menu();
    }
}


//---------------------------
//   SUPPLIER AUTHORIZATION
//---------------------------
void supplier_Authorization() 
{
    system("cls");
    string Supplier_Username;
    string Supplier_Password;
    cout << "\t================= " << endl;
    cout << "\t SUPPLIER LOGIN " << endl;
    cout << "\t=================\n\n " << endl;
    cin.ignore();
    cout << "ENTER YOUR LOGIN USERNAME : ";
    getline(cin,Supplier_Username);
    cout << "ENTER YOUR LOGIN PASSWORD : ";
    cin >> Supplier_Password;

    auto id = customer.find(Supplier_Username);
    if (id != customer.end() && id->second.first == Supplier_Password) 
    {
        // current_user = Supplier_Username;
        current_user = id->first;
        system("cls");
        cout << " \n\nLOGIN DONE !!" <<endl;
        cout<<"\nWelcome "<<id->first<<endl<<endl;
        system("pause");
        Supplier_Choice();
    }
    else 
    {
        char choice;
        system("cls");
        cout << "\n\nTHE USERNAME OR PASSWORD YOU ENTERED IS WRONG \n\n!! "<<endl;
        cout << " 1) TRY AGAIN "<<endl;
        cout << " 2) EXIT "<<endl;
        cout << " ENTER YOUR CHOICE : ";
        cin >> choice;

        (choice=='1') ? supplier_Authorization() : exit(0);
    }
}

//---------------------------
//   SUPPLIER PURCHASING 
//---------------------------
void Supplier_Choice() 
{
    system("cls");
    cout << "\t\t======================" << endl;
    cout << "\t\t    WAREHOUSE STOCK " << endl;
    cout << "\t\t======================\n\n" << endl;
    
    cout << setw(10) << left << "No" 
         << setw(20) << left << "Item Name " 
         << setw(15) << left << "Category" 
         << setw(15) << left << "Quantity"
         << setw(10) << left << "Price";
    cout << endl;
    cout << endl;
    for (size_t i = 0; i < product.size(); i++)
    {
        cout << setw(10) << left << i +1 
             << setw(20) << left << product[i].item_Name
             << setw(15) << left << product[i].item_category 
             << setw(15) << left << product[i].item_Quantity 
             << fixed << setprecision(2) <<"$ "<< product[i].item_Price << endl;
    }

    char choice;
    cout << "\n\n 1) BUY PRODUCTS : "<<endl;
    cout << " 2) VIEW BOUGHT PRODUCTS : "<<endl;
    cout << " 3) LOGOUT : "<<endl;
    cout << "\nENTER YOUR CHOICE : ";
    cin >> choice;

    switch(choice) 
    {
        case '1':
            Supplier_Purchasing_Products();
            break;
        case '2':
            Supplier_Item_Storage();
            break;
        case '3':
            execute();
            break;
        default:
            cout << "Invalid Choice !! " << endl;
            cout << endl;
            system("pause");
            Supplier_Menu();
    }
}

//-------------------------
// SUPPLIER PURCHASING 
//-------------------------
void Supplier_Purchasing_Products() 
{
    system("cls");
    char choice;
    cout << "\t\t\t======================" << endl;
    cout << "\t\t\t  BUYING INTERFACE " << endl;
    cout << "\t\t\t======================\n\n" << endl;
     cout<< setw(10) << left << "No" 
         << setw(20) << left << "Item Name " 
         << setw(15) << left << "Category" 
         << setw(15) << left << "Quantity"
         << setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;

        for (size_t i = 0; i < product.size(); i++)
        {
            cout<< setw(10) << left << i+1 
                << setw(20) << left << product[i].item_Name
                << setw(15) << left << product[i].item_category 
                << setw(15) << left << product[i].item_Quantity 
                << fixed << setprecision(2) <<"$ "<< product[i].item_Price<<endl;
        }
    cout << "\n\n\nPRESS 1 TO BUY 1 ITEMS " << endl;
    cout << "PRESS 2 TO BUY 5 ITEMS " << endl;
    cout << "PRESS E/e TO RETURN TO TH STOCK INTERFACE \n\n" << endl;
    cout << "ENTER YOUR CHOICE : ";
    cin >> choice;
    int Num_To_Buy;
    int itemNumber;
    int index;
    bool iteminCart = false;
    int num = 0;

    switch (choice) 
    {
        case '1':
            Num_To_Buy = 1;
            cout << "ENTER THE NUMBER OF ITEM TO BE BOUGHT : ";
            cin >> itemNumber;
            if (itemNumber < 1 || itemNumber > product.size()) 
            {
                cout << "INVALID ITEM NUMBER !! \n\n" << endl;
                system("pause");
                Supplier_Purchasing_Products();
                return;
            }

            index = itemNumber - 1;
            int found;
//-----------------------------------------------------------------------------------------
        for(auto i = customer[current_user].second.begin(); i!= customer[current_user].second.end(); i++)
        {
            if(customer[current_user].second[num].Supplier_item_Name == "test")
            {
                
            }
        }
//-----------------------------------------------------------------------------------------
        if (product[index].item_Quantity >= Num_To_Buy)
        {
            num = 0;
            for(auto i = customer[current_user].second.begin(); i!= customer[current_user].second.end(); i++)
            {
                if(customer[current_user].second[num].Supplier_item_Name == product[index].item_Name)
                {
                    found = num;
                    iteminCart = true;
                    break;
                }
                num++;
            }
            if(iteminCart)
            {
                customer[current_user].second[found].Supplier_item_Quantity += Num_To_Buy;
                customer[current_user].second[found].Supplier_item_Price += product[index].item_Price;
                product[index].item_Quantity -= 1;
            }
            else
            {
                supplier_products tmp;
                tmp.Supplier_item_Name = product[index].item_Name;
                tmp.Supplier_item_Quantity = Num_To_Buy;
                tmp.Supplier_item_Price = product[index].item_Price;

                product[index].item_Quantity -= Num_To_Buy;
                customer[current_user].second.push_back(tmp);
            }
//-----------------------------------------------------------------------------------------
            cout << "\n\nPURCHASE SUCCESSFUL!!\n" << endl;
        } 
        else
        {
            cout << "\n\nNOT ENOUGH QUANTITY AVAILABLE!!\n" << endl;
        }
        break;            
//-----------------------------------------------------------------------------------------
        case '2': 
            Num_To_Buy = 5;
            cout << "ENTER THE NUMBER OF ITEM TO BE BOUGHT : ";
            cin >> itemNumber;

            if (product[index].item_Quantity >= Num_To_Buy) {
            supplier_products tmp;
            tmp.Supplier_item_Name = product[index].item_Name;
            tmp.Supplier_item_Quantity = Num_To_Buy;
            tmp.Supplier_item_Price = product[index].item_Price * Num_To_Buy;

            product[index].item_Quantity -= Num_To_Buy;

            auto it = Supplier_cart.find(product[index].item_Name);
            
            if (it != Supplier_cart.end())
            {
                it->second.Supplier_item_Quantity += Num_To_Buy;
                it->second.Supplier_item_Price += product[index].item_Price * Num_To_Buy;
            } 
            else
            {
                Supplier_cart[product[index].item_Name] = tmp;
            }

            cout << "\n\nPURCHASE SUCCESSFUL!!\n" << endl;
        } else {
            cout << "\n\nNOT ENOUGH QUANTITY AVAILABLE!!\n" << endl;
        }
            break;
        case 'E':
        case 'e':
            Supplier_Choice();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    system("pause");
    Supplier_Purchasing_Products();
}


//-------------------------
// SUPPLIER STORAGE
//-------------------------
void Supplier_Item_Storage() 
{
    system("cls");
    cout<<"\t\t========================" << endl;
    cout<<"\t\t   SUPPLIER STORAGE " << endl;
    cout<<"\t\t========================" << endl;
    cout << endl;
    cout << endl;
    cout<< setw(5) << left << "No" 
        << setw(20) << left << "Item Name " 
        << setw(15) << left <<"Quantity"
        << setw(10) << left << "Price";

    cout<<endl;
    cout<<endl;

    int count = 1;
    int index = 0;
    for(auto x = customer[current_user].second.begin(); x!= customer[current_user].second.end(); x++)
    {
    cout<< setw(5) << left << count 
        << setw(20) << left << customer[current_user].second[index].Supplier_item_Name
        << setw(15) << left << customer[current_user].second[index].Supplier_item_Quantity
        << fixed << setprecision(2) <<"$ "<< customer[current_user].second[index].Supplier_item_Price << endl;
        count++;
        index++;
    }
   
    double checkoutPrice = 0;
    index = 0;
    for(auto x = customer[current_user].second.begin(); x!= customer[current_user].second.end(); x++)
    {
        checkoutPrice += customer[current_user].second[index].Supplier_item_Price;
        index++;
    }
    cout<<endl;
    cout<<endl;
    cout<<"Checkout Prize: $"<<checkoutPrice<<endl;
    cout<<endl;
    cout<<endl;

    system("pause");
    Supplier_Choice();
}

//---------------------------
//     DISPLAY ITEMS 
//---------------------------
void Display_Stock()
{
    system("cls");
    cout << "\t======================" << endl;
    cout << "\t WARHOUSE STOCK ITEMS" << endl;
    cout << "\t======================\n\n" << endl;
      cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
        << setw(15) << left <<"Category" << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;
          for (size_t i = 0; i < product.size(); i++)
        {
            cout<< setw(10) << left << i +1 << setw(20) << left << product[i].item_Name
                << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity 
                 << fixed << setprecision(2) <<"$ "<< product[i].item_Price<<endl;
        }
    cout<<endl;
    cout<<endl;
    system("pause");
    Admin_Menu();
}
//---------------------------
// DISPLAY CATOGORIED ITEMS 
//---------------------------
void Display_Categories() 
{
        system("cls");
        cout << "\t\t====================" << endl;
        cout << "\t\t     CATEGORIES" << endl;
        cout << "\t\t====================\n\n" << endl;

        map<string, vector<stock>> categories;

        for (auto item : product) 
        {
            categories[item.item_category].push_back(item);
        }

        for (auto category: categories)
        {
            cout << "\t\t=============" << endl;
            cout << "\t\t  " << category.first << endl;
            cout << "\t\t=============\n\n" << endl;

            cout << setw(10) << left << "No" << setw(20) << left << "Item Name "
                 << setw(15) << left << "Quantity" << setw(10) << left << "Price";
            cout << endl;
            cout << endl;

            int count = 1; //Display Item ID
            for (auto item : category.second) 
            {
                cout << setw(10) << left << count << setw(20) << left << item.item_Name
                     << setw(15) << left << item.item_Quantity
                     << fixed << setprecision(2) << "$ " << item.item_Price << endl;
                count++;
            }

            cout << endl;
            cout << endl;
        }

        system("pause");
        Admin_Menu();
    }
//---------------------------
// Program Execute FUNCTION
//---------------------------
void execute()
{
    system("cls");
    char choice;
    cout << "\t===========================" << endl;
    cout << "\t WELCOME TO THE INVENTORY" << endl;
    cout << "\t===========================\n\n" << endl;
    cout<<" 1) ADMIN : "<<endl;
    cout<<" 2) SUPPLIER : "<<endl;
    cout<<" 3) EXIT : "<<endl<<endl;
    cout<<"ENTER A CHOICE : ";
    
    cin>>choice;
    switch(choice)
    {
        case '1':
        Admin_Authorization();
        break;
        case '2':
        Supplier_Menu();
        break;
        case '3':
        exit(0);
        break;
        default:
        system("cls");
        cout<<"Invalid Choice !\n\n";
        system("pause");
        execute();
    }
}

};// Class ends

//-------------------------
//     MAIN FUNCTION
//-------------------------
int main()
{   int indexNumber;
    inventory s1;
    s1.execute();
    // s1.Supplier_Choice();
return 0;
}