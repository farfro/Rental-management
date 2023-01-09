#include "board.h"

//Name: Saimon Asghedom
//course: CS202
//file: in this file I will build the program appilication to use the objects
//and data structure

int main()
{
	red_black bulletin;
	short_term short_obj;
	school_year school_obj;
	long_term long_obj;
	rental * obj;
	int option, option1;
	int price;


	do
	{
	     cout << "Welcome to the rental bulletin board." << endl;
	     cout << "1. add a new rental. " << endl;
	     cout << "2. display all available rentals. " << endl;
	     cout << "3. search for a rental by price. " << endl;
	     cout << "4. remove a rental. " << endl;
	     cout << "Choose from the following: ";
	     cin >> option;
	     cin.ignore(100, '\n');

	     switch(option)
	     {
		     case 1:
			  do
			  {
			     cout << "1. Short term rental. " << endl;
			     cout << "2. Rental for the school year. " << endl;
			     cout << "3. long term rental. " << endl;
			     cout << "Choose rental type to add: ";
			     cin >> option1;
			     cin.ignore(100, '\n');

			     switch(option1)
			     {
				case 1:
				     short_obj.set();
				     bulletin.add_request(short_obj);
				     break;
				case 2:
				     school_obj.set();
				     bulletin.add_request(school_obj);
				     break;
				case 3:
				     long_obj.set();
				     bulletin.add_request(long_obj);
				     break;
				default:
				     short_obj.set();
				     bulletin.add_request(short_obj);
			     }

			     cout << "Enter any number to add more rental or 0 to continue: ";
			     cin >> option1;
			     cin.ignore(100, '\n');

			   }while(option1 != 0);
			   break;
		      case 2:
			   bulletin.display_all();
			   break;
		      case 3:
			   cout << "Enter the price: ";
			   cin >> price;
			   cin.ignore(100, '\n');
			   if(!bulletin.retrieve(price, obj))
		           {
			        cout << "No Match. " << endl;
			   }
			   else
		           {
			        cout << *obj;
				delete obj;
				obj = NULL;
			   }
			   break;
		      case 4:
			   cout << "Enter the price of rental to remove: ";
			   cin >> price;
			   cin.ignore(100, '\n');

			   if(!bulletin.remove(price))
				cout << "Unable to remove. " << endl;
			   else
				cout << "Successfully removed. " << endl;
			   break;

	     }

	     cout << "Enter 1 to see the options again, or 0 to exit: ";
	     cin >> option;
	     cin.ignore(100, '\n');
	}while(option != 0);
   return 0;
}

