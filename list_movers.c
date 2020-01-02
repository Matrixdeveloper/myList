/*
 Fake code, Yue Weng, Dec23, 2019
 remake the assignment list for self usage and practice
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
 * Function: 
 *  returns a pointer to the first item in list and makes first item
 *  the current item.
 * Input:
 *  list, a pointer of LIST
 * Output:
 *  address of first item in the list
 */
void *ListFirst(LIST* list)
{
  list->cursor = list->head;
  return list->cursor->data;
}


/*
 * Function: 
 *  returns a pointer to the last item in list and makes first item
 *  the current item.
 * Input:
 *  list, a pointer of LIST
 * Output:
 *  address of last item in the list
 */
void *ListLast(LIST* list)
{
  list->cursor = list->tail;
  return list->cursor->data;
}


/*
 * Function: 
 *  advances the list's current node by one, and returns a pointer to the 
 *  new current item.
 * Input:
 *  list, a pointer of LIST
 * Output:
 *  if this operation attempts to advances the current item beyond the end
 *  of thel ist, return NULL.
 * 
 *  if success, return the item of next node 
 */
void *ListNext(LIST* list)
{
  if(list->cursor->next == NULL)
  {
    return NULL;
  }
  else
  {
    list->cursor = list->cursor->next;
    return list->cursor->data;
  } 
}


/*
 * Function: 
 *  backs up the list's current node by one, and returns a pointer to the 
 *  new current item.
 * Input:
 *  list, a pointer of LIST
 * Output:
 *  if this operation attempts to backs up the current item beyond the start
 *  of thel ist, return NULL.
 * 
 *  if success, return the item of next node 
 */
void *ListPrev(LIST* list)
{
  if(list->cursor->prev == NULL)
  {
    return NULL;
  }
  else
  {
    list->cursor = list->cursor->prev;
    return list->cursor->data;
  } 
}


/*
 * Function: 
 *  returns a pointer to the current item.
 * Input:
 *  list, a pointer of LIST
 * Output:
 *  if this operation attempts to access empty list, return NULL
 * 
 *  if success, return the item of current node 
 */
void *ListCurr(LIST* list)
{
    if(list->cursor == NULL)
  {
    return NULL;
  }
  else
  {
    return list->cursor->data;
  } 
}

/*
 * Function:
 *  searches list starting at the current item until the end is reached or a
 *  match is found. A match is determined by the comparator parameter. This
 *  parameter is a pointer to a routine that takes as its first argument an
 *  item pointer, and as its second argument comparisionArg. Comparator returns
 *  0 if the item and comparisonArg don't match, or 1 if they do. Exactly what
 *  constitutes a match is up to the implementor of comparator. If a match is
 *  found, the current pointer is left at the matched item and the pointer to
 *  that pointer to that item is returned. If no match is found, the current
 *  pointer is left at the end of the list and a NULL pointer is returned.
 * Input:
 * Output:
 */
void*
ListSearch(LIST* list, int (*comparator)(void*, void*), void* comparisonArg)
{
  // List if empty
  if (list->cursor == NULL)
  {
    return NULL;
  }
  
  // loop for iterate the whole list
  while (1)
  {
    if (comparator(list->cursor->data, comparisonArg))
    {
      return list->cursor->data;
    }
    if (list->cursor->next == NULL){
      return NULL;
    }
    list->cursor = list->cursor->next;
  }
}