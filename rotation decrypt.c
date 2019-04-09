#include <stdio.h>



int main(void)
{
   
   
   
   //creates a string for the message to be stored in, and an input system for the message.
   char message[1000];
   printf("Enter message to incrypt\n");
   scanf("%s", message);
   
   //creates rotation key input.
   int k; //k = rotation key
   printf("Enter rotation key\n");
   scanf("%d\n", &k);
   
   
   printf("%d\n", message[0]);
   
   return 0;
 }  