#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char userName[] = "Claude";
const char password[] = "iamcld#";

char bufferUser[32];
char bufferPass[32];

int check_userName(char* user)
{
    return (strcmp(user, userName) == 0);
}

int check_userPass(char *pass)
{
    return (strcmp(pass, password) == 0);
}

int main(){

    int exit = 1;

    while (exit)
    {
        printf("Enter your Username: \n");
        scanf("%32s", bufferUser);

        if (check_userName(bufferUser)){

            printf("Enter your Password: \n");
            scanf("%32s", bufferPass);

                if (check_userPass(bufferPass))
                {
                    printf("Welcome %s!\n", bufferUser);
                    exit = 0;
                }
                else
                {
                    printf("Password is not Correct \n");
                }
            }
        else
            {
                printf("Username is not Correct \n");
            }

   }

   return 0;
}
