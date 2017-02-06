
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
//  	HEADER FILE -- CLASS DECLARATIONS
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

#include <cstring>
#include <fstream>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;
const int SIZE=100;

//******************************************************
//  STACK AND QUEUE CLASSES
//******************************************************

//******************************************************
//  INVENTORY CLASS:
//	Data members for each individual inventory item.

class inventory
{
public:
    inventory(void);
    ~inventory(void);
    bool set(char[], int, int, int);
    void display(char*);
    void display(void);

private:
    char*name;
    int w;
    int h;
    int l;
};


//******************************************************
//  STACK NODE STRUCT:
//	Each queue list is initialized with an inventory
//  item and a 'next' pointer.

struct node
{
    inventory item;
    node*next;
};


//******************************************************
//  QUEUE NODE STRUCT:
//	Each struct list is initialized with an inventory
//  item and a 'next' pointer.

struct qnode
{   
    inventory item;
    qnode*next;
    qnode(void);
    ~qnode(void);
};





//******************************************************
//  STACK CLASS:
//	A LLL of items to go into storage (FIFO).

class stack
{
public:
    stack(void);
    ~stack(void);
    bool push(char[], int, int, int);
    bool pop();
    bool displayall(void);
    bool peek();
    bool look();

private:
    node*head;
};


//******************************************************
//  QUEUE CLASS:
//	A circular linked list of items to go elsewhere.

class queue
{
public:
    queue(void);
    ~queue(void);
    bool enqueue(char[], int, int, int);
    bool dequeue();
    bool displayall(void);
    bool peek();
    bool look();

private:
    qnode*ptr;
};


//**************
//  END.
//**************

