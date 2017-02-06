
//******************************************************
//
// 	MOVING ASSISTANT ::
//	    Helps you track your possessions and organize
//		for your move!
// 	AMANDA RYMAN :: amanda.ryman@gmail.com
//  Portland State University :: Computer Science 163
// 	OCTOBER 29, 2013
//
//******************************************************
//
//	STACK CLASS
//
//******************************************************
//
//	ASSOCIATED FILES:
//  -- "inventory.h"
//	-- "inventory.cpp"
//	-- "stack.cpp"
//	-- "queue.cpp"
//	-- "main.cpp"
//
//******************************************************

#include "inventory.h"

//******************************************************
//  CONSTRUCTOR:
//	Initialize the list with a null head.

stack::stack()
{
    head=NULL;
}


//******************************************************
//  DESTRUCTOR:
//	Release any dynamically allocated memory.

stack::~stack()
{

    
    if (head)
    {
	while (head->next)
        {
	    delete head;
	    head=head->next;
	}
	delete head;
	head=NULL;
    }
}


//******************************************************
//  PUSH: ADD A NODE
//	Add a node to the beginning of the list. Set 
//  head to point to it. Returns true.

bool stack::push(char name[], int tempw, int temph, int templ)
{
    node*temp=new node;
    temp->item.set(name, tempw, temph, templ);
    temp->next=head;
    head=temp;
    return true;
}


//******************************************************
//  POP: REMOVE A NODE
//	Set a temp pointer to the point where head is 
//  pointing. Set head to point to the next item. 
//  Delete the first item in the list and return true.

bool stack::pop()
{
    node*temp=head;
    head=head->next;
    delete temp;
    temp=NULL;
    return true;
}


//******************************************************
//  DISPLAY ALL NODES:
//	If there is no list, return false. Otherwise 
//  call 'display' for each item in the list. Return true.

bool stack::displayall()
{
    if (!head)
	return false;
    node*current=head;
    current->item.display();
    while (current->next)
    {
	current=current->next;
	current->item.display();
    }	
    return true;
}



//******************************************************
//  PEEK:
//	If there is no list, return false. Otherwise 
//  return true.

bool stack::peek()
{
    if (!head)
	return false;
    return true;
}


//******************************************************
//  LOOK:
//	If there is no list, return false. Otherwise
//  display the first item.

bool stack::look()
{
    if (!head)
	return false;
    
    head->item.display();
    return true;

}


//**************
//  END.
//**************

