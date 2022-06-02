#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

int main()
{
    
    int pswd_len;
    char c;
    int min = 48;
    int max = 126;
    char str[pswd_len];
    
    srand(time(0));
    printf("Welcome in password generator ! \n");
    printf("\n");
 
    do
    {  
        printf("Enter lenght of password :\n");
        printf("Minimal lengh of password is 5. \n");

    } while (((scanf("%d%c", &pswd_len, &c)!=2 || c!='\n') && clean_stdin()) || pswd_len<5);
     
    for(int i =0; i<pswd_len;i++){
        
        char r = (rand() % (max + 1 - min)) + min;
        //printf("%c", r );
        strncat(str, &r, 1);
    
    }
    printf("%s", str);
    
    FILE *out=fopen("./your_password.txt","w");
	fputs(str,out);
	fclose(out);
    return 0;
}