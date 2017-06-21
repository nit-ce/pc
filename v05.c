#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b)	((a) < (b) ? (a) : (b))
#define NT		10001		/* maximum time */		
#define MT		16

static int t;			/* show length */
static int res[NT][301];	/* game status */

static int eval_input(FILE *fp)
{
	if (fscanf(fp, "%d", &t) != 1)
		return 1;
	return 0;
}

static int eval_solution(FILE *fp)
{
	int winner;
	int i, j;
	if (fscanf(fp, "%d", &winner) != 1)
		return -1;
	for (i = 1; i <= 300; i++)
		res[0][i] = 0;
	for (i = 1; i <= t; i++) {
		int losing = 0;
		for (j = 1; j <= 10 && i >= j; j++)
			losing += !res[i - j][j];
		for (j = 1; j <= 300; j++) {
			if (j <= 300 - MT && i >= j)
				res[i][j] = (losing + !res[i - j][j + MT]) > 0;
			else
				res[i][j] = losing > 0;
		}
	}
	if (res[t - 30][40] && winner == 2)
		return 1;
	if (!res[t - 30][40] && winner == 1)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int score;
	if (argc < 3)
		return 1;
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "r");
	if (!ifp || !ofp)
		return 1;
	if (eval_input(ifp))
		return 1;
	fclose(ifp);
	score = eval_solution(ofp);
	fclose(ofp);
	if (score < 0)
		return 1;
	printf("%d\n", score);
	return 0;
}
