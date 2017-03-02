#include <stdio.h>
#include <stdlib.h>

#define N		300000
#define V		1000000

static void test00(void)
{
	printf("1\n");
	printf("5\n");
}

static void test01(void)
{
	printf("10\n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
}

static void test02(void)
{
	printf("10\n");
	printf("9 8 7 6 5 4 3 2 1 0\n");
}

static void test03(void)
{
	printf("10\n");
	printf("3 3 3 3 3 3 3 3 3 3\n");
}

static void test04(void)
{
	int n = N;
	int i;
	printf("%d\n", n);
	for (i = 0; i < n; i++)
		printf("%d\n", (i & 1) ? i : V - i);
}

static void test05(void)
{
	int n = N;
	int i;
	printf("%d\n", n);
	for (i = 0; i < n; i++)
		printf("%d\n", i % 23);
}

static void test06(void)
{
	int n = N;
	int i;
	printf("%d\n", n);
	for (i = 0; i < n; i++)
		printf("%d\n", i % 12345 - 10000);
}

static void test07(void)
{
	int n = N;
	int i;
	printf("%d\n", n);
	srand(7);
	for (i = 0; i < n; i++)
		printf("%d\n", 300000 + rand() % 5);
}

static void test08(void)
{
	int n = N;
	int i;
	printf("%d\n", n);
	srand(8);
	for (i = 0; i < n; i++)
		printf("%d\n", 300000 + rand() % 500);
}

static void test09(void)
{
	int n = N;
	int i;
	printf("%d\n", n);
	srand(9);
	for (i = 0; i < n; i++)
		printf("%d\n", -200000 + rand() % 500000);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	else if (atoi(argv[1]) == 0)
		test00();
	else if (atoi(argv[1]) == 1)
		test01();
	else if (atoi(argv[1]) == 2)
		test02();
	else if (atoi(argv[1]) == 3)
		test03();
	else if (atoi(argv[1]) == 4)
		test04();
	else if (atoi(argv[1]) == 5)
		test05();
	else if (atoi(argv[1]) == 6)
		test06();
	else if (atoi(argv[1]) == 7)
		test07();
	else if (atoi(argv[1]) == 8)
		test08();
	else if (atoi(argv[1]) == 9)
		test09();
	else
		return 1;
	return 0;
}
