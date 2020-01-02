/*
 Fake code, Yue Weng, Dec23, 2019
 remake the assignment list for self usage and practice
*/

/*
 Header file for list library
 The list functions has been devided to 3 parts:
  -Adders: create, add new node/content to the list
  -Movers: move the cursor, the nodes of the list
  -Removers: remove the designated target
*/

// Argument of LIST
// Library shall have no dynamic memory allocation on a per-list or per-node
extern int MAX_LIST;
extern int MAX_NODE;
extern int LIST_COUNT;
extern int LIST_NODE;

// define the standard doubly linked list structure
typedef struct NODE
{
  struct NODE *prev; // point to the previous node
  void *data; // pointer, hold the data address
  struct NODE *next; // point to the next node
} NODE;

typedef struct LIST
{
  struct NODE *head; // hold the front of list
  struct NODE *tail; // hold the tail of list for convenience
  struct NODE *cursor; // cursor, the node that currenetly operate
  int count;  // number of items/nodes of the list
} LIST;


typedef struct LIST* list;
typedef void* item;


// Adder functions
LIST * ListCreate();

int ListCount(list);

int ListAdd(list, item);

int ListInsert(list, item);

int ListAppend(list, item);

int ListPrepend(list, item);


// Movers functions
void *ListFirst(list);

void *ListLast(list);

void *ListNext(list);

void *ListPrev(list);

void *ListCurr(list);

void 
*ListSearch(list, int (*comparator)(void*, void*), void* comparisonArg);


// Removers functions
void *ListRemove(list);

void ListConcat(list, list);

void ListFree(list, item);

void *ListTrim(list);