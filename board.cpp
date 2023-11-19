#include "board.h"

//Name: Saimon Asghedom
//course: CS202
//file: in this file I'm going to implement the node class and the BST class which
//will contain the node class to create a data structure to manage

//default constructor
node::node(): request(NULL), right(NULL), left(NULL)
{
}

//constructor with a rental ptr as parameter
node::node(rental * source): right(NULL), left(NULL)
{
        rental * temp = source;                                        //to determine what rental 
        const short_term * obj = dynamic_cast<short_term *> (temp);    //is pointing to we are going
        if(obj)                                                        //to used dynamic cast to assign
           request = new short_term(*obj);                             //request to pointer of rental
        else                                                           //if one of the pointers is not null
        {                                                              //then we create a memory of the copy
           const school_year * obj = dynamic_cast<school_year *> (temp); //request and give it the data
           if(obj)
              request = new school_year(*obj);
           else
           {
              const long_term * obj = dynamic_cast<long_term *> (temp);
              if(obj)
                   request = new long_term(*obj);
              else
                   request = NULL;
           }
        }
}

//copy constructor with a node obj reference as arg
node::node(const node & source): right(NULL), left(NULL)
{
	rental * temp = source.request;				       //to determine what rental 
	const short_term * obj = dynamic_cast<short_term *> (temp);    //is pointing to we are going
	if(obj)							       //to used dynamic cast to assign
	   request = new short_term(*obj);			       //request to pointer of rental
	else							       //if one of the pointers is not null
	{							       //then we create a memory of the copy
	   const school_year * obj = dynamic_cast<school_year *> (temp); //request and give it the data
	   if(obj)
	      request = new school_year(*obj);
	   else
	   {
	      const long_term * obj = dynamic_cast<long_term *> (temp);
	      if(obj)
		   request = new long_term(*obj);
	      else
		   request = NULL;
	   }
	}

}

//destructor
node::~node()
{
	if(request)
	{
	    delete request;
	    request = NULL;
	}
	right = NULL;
	left = NULL;
}

//overloading the extraction operator for the node class
//takes ostream and node obj
ostream & operator << (ostream & out, const node & op2)
{
	out << *(op2.request);
	return out;
}

//overloading the < operator for the node class
//takes rental reference and node obj
bool operator < (const rental & op1, const node & op2)
{
	return op1 < *(op2.request);
}

//oveloading the == operator for the node class
//takes rental reference and  node obj
bool operator == (const rental & op1, const node & op2)
{
	return op1 == *(op2.request);
}

//overloading the < operator for the node class
//with different arg, an int and node obj
bool operator < (int op1, const node & op2)
{
	return op1 < *(op2.request);
}

//overloading the == operator for the node class
//with different arg, an int and node obj
bool operator == (int op1, const node & op2)
{
	return op1 == *(op2.request);
}

//overloading the assignment operator
//takes a node obj referent as arg
node & node::operator = (const node & op2)
{
	if(this == &op2)		//check if self assignment
		return *this;
	if(request)			//delete if there data
        {	
		delete request;
		request = NULL;
	}
	
        rental * temp = op2.request;                                   //to determine what rental 
        const short_term * obj = dynamic_cast<short_term *> (temp);    //is pointing to we are going
        if(obj)                                                        //to used dynamic cast to assign
           request = new short_term(*obj);                             //request to pointer of rental
        else                                                           //if one of the pointers is not null
        {                                                              //then we create a memory of the copy
           const school_year * obj = dynamic_cast<school_year *> (temp); //request and give it the data
           if(obj)
              request = new school_year(*obj);
           else
           {
              const long_term * obj = dynamic_cast<long_term *> (temp);
              if(obj)
                   request = new long_term(*obj);
              else
                   request = NULL;
           }
        }

	return *this;
}

//function to retrieve rental obj info
//using dynamic casting
bool node::retrieve(rental *& data)
{
        rental * temp = request;					
        const short_term * obj = dynamic_cast<short_term *> (temp);	
        if(obj)								
           data = new short_term(*obj);				
        else								
        {
           const school_year * obj = dynamic_cast<school_year *> (temp);
           if(obj)
              data = new school_year(*obj);
           else
           {
              const long_term * obj = dynamic_cast<long_term *> (temp);
              if(obj)
                   data = new long_term(*obj);
              else
                   data = NULL;
           }
         }
        return 1;
}

//getter function that return right
node * & node::go_right()
{
	return right;
}
//getter function that return left
node * & node::go_left()
{
	return left;
}
//function that set right
void node::set_right(node * connect)
{
	if(!connect)
	   right = NULL;
	else
	   right = connect;
}
//function that set left
void node::set_left(node * connect)
{
	if(!connect)
	   left = NULL;
	else
	   left = connect;
}
//default constructor
BST::BST()
{
	root = NULL;
}
//copy constructor
BST::BST(const BST & source)
{
	if(source.root)				//check if there is data and then call copy function
	   copy_tree(root, source.root);
}

//destructor
BST::~BST()
{
	if(root)		//check if there is data then call remove all function
	   remove_all(root);
}

//copy function that will copy the data structure
void BST::copy_tree(node * &root, node * o_root)
{
	if(!o_root)
	{
	   root = NULL;
	   return;
	}

	root = new node(*o_root);

	copy_tree(root->go_left(), o_root->go_left());
	copy_tree(root->go_right(), o_root->go_right());
}

//wrapper function that will remove all rental obj
void BST::remove_all() 
{
	if(!root) return;

	remove_all(root);
}

//recussive function for remove_all
void BST::remove_all(node * &root)
{
	if(!root) return;

	remove_all(root->go_left());
	remove_all(root->go_right());
	delete root;
	root = NULL;
}
//wrapper function to display all rental obj
void BST::display_all()
{
	if(!root) return;

	display_all(root);
}

//recussive function for display_all
void BST::display_all(node * root)
{
	if(!root) return;

	display_all(root->go_left());
	cout << *root;
	display_all(root->go_right());
}

//function to add rental obj to the tree
void BST::add_request(rental & source)
{
	if(!root)			//check if empty and then add the obj to new node
	{				//set its color to black
	   root = new node(&source);
	   return;
	}
	add_request(root, source);	//if not empty call recussive function of add
}

//recussive function of add_request
void BST::add_request(node * &root, rental & source)
{
	if(!root)			//add obj to new node and set the parent to the previous node
	{				//chack if the previous node color is red if it is call function to fix
	   root = new node(&source);	//the tree if not red return
	   return;
	}

	if(source < *root)
	   add_request(root->go_left(), source);
	else
	   add_request(root->go_right(), source);

}

//function to retrieve rental obj from the tree
//using the price argument provided by the user
bool BST::retrieve(int price, rental *& data)
{
	if(!root) return 0;

	return retrieve(root, price, data);
}

//recurssive function of retrieve
bool BST::retrieve(node * root, int price, rental *& data)
{
	if(!root) return 0;

	if(price == *root)
	{
		return root->retrieve(data);
	}

	else if(price < *root)
		return retrieve(root->go_left(), price, data);
	else
		return retrieve(root->go_right(), price, data);
}

//overloading the assignment operator for BST class
BST & BST::operator = (const BST & source)
{
	if(this == &source)
		return *this;

	if(root)
	{
	   remove_all(root);
	}

	copy_tree(root, source.root);
	return *this;
}

int BST::remove(int price)
{
   if(!root) return 0;			//return 0 if no data to remove

   return remove(root, price);		//otherwise call the recussive function
}

//recussive function to remove
int BST::remove(node * &root, int price)
{
   if(!root) return 0;			//return 0 if no match

   node * hold = NULL;

   int result;

   if(price == *root)					//if matching data then,
   {
       if(root->go_left() == NULL && root->go_right() == NULL)	//if leaf then delete the node and set to null and return 1
       {
	  delete root;
	  root = NULL;
	  return 1;
       }
       else if(root->go_left() == NULL && root->go_right() != NULL)	//if we have right but not left, then hold the right node
       {							//delete the node then set to the right node
	  hold = root->go_right();
	  delete root;
	  root = hold;
	  return 1;
       }
       else if(root->go_left() != NULL && root->go_right() == NULL)	//if we have left but not right, then hold the left node
       {							//delete the node then set to left node
	  hold = root->go_left();
	  delete root;
	  root = hold;
	  return 1;
       }
       else
       {
	  remove_node(root->go_right(), root);
	  return 1;
       }
    }
    else if(price < *root)						//if less go left
        result = remove(root->go_left(), price);
    else  							//if greater go right
        result = remove(root->go_right(), price);

    return result;

}

void BST::remove_node(node * &root, node * &current)
{
       if(root->go_left() == NULL)                          //travese til current->left is NULL
       {
          if(root->go_right() == NULL)                            //when we get to the last left, check if it has a right node
          {                                                     //if no assign the data to the root to be deleted, then delete
             *current = *root;			               //the node and set to null
             delete root;
             root = NULL;
          }
          else                                                  //if yes, then hold the right, copy the data to the root data
          {                                                     //delete the node and set it to the right
             node * hold = root->go_right();
             *current = *root;
             delete root;
             root = hold;
          }
	  return;
       }

       remove_node(root->go_left(), current);
}
