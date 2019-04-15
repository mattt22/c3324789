#include <stdio.h>
#include <string.h>

int main()
{
    int i = 1000;
    char str2[i];
    
    printf("Enter message to be Encrypted:");
    scanf("%[^\n]s", str2);
    
    int k;
    printf("\nEnter rotation of cipher:");
    scanf("%d", &k);
    
    printf("Your message has been encrypted to the following:\n");
    for(i=0;i<strlen(str2);i++){
    
    if(str2[i]>=32 && str2[i]<=64){
        continue;
    }
    else if(str2[i]>=97 && str2[i]<=122){
        str2[i]= str2[i] - 97;
        str2[i] = ((str2[i] + k) % 26);
        str2[i]= str2[i] + 65;
        continue;
    }
    else
    str2[i]= str2[i] - 65;
    str2[i] = ((str2[i] + k) % 26);
   str2[i] = str2[i] + 65;
    continue;
  
    }
   printf("%s", str2);
    return 0;
}
