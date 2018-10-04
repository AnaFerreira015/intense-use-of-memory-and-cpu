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
  char cpu[100], cpu_mem[100], kill_process[20];
  int i;            //counter variable
  int time_process; //time process

  pid = fork(); //creating a Process
  // printf("PID = %d\n",pid);

  if (pid < 0) //process fail
  {
    perror("Erro: ");
    exit(-1);
  }

  sprintf(cpu, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");          //script to result CPU
  sprintf(cpu_mem, "%s%d%s", "pmap -x ", pid, " | grep total | awk '{print $4}'"); //script to result RAM
  sprintf(kill_process, "%s%d", "kill ", pid);                                     //script to kill the process

  // system(cpu);

  if (pid > 0) //I'm the father process
  {
    for (i = 0; i < 10; i++)
    {
      system("clear");

      if (strcmp(argv[1], "cpu") == 0) //if the argument after the program name is cpu, we executing the usage of him
      {
        printf("||| CPU Process |||\n");
      }
      else if (strcmp(argv[1], "cpu_mem") == 0) //if the argument after the program name is cpu-mem, we executing the usage of him
      {
        printf("||| CPU AND MEMORY Process |||\n");
      }

      printf("TIME: %ds\n", i);
      // printf("CPU Process\n");
      printf("CPU\n");
      system(cpu); //calling the cpu usage
      printf("\nRAM\n");
      system(cpu_mem); //calling the moemory usage
      usleep(1000000); //suspend execution for microsecond intervals
    }
    system(kill_process);
  }
  else // I'm the soon process (pid == 0)
  {
    if (strcmp(argv[1], "cpu") == 0) //If argv[1] = 'cpu', execute code with intensive use of CPU:
    {
      for (;;)
      {
       // usleep(1000);
      }
    }
    else if (strcmp(argv[1], "cpu_mem") == 0) //If argv[1] = 'cpu-mem', execute code with intensive use of UCP and memory:
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