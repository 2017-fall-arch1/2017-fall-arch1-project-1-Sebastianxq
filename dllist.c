#include <stdio.h>   /*puts */
#include <stdlib.h>  /*for allocation */
#include <assert.h>  /* for asserts */
#include "dllist.h"  /* extendds dllist.h  properties*/

int dllDoCheck = 1; /*something about consistency checking */

#define doCheck(_lp) (dllDoCheck && llCheck(_lp))

/* creates the new list */
dLList *llAlloc()
{
  dLList *lp = (dLList *)malloc(sizeof(dLList));
  lp->first = lp->last = 0;
  doCheck(lp);
  return lp;
}

/*deallocates and recycles a list */
void dllFree(dLList *lp)
{
  doCheck(lp);
  dllMakeEmpty(lp);
  free(lp);
}

void dllMakeEmpty(dLList *lp)
{
  dLLItem *current = lp->first, *next;
  doCheck(lp);
  while (current)
    {
      next = current->next;
      free(current->str);
      free(current);
      current = next;
    }
  lp->first = lp->last = 0; /* list is now empty */
  doCheck(lp);
}

void dllPut(dLList *lp, char *s)
{
  int length;
  char *scopy;
  dLLItem *i;

  doCheck(lp);
  /* w is a newly created copy of "putWord" */
  for (length = 0; s[length] ; length++);

  scopy = (char *)malloc(length+1);

  for (length=0; s[length];length++)
    scopy[length] = s[length];
  scopy[length] = 0;

    /* i is the new item containing s */
    i = (dLLItem *)malloc(sizeof(dLLItem));
  i->str = scopy;
  i->next = 0;

  /*puts at the end of the list */
  if (lp->last){
    lp->last->next = i;
  } else{
    lp->first = i; /* if list is empty */
  }

  /*new item is now the last on the list */
  lp->last = i;
  doCheck(lp);
}

void llPrint(dLList *lp, char *msg)
{
  dLLItem *ip;
  int count = 1;
  doCheck(lp);
  puts(msg ? msg :"List content:");
  for (ip = lp->first; ip; ip = ip->next){
    printf(" %d: <%s>\n", count, ip->str);
    count++;
  }
}

int llCheck(dLList *lp)
{
  dLLItem *ip;
  ip = lp->first;
  if (!ip)
    assert(lp->last == 0);
  else{
    for(; ip->next; ip = ip->next);
    assert(ip == lp->last);
  }
  return 0;
}
