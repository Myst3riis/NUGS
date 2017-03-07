#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count = 0;
int main(int argc, char* argv[]){
    printf("NUGS\n");
    while (count < 1){
        printf("> ");
        fflush(stdout); //Allow display on every shell

        //Define var
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

        if (fork()== 0){
            execvp(args[0],args);
            exit(0);
        }
        wait(0);

    }
    //Final print
    printf(">Terminated<\n");

}