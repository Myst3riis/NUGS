#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

void tee(FILE* f, char* fmt, ...) {
	/*
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
	*/
    va_list ap1, ap2;

    va_start(ap1, fmt);
    va_copy(ap2, ap1);

    vprintf(fmt, ap1);
    vfprintf(f, fmt, ap2);

    va_end(ap2);
    va_end(ap1);
}

int main(int argc, char* argv[]){
    /*
    * Opens a shell to talk with NUGS
    * enter text, NUGS answers / enter "[record]" to record the conversation 
    * ctrl+c to close
    */
    printf("#   #  #  #   ##    ##\n");
    printf("##  #  #  #  #     #\n");
    printf("# # #  #  #  # ##   #\n");
    printf("#  ##  #  #  #  #    #\n");
    printf("#   #   ##    ##   ##\n");

    //Define variables
    int count = 0;
    int record = 0;
    int MAXLINE = 1024;
    int MAXARGS = 1024;
    char cmd[MAXLINE];

    while (count < 1){
        printf("> ");
        fflush(stdout); //Allow display on every shell

        //Reading keyboard
        if (fgets(cmd, MAXLINE, stdin) == NULL){
            printf("No command to execute \n");
        }

        //Exec
        int i;
        char* args[MAXARGS];        
        args[0] = "./Nugs,.sh";
        args[1] = strtok(cmd, " \t\n");
        for (i = 2; i < MAXARGS; i++){
            if ((args[i] = strtok(NULL, " \t\n")) == NULL) break;
        }
            //Records or not
        if (strcmp(args[1],"[record]")==0)
            record = 1;
        if (strcmp(args[1],"[end]")==0)
            record = 0;

        if (fork()== 0){
            if (record == 1){
                // records the conversation in a file
		FILE* fd = fopen("Conversations.txt","a");
//                printf("\x1B[31m""NUGS>\n");
		tee(fd, "%s","\x1B[31m""NUGS>\n");
                execvp(args[0],args);
		fclose(fd);
                exit(0);
            }else{
                // normal conversation, not recorded
                printf("\x1B[0m" "NUGS>\n");
                execvp(args[0],args);
                exit(0);
            }
        }
        wait(0);

    }
    //Final print
    printf(">Terminated<\n");

}
