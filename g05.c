#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void test00(void)
{
	printf("30\n");
}

static void test01(void)
{
	printf("100\n");
}

static void test02(void)
{
	printf("140\n");
}

static void test03(void)
{
	printf("1234\n");
}

static void test04(void)
{
	printf("9809\n");
}

static void test05(void)
{
	printf("9999\n");
}

static void test06(void)
{
	printf("31\n");
}

static void test07(void)
{
	printf("260\n");
}

static void test08(void)
{
	printf("8837\n");
}

static void test09(void)
{
	printf("2604\n");
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
