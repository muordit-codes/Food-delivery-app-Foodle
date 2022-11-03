/////////////////////////////////////////////
//
//  MAROP MAWIEN NGOR 				2101020687
// 
//  NATENAILE ASMAMAW SHIFERAW 		2101020423
//
//  SIMPENZWE HONORE LEANDRE 			2101020234
//
//  CV RAMAN GLOBAL UNIVERSITY
//
//	C++ PROJECT 3RD SEMESTER 2022
//
///////////////////////////////////////////////

#include<iostream>

//#include<stdexcept>

//#include<string>

//#include<ctime>

//#include<fstream>

using namespace std;

//used inheritance to make order classes as children of the Menu class

//abstraction and encapsulation using classes

//array to store names and prices of items

class Menu
{	
	string Menu_Title =" **************************************************************************************************************"
	"*********************\n\n\t\t\t\t\t\t🍴🍴🍴🍴 WELCOME TO AFRO SHOP FOODLE 🍴🍴🍴🍴\n\n ***********************************************"
	"************************************************************************************";
	
	public:

	void Display_Menu_Title();

};

void Menu::Display_Menu_Title()
{
	cout<< Menu_Title << endl;
}

class Menu_items: public Menu
{	
	protected: 

	int Purchase_Total = 0;

	int count  = 1 ;

	int Quantity;

	string Cart[15];

	int Cart_price[15];

	int Cart_choice = 1;

	public:

	void Confirm_Purchase();
		
};

class Drink_Items:public Menu_items
{
	protected:
	
	int DPurchase_Total = 0;//stores total for drinks

	string drink_list[10] =
	{
		//Rwandan drinks
		"Ikivuguto" , "Mukaru" , "Igikoma " , "Umutobe" , "Inshyushyu" ,

		"Turbo King" , "Primus " , "Green Tea" , "Coffee" , "Urwarwa"

	};

	//array to store prices of drinks
	int Drink_Price_List[10] =
	{
		100 , 200 , 120 , 300 , 60 ,

		134 , 125 , 270 , 340 , 95

	};

	public:

	void Display_drink();

	void Add_Drink_To_Cart();//add items customer wants to buy to cart array

	void Confirm_Purchase();

	int Return_Drink_Total();

};

void Drink_Items::Display_drink()
{
	int i = 0;

	count = 1;

	cout<<"																							"
	"~~~~~~~~~~~~~~~~~~🍸DRINKS🍸~~~~~~~~~~~~~~~~~~~~                                                                           "<<endl;

	for(string i : drink_list)
	{

	// cout<< "[" << i+1 << "]  "<<drink_list[i] <<"\t\t\t" << Drink_Price_List[i] << endl;

	cout<< "[" << count << "]"<<i << "\t\t\t ..."<< Drink_Price_List[count-1] << " INR " <<endl;

	count++;

	}
	
}

void Drink_Items::Add_Drink_To_Cart()
{
	/// @brief calculates total cost
	Purchase_Total = 0;

	ofstream Receipt_File("Receipt.txt");

	Receipt_File << " \t\t\t\t\t\t ~~~~~~~~~~YOUR CART ITEMS~~~~~~~~~~  \n";

	Cart_choice = 1;//variable to run loop and store index of cart items

	while(Cart_choice != 0)
	{
	cout<<" Select an item to add to yout cart or press '0' to exit:  ";

	cin>>Cart_choice;

	if (Cart_choice == 0)
	{
		break;
	}
	

	cout<< " How many pieces do you want? "<<endl;

	cin>>Quantity;

// try block needed
		try
		{
			if(Cart_choice < 1)
			{
				throw(Cart_choice);
			}
			else if (Cart_choice > sizeof(drink_list)/sizeof(string))
			{
				throw(Cart_choice);
			}
	
			Cart[Cart_choice-1] = drink_list[Cart_choice-1];

			Receipt_File << drink_list[Cart_choice-1] << "\t\t"<<Drink_Price_List[Cart_choice-1] <<" X " << Quantity << endl;

			DPurchase_Total += (Drink_Price_List[Cart_choice-1] * Quantity);

		}	

		catch(...)
		{
			cout<<"Enter a valid choice. \n" ;
		}

	}	

	Receipt_File<< "\n \n----------------------------------------------------------------------\n";

	Receipt_File << "Purchase total :  " << DPurchase_Total;

	Receipt_File.close();
}

void Drink_Items::Confirm_Purchase()
{
	/// @brief displays total bill to customer
	/// @param Confirm_Purchase 
	char Confirm;

	string Display_Cart_Line;

	cout<<" Would you like to buy the selected items? \n Press y :"<<endl;

	ifstream ReceiptFile("Receipt.txt");

	while (getline(ReceiptFile , Display_Cart_Line ))
	{
		cout << Display_Cart_Line << endl;
	}
	
	cin>> Confirm;

	if (Confirm == 'y')
	{
		cout<<" Your total bill is:  "<<endl;

		cout<< DPurchase_Total << endl;
	}
}

int Drink_Items::Return_Drink_Total()
{
	int Drink_Total = DPurchase_Total;

	return Drink_Total;
}

class Food_Items:public Menu_items
{
	protected:

	int FPurchase_Total;

	string Food_List[15] =
	{
		//Rwandan foods 
		
		"Igitoki" , "Ibijumba" , "Umuceri" , "Ibigori" , "Ibirayi" ,
		
		//Ethiopian foods			//South Sudan									
		"Injera" , "Doro Wet" , "Piri Piri Chicken" , "Wala-wala" , "Ful sudani" , 
	
		"Tamia" , "Kisra", "Full Medames" , "Kapenta with Sadza" , "Jollof Rice and egusi soup" 

	};

	int Food_Price_List[15] =
	{
		90 , 60 , 120 , 80 , 75 ,

		100 , 40 , 200 , 150 , 90 ,

		160 , 230 , 170 , 85 , 65

	};

	public:

	void Add_Food_To_Cart();

	void Display_Food();

	void Confirm_Food_Purchase();

	int Return_Food_Total();

};

void Food_Items::Display_Food()
{
	int i = 0;

	count = 1;

	cout<<"																							"
	"~~~~~~~~~~~~~~~~~~~🍴🍴FOOD🍴🍴~~~~~~~~~~~~~~~~~~~~~                                              "
	"                             "<<endl;

	for(string i : Food_List)
	{

	cout<< "[" << count << "]"<<i << "\t\t..."<< Food_Price_List[count-1] << " INR " <<endl;

	count++;

	}

}

void Food_Items::Add_Food_To_Cart()
{
	/// @brief calculates total cost of foods added to cart
	FPurchase_Total = 0;

	ofstream Receipt_File("Receipt.txt");

	Receipt_File << " \t\t\t\t\t\t ~~~~~~~~~~YOUR CART ITEMS~~~~~~~~~~  \n";

	Cart_choice = 1;//variable to run loop and store index of cart items

	while(Cart_choice != 0)
	{
	cout<<" Select an item to add to your cart or press '0' to exit:  ";

	cin>>Cart_choice;

	if (Cart_choice == 0)
	{
		break;
	}
	
	cout<< " How many pieces do you want? "<<endl;

	cin>>Quantity;

// try block needed
		try
		{	
			if(Cart_choice < 1)
			{
				throw(Cart_choice);
			}
			else if (Cart_choice > sizeof(Food_List)/sizeof(string))
			{
				throw(Cart_choice);
			}
		
			Cart[Cart_choice-1] = Food_List[Cart_choice-1];

			Cart_price[Cart_choice-1] = Food_Price_List[Cart_choice-1];

			Receipt_File << Food_List[Cart_choice-1] << "\t\t"<<Food_Price_List[Cart_choice-1] <<" X " << Quantity << endl;

			FPurchase_Total += (Food_Price_List[Cart_choice-1] * Quantity);
		}	

		catch(...)
		{
			cout<<"Enter a valid choice. \n" ;
		}

	}
	
	Receipt_File<< "\n \n----------------------------------------------------------------------\n";

	Receipt_File << "Purchase total:  " << FPurchase_Total;

	Receipt_File.close();

}

void Food_Items::Confirm_Food_Purchase()
{
	/// @brief displays total bill to customer
	/// @param Confirm_Purchase 
	char Confirm;

	string Display_Cart_Line;

	cout<<" Would you like to buy the selected items? \n Press y :"<<endl;

	ifstream ReceiptFile("Receipt.txt");

	while (getline(ReceiptFile , Display_Cart_Line ))
	{
		cout << Display_Cart_Line << endl;
	}
	
	cin>> Confirm;

	if (Confirm == 'y')
	{
		cout<<" Your total bill is:  "<<endl;

		cout<< FPurchase_Total << endl;
	}

}

int Food_Items::Return_Food_Total()
{
	int Food_total = FPurchase_Total;

	return Food_total;
}

class Customer:Menu_items
{	
	/// customer class contains name of customer and public funtions to initialise member

	string CustomerName;

    public:
	
	char Menu_choice;
	
	Customer()	///constructor dynamically initialises customer name
	{
	cout<<"\t\t\tToday is : "<<__DATE__<<endl;

	cout<<"\t\t\t👋 Hello. Please enter your name: "<< endl;

	getline(cin , CustomerName);

	}

	void Display_Name();

};

void Customer::Display_Name()
{
	cout <<"👋"<< CustomerName << "\n";
}

void Start_Shopping()
{
	Customer New_Customer;

	Drink_Items DNew_Customer;

	Food_Items FNew_Customer;

	int Switch_Count = 0;//keeps count of how many times the second or first switch statements are run

	//Loop to keep app running and select items

	cout<< "Welcome to our store ";

	New_Customer.Display_Name();

	cout<<". \nWhat would you like to have today ?";

	New_Customer.Menu_choice = 'y' ;

	do{
		cout<<"\nPlease press the number corresponding to the desired option:  "<<endl;

		cout<<"[1] Foods \n[2] Drink \n[3] Total cost of purchases\n";

		cin>> New_Customer.Menu_choice;

		int Total_Bill = 0;

		//select drink or select food
		
		switch(New_Customer.Menu_choice)
		{

			case '1':

			Switch_Count++;

			FNew_Customer.Display_Food();

			FNew_Customer.Add_Food_To_Cart();

			FNew_Customer.Confirm_Food_Purchase();

			break;

			case '2':

			Switch_Count++;

			DNew_Customer.Display_drink();

			DNew_Customer.Add_Drink_To_Cart();

			DNew_Customer.Confirm_Purchase();

			case '3':

			if (Switch_Count == 0)
			{
				Total_Bill = 0;

				cout <<"\n \t \t Your overall bill for the order issued on "<< __DATE__<<" is: "<< Total_Bill ;

			}

			else
			{
				int food_bill = FNew_Customer.Return_Food_Total();

				int drink_bill = DNew_Customer.Return_Drink_Total(); 

				Total_Bill =  food_bill +drink_bill;

				cout << "Dear ";
				
				New_Customer.Display_Name();

				cout<<"\n \t \t Your overall bill for the order issued on "<< __DATE__<<" is: "<< Total_Bill ;

				cout<<"\n \t \t You will get a notification when your items arrive \n";

			}
			
			break;
		

			default:

			cout<< "\nInvalid choice \n";

			break;
			

		}

		cout<<" \nPress 'y' if you would like to buy more items or press 'n' if you would like to exit. \n";
		
		try
		{	

			cin >> New_Customer.Menu_choice;

			if(New_Customer.Menu_choice != 'y')
			{
				throw(New_Customer.Menu_choice);
			}

		}
		catch(...)
		{
			cout << "Goodbye  ";

			New_Customer.Display_Name();
		}

	}

	while(New_Customer.Menu_choice == 'y');	
}

int main()
{
	Menu Foodle;

	Foodle.Display_Menu_Title();

	Start_Shopping();

	cout<< "\n\nThank you for shopping with us!!!"<<endl;

	return 0;
}
