
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
//	INVENTORY CLASS -- FUNCTION DEFINITIONS
//
//******************************************************
//
//	ASSOCIATED FILES:
//			-- "inventory.h"
//			-- "inventory.cpp"
//			-- "stack.cpp"
//			-- "queue.cpp"
//			-- "main.cpp"
//
//******************************************************

#include "inventory.h"


//******************************************************
//  CONSTRUCTOR:
//	Each item in inventory receives null values at
//  initialization.

inventory::inventory()
{
    name=NULL;
    w=0;
    h=0;
    l=0;
}




//******************************************************
//  DESTRUCTOR:
//	Upon deletion, dynamically allocated memory is 
//  released.

inventory::~inventory()
{
    if (name)
    {
	delete [] name;
	name=NULL;
    }
}

qnode::qnode()
{
    next=NULL;
}

qnode::~qnode()
{
    next=NULL;
}




//******************************************************
//  SET MEMBER DATA:
//	Variables tempw, temph and templ are temporary
//  values which are then copied into the member data.

bool inventory::set(char tempname[], int tempw, int temph, int templ)
{
// Dynamically allocate "name":
    name=new char[strlen(tempname)+1];
    strcpy(name, tempname);

// Set int variables:
    w=tempw;
    h=temph;
    l=templ;
    return true;
}


//******************************************************
// 	DISPLAY EACH MEMBER:

void inventory::display()
{
    cout << name <<
    	" (" << 
    	w << "in x " << h << "in x " << l << "in) " << endl;
}


//**************
//	END.
//**************

