#include <stdio.h>  //Used for print statements
#include <stdlib.h> //Used for freeing memory
#include <string.h> //Used for computing string length (strlen)
#include "dllist.h"  //used for linked list related operations

/*reads up to the limi of char to S */
int gets_n(char *s, int limit)
{
  char *p = s;
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n')
      p++;
    if (c == '\n')
      *p = 0;
  }
  return (p-s);
}

int main()
{
  char buf[100];    //buffer to read in input byte by btye
  dLList *lp = llAlloc();  //Creates an empty list

  printf("Choose one of the following options\n"
    " 1.)Print list\n"
    " 2.)Input list and then print\n"
    " 3.)type stop to exit\n");
  //FILE INSERT BASICS
  /*printf("Enter a filename: ");
  //scanf("%s", buf);
  fgets(buf,100,stdin);
  printf("the string was: %s\n", buf); */

  llPrint(lp, "Contents before input:");

  printf("Input employee names, type ""stop""  to finish inputting names\n");
  
  while(gets_n(buf,100)&& strcmp(buf,"stop") ){
    dllPut(lp, buf);
  }

  llPrint(lp, "List contents, after creating a list:");

  dllFree(lp);

  printf("Thanks for playing.");

  getchar();
  return 0;
}
/*llPrint(lp, "Current contents before input:"); //shows list, at this point should be empty

  while (gets_n(buf,100)) //creates list
    llPut(lp, buf);

  llPrint(lp, "Contents after inputs");

   llMakeEmpty(lp); //deletes content of the lists */


//FIle Input output related items, Information gathered from Utah.edu

/*FILE *in_file = fopen("Name-of-file", "r"); //only reads
FILE *out_file = fopen("Name-of-file", "w"); //only writes

*/
