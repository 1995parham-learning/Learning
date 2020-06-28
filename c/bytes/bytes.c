/*
 * In The Name Of God
 * ========================================
 * [] File Name : bytes.c
 *
 * [] Creation Date : 22-02-2015
 *
 * [] Last Modified : Sun 22 Feb 2015 07:50:32 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

int main() {
  /* Open file */
  FILE *fp;

  fp = fopen("testfile.txt", "w+");
  if (fp == NULL) {
    perror("fopen()");
  }

  /* Write 8 byte number to file */
  long long n = 5000;
  fwrite(&n, sizeof(long long), 1, fp);

  /* Seek to EOF and check that the file is 8 bytes */
  fseek(fp, 0, SEEK_END);
  long loc1 = ftell(fp);
  printf("Endbyte: %ld\n", loc1);

  /* Seek back to start of file and print out location */
  fseek(fp, -sizeof(long long), SEEK_END);
  long loc2 = ftell(fp);
  printf("Location: %ld\n", loc2);

  /* Read and print out number */
  long long num;
  fread(&num, sizeof(long long), 1, fp);
  printf("Number: %lld\n", num);

  /* Cleanup */
  fclose(fp);
  return (0);
}
