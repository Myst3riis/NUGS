#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count = 0;
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
    int record = 0;
    while (count < 1){
        printf("> ");
        fflush(stdout); //Allow display on every shell

        //Define variables
        int MAXLINE = 1024;
        int MAXARGS = 1024;
        char cmd[MAXLINE];

        //Reading keyboard
        if (fgets(cmd, MAXLINE, stdin) == NULL){
            printf("No command to execute \n");
        }

        //Exec
        int i;
        char* args[MAXARGS];
        //args[0] = strtok(cmd, " \t\n");
        
        args[0] = "./Nugs,.sh";
        args[1] = strtok(cmd, " \t\n");
        for (i = 2; i < MAXARGS; i++){
            //if ((args[i] = strtok(NULL, " \t\n")) == NULL) break;
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
                printf("ON RECORD\n");
                execvp(args[0],args);
                exit(0);
            }else{
                // normal conversation, not recorded
                printf("NORMAL\n");
                execvp(args[0],args);
                exit(0);
            }
        }
        wait(0);

    }
    //Final print
    printf(">Terminated<\n");

}
