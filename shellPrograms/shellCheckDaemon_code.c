#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{
   ssize_t nread;
   char *line = NULL;
   size_t len = 0;

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   while (1)
   {
      if (system(command) != -1)
      {
         break;
      }
   }
   free(command);

   int live_daemons = 0;
   // // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // // 1. Open the file
   FILE *fp = fopen("output.txt", "r");
   // // 2. Fetch line by line using getline()
   // // 3. Increase the daemon count whenever we encounter a line
   if (fp != NULL)
   {

      printf("count is %i\n", live_daemons);
      // 3. Read the file line by line by using getline(&buffer, &size, fp)
      while ((nread = getline(&line, &len, fp)) != -1)
      {
         live_daemons = live_daemons + 1;
         printf("Retrieved line of length %zu:\n", nread);
         fwrite(line, nread, 1, stdout);
      }
   }
   // // 4. Close the file
   printf("this is closing...\n");
   fclose(fp);
   // // 5. print your result
   printf("live daemon count: %i\n", live_daemons);

   if (live_daemons == 0)
      printf("No daemon is alive right now\n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }

   // TODO: close any file pointers and free any statically allocated memory

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}