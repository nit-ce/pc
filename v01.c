#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	500000

static int A[N];
static int n;
static int k;

/* test case input */
static int input(FILE *fp)
{
	int i;
	if (fscanf(fp, "%d %d", &n, &k) != 2)
		return -1;
	for (i = 0; i < n; i++)
		if (fscanf(fp, "%d", &A[i]) != 1)
			return -1;
	return 0;
}

static int diff(int pos)
{
	int min = +0x7fffffff;
	int max = -0x7fffffff;
	int i;
	for (i = 0; i < k; i++)
		if (A[pos + i] < min)
			min = A[pos + i];
	for (i = 0; i < k; i++)
		if (A[pos + i] > max)
			max = A[pos + i];
	return max - min;
}

/* evaluate submission output */
static int submission(FILE *fp)
{
	int l;
	int diff0, diffl;
	if (fscanf(fp, "%d", &l) != 1)
		return -1;
	if (l < 0 || l > n - k)
		return -1;
	diff0 = diff(0);
	diffl = diff(l);
	return diffl < diff0 ? diff0 - diffl : 0;
}

int main(int argc, char *argv[])
{
	FILE *ifp = fopen(argc > 2 ? argv[1] : ".i", "r");
	FILE *sfp = fopen(argc > 2 ? argv[2] : ".o", "r");
	int score;
	if (!ifp || !sfp)
		return 1;
	if (input(ifp))
		return 1;
	score = submission(sfp);
	fclose(ifp);
	fclose(sfp);
	if (score < 0)
		return 1;
	printf("%d\n", score);
	return 0;
}
