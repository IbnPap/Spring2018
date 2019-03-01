
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>


int sched_setaffinity(pid_t pid, size_t lenght,
                      cpu_set_t *set);

int sched_getaffinity(pid_t pid, size_t lenght,
                      cpu_set_t *set);

//function prototy to get time 
double get_time()
{
	double time = 0.0;
	struct timeval ctime;
	gettimeofday(&ctime, (struct timezone*)0);
	time = (double)(ctime.tv_sec + ctime.tv_usec*1.0e-3);

	return(time);
}

	int main(int argc, char const *argv[]){

		//these veriable will record the start and end time for the process execution
		double start;
		double end;

		// set mask to CPU
    //    variables to set thread affinity to one processor
    cpu_set_t  set;
    CPU_ZERO(&set);
    unsigned int lenght = sizeof(set);
    CPU_SET(0, &set);

    unsigned int lenght = sizeof(set);
	
		// pipe definition for process intercommunication
    int     pipe[2];
    int     byte_lenght;
    char    piping[] = "pipe info!\n";
    pid_t   child_processId;
    char    buff_read[500];
    
    //macro of pipe for child process
    pipe(pipe);
    if((child_processId = fork()) == -1)
    	{       
        	perror("error\n");
        	exit(1);
    	}

    //The time is recorded for runtime
   start = get_time();
    
    //the affinity mask of processes to run on single CPU  
    if ( (sched_setaffinity(0, lenght, &set) ) < 1)
	    {
	    if(child_processId == 0)       
	    	{       
       			
       			 close(pipe[0]);
       			 write(pipe[1],piping, (strlen(piping)+1));
       			 exit(0);
    		}
  
   		 else
		    {
	
		        byte_lenght = read(pipe[0], buff_read, sizeof(buff_read));
		        end = get_time();

		        //print the time taken for a context switch
				printf("Context switch time is: %f \n", end - start);
		        close(pipe[1]);
		        
		    }
		}
    

    return(0);

}



 	   