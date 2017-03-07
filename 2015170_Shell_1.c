#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
#define HISTORY_COUNT 1000


 int currentmain=0;

void sigintHandler(int sig_num)
{
   
    fflush(stdout);
    
    

}

int history(char *hist[], int current)
{
        int i = 0;
        int hist_num = 1;

        while (i < current) {
                if (hist[i]) {
                        printf("%4d  %s\n", hist_num, hist[i]);
                        hist_num++;
                }

                i = i + 1;

        } 

        return 0;
}



int killl(int j,char *str1[100])
{
 if (j<=2)
    {
        printf("usage: ./kill PID");
        return -1;
    }

    kill(atoi(str1[1]), SIGKILL);

    return 0;
}


int main()
{

signal(SIGINT, sigintHandler);

pid_t pid1,pid2;
char *hist[101];
int current=0,cc=0,kk=0;


    //execl("/usr/bin/xterm", "xterm", "-c","./a.out", NULL);

    while(1)
    {
	
    char s[20],ss[20]={'S','h','e','l','l'};
    signal(SIGINT, sigintHandler);
    printf("%s> ",ss);

    gets(s);
    
    //puts(s);
    if(strcmp(s,"exit")==0||strcmp(s,"Exit")==0)
        exit(1);
     if(strcmp(s,"cd")==0||strcmp(s,"cd ")==0)
        kk=1;
    if(strcmp(s,"clear")==0)
           printf  ("\033c");  
    if(strcmp(s,"help")==0)
	{
		printf("cd [-L|[-P [-e]] [-@]] [dir]\nclear\nexec [-cl] [-a name] [command [argume>\nhelp [-dms] [pattern ...]\nhistory [-c] [-d offset] [n] or hist>\nkill [-s sigspec | -n signum | -sigs>\npwd [-LP]\nwait [-n] [id ...]\n");
	}


    char* str1[100];
    char main[6]= "/bin/";
    char str[100]="";
    char *token;


    if(kk==0)
        token = strtok(s," ");
    else
        kk=0;
   
    int i=0;

    while(token!=NULL)
    {
       // printf("%d %d",strlen(token),strlen(s));
        str1[i]=token;
        if(i==0)
            strcpy(str,token); 

       
        token = strtok(NULL," ");
        i++;
    }

    str1[i]=NULL;
    int j;
    char fin[100];
    j=i;

    if(strcmp(str,"cd")==0)
        strcat(ss,str1[1]);
   if(strcmp(str,"kill")==0)
	killl(j,str1);
   
	

    strcpy(fin, main);
    strcat(fin, str);
//puts(fin);
    for(i=0; i<strlen(fin); i++)
        {
            if(fin[i]=='\n')
            {
                fin[i]='\0';
            }
        }

        
       if (s[strlen(s) - 1] == '\n')
                        s[strlen(s) - 1] = '\0';
    		
		if(s[0]!='\0')
{
   		hist[current] = strdup(s);
		cc=current;
		currentmain=current;
                current = current + 1;
			
		 if (strcmp(s, "history") == 0)
                        history(hist, current);
		if(current==100)
			current=0;
                
}    


	


   
    pid2=fork();

    if(pid2==0)
    {

 
        if(str1[j-1]!=NULL)
            {
                if(strcmp(str,"cd")==0)
                {
                        
			if(str1[1]!=NULL)
			{
			chdir(str1[1]);
			FILE *f;
			f = fopen(str1[1], "r");
			if(!f)
   			printf("bash: cd: %s: No such file or directory\n",str1[1]);
			}
		    
                }

                else
                {
		   
                    execvp(fin,str1);
		    if(str1[0]!=NULL)
		    printf("%s: command not found\n",s);
			
                }

            }
        
exit(0);
    }
    else
        {
 		if(strcmp(str,"cd")==0)
                {
                    chdir(str1[1]);
                }


           
          
		 
          wait(NULL);

        }
}


return 0;
}
