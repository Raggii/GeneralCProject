#include <stdio.h> // define the header file 
#include <stdlib.h>
#include <string.h> 

#include "utils/logger.h"
#include "modules/folderTest/folderTest.h"


/********************************************************************************
TODO
- Add Custom inline commands DEBUG = XYZ so it can be changed on command line but
also has defaults
- Set Up Doxygen
- Set up GDB
- Set up the Git hub pipelines
- Write tests (Or exaple tests)
- Create an example for the project

*********************************************************************************/

void setDefults()
{
    setLoggingLevel(1);
    // Add all debugs
}


int main( int argc, char *argv[])   // define the main function  
{  
    setDefults();
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-D") == 0)
        {
            setLoggingLevel(atoi(argv[i+1]));
            i++; // Takes the number after the debug and moves to next value afterwards 
        } else if(strcmp(argv[i], "DEBUG_TO_F")){
            //Set debugging to a file
            
        } else if(strcmp(argv[i], "CHANGE_CODE_VALUE_1")){
            //Set to a specific build variable
            
        } else if(strcmp(argv[i], "CHANGE_CODE_VALUE_2")){
            //Set to a specific build variable
            
        } else if(strcmp(argv[i], "CHANGE_CODE_VALUE_3")){
            //Set to a specific build variable
            
        }
         
    }


    printf("Welcome to C Convenience \n");  // print the statement.  
    testFuntion();
    printf("\n\n");
}  