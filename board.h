#include "prog3.h"

//Name: Saimon Asghedom
//course: CS202
//file:  in this file I'm going to create a node class that will be used
//       to set up a data structure to implement a table of rental request

class node
{
	public:
	      node();			//deafult construtore
	      node(const node &);	//copy constructor
	      node(rental *);		//constructor that take rental ptr
	      ~node();			//destructor

	      //overloading the extraction operator
	      //takes ostream obj and node obj
	      friend ostream & operator << (ostream & out, const node & op2);
	      //overloading the < operator
	      //takes rental obj and node obj
	      friend bool operator < (const rental & op1, const node & op2);
	      //overloading the == operator
	      //takes rental obj and node obj
	      friend bool operator == (const rental & op1, const node & op2);
	      //overloading the < operator
	      //with differnet argument
	      //takes an int and node obj
	      friend bool operator < (int op1, const node & op2);
	      //overloading the == operator
	      //with differnt argument
	      //takes int and node obj
	      friend bool operator == (int op1, const node & op2);
	      //overloading the assignment operator
	      node & operator = (const node &);

	      node * & go_right();	//getter function that return right
	      node * & go_left();	//gettet function that return left
	      void set_right(node * connect);	//function that set right
	      void set_left(node * connect);	//function that set left
	      bool retrieve(rental * &);	//wrapper function that retrieve rental obj

	private:
	      rental * request;			
	      node * right;
	      node * left;
};

//class red_black to be used to manage the node data structure
class red_black
{
	public:
	      red_black();			//default constructor
	      red_black(const red_black &);	//copy constructor
	      ~red_black();			//destructor
	      void remove_all();		//function to remove all rental obj
	      void display_all();		//function to display all rental obj
	      //function to add rental obj
	      //to the tree and takes a rental
	      //obj as arg
	      void add_request(rental &);
      	      //function to retrieve a rental
	      //obj from the tree, return 1
	      //if success, 0 otherwise	      
	      bool retrieve(int, rental *&);
	      //overloading the = operator
	      red_black & operator = (const red_black &);
	      //function to remove rental obj from
	      //the tree, takes a int price from the
	      //user
	      int remove(int);

	private:
	      node * root;
	      void remove_all(node * &);			//recussive fuunction to remove all rental obj
	      void display_all(node *);				//recussive function to display all rentla obj
	      void add_request(node *&, rental &);		//recussive function to add rental obj to tree
	      //recurssive function to retrieve the rental obj
	      bool retrieve(node *, int, rental *&);
	      //recurssive function to copy the tree
	      void copy_tree(node *&, node*);
	      //recussive function to remove rental obj
	      int remove(node *&, int);
	      //utility function of remove
	      void remove_node(node *&, node *&);

};
