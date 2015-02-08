#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


time_t currentTime;
FILE *outputFile;
void printCurrentTime(){

	currentTime=time(NULL);
	
	outputFile=fopen("t.txt", "a");
	fprintf(outputFile, ctime(&currentTime));
	fprintf(outputFile, "\n");
	fclose(outputFile);
}

void timerOn() {
    time_t currentTime, end;
    int elapsed=0;
 
    time(&currentTime);
 
    while(elapsed < 5) {
         time(&end);
         elapsed = difftime(end, currentTime);         
    }    
}



int main (){

/*pid_t process_id = 0;
pid_t sid = 0;
// Create child process
process_id = fork();
// Indication of fork() failure
if (process_id < 0)
{
printf("fork failed!\n");
// Return failure in exit status
exit(1);
}
// PARENT PROCESS. Need to kill it.
if (process_id > 0)
{
printf("process_id of child process %d \n", process_id);
// return success in exit status
exit(0);
}
//unmask the file mode
umask(0);
//set new session
sid = setsid();
if(sid < 0)
{
// Return failure
exit(1);
}
// Change the current working directory to root.
chdir("/tmp");
// Close stdin. stdout and stderr
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
*/
	pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    chdir("/tmp");

		while(1){
			//sleep(1);
		printCurrentTime();
		timerOn();
	}
}