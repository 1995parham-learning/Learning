// In The Name Of God
// ========================================
// * File Name : FAT.c
// 
// * Creation Date : 08-12-2014
//
// * Last Modified : Tue 09 Dec 2014 08:23:44 PM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include "FAT.h"

fat_addr_t root_dir_sectors(const fat_BS_t* fat_boot){ 
	return ((fat_boot->root_entry_count * 16) + (fat_boot->bytes_per_sector - 1)) / fat_boot->bytes_per_sector;
}
fat_addr_t first_fat_sector(const fat_BS_t* fat_boot){
	return  fat_boot->reserved_sector_count;
}
fat_addr_t first_data_sector(const fat_BS_t* fat_boot){
	return fat_boot->reserved_sector_count + (fat_boot->table_count * fat_boot->table_size_16);
}
fat_addr_t data_sectors(const fat_BS_t* fat_boot){
	return fat_boot->total_sectors_16 - (fat_boot->reserved_sector_count + (fat_boot->table_count * fat_boot->table_size_16) + root_dir_sectors(fat_boot));
}
fat_addr_t total_clusters(const fat_BS_t* fat_boot){
	return data_sectors(fat_boot) / fat_boot->sectors_per_cluster;
}
