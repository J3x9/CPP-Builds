#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
class sys
{
private:
//---------------------------------------
//       Login Data
//---------------------------------------
string mainUserName = "l";
string mainUserPass = "l";
string adminName = "l";
string adminPass = "l";
//---------------------------------------
//       Store Data
//---------------------------------------
string stock_item[2] = {"Milk","Apples"};
int product_quantity[2] = {3,20};
double product_price[2] = {32,21};
//---------------------------------------
//       User Cart
//---------------------------------------
string user_cart_items[2];
int user_item_quantity[2] = {0,0};
double user_item_price[2] = {0,0};
int total_cart_items = sizeof(user_cart_items) / sizeof(user_cart_items[0]);
//---------------------------------------
//       Admin Controls
//---------------------------------------
void adminMenu()
{
    system("cls");
    cout<<"1) Data Entry"<<endl;
    cout<<"2) Display Stock"<<endl;
    cout<<"3) Exit"<<endl;

    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
    stockEntry();
    break;

    case 2:
    displayStock();
    break;

    case 3:
    run();
    break;
    
    default:
    cout<<"Invalid case!!!";
    getch();
    adminMenu();
    break;
    }

}
void stockEntry()
{

    system("cls");
    for (int i = 0; i < 2; i++)
    {
        string name;
        int quan;
        double pric;
        cout<<"Enter Product "<<i+1<<" Name: ";
        cin>>name;
        stock_item[i] = name;
        cout<<"Quantity: ";
        cin>>quan;
        product_quantity[i] = quan; 
        cout<<"Price: $";
        cin>>pric;
        product_price[i] = pric;
        cout<<endl;
    }
    adminMenu();
}
void displayStock()
{
    system("cls");
    cout<<"STOCK ITEMS"<<endl;
    cout<<endl;
    cout <<setw(5) << left << "No"<< setw(15) << left << "Item"
         << setw(15) << left << "Quantity"
         << setw(10) << left << "Price" << endl;
         cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << setw(5) << left <<i+1<< setw(15) << left << stock_item[i] 
             << setw(15) << left << product_quantity[i]
             << fixed << setprecision(2) // Set precision for price
             << "$" << product_price[i] << endl;
    }
}
//---------------------------------------
//       User Controls
//---------------------------------------
void userMenu()
{
    char choice;

    system("cls");
    displayStock();
    cout<<endl;
    cout<<endl;
    cout<<"1) Add to cart"<<endl;
    cout<<"2) View Cart"<<endl;
    cout<<"3) Logout"<<endl;
    cout<<"Choose: ";
    cin>>choice;
    
    switch (choice)
    {
    case '1':
    cartManipulation();
    break;

    case '2':
    viewCart();
    break;

    case '3':
    run();
    break;
    
    default:
    cout<<"Invalid case!!!";
    getch();
    userMenu();
    break;
    }

}
void cartManipulation()
{
    char choice;
    displayStock();
    cout<<endl;
    
    do{
    cout<<"Press E/e to Exit: \n";
    cout<<"Choose No: ";
    cin>>choice;
    switch (choice)
    {
    case '1':
    if (product_quantity[0] > 0)
    {
        user_cart_items[0] = stock_item[0];
        product_quantity[0] -= 1;
        user_item_quantity[0] += 1;
        user_item_price[0] += product_price[0];
    }
    else
    {
        cout<<"No More Left"<<endl;
        getch();
        cartManipulation();
    }
    break;

    case '2':
    if (product_quantity[1] > 0)
    {
        user_cart_items[1] = stock_item[1];
        product_quantity[1] -= 1;
        user_item_quantity[1] += 1;
        user_item_price[1] += product_price[1];
    }
    else
    {
        cout<<"No More Left"<<endl;
        getch();
        cartManipulation();
    }
    break;

    case 'e':
    userMenu();
    break;
    }
    }while(true);

}
void viewCart()
{
    system("cls");
    cout<<"CART"<<endl;
    cout<<endl;
    cout<<endl;
    cout <<setw(5) << left << "No"<< setw(15) << left << "Item"
    << setw(15) << left << "Quantity"
    << setw(10) << left << "Cost" << endl;

    for (int i = 0; i < total_cart_items; i++)
    {
        cout << setw(5) << left <<i+1<< setw(15) << left << user_cart_items[i] 
             << setw(15) << left << user_item_quantity[i]
             << fixed << setprecision(2) // Set precision for price
             << "$" << user_item_price[i] << endl;
    }


    double cart_item_total_price;
    for (int i = 0; i < total_cart_items; i++)
    {
        cart_item_total_price += user_item_price[i];
    }
    
    cout<<endl;
    cout<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Total items: "<<total_cart_items<<endl;
    cout<<"Total Checkout price: "<<cart_item_total_price<<endl;
    cout<<"---------------------------"<<endl;
    cout<<endl;
    cout<<endl;
}
//---------------------------------------
public:
void adminAuth()
{
    string x,y;
    system("cls");
    cout<<"username: ";
    cin>>x;
    cout<<"Password: ";
    cin>>y;
    
    if (x==adminName && y==adminPass)
    {
        system("cls");
        cout<<"Login Done"<<endl;
        cout<<"Press any to enter Admin Menu...";
        getch();
        adminMenu();
    }
    else
    {
        cout<<"Username or Password Incorrect"<<endl;
        cout<<"Enter any key to exit: ";
        getch();
        run();
    }
}

void auth(string &authUser, string &authPwd)
{
    if (authUser==mainUserName && authPwd==mainUserPass)
    {
        system("cls");
        cout<<"Login Done"<<endl;
        cout<<"Press any key to view Items"<<endl;
        getch();
        userMenu();
    }
    else
    {
        system("cls");
        cout<<"Username or Password Incorrect"<<endl;
        cout<<"Enter any key to exit: ";
        getch();
        user_Registration_Login();
    }

}

void setID()
{
    system("cls");
    cout<<"Make a username: ";
    cin>>mainUserName;
    cout<<"Enter Password: ";
    cin>>mainUserPass;
    user_Registration_Login();
}

void user_Registration_Login()
{
    system("cls");
    cout<<"--------------------------------"<<endl;
    cout<<"\t Register/Login"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"   1 : Register"<<endl;
    cout<<"   2 : Login"<<endl;
    cout<<"   3 : Exit"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"Enter Choice: ";

    int choise;
    cin>>choise;
    string x,y;

    switch (choise)
    {
    case 1:
    setID();
    break;

    case 2:
    system("cls");
    cout<<"username: ";
    cin>>x;
    cout<<"Password: ";
    cin>>y;
    auth(x,y);
    break;

    case 3:
    exit(0);
    break;
    default:
    cout<<"Ivalid Entry"<<endl;
    break;
    }
}

void run()
{
    int choice;
    system("cls");
    cout<<"Choose Role:"<<endl;
    cout<<"1) Admin"<<endl;
    cout<<"2) Customer"<<endl;
    cout<<"Enter: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
    adminAuth();
    break;

    case 2:
    user_Registration_Login();
    break;
    
    default:
    cout<<"Invalid case!!!"<<endl;
    break;
    }
}
};


int main()
{
    sys store;
    store.run();

    return 0;
}