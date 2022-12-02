//program to execute all function and system calls in one program
//162_mandar jondhale & 173_akash deshmukh.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/stat.h>
//Declarations of functions.
int fork1();
int read_write();
int lseek1();
int create();
int exit1();
int main()  //main function.
{
	int ch;
	//while loop used for performing function calls multiple time.
	while(1)
	{
		printf("\n1.fork\n2.read & write\n3.lseek\n4.create\n5.exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		//Switch case is for all functions.
		switch(ch)
		{
			case 1: fork1();
			break;
			
			case 2: read_write();
			break;
			
			case 3: lseek1();
			break;
			
			case 4: create();
			break;
			
			case 5: exit1();
			break;
			
			default: printf("Wrong choice.\n");
		}
	}
}

/*Created fork1() function for execute fork() system call.
Fork system call creates child process that executes simultaneously with parent. Parent process returns child's process id and child process returns 0.
syntax: pid_t fork(void) */
int fork1()
{
	int x=fork();
	if(x>0)
	{
		printf("Control in parent process.\n");
		printf("Parent process id:\t%d\n",getpid());
		printf("Child process id:\t%d\n",x);
	}
	else
	{
		printf("Control in child process.\n");
		printf("Child process id:\t%d\n",getpid());
	}
}

/*Created read_write() function for executing read and write functions.We have taken one buffer and stores the data from file(sample.txt) in that buffer.
syntax: ssize_t read(int filedes, void *buf, size_t nbytes) */
int read_write()
{
	char buff[50];
	int fd=open("sample.txt",O_RDWR);
	read(fd,buff,5);
	write(1,buff,5);
}

/*Created lseek1() function for executing lseek function.
lseek function is used for changing the location of read_write pointer.
syntax: off_t lseek(int filedes, off_t offset, int whence) */
int lseek1()
{
	char buff[50];
	int fd=open("sample.txt",O_RDWR);
	lseek(fd,5,SEEK_CUR);
	read(fd,buff,5);
	write(1,buff,5);
}

/*Created create() function for executing creat function call. 
creat function creats a new file in your directory.
syntax: int creat(const char *pathname, mode_t mode) */
int create()
{
	int fd=open("x.txt",O_RDWR,0777);   //created file using open function
	int fd1=creat("x1.txt",S_IRWXU);   //created file using creat function
	printf("Files created successfully.\n");
	write(fd,"hello world",5);
	write(fd1,"hello universe",5);	void exit(int status);
}

/*Exit function terminates running process forcefully.
syntax: void exit(int status);*/
int exit1()
{
	exit(0);
}






	
