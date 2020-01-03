/*
 Fake code, Yue Weng, Dec23, 2019
 remake the assignment list for self usage and practice
*/
#include <stdlib.h>
#include "list.h"


/*
 * Function:
 * Input:
 * Ouput:
 */
void *ListRemove(LIST* list)
{
  void* tempItem;

  if (list->count == 0)
  {
    return NULL;
  }

  tempItem = list->cursor->data;
  list->cursor->data = NULL;
  list->count--;
  NODE_FREE_NUM++;

  // cursor at the front of list
  if (list->cursor->prev == NULL)
  {
    // cursor also at the end of list
    if(list->cursor->next == NULL)
    {
      list->cursor->next = FreeNODES; // add node to the front of freenodes
      FreeNODES = list->cursor;       // re-hook the new freenodes
      list->cursor = NULL;            // clear cursor
      list->head = NULL;
      list->tail = NULL;
    }
    else
    {
      list->head = list->cursor->next;
      list->head->prev = NULL;
      list->cursor->next = FreeNODES; // add node to the front of freenodes
      FreeNODES = list->cursor;       // re-hook the new freenodes
      list->cursor = list->head;      // update cursor
    }
  }
  // cursor not at the front
  else
  {
    // cursor at the end of list
    if(list->cursor->next == NULL)
    {
      list->tail = list->cursor->prev;
      list->cursor->next = FreeNODES; // add node to the front of freenodes
      list->cursor->prev = NULL;      // clear freed node's prev
      FreeNODES = list->cursor;       // re-hook the new freenodes
      list->cursor = list->tail;      // update cursor
    }
    else
    {
      FreeNODES->prev = list->cursor;
      list->cursor->prev->next = list->cursor->next; // unhook free node 
      list->cursor->next->prev = list->cursor->prev;
      list->cursor = list->cursor->prev;
      FreeNODES->prev->next = FreeNODES;
      FreeNODES = FreeNODES->prev;
      FreeNODES->prev = NULL;
    }
  }
  return tempItem;
}


/*
 * Function:
 * Input:
 * Ouput:
 */
void ListConcat(LIST* list1, LIST* list2)
{ 
  LIST_FREE_NUM++;
  if (list1->count == 0)
  {
    list1->head = list2->head;
    list1->tail = list2->tail;
    list1->cursor = list2->head;
    list1->count = list2->count;
  }
  else{
    list2->head->prev = list1->tail;
    list1->tail->next = list2->head;
    list1->tail = list2->tail;
    list1->count = list1->count + list2->count;
  }

  list2->tail = NULL;
  list2->count = 0;
  list2->cursor = NULL;
  list2->head =(NODE*)FreeLISTS; 
  FreeLISTS = list2;
}


/*
 * Function:
 * Input:
 * Ouput:
 */
void ListFree(LIST* list, void (*itemFree)(void*))
{
  LIST_FREE_NUM++;
  if (list->count != 0)
  {
    list->cursor = list->head;
    while (list->count > 0)
    {
      list->cursor->prev = NULL;
      itemFree(list->cursor->data); // Free data via external routine
      list->cursor->data = NULL;
      FreeNODES->prev = list->cursor;
      list->cursor = list->cursor->next;
      FreeNODES->prev->next = FreeNODES;
      FreeNODES = FreeNODES->prev;
      NODE_FREE_NUM++;
    }
    list->cursor = NULL;
    list->tail = NULL;
    list->head = (NODE*)FreeLISTS; // cast for hooking the freed lists
    FreeLISTS = list;
  }
  LIST_FREE_NUM++;
}


/*
 * Function:
 * Input:
 * Ouput:
 */
void *ListTrim(LIST* list)
{

}