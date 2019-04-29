#include <stdio.h>
#include <string.h>

char encryption(char str2[], int k);    //function prototype for rotation cipher encryption
char decryption(char str1[], int k);    //function prototype for rotation cipher decryption
char encryptionSub(char str3[], char str4[]);   //function prototype for substitution cipher encryption
char decryptionSub(char str3[], char str4[]);   //function prototype for substitution cipher decryption
char decryptionKeyless(char str1[], char str2[], int k); //function for rotation cipher decryption (without key)

int main()
{
 
 char str2[1000];
 char str1[1000];
 char str3[1000];
 char str4[25]; //creates string for substitution key to be stored in
 int k; //creates integer for rotation key to be stored in

 label: //program returns to this point if selected after encryption/decryption operation
 
 //prompts user to select one of the options printed to screen by typing a number between 1-6
 printf("Enter 1-6 to carry out one of the following operations:\n");
 printf("(1)  Encrypt message with roatation cipher\n");
 printf("(2)  Decrypt rotation cuipher with given rotation\n");
 printf("(3)  Encrypt substitution cipher with given alphabet substitution\n");
 printf("(4)  Decript substitution cipher with given alphabet substitution\n");
 printf("(5)  Decrypt rotation cipher with unknown rotation\n");
 
 //menu interation s=selected number from previous user prompt
 int s;
 scanf("%d", &s);
 switch(s){
     case 1:    //if 1 is selected the rotation encryption (with rotation key) function will be run
        encryption(str2, k);
        break;
     
     case 2:    //if 2 is selected the rotation decryption (with rotation key) function will be run
        decryption(str1, k);
        break;
     
     case 3:    //if 3 is selected the substitution encryption (with substitution key) function will be run
        encryptionSub(str3, str4);
        break;
     
     case 4:    //if 4 is selected the substitution decryption (with substitution key) function will be run
        decryptionSub(str3, str4);
        break;
     
     case 5:    //if 2 is selected the rotation decryption (without rotation key) function will be run
        decryptionKeyless(str1, str2, k);
        break;
     
     default:
        printf("%d was not on option, program has been terminated", s);
        return 0;
 }
 int m; //creates a storage integer for user selction
 printf("\nWould you like to Decrypt/Encrypt again?:\n"); //prompts user to select 1 is they want the program to run again and 2 if they want it to terminate
 printf("(1) Yes\n"); 
 printf("(2) No\n");
 scanf("%d", &m);   //scans user selection and stores it in m
 
 switch(m){
     case 1: //program goes to "label" in code
        goto label; 
        break;
     
     case 2:  //program terminates
        printf("Program has been terminated\n");
        break;
     
     default: 
        printf("%d was not an option, program has been terminated\n", m);
        break;
 }
return 0;
}
//definition of the rotation encryption function
char encryption(char str2[], int k){
    
    int i;  //creates a integer to count thorugh string characters and modify them individually
    
    //prompts user to enter a message to be encrypted and stores it in str2
    printf("\nEnter message to be Encrypted:\n"); 
    scanf(" %[^\n]s", str2);
    
    //prompts user to enter a rotation value and stores it in k
    printf("\nEnter rotation of cipher:");
    scanf(" %d", &k); 
    
    printf("\nYour message has been encrypted to the following:\n");    //tells user that the text below it is the encrypted message
    
    
    for(i=0;i<strlen(str2);i++){    //encrypts each character of the string individually then moves to the next
    
    if(str2[i]>=32 && str2[i]<=64){     //if the character isn't a letter its ascii value remains unchanged pre encryption
        continue;
    }
    else if(str2[i]>=97 && str2[i]<=122){       //if the character is a lower case the following will happen:
        str2[i]= str2[i] - 97;                  //each letters ascii value will be reduced so "a" = 0 "z" = 25 
        str2[i] = ((str2[i] + k) % 26);         //the rotation of the cipher will be added to each new string char assignment and its modulas of 26 will become the new value to account for the rotation wrapping from the end of the alphabet back to the start
        str2[i]= str2[i] + 65;                  //converts string chars back into letter ascii values + the rotation amount 
        continue;
    }
    else
    str2[i]= str2[i] - 65;                      //if the character is already a capital each letters ascii value will be reduced so "A" = 0 "Z" = 25 
    str2[i] = ((str2[i] + k) % 26);             //the rotation of the cipher will be added to each new string char assignment and its modulas of 26 will become the new value to account for the rotation wrapping from the end of the alphabet back to the start
   str2[i] = str2[i] + 65;                      //converts string chars back into letter ascii values + the rotation amount
    continue;
  
    }
   printf("%s\n\n", str2);  //prints encrypted message to screen
   
   return str2[i];
}

//definition of the rotation decryption function
char decryption(char str1[], int k){
    int i;  //creates a integer to count thorugh string characters and modify them individually
    
    //prompts user to enter a message to be decrypted and stores it in str1
    printf("\nEnter message to be decrypted:\n");
    scanf(" %[^\n]s", str1);
    
    //prompts user to enter a rotation value and stores it in k
    printf("\nEnter rotation of cipher:");
    scanf(" %d", &k);
    
    printf("\nYour message has been decrypted to the following:\n");    //tells user that the text below it is the decrypted message
    
    for(i=0;i<strlen(str1);i++){    //decrypts each character of the string individually then moves to the next
    
    if(str1[i]>=32 && str1[i]<=64){     //if the character isn't a letter its ascii value remains unchanged pre encryption
        continue;
    }
    else if(str1[i]>=97 && str1[i]<=122){           //if the character is a lower case the following will happen:
        str1[i]= str1[i] - 97;                      //each letters ascii value will be reduced so "a" = 0 "z" = 25
        str1[i] = ((str1[i] + 26 - k) % 26);        //the rotation of the cipher will be subtracted from each new string char assignment and its modulas of 26 will become the new value to account for the rotation wrapping from the end of the alphabet back to the start
        str1[i]= str1[i] + 65;                      //converts string chars back into letter ascii values + the rotation amount
        continue;
    }
    else
    str1[i]= str1[i] - 65;                          //if the character is already a capital each letters ascii value will be reduced so "A" = 0 "Z" = 25 
    str1[i] = ((str1[i] + 26 - k) % 26);            //the rotation of the cipher will be subtracted from each new string char assignment and its modulas of 26 will become the new value to account for the rotation wrapping from the end of the alphabet back to the start
    str1[i] = str1[i] + 65;                         //converts string chars back into letter ascii values + the rotation amount
    continue;
  
    }
   printf("%s\n\n", str1);  //prints decrypted message to screen
   return str1[i];
}

//definition of the substitution encryption (with key) 
char encryptionSub(char str3[], char str4[]){
//*creates a string to store message and prompts user to enter message*//
	int i;
	
	//prompts user to enter a message to be encripted and stores it in the string str3
	printf("\nEnter message to be encripted:\n");
	scanf(" %[^\n]s", str3);
	
	//*prompts user to enter a substitution for each letter of the alphabet and stores it*//
	printf("\nEnter substitution of cipher in order of substitution e.g. QWERTYUIOPASDFGHJKLZXCVBNM where 'A' will become 'Q' and 'Z' will become 'M':\n");
	scanf(" %s", str4);
	
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
			
			//*Encrypts message stored in str3 by substitution of each letter individually*//
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
	printf("\nYour message has been encrypted to:\n%s\n\n", str3);
}

//definition of the substitution decryption 
char decryptionSub(char str3[], char str4[]){
    
    
	int i;

	//prompts user to enter a message to be encripted and stores it in the string str3
	printf("\nEnter message to be decripted:\n");
	scanf(" %[^\n]s", str3);
	
	//*prompts user to enter a substitution for each letter of the alphabet and stores it*//
	printf("\nEnter substitution of cipher in order of substitution e.g. QWERTYUIOPASDFGHJKLZXCVBNM where 'Q' will become 'A' and 'M' will become 'Z':\n");
	scanf(" %s", str4);
	
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
	}
	
			
			//*Encrypts message stored in str3 by substitution of letters. (str3 = message to be decrypted) (str4[1] - str4[25] = substitution string) (65-90 = ascci code for A-Z)lkj*//
			for(i=0;i<strlen(str3);i++){
			    if (str3[i] == str4[0]){
			        str3[i] = 65;
			    }
			    else if(str3[i] == str4[1]){
			        str3[i] = 66;
			    }
			    else if(str3[i] == str4[2]){
			        str3[i] = 67;
			    }
			    else if(str3[i] == str4[3]){
			        str3[i] = 68;
			    }
			    else if(str3[i] == str4[4]){
			        str3[i] = 69;
			    }
			    else if(str3[i] == str4[5]){
			        str3[i] = 70;
			    }
			    else if(str3[i] == str4[6]){
			        str3[i] = 71;
			    }
			    else if(str3[i] == str4[7]){
			        str3[i] = 72;
			    }
			    else if(str3[i] == str4[8]){
			        str3[i] = 73;
			    }
			    else if(str3[i] == str4[9]){
			        str3[i] = 74;
			    }
			    else if(str3[i] == str4[10]){
			        str3[i] = 75;
			    }
			    else if(str3[i] == str4[11]){
			        str3[i] = 76;
			    }
			    else if(str3[i] == str4[12]){
			        str3[i] = 77;
			    }
			    else if(str3[i] == str4[13]){
			        str3[i] = 78;
			    }
			    else if(str3[i] == str4[14]){
			        str3[i] = 79;
			    }
			    else if(str3[i] == str4[15]){
			        str3[i] = 80;
			    }
			    else if(str3[i] == str4[16]){
			        str3[i] = 81;
			    }
			    else if(str3[i] == str4[17]){
			        str3[i] = 82;
			    }
			    else if(str3[i] == str4[18]){
			        str3[i] = 83;
			    }
			    else if(str3[i] == str4[19]){
			        str3[i] = 84;
			    }
			    else if(str3[i] == str4[20]){
			        str3[i] = 85;
			    }
			    else if(str3[i] == str4[21]){
			        str3[i] = 86;
			    }
			    else if(str3[i] == str4[22]){
			        str3[i] = 87;
			    }
			    else if(str3[i] == str4[23]){
			        str3[i] = 88;
			    }
			    else if(str3[i] == str4[24]){
			        str3[i] = 89;
			    }
			    else if(str3[i] == str4[25]){
			        str3[i] = 90;
			    }
			    else
			    str3[i] = str3[i];
	        }
			
	//*prints Encrypted message*//
	printf("\nYour message has been encrypted to:\n%s\n\n", str3);
}

//definition of the rotation decryption (without key) function
char decryptionKeyless(char str1[], char str2[], int k){
    int i;  //creates a integer to count thorugh string characters and modify them individually
    
    //prompts user to enter a message to be decrypted and stores it in str1
    printf("\nEnter message to be decrypted:\n");
    scanf(" %[^\n]s", str2);
    
    printf("\nYour message is one of the combinitions below:\n");    //tells user that the text below it is the decrypted message
    
    for(k=1;k<=25;k++){
        for(i=0;i<strlen(str2);i++){
            str1[i] = str2[i];
        }
        
        
        
        for(i=0;i<strlen(str2);i++){    //decrypts each character of the string individually then moves to the next
            
            if(str1[i]>=32 && str1[i]<=64){     //if the character isn't a letter its ascii value remains unchanged pre encryption
            continue;
            }
            else if(str1[i]>=97 && str1[i]<=122){           //if the character is a lower case the following will happen:
                str1[i]= str1[i] - 97;                      //each letters ascii value will be reduced so "a" = 0 "z" = 25
                str1[i] = ((str1[i] + 26 - k) % 26);        //the rotation of the cipher will be subtracted from each new string char assignment and its modulas of 26 will become the new value to account for the rotation wrapping from the end of the alphabet back to the start
                str1[i]= str1[i] + 65;                      //converts string chars back into letter ascii values + the rotation amount
                continue;
            }
            else
                str1[i]= str1[i] - 65;                          //if the character is already a capital each letters ascii value will be reduced so "A" = 0 "Z" = 25 
                str1[i] = ((str1[i] + 26 - k) % 26);            //the rotation of the cipher will be subtracted from each new string char assignment and its modulas of 26 will become the new value to account for the rotation wrapping from the end of the alphabet back to the start
                str1[i] = str1[i] + 65;                         //converts string chars back into letter ascii values + the rotation amount
                continue;
            }
        
        printf("rotation of %d: %s\n", k, str1);  //prints decrypted message to screen
    }
   return str1[i];
}
