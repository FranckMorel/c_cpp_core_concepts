#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char eingabe_buffer[10];
int unknownCounter = 0;
int helpShown = 0;
int running = 1;
const char *actualStatus = "ok";
const char *systemStatus[] = {"ok","warning","error","unknown"};

void handleHelp(void);
void handleStatus(void);
void handleClear(void);
void handleExit(void);
void handleUnknown(void);
void handleReset(void);

struct commandStruct{
    const char *name;
    void (*handler)(void);
};

const struct commandStruct commandList[] = {{"help", handleHelp},
                                            {"status", handleStatus},
                                            {"clear", handleClear},
                                            {"exit", handleExit},
                                            {"reset", handleReset}};


void readCommand()
{
    scanf("%9s", eingabe_buffer);
}

void showCommands()
{
    int size = sizeof(commandList) / sizeof(commandList[0]);
    for (int i = 1; i < size; i++)
    {
        printf("%s\n", commandList[i].name);
    }
}

void clearCommand(char *cmd)
{

    eingabe_buffer[0] = '\0';
}

/*int caracterCount(char *cmd)
{
    int count = 0;
    while (*cmd != '\0')
    {
        cmd++;
        count++;
    }
    return count;
} */


void handleHelp(){
    showCommands();
    helpShown = 1;
}

void handleStatus()
{
    printf("Status: %s\n", actualStatus);
}

void handleClear()
{
    clearCommand(eingabe_buffer);
}

void handleExit()
{
    running = 0;
}

void handleReset(){
    actualStatus = systemStatus[0];
    unknownCounter = 0;
    helpShown = 0;
}

void handleUnknown()
{
    if (unknownCounter >=  3)
    {
        actualStatus = systemStatus[0];
        printf("Too many invalid commands. System error.\n");
    }
    else
    {
        actualStatus = systemStatus[3];
        printf("Unknown Command\n");
        unknownCounter++;
    }
}



int main(){
    while (running)
    {
        printf("Enter command: ");
        readCommand();
        int size = sizeof(commandList) / sizeof(commandList[0]);
        int found = 0;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(eingabe_buffer, commandList[i].name) == 0)
            {
                commandList[i].handler();
                found = 1;
                break;
            }
        }
        if (!found)
            if(helpShown == 0){
                printf("Please enter 'help' to see the list of available commands.\n");
            }else{
                handleUnknown();
            }
    }
    return 0;



}
