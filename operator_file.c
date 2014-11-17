#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <fcntl.h>

int main(int argc,char *argv[])
{	
	fprintf(stderr,"error\n");
	int fd = open("/home/hjt/server.java",O_RDONLY);
	struct stat st;
	stat("/home/hjt/server.java",&st);
	printf(" st size = %ld \n",st.st_size);
	char buffer[st.st_size];
	read(fd,buffer,sizeof(buffer));
	//printf(" file: %s \n",buffer);
	close(fd);
	int file = open("/home/hjt/qqq.txt",O_CREAT|O_RDWR,S_IRWXU);
	char s[] = "hjt";
	printf("file = %d \n",file);


	char buffer2[1080];
	int w_ret = write(file,buffer,sizeof(buffer));
	
	printf("w_ret = %d \n",w_ret);
	close(file);
	return 0;
}
