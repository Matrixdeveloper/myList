/*
 Fake code, Yue Weng, Dec23, 2019
 remake the assignment list for self usage and practice
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define MAX_LIST 8
#define MAX_NODE 16

// Count the total assigned objects
int LIST_COUNT = 0;
int NODE_COUNT = 0;

// For manage the freed NODES & LISTS in the pool
int LIST_FREE_NUM = 0;
int NODE_FREE_NUM = 0;

// Define the pool size, static memmory
NODE NODE_MEM[MAX_NODE];
LIST LIST_MEM[MAX_LIST];

// Anchor of freed objects
NODE* FreeNODES;
NODE* FreeLISTS;


// Adder functions

/*
 * Function: Assign a new list from the pool
 * Input: None
 * Output:
 *  if success, return back the reference of the new list.
 *  if fail, return NULL;
 */
LIST * ListCreate()
{
  LIST* tempList;
  // there is free space for new list
  if (LIST_COUNT < MAX_LIST)
  {
    // try find a freed list from Hook
    if (LIST_FREE_NUM> 0)
    {
      LIST_COUNT++;
      LIST_FREE_NUM--;
      tempList = (LIST*) FreeLISTS->data;
      // unhook the head & update the anchor
      FreeLISTS = FreeLISTS->next;
      return tempList;
    }
    else{
      // return the address of next unused postion of the list pool
      // then, increment COUNT number
      return &LIST_MEM[LIST_COUNT++];
    }
  }else{
    // no free list exist
    return NULL;
  }
}


/*
 * Function: Return back the item amount of the argument list pointer
 * Input: list, a LIST pointer
 * Output: amount of item in the list, integer.
 */
int ListCount(LIST* list)
{
  return list->count;
}


/*
 * Function: 
 *  Add the new item to the list, make the new node after current node
 * Input:
 *  list, LIST pointer of the target list
 *  item, void pointer of the item which will be added to the list
 * Output:
 *  if success, return 0.
 *  if fail, return -1. <basically, that means no free space for use>
 */
int ListAdd(LIST* list, void* item)
{
  NODE* tempNode;
  int free_index;
  // find a free node from pool
  if (NODE_COUNT<MAX_NODE)
  {
    // find a node
    // always try to use the freed node first
    if (NODE_FREE_NUM>0)
    {
      NODE_COUNT++;
      NODE_FREE_NUM--;
      tempNode =(NODE*)FreeNODES->data;
      FreeNODES = FreeNODES->next;
      tempNode->data = item;
    }else{
      tempNode = &NODE_MEM[NODE_COUNT++];
      tempNode->data = item;
    }

    // assign the node
    if (list->count == 0)
    {
      list->head = tempNode;
      list->tail = tempNode;
      list->count++;
      list->cursor = tempNode;
    }else
    {
      tempNode->prev = list->cursor;
      tempNode->next = list->cursor->next;
      list->cursor->next = tempNode;
      list->cursor = tempNode;
      list->count++;
      // if the new node become the new tail
      if(list->cursor->next == NULL)
      {
        list->tail = tempNode;
      }  
    }
    return 0;
  }
  else
  {
    // No node can be assigned
    return -1;
  }
}


/*
 * Function: 
 *  Add the new item to the list, make new node before current node
 * Input:
 *  list, LIST pointer of the target list
 *  item, void pointer of the item which will be added to the list
 * Output:
 *  if success, return 0.
 *  if fail, return -1. <basically, that means no free space for use>
 */
int ListInsert(LIST* list, void* item)
{
  NODE* tempNode;
  int free_index;
  // find a free node from pool
  if (NODE_COUNT<MAX_NODE)
  {
    // find a node
    // always try to use the freed node first
    if (NODE_FREE_NUM>0)
    {
      NODE_COUNT++;
      NODE_FREE_NUM--;
      tempNode =(NODE*)FreeNODES->data;
      FreeNODES = FreeNODES->next;
      tempNode->data = item;
    }else{
      tempNode = &NODE_MEM[NODE_COUNT++];
      tempNode->data = item;
    }

    // assign the node
    if (list->count == 0)
    {
      list->head = tempNode;
      list->tail = tempNode;
      list->count++;
      list->cursor = tempNode;
    }else
    {
      tempNode->prev = list->cursor->prev;
      tempNode->next = list->cursor;
      // if the cursor is the head of list
      if(list->cursor->prev == NULL)
      {
        list->head = tempNode;
      }
      list->count++;
    }
    return 0;
  }
  else
  {
    // No node can be assigned
    return -1;
  }
}


/*
 * Function: 
 *  Add the new item to the list, make new node as the new tail
 * Input:
 *  list, LIST pointer of the target list
 *  item, void pointer of the item which will be added to the list
 * Output:
 *  if success, return 0.
 *  if fail, return -1. <basically, that means no free space for use>
 */
int ListAppend(LIST* list, void* item)
{
  NODE* tempNode;
  int free_index;
  // find a free node from pool
  if (NODE_COUNT<MAX_NODE)
  {
    // find a node
    // always try to use the freed node first
    if (NODE_FREE_NUM>0)
    {
      NODE_COUNT++;
      NODE_FREE_NUM--;
      tempNode =(NODE*)FreeNODES->data;
      FreeNODES = FreeNODES->next;
      tempNode->data = item;
    }else{
      tempNode = &NODE_MEM[NODE_COUNT++];
      tempNode->data = item;
    }

    // assign the node
    if (list->count == 0)
    {
      list->head = tempNode;
      list->tail = tempNode;
      list->count++;
      list->cursor = tempNode;
    }else
    {
      tempNode->prev = list->tail;
      list->tail = tempNode;
      list->count++;
    }
    return 0;
  }
  else
  {
    // No node can be assigned
    return -1;
  }
}

int ListPrepend(LIST* list, void* item)
{
  NODE* tempNode;
  int free_index;
  // find a free node from pool
  if (NODE_COUNT<MAX_NODE)
  {
    // find a node
    // always try to use the freed node first
    if (NODE_FREE_NUM>0)
    {
      NODE_COUNT++;
      NODE_FREE_NUM--;
      tempNode =(NODE*)FreeNODES->data;
      FreeNODES = FreeNODES->next;
      tempNode->data = item;
    }else{
      tempNode = &NODE_MEM[NODE_COUNT++];
      tempNode->data = item;
    }

    // assign the node
    if (list->count == 0)
    {
      list->head = tempNode;
      list->tail = tempNode;
      list->count++;
      list->cursor = tempNode;
    }else
    {
      tempNode->next = list->head;
      list->head = tempNode;
      list->count++;
    }
    return 0;
  }
  else
  {
    // No node can be assigned
    return -1;
  }
}











