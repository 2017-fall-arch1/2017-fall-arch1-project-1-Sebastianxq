#include <stdio.h>  //Used for print statements
#include <stdlib.h> //Used for freeing memory
#include <string.h> //Used for computing string length (strlen)
#include "llist.h"  //used for linked list related operations

int main()
{
  char buf[100];    //buffer to read in input byte by btye
  LList *lp = llAlloc();  //Creates an empty list

  printf("Enter a filename: ");
  scanf("%s", buf);

  printf("the string was: %s\n", buf);
}

/*llPrint(lp, "Current contents before input:"); //shows list, at this point should be empty

  while (gets_n(buf,100)) //creates list
    llPut(lp, buf);

  llPrint(lp, "Contents after inputs");

   llMakeEmpty(lp); //deletes content of the lists */
