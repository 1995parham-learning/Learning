#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

uint32_t make_bytes_int(uint8_t* buff, int start)
{
	return buff[start] + (buff[start + 1] << 8) + (buff[start + 2] << 16) + (buff[start + 3] << 24);
}

int main(int argc, char *argv[])
{
	/* Open device file */
	int fd = open("/dev/sdb1", O_RDONLY);

	uint8_t buff[1024];	
	lseek(fd, 1024, SEEK_SET);
	read(fd, buff, 1024);
	
	printf("Ext2 signature : %x %x\n", buff[56], buff[57]);

	printf("File system state : %1x %1x\n", buff[58], buff[59]);

	int os_id = make_bytes_int(buff, 72);
	printf("OS ID : %d\n", os_id);

	time_t last_written_time = make_bytes_int(buff, 48);
	char timestr[100];
	strftime (timestr, 100, "%Y-%m-%d %H:%M:%S.000", localtime(&last_written_time));
	printf("Last written time : %s\n", timestr);
	
	time_t last_mount_time = make_bytes_int(buff, 44);
	strftime (timestr, 100, "%Y-%m-%d %H:%M:%S.000", localtime(&last_written_time));
	printf("Last mount time : %s\n", timestr);
}
