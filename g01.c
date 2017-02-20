#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N	250000

static void test00(void)
{
	printf("10 3\n");
	printf("5 0 6 2 4 4 5 9 1 7\n");
}

static void test01(void)
{
	int n = N;
	int k = 1;
	int i;
	printf("%d %d\n", n, k);
	for (i = 0; i < n; i++)
		printf("%d\n", i * 7 % 19);
}

static void test02(void)
{
	int n = N;
	int k = N;
	int i;
	printf("%d %d\n", n, k);
	for (i = 0; i < n; i++)
		printf("%d\n", i * 7 % 19);
}

static void test03(void)
{
	int n = N;
	int k = 100000;
	int i;
	printf("%d %d\n", n, k);
	for (i = 0; i < n / 2; i++)
		printf("%d\n", i);
	for (; i < n; i++)
		printf("%d\n", n - i);
}

static void test04(void)
{
	int n = N;
	int k = 100000;
	int i;
	printf("%d %d\n", n, k);
	for (i = 0; i < n; i++)
		printf("%d\n", 1000000 - i);
}

static void test05(void)
{
	int n = N;
	int k = 100000;
	int i;
	printf("%d %d\n", n, k);
	for (i = 0; i < n; i++)
		printf("%d\n", 7);
}

static void test06(void)
{
	int n = N;
	int k = 50000;
	int i;
	printf("%d %d\n", n, k);
	for (i = n; i > 0; i--)
		printf("%d\n", 1000 + (i & 1 ? -i : +i));
}

static void test07(void)
{
	int n = N;
	int k = N / 2;
	int i;
	printf("%d %d\n", n, k);
	srand(1);
	for (i = 0; i < n; i++)
		printf("%d\n", rand() % 1000000);
}

static void test08(void)
{
	int n = N;
	int k = 1000;
	int i;
	printf("%d %d\n", n, k);
	srand(1);
	for (i = 0; i < n; i++)
		printf("%d\n", rand() % 100);
}

static void test09(void)
{
	int n = N;
	int k = 10000;
	int i;
	printf("%d %d\n", n, k);
	srand(1);
	for (i = 0; i < n; i++)
		printf("%d\n", i & 1 ? 11 : (rand() % 50000) + 9);
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
