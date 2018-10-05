#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
  int pid; // Process ID
  char ucp[100], ucp_mem[100], kill_process[20];
  int i;            //counter variable
  // int time_process; //time process

  pid = fork(); //creating a Process
  // printf("PID = %d\n",pid);

  if (pid < 0) //process fail
  {
    perror("Erro: ");
    exit(-1);
  }

  // sprintf(ucp_mem, "%s%d%s","ps v ",pid," | awk '{print $9}' | grep -v MEM");
  // system(ucp_mem);

  sprintf(ucp, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");          //script to result CPU
  // sprintf(ucp_mem, "%s%d%s", "pmap -x ", pid, " | grep total | awk '{print $4}'"); //script to result RAM
  sprintf(kill_process, "%s%d", "kill ", pid);                                     //script to kill the process

  // system(ucp);

  if (pid > 0) //I'm the father process
  {
    for (i = 0; i < 10; i++)
    {
      system("clear");

      if (strcmp(argv[1], "ucp") == 0) //if the argument after the program name is ucp, we executing the usage of him
      {
        printf("||| CPU Process |||\n");
      }
      else if (strcmp(argv[1], "ucp-mem") == 0) //if the argument after the program name is ucp_mem, we executing the usage of him
      {
        printf("||| CPU AND MEMORY Process |||\n");
      }

      printf("TIME: %ds\n", i);
      // printf("CPU Process\n");
      printf("CPU\n");
      system(ucp); //calling the ucp usage
      printf("\nRAM\n");
      system(ucp_mem); //calling the moemory usage
      usleep(1000000); //suspend execution for microsecond intervals
    }
    system(kill_process);
  }
  else // I'm the soon process (pid == 0)
  {
    if (strcmp(argv[1], "ucp") == 0) //If argv[1] = 'ucp', execute code with intensive use of CPU:
    {
      for (;;)
      {
       // usleep(1000);
      }
    }
    else if (strcmp(argv[1], "ucp_mem") == 0) //If argv[1] = 'ucp_mem', execute code with intensive use of UCP and memory:
    {
      for (;;)
      {
        malloc(sizeof(1024));
        usleep(1000);
      }
    }
  }
  perror("Erro: ");

  printf("Tchau !\n");
  exit(0);
}
