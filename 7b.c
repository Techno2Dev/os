#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define MAX_BUF 1024

int main()
{
    int fd,c=0;
    char *fifo1="fifo1";
    char *fifo2="fifo2";
    int fd1;
    int words=1,lines=1,chars=0;
    char buf1[MAX_BUF];
    mkfifo(fifo1,0666);
    fd=open(fifo1,O_RDWR);
    char str;
    printf("\nEnter the String:");
    while ((str=getchar())!='#')
    buf1[c++]=str;
    buf1[c]='\0';
    write(fd,buf1,sizeof(buf1));
    close(fd);
    unlink(fifo1);
    fd1=open(fifo2,O_RDWR);
    read(fd1,buf1,sizeof(buf1));
    printf("\nThe contents of file are %s\n",buf1);
    int i=0;
      while(buf1[i]!='\0')
          {
            if(buf1[i]==' '||buf1[i]=='\n')
             {words++;}
            else
             {chars++;}
             if(buf1[i]=='\n')
             { lines++;}
              i++;
           }
     printf("\n No of Words: %d",words);
     printf("\n No of Characters: %d",chars);
     printf("\n No of Lines: %d",lines);
    close(fd1);
fp=fopen("out","w");
	fprintf(fp,"\nno. of words %d",w);
	fprintf(fp,"\nno. of character %d",c);
	fprintf(fp,"\nno. of lines %d",l);			
	fclose(fp);
	fp=fopen("out","r");
	i=0;
	while(!EOF)	
	{
		
		ch=fgetc(fp);
		if(ch!=EOF)
		{
			buffer[i]=ch;
		}
		i++;
	}
	write(fd2,buffer,strlen(buffer)+1);
	printf("\nthe content of o/p file send to first process");
	return 0;
    return 0;
}
/*
//OUTPUT

rohit:~/Desktop/sl2/7$ gcc os5b.c

rohit:~/Desktop/sl2/7$ ./a.out

Enter the String:hello my name is abcde(Professional Cipher) the string ends with (hash sign) #         

The contents of file are hello my name is abcde(Professional Cipher) the string ends with (hash sign) 

 No of Words: 13
 No of Characters: 66
 No of Lines: 1
*/
