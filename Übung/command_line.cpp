#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char eingabe_buffer[10];
const char *actualStatus;
const char *systemStatus[] = {"ok","warning","error","unknown"};
const char *commands[3] = {"status",
                            "clear",
                            "exit"  };

void showCommands(){
    for (int i; i < sizeof(commands); i++)
    {
        printf("%s\n", commands[i]);
    }
}

void statusCommand(char *cmd){

    if(strcmp(eingabe_buffer, "status") == 0){
        printf("Status: %s", actualStatus);
    }
}

void clearCommand(char *cmd){

    if (strcmp(eingabe_buffer, "clear") == 0)
    {
        eingabe_buffer[0] = '\0';
    }
}

int caracterCount(char* cmd){
    int count=0;
    while(*cmd != '\0'){
        cmd++;
        count++;
    }
    return count;
}

int main(){

    printf("Enter Command: ");
    scanf("%10s", eingabe_buffer);
    int numofCaracters = caracterCount(eingabe_buffer);

    if (strcmp(eingabe_buffer, "help") == 0)
    {
        showCommands();
    }
    else if (numofCaracters > sizeof(eingabe_buffer) || eingabe_buffer[0] == '\0')
    {
        actualStatus = systemStatus[2];
        printf("Error");
    }
}

/*else
{
    actualStatus = systemStatus[3];
    printf("Unknown Command");
}*/
