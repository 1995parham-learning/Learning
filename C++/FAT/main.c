// In The Name Of God
// ========================================
// * File Name : main.c
// 
// * Creation Date : 08-12-2014
//
// * Last Modified : Tue 09 Dec 2014 09:08:38 PM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "FAT.h"

int main(int argc, char* argv[]){
	int fd = open("/dev/loop0", O_RDONLY); 
	
	fat_BS_t fat;
	read(fd, &fat, 512);
	printf("Boot Jump: %2X %2X %2X\n", fat.bootjmp[0], fat.bootjmp[1], fat.bootjmp[2]);
	printf("OEM Media: %8s\n", fat.oem_name);
	printf("Media Type: %2X\n", fat.media_type);
	printf("Sectors Per Track: %hu\n", fat.sectors_per_track);
	printf("Sectors Per Cluster: %hu\n", fat.sectors_per_cluster);
	printf("Reserved Sectors: %hu\n", fat.reserved_sector_count);
	printf("FAT Tables: %hhu\n", fat.table_count); 
	printf("Table Size: %hu\n", fat.table_size_16);
	printf("Volume Label: %11s\n", fat.extBS.volume_label);

	fat_addr_t root_cluster = first_data_sector(&fat);

	printf("Root Cluster: %hu\n", root_cluster);
	
	fat_addr_t fat_sector = first_fat_sector(&fat);
	lseek(fd, fat_sector * 512, SEEK_SET);
	fat_addr_t fat_table[256];
	read(fd, &fat_table, 512);
	int i;
	for(i = 0; i < 256; i++){
		printf("%d : %04X\n", i, fat_table[i]);
	}

	close(fd);

	return 0;
}
