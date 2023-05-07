#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "logger.h"

/********************************************************************************
TODO
- Add file logging
- Add possible timestamps if requested
- Thread ID's, Function Names, Sorce Files
- Deletion of old log files
- Docstrings

*********************************************************************************/



char * colourList[6] = {RED, YEL, GRN, CYN, BLU, MAG};
char * messageList[4] = {ERROR, WARNING, INFO, SUCCESS};
int LOGGING_LEVEL = 1;


void setLoggingLevel(int level)
{
    if(level >= 0 && level <=3)
    {
        LOGGING_LEVEL = level;
    } else
    {
        //Some error message
    }
}


static void printMessage(char * string, int level)
{
    if(level <= LOGGING_LEVEL)
    {
        int strLen = strlen(string) + strlen(messageList[level-1]) + 2;
        char buf[strLen];
        memset(buf, 0, sizeof(buf));
        snprintf(buf, strLen, "%s%s%s", messageList[level-1], string, "\n");
        buf[strlen(buf)] = '\0';
        printf("%s", buf);
    }
}


void errorMessage(char * string)
{
    printMessage(string, 1);
}


void warningMessage(char * string)
{
    printMessage(string, 2);
}


void infoMessage(char * string)
{
    printMessage(string, 3);
}


void rainbowMessage(char *string) {
    if(LOGGING_LEVEL == 3){
        char buf[strlen(string)*16 + 1];
        memset(buf, 0, sizeof(buf));

        for (int i = 0; i < strlen(string); i++) {
            strcat(buf, colourList[i % 6]);
            char temp[2] = {string[i], '\0'};
            strcat(buf, temp);
            strcat(buf, "\033[0m");
        }
        buf[strlen(buf)] = '\0';
        printf("%s", buf);
    }
}


void testFuntion() {
    errorMessage("This is a test error");
    warningMessage("This is a test warning");
    infoMessage("This is a test info");
    rainbowMessage("Hello World!");
}