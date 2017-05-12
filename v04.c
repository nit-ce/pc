#include <stdio.h>
#include <stdlib.h>

#define MAXN		10000		/* intersections */
#define MAXM		200000		/* streets */
#define MAXK		10000		/* machines */

static char A[MAXN][MAXN];
static int n;
static int m;
static int k;

static int eval_input(FILE *fp)
{
	int a, b;
	int i;
	if (fscanf(fp, "%d %d %d", &n, &m, &k) != 3)
		return 1;
	for (i = 0; i < m; i++) {
		if (fscanf(fp, "%d %d", &a, &b) != 2)
			return 1;
		A[a][b] = 1;
		A[b][a] = 1;
	}
	return 0;
}

static int eval_solution(FILE *fp)
{
	int cnt;
	int i, j;
	int score;
	if (fscanf(fp, "%d", &cnt) != 1)
		return -1;
	for (i = 0; i < k; i++) {
		int u, v;
		if (fscanf(fp, "%d", &u) != 1 || u < 0 || u >= n)
			return -1;
		for (j = 0; j < cnt; j++) {
			if (fscanf(fp, "%d", &v) != 1 || v < 0 || v >= n)
				return -1;
			if (!A[u][v])
				return -1;
			A[u][v] = 2;
			A[v][u] = 2;
			u = v;
		}
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (A[i][j] == 1)
				return -1;
	score = (m + k - 1) * 2 / k - cnt;
	return score > 0 ? score : 0;
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
