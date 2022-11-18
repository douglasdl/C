#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (void) {
   FILE *fileName;
   int i=2, j=3, k=4, n=0;
   fileName = fopen("anything.txt","w");
   putw(i, fileName);
   putw(j, fileName);
   putw(k, fileName);
   fclose(fileName);
 
   fileName = fopen ("test.txt","r");
   while(getw(fileName) != EOF) {
      n = getw(fileName);
      printf("Value is %d \t: ", n);
   }
   fclose(fileName);
   return 0;
}