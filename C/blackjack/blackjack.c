/*
 * In The Name Of God
 * ========================================
 * [] File Name : blackjack.c
 *
 * [] Creation Date : 07-02-2015
 *
 * [] Last Modified : Sat 07 Feb 2015 11:59:41 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int deal(void)
{
	int deck[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
	return deck[rand() % 13];
}

void clearBuffer(void)
{
	char ch;

	while ((ch = getchar()) != '\n' && ch != EOF);
}

int dealerhand(void)
{
	int dealerhand[10];
	int dealertotal = 0;

	while (dealertotal < 17) {
		dealertotal = deal();
		printf("%d\n dx", deal());
		dealertotal = dealertotal + deal();
		printf("%d\n D", dealertotal);
	}
	/* RETURN INT ... */
}

int playerhand(void)
{
	int playerhand[10];
	int i;

	for (i = 0; i < 10; i++) {
		playerhand[i] = deal();
		printf(" %d\n", playerhand[i]);
	}
	/* RETURN INT ... */
}

int hit(void)
{
	int i;
	int playerhand[10];

	/* I think you need for here ... */
	for (i = 0; i < 10; i++) {
		playerhand[i] = deal();
		printf(" %d", playerhand[i]);
	}

	/* RETURN INT ... */
}

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	int hold = 1;
	int num;
	int num2;
	int money = 500;

	printf("Welcome to Blackjack! You have $500. Play a hand? 1=y 2=n. ");

	while (hold == 1) {
		scanf("%d", &num);
			if (num == 1) {
				printf("Great! Ante is $20, here's your hand!");
				playerhand();
				playerhand();
				dealerhand();
				money = money - 20;

				printf("You have %d dollars. Hit? 1=y 2=n", money);
				scanf("%d", &num2);
				if (num2 == 1) {
					playerhand();
					break;
				}
				if (num2 == 2);
					/* compare(); */
			}
			if (num == 2) {
				printf("Too bad, come back soon!");
				break;
			}
			if (num != 1 || num != 2) {
				printf("Sorry what was that? Play a hand? 1=y 2=n.");
				while (((num = getchar()) != EOF) && num != '\n');
			}
	}
}
