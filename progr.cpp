#include "prog3.h"

//Name: Saimon Asghedom
//course: CS202
//file: in this file I will implement the code for the heirarchy 
//and have operators overloaded 

using namespace std;

//default constructor
rental::rental()
{
	address = " ";
	contact = " ";
	price = 0;
	criminal_record = false;
	credit_scr = false;
}

//constructor with arguments
rental::rental(string addr, string phone, int cost)
{
	address = addr;
	contact = phone;
	price = cost;
}

//destructor
rental::~rental() {}

//function that will prompt the user for some info
void rental::bk_check()
{
        char answer;
        int choice = 0;

        try				//exception handling to throw if there are not the right input
        {
          cout << "Do you run background check: ";
          cin >> answer;
          cin.ignore(100, '\n');
          answer = toupper(answer);
          if(answer != 'Y' && answer != 'N')
                throw answer;
          if(answer == 'Y')
          {
                cout << "1. criminal record. " << endl;
                cout << "2. credit history. " << endl;
                cout << "3. both. " << endl;
		cout << "Which backgroud info is required: " << endl;
                cin >> choice;
                cin.ignore(100, '\n');

                switch(choice)
                {
                    case 1:
                         criminal_record = true;
                         break;
                    case 2:
                         credit_scr = true;
                         break;
                   case 3:
                         criminal_record = credit_scr = true;
                         break;
                    default:
                         criminal_record = credit_scr = false;
                }
           }
        }
        catch(char)
        {
           cout << "Entered " << answer << "Invalid answer...please try again." << endl;
           bk_check();
        }

}

//function that will display info
void rental::display(ostream & out) const
{
	out << "Address: " << address << endl;
	out << "Contact-info: " << contact << endl;
	out << "Price: " << price << endl;
}

//overloading the extraction operator
ostream & operator << (ostream & out, const rental & source)
{
	source.display(out);	//call to the virtual display function
	return out;
}

//function that will prompt the user for info
void rental::set()
{
	cout << "Enter the address: ";
	getline(cin, address);
	cout << "Enter contact info: ";
	getline(cin, contact);
	cout << "Enter the price: ";
	cin >> price;
	cin.ignore(100, '\n');
}

//overloading the += operator to add price
rental & rental::operator += (const int raise)
{
	price += raise;
	return *this;
}

//overloading the == operator 
bool operator == (const rental & op1, const rental & op2)
{
	if(op1.compare(op2) == 0) //call to the compare function
		return 1;
	return 0;
}
//overloading the < operator
bool operator < (const rental & op1, const rental & op2)
{

	if(op1.compare(op2) < 0)	//call to compare function
		return 1;
	return 0;
}
//overloading the > operator
bool operator > (const rental & op1, const rental & op2)
{
	if(op1.compare(op2) > 0)	//call the compare function
		return 1;
	return 0;
}
//overloading the >= operator
bool operator >= (const rental & op1, const rental & op2)
{
	if(op1.compare(op2) >= 0)	//call the compare function
		return 1;
	return 0;
}
//overloading the <= operator
bool operator <= (const rental & op1, const rental & op2)
{
	if(op1.compare(op2) <= 0)	//call the compare function
		return 1;
	return 0;
}
//overloading != operator
bool operator != (const rental & op1, const rental & op2)
{
	return !(op1 == op2); //call the overloaded == operator
}
//overloading the < operator
bool operator < (int op1, const rental & op2)
{
	if(op2.compare(op1) < 0)	//call the compare function
		return true;
	return false;
}

//overloading the == operator
bool operator == (int op1, const rental & op2)
{
	if(op2.compare(op1) == 0)	//call the compare function
		return true;
	return false;
}

//compare function that will compare the prices
int rental::compare(const rental & source) const
{
	if(price == source.price)
                return 0;
        else if(price < source.price)
                return -1;
        else
                return 1;

}

//compare function with different argument
int rental::compare(int op1) const
{
        if(op1 == price)
             return 0;
        else if(op1 < price)
             return -1;
        else
             return 1;
}

//default constructor
short_term::short_term()
{
	description = " ";
}

//constructor with arguments
short_term::short_term(string location, string detail, string phone, int cost): rental(location, phone, cost)
{
	description = detail;
	bk_check();
}

//function that will prompt the user for info
void short_term::set()
{
	  rental::set();
	  cout << "Enter the description: ";
	  getline(cin, description);
	  bk_check();
}

//function that will display the info
void short_term::display(ostream & out) const
{
	rental::display(out);
	out << "Description: " << description << endl;
	if(criminal_record)
	  cout << "* we run background check for criminal record. " << endl;
	if(credit_scr)
	  cout << "* we run background check for credit score. " << endl;
}
//oveloading the += operator to add more info
short_term & short_term::operator +=(string add)
{
	description.append(add);
	return *this;
}

//default constructor
school_year::school_year()
{
        description = " ";
}

//constructor with argument
school_year::school_year(string location, string detail, string phone, int cost): rental(location, phone, cost)
{
        description = detail;
	bk_check();
}

//function to prompt the user and set the data members
void school_year::set()
{
        rental::set();
        cout << "Enter the description: ";
        getline(cin, description);
	bk_check();
}

//function to display the info
void school_year::display(ostream & out) const
{
	rental::display(out);
        out << "Description: " << description << endl;
        if(criminal_record)
          cout << "* we run background check for criminal record. " << endl;
        if(credit_scr)
          cout << "* we run background check for credit score. " << endl;

}
//overloading the += operator to add more info
school_year & school_year::operator += (string add)
{
	description.append(add);
	return *this;
}

//default constructor
long_term::long_term()
{
        description = " ";
}

//constructor with argument
long_term::long_term(string location, string detail, string phone, int cost): rental(location, phone, cost)
{
        description = detail;
	bk_check();
}

//function to prompt the user and set data members
void long_term::set()
{
        rental::set();
        cout << "Enter the description: ";
        getline(cin, description);
	bk_check();
}

//function to display the info
void long_term::display(ostream & out) const
{
	rental::display(out);
        out << "Description: " << description << endl;
        if(criminal_record)
          cout << "* we run background check for criminal record. " << endl;
        if(credit_scr)
          cout << "* we run background check for credit score. " << endl;

}
//oveloading the += operator to add more info
long_term & long_term::operator +=(string add)
{
	description.append(add);
	return *this;
}


