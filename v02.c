#include <stdio.h>
#include <stdlib.h>
#include "fenwick.h"

#include "fenwick.c"

static int *A;
static int A_n;
static int *A_sorted;
static int *A_pos;
static int *A_rank;

static int A_cmp(void *v1, void *v2)
{
	int a1 = A[*(int *) v1];
	int a2 = A[*(int *) v2];
	return a1 - a2;
}

int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	struct fenwick *fw;
	int rank = 0;
	int i;
	if (argc < 3)
		return 1;
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "r");
	if (!ifp || !ofp)
		return 1;
	if (fscanf(ifp, "%d", &A_n) != 1)
		return 1;
	A = malloc(A_n * sizeof(A[0]));
	A_sorted = malloc(A_n * sizeof(A_sorted[0]));
	A_pos = malloc(A_n * sizeof(A_pos[0]));
	A_rank = malloc(A_n * sizeof(A_rank[0]));
	for (i = 0; i < A_n; i++)
		if (fscanf(ifp, "%d", &A[i]) != 1)
			return 1;
	for (i = 0; i < A_n; i++)
		A[i] = -A[i];
	fclose(ifp);
	for (i = 0; i < A_n; i++)
		A_sorted[i] = i;
	qsort(A_sorted, A_n, sizeof(A_sorted[i]), (void *) A_cmp);
	for (i = 0; i < A_n; i++) {
		if (i > 0 && A[A_sorted[i]] != A[A_sorted[i - 1]])
			rank = i;
		A_rank[A_sorted[i]] = rank;
		A_pos[A_sorted[i]] = i;
	}
	fw = fenwick_make(A_n);
	for (i = 0; i < A_n; i++) {
		long cur;
		if (fscanf(ofp, "%ld", &cur) != 1)
			return 1;
		if (cur != fenwick_sum(fw, 0, A_rank[i] - 1))
			return 1;
		fenwick_update(fw, A_pos[i], 1);
	}
	fclose(ofp);
	fenwick_free(fw);
	free(A);
	free(A_pos);
	free(A_sorted);
	free(A_rank);
	printf("1\n");
	return 0;
}
