/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 24-06-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdio.h>
#include <stdint.h>

uint8_t HEM(uint8_t A, uint8_t B)
{
	uint8_t R0 = ((A & (0x1)) | (((B & (0x4)) >> 1))) *
	             ((((A & (0x4)) >> 2)) | ((B & (0x1)) << 1));
	uint8_t R1 = ((((A & (0x2)) >> 1)) | ((B & (0x8)) >> 2)) *
	             ((((A & (0x8)) >> 3)) | (B & (0x2)));
	return R0 | (R1 << 4);
}

uint8_t HEA(uint8_t A, uint8_t B)
{
	uint8_t S0 = ((B & (0x8)) >> 3) + (A & (0x1));
	uint8_t S1 = ((B & (0x4)) >> 2) + ((A & (0x2)) >> 1);
	uint8_t S2 = ((B & (0x2)) >> 1) + ((A & (0x4)) >> 2);
	uint8_t S3 = (B & (0x1)) + ((A & (0x8)) >> 3);
	return S0 | (S1 << 2) | (S2 << 4) | (S3 << 6);
}

void fsl(int slot1, int slot2, uint32_t *src, uint32_t *dest)
{
	uint8_t B1 = (uint8_t) ((*src) & 0xF);
	printf("%u\n", B1);
	uint8_t A1 = (uint8_t) ((*src) & 0xF0);
	printf("%u\n", A1);
	uint8_t B2 = (uint8_t) ((*src) & 0xF00);
	printf("%u\n", B2);
	uint8_t A2 = (uint8_t) ((*src) & 0xF000);
	printf("%u\n", A2);
	if ((*src) & 1 << 16) {
		(*dest) = HEM(A1, B1) | HEM(A2, B2) << 8;
	} else {
		(*dest) = HEA(A1, B1) | HEA(A2, B2) << 8;
	}
}

int main(void)
{
	uint32_t A = 0;

	printf("type your input here: ");
	scanf("%u", &A);

	fsl(0, 0, &A, &A);

	A = A ^ 1 << 16;
	fsl(0, 0, &A, &A);

	fsl(0, 0, &A, &A);

	A = A ^ 1 << 16;
	fsl(0, 0, &A, &A);

	printf("your output is : %d\n", A);

	return 0;
}
