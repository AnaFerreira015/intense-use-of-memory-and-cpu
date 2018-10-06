#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[], char *envp[])
{
  int pid; // Process ID
  char cpu[100], cpu_mem[100],kill_process[20];
  int i; //counter variable
  int time_process; //time process

    pid = fork(); //creating a Process
   

    if(pid < 0) //process fail
    {
      perror("Erro: ");
      exit(-1);
    }
    

      sprintf(cpu, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");  //script to result CPU
      sprintf(cpu_mem,"%s%d%s","pmap ", pid, " | grep -i total |" " awk '{print $2}'"); //script to result MEM
      sprintf(kill_process, "%s%d","kill ",pid);  //script to kill the process


    if(pid > 0) //I'm the father process
    {
      for(i=0;i<10;i++)
      {
        system("clear");
      
        if(strcmp(argv[1],"ucp") == 0) //if the argument after the program name is cpu, we executing the usage of him
        {
          printf("||| UCP Process |||\n");
          printf("TIME: %ds\n",i);
          printf("UCP(%%)\n");
          system(cpu); //calling the cpu usage
        }
        else if(strcmp(argv[1],"ucp-mem") == 0) //if the argument after the program name is cpu-mem, we executing the usage of him
        {
          printf("||| UCP AND MEMORY Process |||\n");
          printf("TIME: %ds\n",i);
          printf("UCP(%%)\n");
          system(cpu); //calling the cpu usage
          printf("\nMEM\n");
          system(cpu_mem); //calling the memory usage
        }

        usleep(1000000); //suspend execution for microsecond intervals
      }

      system(kill_process);
    }
    else // I'm the soon process (pid == 0)
    {
      if (strcmp(argv[1], "ucp") == 0) //If argv[1] = 'cpu', execute code with intensive use of CPU:
  		{
  			for(;;)
  			{
  				 //usleep(1000);
  			}
  		}
  		else if (strcmp(argv[1], "ucp-mem") == 0) //If argv[1] = 'cpu-mem', execute code with intensive use of UCP and memory:
  		{
        clock_t start_t, end_t, total_t;
        start_t = clock(); // start to count clock
  			for(;;)
  			{
          end_t = clock(); // end of clock
          total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
          //
          if(total_t <= 10000)
          {
            	malloc(15*sizeof(int));
          }

  			}
  		}

    }
    perror("Erro: ");

    printf("Tchau !\n");
    exit(0);


}
