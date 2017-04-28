#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN		200000

static char S[SLEN + 1];

static void test00(void)
{
	printf("abCDABCdaBcda\n");
}

static void test01(void)
{
	printf("abcdefAbCdEf\n");
}

static void test02(void)
{
	printf("aaaaaAaaaaaAaaaaaAabaaaAaaaaaAaaaaaA\n");
}

static void test03(void)
{
	int n = SLEN;
	int i;
	for (i = 0; i < n; i++)
		S[i] = 'A';
	S[n] = '\0';
	printf("%s\n", S);
}

static void test04(void)
{
	int n = SLEN;
	int i;
	for (i = 0; i * 2 < n; i++)
		S[i] = 'B';
	for (; i < n; i++)
		S[i] = 'b';
	S[n] = '\0';
	printf("%s\n", S);
}

static void test05(void)
{
	int n = SLEN;
	int i;
	for (i = 0; i < n; i++)
		S[i] = (i & 1) ? 'B' : 'b';
	S[n] = '\0';
	printf("%s\n", S);
}

static void test06(void)
{
	int n = SLEN;
	int i;
	for (i = 0; i < n; i++)
		S[i] = (i & 1) ? 'a' + i % 26 : 'A' + i % 26;
	S[n] = '\0';
	printf("%s\n", S);
}

static void test07(void)
{
	int n = SLEN;
	int i;
	for (i = 0; i < n; i++)
		S[i] = (i & 1) ? 'a' + (i * 19 % 26) : 'A' + (i * 19 % 26);
	S[n] = '\0';
	printf("%s\n", S);
}

static void test08(void)
{
	int n = SLEN;
	int i;
	srand(8);
	for (i = 0; i < n; i++)
		S[i] = (rand() & 1) ? 'a' + rand() % 26 : 'A' + rand() % 26;
	S[n] = '\0';
	printf("%s\n", S);
}

static void test09(void)
{
	int n = SLEN;
	int i;
	srand(9);
	for (i = 0; i < n; i++)
		S[i] = (rand() & 1) ? 'z' : 'Z';
	S[n] = '\0';
	printf("%s\n", S);
}

static void test10(void)
{
	int n = SLEN;
	int i;
	char r[] = "hxuwyvHXUWYV";
	char c = strlen(r);
	srand(10);
	for (i = 0; i < n; i++)
		S[i] = r[rand() % c];
	S[n] = '\0';
	printf("%s\n", S);
}

static void test11(void)
{
	int n = SLEN;
	int i;
	char r[] = "hxuwyv";
	char c = strlen(r);
	srand(10);
	for (i = 0; i * 2 < n; i++)
		S[i] = r[rand() % c];
	for (; i < n; i++)
		S[i] = toupper(r[rand() % c]);
	S[n] = '\0';
	printf("%s\n", S);
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
	else if (atoi(argv[1]) == 11)
		test11();
	else
		return 1;
	return 0;
}
