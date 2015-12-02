
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
//	MAIN.CPP -- CLIENT PROGRAM
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

void welcome(void);
void goodbye(void);
int which(void);
bool more(void);
int whichlist(char tempname[]);
bool store(stack & storage);
bool move(queue & newhome);
bool donate(queue & donations);

int main()
{

//******************************************************
// FIRST LET'S SET UP SOME VARIABLES:

// Setting up temporary values for our ADT's data members:
    char tempname[SIZE];
    int tempw=0;
    int temph=0;
    int templ=0;

// Welcome to the program:
    welcome();


//******************************************************
// LET'S CREATE SOME LISTS:

// Create a stack for the storage unit:
    stack storage;

// Create a queue for locally moved items:
    queue newhome;

// Create a queue for stuff to donate:
    queue donations;

    
//******************************************************
// NOW LET'S CREATE AN ITEM:

    do
    {
// Get the new data from the user:
	cout << "\nITEM NAME:\t";
	
	cin.get(tempname,SIZE,'\n');
	cin.ignore(SIZE,'\n');
	
	cout << "ITEM DIMENSIONS (in inches):"
	    << "\n\tWidth:\t";
	cin >> tempw;
	cin.ignore(SIZE,'\n');
	cout << "\tHeight:\t";
	cin >> temph;
	cin.ignore(SIZE,'\n');
	cout << "\tLength:\t";
	cin >> templ;
	cin.ignore(SIZE,'\n');


//****************************************************
//   CHOOSE WHERE TO PUT THE NEW ITEM: 

	int selection=whichlist(tempname);

	if (selection == 1)
	{
    // Store new data:
	    newhome.enqueue(tempname, tempw, temph, templ);
    // Echo entry back:
	    cout << "You have entered: ";
	    newhome.look();
	}

	if (selection == 2)
	{
    // Store the new data:
	    storage.push(tempname, tempw, temph, templ);
    // Echo entry back:
	    cout << "You have entered: ";
	    storage.look();
	}

	if (selection == 3)
	{
    // Store new data:
	    donations.enqueue(tempname, tempw, temph, templ);
    // Echo entry back:
	    cout << "You have entered: ";
	    donations.look();
	}

// Do it again?
	cout << "\n\nWould you like to add another item?\t[Y/N]\t";
    }while (more());
    

//****************************************************
// MODIFY THE LISTS:

    store(storage);
    move(newhome);
    donate(donations);



//****************************************************
// ALL DONE!
    goodbye();
    return 0;
}


//******************************************************
//  FUNCTION DECLARATIONS: 
//******************************************************


//******************************************************
//  WELCOME!
//
//	A simple greeting to the user with instructions
//  about how to use the program.

void welcome()
{
    cout << "\n[--MOVING ASSISTANT--]" 
    	<< "\nLet's organize your move! " 

	<< "\n\n[--INSTRUCTIONS--]"
	<< "\nJust type in an item and then decide where it will go."

	<< "\n\nYou can choose to send an item to your new house,"
	<< "\nto storage, or you can donate it."

	<< "\n\nRemember that what you send an item to your house or"
	<< "\ndonate it, it will go straight there, but what you put into"
	<< "\nstorage first will go in the back of the storage unit!" 
	<< endl;
}



//******************************************************
//  WHICH LIST?
//
//	Gets a response from the user and converts that
//  response into a value used to select the list to 
//  modify. "menu" is then returned.

int which()
{
    char reply='\0';
    int menu=0;
    cin >> reply; 
    cin.ignore(SIZE,'\n');
    reply=tolower(reply);
    if ((reply == 'n') || (reply == 'h'))
        menu=1;
    if (reply == 's')
        menu=2; 
    if (reply == 'd')
        menu=3;

    return menu;
}



//******************************************************
//  DECIDE WHERE TO PUT THE NEW ITEM:
//
//	Ask the user to pick a list to append. If a 
//  valid response is not returned from the which() 
//  function, the loop continues until valid data is 
//  entered.
//	Takes 'tempname' as an argument so that the 
//  item can be identified to the user during prompts.

int whichlist(char tempname[])
{
// Set up a variable to store the reply from user:
    int reply=0;
    cout << "Where should we put the " << tempname << "?" 
	<< "  (New House, Storage, or Donations?)\t";

    do
    {
    // Get a response from user:
	reply=which();
    // Take an action based on the reply:
	if (reply)
	    return reply;
    // If the reply is not recognizable, ask again:
	cout << "\nSorry, I'm not sure what you mean."
	    << "\nYou want to put the " << tempname << " where?\t";	
    }while (!reply);

// Once the item has been stored, return to main:
    return true;
}



//****************************************************
//    VIEW OR DELETE ITEMS IN STORAGE:
//
//	Calls a display function to display the list.
//  Displays the first item and asks user if they want
//  to remove it. If they don't want to remove the 
//  item, return to main().
//	Takes the stack 'storage' as an arguement so 
//  that the list can be modified.

   
bool store(stack & storage)
{
    cout << endl << "\n[--STORAGE CONTENTS--]" << endl
	<< "Here is a list of what's in storage:" << endl;

// Display the entire storage contents.
// If list is empty, return to main.
    if (!storage.displayall())
    {
        cout << "Oh. There's nothing to take to storage!" << endl;
        return false;
    }
// Modify storage:
    do
    {
    // Peek at the first item in storage:
	cout << "\nLooks like the first thing in the storage unit is the ";
	storage.look();
    // Remove the first item?
	cout << "Would you like to take this item out?\t[Y/N]\t";
	if (more())
	{
	    storage.pop();
	// If that was our last item, we're outta here.
	    if (!storage.peek())
	    {
		cout << "\nThat's it for the storage unit!" << endl;
		return true;
	    }
	}
    // Well if you don't want to take it out, there's nothing to be done...
	else
	{
	    cout << "\nWell we can't get anything else out of here until"
		<< "\nyou move it out of the way...";
	    return false;
	}
    // As long as there's still something in the list, we'll keep working.
    }while(storage.peek());
    return true;
}



//****************************************************
//  VIEW OR MOVE ITEMS TO THE NEW HOUSE:
//
//	Calls a display function to display the list.
//  Displays the first item and asks user if they want
//  to remove it. If they don't want to remove the 
//  item, return to main().
//	Takes the queue 'newhome' as an arguement so 
//  that the list can be modified.
   
bool move(queue & newhome)
{
    cout << endl << "\n[--TO BE MOVED--]" << endl
	<< "Okay, now let's get some stuff put into your new house." << endl

// Display the entire list of things being moved. 
// If the list is empty, return false
	<< "Here is a list of what is being moved to your new home:" << endl;
    if (!newhome.displayall())
    {
        cout << "Oh. There's nothing to move!" << endl;
        return false;
    }

// Modify the list:

    do
    {
    // Peek at the first item in the list. Remove it?
	cout << "\nAt the top of our moving list we have the ";
	newhome.look();
	cout << "Would you like to move it now?\t[Y/N]\t";
	if (more())
	{
	    newhome.dequeue();
	// If that was our last item, we're outta here.
	    if (!newhome.peek())
	    {
		cout << "There's nothing left to move. Nice!!" << endl;
		return true;
	    }
	}
    // Well if you don't want to move that, we can't reach anything else...
	else
	{
	    cout << "\nWell we can't get anything else out of here until"
		<< "\nyou move it out of the way...";
	    return false;
	}
    // Keep going as long as there is something in the list:
    }while(newhome.peek());
    return true;
}



//****************************************************
//    VIEW AND MOVE ITEMS TO BE DONATED:
//
//	Calls a display function to display the list.
//  Displays the first item and asks user if they want
//  to remove it. If they don't want to remove the 
//  item, return to main().
//	Takes the queue 'donations' as an arguement so 
//  that the list can be modified.

   
bool donate(queue & donations)
{
    cout << endl << "\n[--TO BE DONATED--]" << endl
	<< "Now to get those donations taken care of." << endl

// Display the entire list of things being donated. 
// If the list is empty, return false
	<< "Here is a list of what is being donated:" << endl;
    if (!donations.displayall())
    {
        cout << "Oh. There's nothing to donate!" << endl;
        return false;
    }

// Modify the list:
    do
    {
    // Peek at the first item in the list. Remove it?
	cout << "\nAt the top of the list is the ";
	donations.look();
	cout << "Would you like to donate it now?\t[Y/N]\t";
	if (more())
	{
	    donations.dequeue();
	// If that was our last item, we're outta here.
	    if (!donations.peek())
	    {
		cout << "There's nothing left. You're all done!" << endl;
		return true;
	    }
	}
    // Well if you don't want to move that, we can't reach anything else...
	else
	{
	    cout << "\nWell we can't get anything else out of here until"
		<< "\nyou move it out of the way...";
	    return false;
	}
    // Keep working as long as there is something in the list: 
    }while(donations.peek());
    return true;
}



//******************************************************
//  ENTER MORE DATA
//     OR CONTINUE?
//
// 	More() returns true to continue the
// 	loop; returns false to quit

bool more()
{
    char reply='\0';
    cin >> reply;
    cin.ignore(100,'\n');
    if (tolower(reply)=='y')
	return true;
    return false;
}


//******************************
//  GOODBYE!
//	A brief farewell, dear user.

void goodbye()
{
    cout << "\n\nCongratulations, you're all done!" << endl;
    cout << "\n[--SESSION COMPLETE--]" << endl;
    cin.get();
}


//*****************
// SMILE. YOU DONE!
//*****************

