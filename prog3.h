#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

//Name: Saimon Asghedom
//course: CS202
//file: I will define an abstract base class that has three derived classes  
//I'm going to overload some operators that will work with the each classes
//

class rental
{
	public:
	      rental();				//default constructor
	      rental(string, string, int);	//constructor with parameter
	      virtual ~rental();		//destrutor

	      virtual void set();		//vitual function to set the data members
	      //overloading the extraction operator
	      //takes ostream obj and rental obj
	      friend ostream & operator << (ostream & out, const rental & source);
	      //overloading the += operator to
	      //increase the data memeber price
	      virtual rental & operator += (const int);
	      //oveloading the relational operators
	      //they all take two rental obj and return
	      //true or false 
	      friend bool operator == (const rental &, const rental &);
	      friend bool operator < (const rental &, const rental &);
	      friend bool operator > (const rental &, const rental &);
	      friend bool operator >= (const rental &, const rental &);
	      friend bool operator <= (const rental &, const rental &);
	      friend bool operator != (const rental &, const rental &);
	      //overaloding the < and == operator with different arg
	      //take an int and rental obj and return true or false
	      friend bool operator < (int op1, const rental &);
	      friend bool operator == (int op1, const rental &);

	protected:
	      string address;
	      string contact;
	      int price;
	      bool criminal_record;
	      bool credit_scr;
	      //virtual function to display the info of
	      //the data memebers
	      virtual void display(ostream & out) const;
	      //function to compare the prices of different
	      //rental classes
	      int compare(const rental &) const;
	      //function to compare a rental obj
	      //with an int
	      int compare(int) const;
	      //function that will prompt the user
	      //set the bool data memebers
	      void bk_check();
};

//derive class of rental
class short_term: public rental
{
	public:
	      short_term();					//default constructor
	      short_term(string, string, string, int);		//constructor with parameters

	      void set();					//function to set the data memebers
	      void display(ostream & out) const;		//function to display the info in the data 
	      short_term & operator += (string);

	protected:
	      string description;			
};
	    
//derived class of rental
class school_year: public rental
{
	public:
	      school_year();					//default constructor
	      school_year(string, string, string, int);		//constructor with parameter

	      void set();					//function to set the data memebers
	      void display(ostream & out) const;		//function to display the info
	      school_year & operator += (string);

	protected:
	      string description;
};

//derived class of rental
class long_term: public rental
{
	public:
	      long_term();					//default constructor
	      long_term(string, string, string, int);		//consturctor with argument

	      void set();					//function to set the data members
	      void display(ostream & out) const;		//function to display the info
	      long_term & operator += (string);

       protected:
	      string description;
};
