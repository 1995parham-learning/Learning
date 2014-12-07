// In The Name Of God
// ========================================
// * File Name : main.c
// 
// * Creation Date : 08-12-2014
//
// * Last Modified : Mon 08 Dec 2014 01:52:47 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "FAT.h"

int main(int argc, char* argv[]){
	int fd = open("/dev/loop1", O_RDONLY); 
	
	fat_BS_t fat;
	read(fd, &fat, 512);
	printf("Boot Jump: %2X %2X %2X\n", fat.bootjmp[0], fat.bootjmp[1], fat.bootjmp[2]);
	printf("Media Type: %2X\n", fat.media_type);
	printf("Sectors Per Track: %hu\n", fat.sectors_per_track);
	printf("Reserved Sectors: %hu\n", fat.reserved_sector_count);
	printf("FAT Tables: %hhu\n", fat.table_count); 

	close(fd);

	return 0;
}
