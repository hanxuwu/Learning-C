/*
(Characters) 
Write a C-program that outputs, in alphabetical order, 
all strings that use each of the characters 'c', 'a', 't', 'd', 'o', 'g' exactly once.
How many strings does the program generate?

*/

#include <stdio.h>

int main(void) {
   char catdog[] = { 'a','c','d','g','o','t' };

   int count = 0;
   int i, j, k, l, m, n;
   for (i=0; i<6; i++)
      for (j=0; j<6; j++)
	 for (k=0; k<6; k++)
	    for (l=0; l<6; l++)
	       for (m=0; m<6; m++)
		  for (n=0; n<6; n++)
		     if (i!=j && i!=k && i!=l && i!=m && i!=n &&
			 j!=k && j!=l && j!=m && j!=n &&
			 k!=l && k!=m && k!=n &&
			 l!=m && l!=n && m!=n) {
			   printf("%c%c%c%c%c%c\n", catdog[i], catdog[j],
						    catdog[k], catdog[l],
						    catdog[m], catdog[n]);
			   count++;
		     }
   printf("%d\n", count);
   return 0;
}