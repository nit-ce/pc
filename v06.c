#include <stdio.h>
#include <stdlib.h>

#define N		100000		/* maximum vertices */
#define Q		200000		/* maximum queries */

static int n, q;		/* the number vertices and points */
static int px[N], py[N];	/* coordinates of the input points */
static int qx[Q], qy[Q];	/* coordinates of the query points */
static int n_u, n_l;
static int ux[N], uy[N];	/* upper envelope */
static int lx[N], ly[N];	/* lower envelope */
static int qmin, qmax;

static void order(int *x, int *y, int n)
{
	int beg = 0;
	int end = n - 1;
	while (beg < end && x[beg] > x[end]) {
		int t = x[beg];
		x[beg] = x[end];
		x[end] = t;
		t = y[beg];
		y[beg] = y[end];
		y[end] = t;
		beg++;
		end--;
	}
}

static int eval_input(FILE *fp)
{
	int i;
	if (fscanf(fp, "%d %d", &n, &q) != 2)
		return 1;
	for (i = 0; i < n; i++)
		if (fscanf(fp, "%d %d", &px[i], &py[i]) != 2)
			return 1;
	for (i = 0; i < q; i++)
		if (fscanf(fp, "%d %d", &qx[i], &qy[i]) != 2)
			return 1;
	for (i = 0; i < n; i++)
		if (px[i] < px[qmin])
			qmin = i;
	for (i = 0; i < n; i++)
		if (px[i] > px[qmax])
			qmax = i;
	for (i = qmin; ; i = (i + 1) % n) {
		ux[n_u] = px[i];
		uy[n_u] = py[i];
		n_u++;
		if (i == qmax)
			break;
	}
	for (i = qmax; ; i = (i + 1) % n) {
		lx[n_l] = px[i];
		ly[n_l] = py[i];
		n_l++;
		if (i == qmin)
			break;
	}
	order(ux, uy, n_u);
	order(lx, ly, n_l);
	return 0;
}

static int binsearch(int *A, int n, int x)
{
	int l = 0;
	int h = n;
	while (l + 1 < h) {
		int m = (l + h) >> 1;
		if (A[m] > x)
			h = m;
		else
			l = m;
	}
	return l;
}

static int cross(int x0, int y0, int x1, int y1, int x2, int y2)
{
	return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

static int level(int x, int y, int *ex, int *ey, int en)
{
	int m;
	int cp;
	if (ex[0] == x || ex[en - 1] == x)
		return 0;
	m = binsearch(ex, en, x);
	cp = cross(ex[m], ey[m], ex[m + 1], ey[m + 1], x, y);
	if (cp < 0)
		return -1;
	if (cp > 0)
		return +1;
	return 0;
}

static int eval_inside(int x, int y)
{
	int l1 = level(x, y, ux, uy, n_u);
	int l2 = level(x, y, lx, ly, n_l);
	return l1 * l2 == -1;
}

static int eval_solution(FILE *fp)
{
	int score = 0;
	int i;
	for (i = 0; i < q; i++) {
		int a;
		if (fscanf(fp, "%d", &a) != 1)
			return -1;
		if (a == eval_inside(qx[i], qy[i]))
			score++;
	}
	return score;
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
