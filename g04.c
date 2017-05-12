#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN		10000		/* intersections */
#define MAXN0		1000
#define MAXM		200000		/* streets */
#define MAXK		10000		/* machines */

static void test00(void)
{
	printf("5 5 2\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 3\n");
	printf("3 4\n");
	printf("4 0\n");
}

static void test01(void)
{
	printf("5 10 5\n");
	printf("0 1\n");
	printf("0 2\n");
	printf("0 3\n");
	printf("0 4\n");
	printf("1 2\n");
	printf("1 3\n");
	printf("1 4\n");
	printf("2 3\n");
	printf("2 4\n");
	printf("3 4\n");
}

static void test02(void)
{
	printf("5 10 3\n");
	printf("0 1\n");
	printf("0 2\n");
	printf("0 3\n");
	printf("0 4\n");
	printf("1 2\n");
	printf("1 3\n");
	printf("1 4\n");
	printf("2 3\n");
	printf("2 4\n");
	printf("3 4\n");
}

static void test03(void)
{
	int n = (MAXN0 & 1) ? MAXN0 : MAXN0 - 1;
	int m = n * (n - 1) / 2;
	int i, j;
	printf("%d %d %d\n", n, m, 2);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			printf("%d %d\n", i, j);
}

static void test04(void)
{
	int n = (MAXN0 & 1) ? MAXN0 : MAXN0 - 1;
	int m = n * (n - 1) / 2;
	int i, j;
	printf("%d %d %d\n", n, m, 7);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			printf("%d %d\n", i, j);
}

static void test05(void)
{
	int n = (MAXN0 & 1) ? MAXN0 : MAXN0 - 1;
	int m = n * (n - 1) / 2;
	int i, j;
	printf("%d %d %d\n", n, m, MAXK);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			printf("%d %d\n", i, j);
}

static void test06(void)
{
	int n0 = MAXN0 | 1;
	int m0 = n0 * (n0 - 1) / 2;
	int n = n0 * 2;
	int m = m0 * 2 + n0;
	int i, j;
	printf("%d %d %d\n", n, m, 17);
	for (i = 0; i < n0; i++)
		for (j = i + 1; j < n0; j++)
			printf("%d %d\n", i, j);
	for (i = 0; i < n0; i++)
		printf("%d %d\n", i, n0 + i);
	for (i = 0; i < n0; i++)
		for (j = i + 1; j < n0; j++)
			printf("%d %d\n", n0 + i, n0 + j);
}

static void test07(void)
{
	int n = MAXN;
	int m = n;
	int i;
	printf("%d %d %d\n", n, m, MAXK / 10);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, i + 1 < n ? i + 1 : 0);
}

static void test08(void)
{
	int n = MAXN;
	int m = n * 4;
	int i;
	printf("%d %d %d\n", n, m, 20);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 1) % n);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 3) % n);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 5) % n);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 7) % n);
}

static void test09(void)
{
	int n = MAXN;
	int m = n * 3;
	int i;
	printf("%d %d %d\n", n, m, 93);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 20) % n);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 47) % n);
	for (i = 0; i < n; i++)
		printf("%d %d\n", i, (i + 50) % n);
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
