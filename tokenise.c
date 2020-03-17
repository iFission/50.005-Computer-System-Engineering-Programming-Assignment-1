#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
/* "readdir" etc. are defined here. */
#include <dirent.h>
/* limits.h defines "PATH_MAX". */
#include <limits.h>

#define SHELL_INPUT_DELIM " \t\r\n\a"
#define SHELL_BUFFERSIZE 256
#define SHELL_OPT_DELIM "-"

char *shellReadLine(void)
{
    /** TASK 1 **/
    // read one line from stdin using getline()
    // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
    char *buffer = malloc(sizeof(char) * 1);
    size_t shell_buffersize = SHELL_BUFFERSIZE;
    // 2. Check that the char* returned by malloc is not NULL
    if (buffer != NULL)
    {
        // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
        getline(&buffer, &shell_buffersize, stdin);
        return buffer;
    }
    // 4. Return the char*

    return NULL;
}

char *line;
int main(int argc, char const *argv[])
{
    while (1)
    {
        line = shellReadLine(); //pointer 'line' stores where the command starts

        char *shell_input_delim = SHELL_INPUT_DELIM;
        char **token_positions = malloc(sizeof(char *) * 8);
        char *token = strtok(line, shell_input_delim);
        int index = 0;
        token_positions[index] = token;
        index++;

        while (token != NULL)
        {
            // Tokenize the rest of the
            token = strtok(NULL, shell_input_delim);
            token_positions[index] = token; //store the position index++;
            index++;
            //continue finding the next token
        }
        token_positions[index] = NULL; //dont forget to NULL terminate.

        printf("length of the commands is %i\n", index - 1);

        for (int i = 0; i < index - 1; i++)
        {
            printf("token %i is : %s, it is at address %0x \n", i, token_positions[i], token_positions[i]);
        }
    }

    return 1;
}
