#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  int status;
  int i;
  
  char *lsl_args[] = {"ls","-l", NULL};
  
  char *ls_args[] = {"ls", NULL};
  char *grep_args[] = {"grep", "^d", NULL};
  char *wc_args[] = {"wc", "-l", NULL};

  int pipes[4];
  pipe(pipes);
  pipe(pipes + 2); 

  if (fork() == 0)
    {
      dup2(pipes[1], 1);

      close(pipes[0]);
      close(pipes[1]);
      close(pipes[2]);
      close(pipes[3]);
      execvp(*ls_args, ls_args);
    }
  else
    {
      if (fork() == 0)
	{

	  dup2(pipes[0], 0);

	  dup2(pipes[3], 1);

	  close(pipes[0]);
	  close(pipes[1]);
	  close(pipes[2]);
	  close(pipes[3]);

	  execvp(*grep_args, grep_args);
	}
      else
	{

	  if (fork() == 0)
	    {
	      dup2(pipes[2], 0);

	      close(pipes[0]);
	      close(pipes[1]);
	      close(pipes[2]);
	      close(pipes[3]);

	      execvp(*wc_args, wc_args);
	    }
	}
    }
     
     if (fork() == 0) 
    {
        wait(NULL);
    }
   else 
    {
        execl( "/bin/ls", "ls", "-l", (char*)0 );
        //execl( "/bin/ls", "ls");
    }
      
  close(pipes[0]);
  close(pipes[1]);
  close(pipes[2]);
  close(pipes[3]);

  for (i = 0; i < 3; i++)
    wait(&status);
}
