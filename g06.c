#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static void test00(void)
{
	printf("5 4\n");
	printf("1 2\n");
	printf("4 1\n");
	printf("3 0\n");
	printf("0 0\n");
	printf("0 1\n");
	printf("2 2\n");
	printf("1 1\n");
	printf("4 0\n");
	printf("3 1\n");
}

static void test01(void)
{
	printf("8 10\n");
	printf("-4 0\n");
	printf("-2 3\n");
	printf("0 4\n");
	printf("2 3\n");
	printf("4 0\n");
	printf("2 -3\n");
	printf("0 -4\n");
	printf("-2 -3\n");
	/* test data */
	printf("0 0\n");
	printf("5 0\n");
	printf("-5 0\n");
	printf("1 1\n");
	printf("2 2\n");
	printf("3 3\n");
	printf("2 2\n");
	printf("4 4\n");
	printf("4 3\n");
	printf("3 3\n");
}

static void curve(int cx, int cy, int r, int n, int nx, int ny)
{
	int i;
	for (i = 0; i < n; i++) {
		int x = sin(M_PI * 2.0 * i / n) * r;
		int y = cos(M_PI * 2.0 * i / n) * r;
		printf("%d %d\n", nx * (cx + x), ny * (cy + y));
	}
}

static void testtemp(int n, int x, int y)
{
	int q = 20;
	printf("%d %d\n", n, q);
	curve(x, y, 10000, n, 1, 1);
	printf("10000 10000\n");
	printf("0 10000\n");
	printf("10000 0\n");
	printf("10000 1\n");
	printf("1 1\n");
	printf("1 10000\n");
	printf("1 20000\n");
	printf("5000 5000\n");
	printf("50000 5000\n");
	printf("5000 50000\n");
	printf("20000 20000\n");
	printf("20000 -20000\n");
	printf("-20000 -20000\n");
	printf("-20000 20000\n");
	printf("-5 -5\n");
	printf("-5 -5\n");
	printf("-123 456\n");
	printf("456 -789\n");
	printf("100 100\n");
	printf("100 10000\n");
}

static void test02(void)
{
	testtemp(1000, 0, 0);
}

static void test03(void)
{
	testtemp(1000, 100, 100);
}

static void test04(void)
{
	testtemp(5000, -1000, -100);
}

static void test05(void)
{
	int n = 1000;
	int q = 20;
	int i;
	printf("%d %d\n", n, q);
	curve(654, -321, 9900, n, 1, -1);
	srand(5);
	for (i = 0; i < q; i++)
		printf("%d %d\n", rand() % 20000 - 10000,
			rand() % 20000 - 10000);
}

static void test06(void)
{
	int n = 5000;
	int q = 500;
	int i;
	printf("%d %d\n", n, q);
	curve(1111, 2222, 15500, n, -1, 1);
	srand(6);
	for (i = 0; i < q; i++)
		printf("%d %d\n", rand() % 20000 - 10000,
			rand() % 20000 - 10000);
}

static void test07(void)
{
	int n = 10000;
	int q = 10000;
	int i;
	printf("%d %d\n", n, q);
	curve(-232, -181, 16666, n, 1, 1);
	srand(6);
	for (i = 0; i < q; i++)
		printf("%d %d\n", rand() % 20000 - 10000,
			rand() % 20000 - 10000);
}

static void test08(void)
{
	int n = 20000;
	int q = 100000;
	int i;
	printf("%d %d\n", n, q);
	curve(-239, 189, 16666, n, -1, -1);
	srand(7);
	for (i = 0; i < q; i++)
		printf("%d %d\n", rand() % 50000 - 20000,
			rand() % 50000 - 30000);
}

/* a pie-like polygon */
static void test09(void)
{
	int n = 20000;
	int q = 100000;
	int r = 50000;
	int i;
	printf("%d %d\n", n, q);
	printf("0 0\n");
	for (i = 0; i < n - 1; i++) {
		int x = sin(M_PI / 2 * i / n) * r;
		int y = cos(M_PI / 2 * i / n) * r;
		printf("%d %d\n", x, y);
	}
	srand(8);
	for (i = 0; i < q; i++)
		printf("%d %d\n", rand() % 50000 - 20000,
			rand() % 50000 - 30000);
}

static void test10(void)
{
	printf("3 10\n");
	printf("-10 2\n");
	printf("-10 40\n");
	printf("-100 40\n");
	printf("0 0\n");
	printf("-10 10\n");
	printf("-10 0\n");
	printf("-10 50\n");
	printf("-10 20\n");
	printf("-5 -5\n");
	printf("-20 2\n");
	printf("-20 8\n");
	printf("-100 41\n");
	printf("-100 100\n");
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
	else if (atoi(argv[1]) == 10)
		test10();
	else
		return 1;
	return 0;
}
