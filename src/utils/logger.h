#include <stdio.h>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define END "\033[0m"

#define ERROR "\033[1;31m[ERROR]: \033[0m" // 26
#define WARNING "\033[1;33m[WARNING]: \033[0m" //28
#define SUCCESS "\033[1;32m[SUCCESS]: \033[0m" //28
#define INFO "\033[1;34m[INFO]: \033[0m" //23


void setLoggingLevel(int level);

void rainbowMessage(char *string);
void infoMessage(char * string);
void successMessage(char * string);
void warningMessage(char * string);
void errorMessage(char * string);


void testFuntion();