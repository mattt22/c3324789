#include <stdio.h>
#include <string.h>

int main()
{
    int i = 1000;
    char str1[i];
    
    printf("Enter message to be decrypted:");
    scanf("%[^\n]s", str1);
    
    int k;
    printf("\nEnter rotation of cipher:");
    scanf("%d", &k);
    
    printf("Your message has been decrypted to the following:\n");
    for(i=0;i<strlen(str1);i++){
    
    if(str1[i]>=32 && str1[i]<=64){
        continue;
    }
    else if(str1[i]>=97 && str1[i]<=122){
        str1[i]= str1[i] - 97;
        str1[i] = ((str1[i] + 26 - k) % 26);
        str1[i]= str1[i] + 65;
        continue;
    }
    else
    str1[i]= str1[i] - 65;
    str1[i] = ((str1[i] + 26 - k) % 26);
    str1[i] = str1[i] + 65;
    continue;
  
    }
   printf("%s", str1);
    return 0;
}
