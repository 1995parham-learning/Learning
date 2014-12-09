// In The Name Of God
// ========================================
// * File Name : FAT.h
// 
// * Creation Date : 08-12-2014
//
// * Last Modified : Wed 10 Dec 2014 12:51:42 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#ifndef FAT_H
#define FAT_H

#include <stdint.h>

typedef struct{
	uint8_t 	bios_drive_num;
	uint8_t 	reserved1;
	uint8_t 	boot_signature;
	uint32_t	volume_id;
	uint8_t		volume_label[11];
	uint8_t		fat_type_label[8];
	uint8_t		boot_code[448];
	uint16_t	bootable_partition;
}__attribute__((packed)) fat_extBS_16_t;

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
	uint32_t	hidden_sector_count;
	uint32_t	total_sectors_32;
	fat_extBS_16_t	extBS;															 
}__attribute__((packed)) fat_BS_t;

typedef uint16_t fat_addr_t;

typedef struct{
	uint8_t		name[8];
	uint8_t		extention[3];
	uint8_t		attr;
	uint8_t		reserved;
	uint8_t		create_second;
	uint16_t	create_time;
	uint16_t	create_date;
	uint16_t	access_date;
	uint16_t	zero;		// Why ???
	uint16_t	modification_time;
	uint16_t	modification_date;
	uint16_t	first_cluster;
	uint32_t	file_size;
}__attribute__((packed)) fat_dir_layout_t;

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
