
INTRODUCTION AND REVIEW:

This is a program designed to allow the user to enter items in preparation
for moving and then sort them into one of several categories. The purpose
of this program was to get some practice with stacks and queues, so I 
implemented the stack as a linear liked list and the queue as a circular
linked list. Both structures have wonderful performance as the assignment 
allows items to added to and removed from the beginning and end -- no 
traversal or sorting is necessary. 

To ensure maximum runtime efficiency, as few operations as possible where 
used. No excessive pointers were created to maintain the lists. For
example, it may have been tempting to create a head and tail pointer for 
the queue, when in reality only a pointer to the last item in the list is
necessary. 

When traversing the linked lists, I tried to increase efficiency further 
by performing actions in the current node rather than “reaching ahead” to 
change the next node that we would move to in the next step anyway. 

To conserve memory, all variables are dynamically allocated from temporary
inputs from the user. The lists themselves are linked lists, which are 
flexible and do not require a shifting of data when an item is added or 
removed. 

In future iterations of this program I would do more work to further 
increase efficiency and decrease memory requirements. For instance, rather
than passing character arrays, passing pointers would perhaps be more 
efficient. In general, passing by reference as much as possible will 
conserve memory usage. Additionally, I would like to create more data 
validation to ensure that the data being entered adheres to the integrity 
of the data structure, though I suppose that this is the work of the 
client program rather than the data structure itself. Use of recursion may
have helped, but the segments in which recursion would have been useful 
(displaying and deleting a list) were minute as the brunt of the work 
(addition and deletions of items) was performed without traversal.
                        

RUNNING IT:

All the files for this game should be in the same directory. 
From the command line, simply type "make" and then "./play".

To recompile after making changes, type "make" again.
To delete all executables, type "make clean".

That's it!
Hope you enjoy my silly program.
-Amanda

