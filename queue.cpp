
//******************************************************
//
//  MOVING ASSISTANT ::
//      Helps you track your possessions and organize
//      for your move!
//  AMANDA RYMAN :: amanda.ryman@gmail.com
//  Portland State University :: Computer Science 163
//  OCTOBER 29, 2013
//
//******************************************************
//
//	QUEUE CLASS
//
//******************************************************
//
//	ASSOCIATED FILES:
//	-- "inventory.h"
//	-- "inventory.cpp"
//	-- "stack.cpp"
//	-- "queue.cpp"
//	-- "main.cpp"
//
//******************************************************

#include "inventory.h"

//******************************************************
//  CONSTRUCTOR:
//	Each queue list is initialized with a null pointer.

queue::queue()
{
    ptr=NULL;
}


//******************************************************
//  DESTRUCTOR:
//	Upon deletion, dynamically allocated memory is 
//  released and set to null.

queue::~queue()
{
    if (ptr)
    {
	qnode*current=ptr;
	qnode*ahead;
	while (current != ptr)
	{
	    ahead=current->next;
	    delete current;
	    current=ahead;
	}
	ptr=NULL;
	ahead=NULL;
	current=NULL;
    }
}


//******************************************************
//  ENQUEUE: ADD A NODE
//	If the head pointer is null, create a new node 
//  and set the data. Otherwise, create a new node at 
//  the end, set the head to point at it, and set the 
//  new node to point to the first node in the list.

bool queue::enqueue(char tempname[], int tempw, int temph, int templ)
{
    if (!ptr)
    {
	ptr=new qnode;
	ptr->item.set(tempname, tempw, temph, templ);
	ptr->next=ptr;
	return true;
    }
    qnode*temp=ptr->next;
    ptr->next=new qnode;
    ptr=ptr->next;
    ptr->item.set(tempname, tempw, temph, templ);
    ptr->next=temp;
    return true;    
}


//******************************************************
//  DEQUEUE: REMOVE A NODE
//	If the list is empty, return false to client.
//  Otherwise, if there is only one item, delete it. 
//  If there is more than one, remove the first item in
//  the list.

bool queue::dequeue()
{
// If the list is empty:
    if (!ptr)
	return false;
// If there is only one item in the list:
    if (ptr == ptr->next)
    {
	delete ptr;
	ptr=NULL;
	return true;
    }
// Otherwise, remove the first node and reconnect the last
//  node to the second item:
    else
    {
	qnode*temp=ptr->next->next;
        delete ptr->next;
	ptr->next=temp;
    }
    return true;
}


//******************************************************
//  DISPLAY ALL NODES:
//	Return false to client if there is no list. 
//  Otherwise, call 'display' for each item in the list.

bool queue::displayall()
{
    if (!ptr)
	return false;
    qnode*current=ptr->next;
    do
    {
	current->item.display();
	current=current->next;
    }while (current != ptr->next);
    return true;
}



//******************************************************
//  LOOK:
//	If the list is empty, return false to client.
//  Otherwise display the first item in the list.

bool queue::look()
{
    if (!ptr)
	return false;
    ptr->next->item.display(); 
    return true;
}



//******************************************************
//  PEEK:
//	Return false to client program if there is no list.
//  Return true if there is an item next.

bool queue::peek()
{
    if (!ptr)
	return false;
    return true;
}


//**************
//  END.
//**************

