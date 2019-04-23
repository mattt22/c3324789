#include <stdio.h>
#include <string.h>

int main()
{
	//*creates a string to store message and prompts user to enter message*//
	int i = 1000;
	char str3[i];
	printf("Enter message to be encripted:\n");
	scanf("%[^\n]s", str3);
	
	//*prompts user to enter a substitution for each letter of the alphabet and stores it*//
	char str4[i];
	printf("Enter substitution of cipher:\n");
	scanf("%s", str4);
	
	//*if the letter substitutions entered are lower case they will be converted to upper case*//
	for(i=0;i<strlen(str4);i++){    //applies if statment to every substitution character
			
			if(str4[i] >= 97 && str4[i] <= 122){
				str4[i] = str4[i] - 32;
				}
				else str4[i] = str4[i];
	}
	
	for(i=0;i<strlen(str3);i++){    //applies if statment to every letter in the message stored in str3
			
			if(str3[i] >= 97 && str3[i] <= 122){    //converts lower case letters in message to upper case
				str3[i] = str3[i] - 32;
				}
			
			//*Encrypts message stored in str3 by substitution of letters*//
			switch(str3[i]){    
				case 65: str3[i] = str4[0]; break;
				case 66: str3[i] = str4[1]; break;
				case 67: str3[i] = str4[2]; break;
				case 68: str3[i] = str4[3]; break;
				case 69: str3[i] = str4[4]; break;
				case 70: str3[i] = str4[5]; break;
				case 71: str3[i] = str4[6]; break;
				case 72: str3[i] = str4[7]; break;
				case 73: str3[i] = str4[8]; break;
				case 74: str3[i] = str4[9]; break;
				case 75: str3[i] = str4[10]; break;
				case 76: str3[i] = str4[11]; break;
				case 77: str3[i] = str4[12]; break;
				case 78: str3[i] = str4[13]; break;
				case 79: str3[i] = str4[14]; break;
				case 80: str3[i] = str4[15]; break;
				case 81: str3[i] = str4[16]; break;
				case 82: str3[i] = str4[17]; break;
				case 83: str3[i] = str4[18]; break;
				case 84: str3[i] = str4[19]; break;
				case 85: str3[i] = str4[20]; break;
				case 86: str3[i] = str4[21]; break;
				case 87: str3[i] = str4[22]; break;
				case 88: str3[i] = str4[23]; break;
				case 89: str3[i] = str4[24]; break;
				case 90: str3[i] = str4[25]; break;
				defalut: str3[i] = str3[i];
			}
	}
	
	//*prints Encrypted message*//
	printf("%s", str3);


	return 0;
}