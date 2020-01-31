/*
 * In The Name Of God
 * ========================================
 * [] File Name : MemoryMaping.c
 *
 * [] Creation Date : 07-03-2015
 *
 * [] Last Modified : Sat 07 Mar 2015 05:36:52 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct stat sb;
  off_t len;
  char *p;
  int fd;

  if (argc < 2) {
    fprintf(stderr, "usage: %s <file>\n", argv[0]);
    return 1;
  }
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  if (fstat(fd, &sb) == -1) {
    perror("fstat");
    return 1;
  }
  if (!S_ISREG(sb.st_mode)) {
    fprintf(stderr, "%s is not a file\n", argv[1]);
    return 1;
  }
  p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
  if (p == MAP_FAILED) {
    perror("mmap");
    return 1;
  }
  if (close(fd) == -1) {
    perror("close");
    return 1;
  }
  for (len = 0; len < sb.st_size; len++)
    putchar(p[len]);
  putchar('\n');
  if (munmap(p, sb.st_size) == -1) {
    perror("munmap");
    return 1;
  }
  return 0;
}
