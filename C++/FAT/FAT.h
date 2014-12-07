// In The Name Of God
// ========================================
// * File Name : FAT.h
// 
// * Creation Date : 08-12-2014
//
// * Last Modified : Mon 08 Dec 2014 02:28:27 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#ifndef FAT_H
#define FAT_H

#include <stdint.h>

typedef struct{
	uint8_t 	bootjmp[3];
	uint8_t 	oem_name[8];
	uint16_t	bytes_per_sector;
	uint8_t		sectors_per_cluster;
	uint16_t	reserved_sector_count;
	uint8_t		table_count;
	uint16_t	root_entry_count;
	uint16_t	total_sectors_16;
	uint8_t		media_type;
	uint16_t	table_size_16;
	uint16_t	sectors_per_track;
	uint16_t	head_side_count;
															 
	uint8_t		boot_routine[481];
}__attribute__((packed)) fat_BS_t;

typedef uint16_t fat_addr_t;

// The first in the File Allocation Table
fat_addr_t first_fat_sector(const fat_BS_t* fat_boot);
// The size of the root directory
fat_addr_t root_dir_sectors(const fat_BS_t* fat_boot);
// The first data sector (that is, the first sector in which directories and files may be stored)
fat_addr_t first_data_sector(const fat_BS_t* fat_boot);
// The total number of data sectors
fat_addr_t data_sectors(const fat_BS_t* fat_boot);
// The total number of clusters
fat_addr_t total_clusters(const fat_BS_t* fat_boot);

#endif
