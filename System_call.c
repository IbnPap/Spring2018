#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>


double get_time()
{
	double time = 0.0;
	struct timeval ctime;
	gettimeofday(&ctime, (struct timezone*)0);
	time = (double)(ctime.tv_sec +
                             ctime.tv_usec*1.0e-3);

	return(time);
}



// this is a sample procedure call which do some primary operation
int Syst_call(){
    int mul;
    
    for (int i=0; i<=10000;i++){
        mul*= 2;
    }
    return(mul);

}
    int main(int argc, const char * argv[])
{
    
	double start, end, avgtimeS, t_interval, avgtimef;
	long k;
    long itr = 10000;
    pid_t   pId;
    
    //Start of process
    start = get_time();
	for (long k = 0; k < itr; k++){
		int i = getpid();
	}
    //end of the process
	end = get_time();

    //
    t_interval = end - start;

    //average time it take for process
	avgtimeS = (end - start) / itr;
	printf("The time it take to get pid %f\n", avgtimeS);
    
    
    // start time for the function call
    start = get_time();
	for (int i = 0; i< itr; i++){
        Syst_call();
    }
    //end of the function call
    end = get_time();
    //time interval for the function call
    t_interval = end -start;
	avgtimef = (end - start) / itr;
	printf("the time it takes to do a system call: %f\n", avgtimef);

	return 0;

}