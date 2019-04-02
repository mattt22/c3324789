#include <stdio.h>

int main()
{
 //menu selection options
 printf("Enter 1-6 to carry out one of the following operations:\n\n");
 printf("(1)  Encrypt message with roatation cipher\n\n");
 printf("(2)  Decrypt rotation cuipher with given rotation\n\n");
 printf("(3)  Encrypt substitution cipher with given alphabet substitution\n\n");
 printf("(4)  Decript substitution cipher with given alphabet substitution\n\n");
 printf("(5)  Decrypt rotation cipher with unknown rotation\n\n");
 printf("(6)  Decrypt substitution cipher with unknown alphabet substitution\n\n");
 
 //menu interation s=selected number
 int s;
 scanf("%d", &s);
 switch(s){
     case 1:
     
     break;
     
     case 2:
     
     break;
     
     case 3:
     
     break;
     
     case 4:
     
     break;
     
     case 5:
     
     break;
     
     case 6:
     
     break;
     
     default:
     printf("%c is not an option. Choose a number between 1-6\n", s);
     return s;
     
 }
 

return 0;
}
