#include <stdlib.h>
#include "fenwick.h"

struct fenwick {
	long *A;
	int n;
};

/* allocate a Fenwick tree with n elements */
struct fenwick *fenwick_make(int n)
{
	struct fenwick *fw = malloc(sizeof(*fw));
	fw->n = (n + 1) * 2;
	fw->A = calloc(fw->n, sizeof(fw->A[0]));
	return fw;
}

/* free the given fenwick struct */
void fenwick_free(struct fenwick *fw)
{
	free(fw->A);
	free(fw);
}

/* update the value of the i-th number */
void fenwick_update(struct fenwick *fw, int i, int x)
{
	for (i++; i <= fw->n; i += i & -i)
		fw->A[i] += x;
}

/* compute the sum of 0-th till i-th number */
static long fenwick_sum0(struct fenwick *fw, int i)
{
	long sum = 0;
	for (i++; i > 0; i -= i & -i)
		sum += fw->A[i];
	return sum;
}

/* compute the sum of i-th till j-th number */
long fenwick_sum(struct fenwick *fw, int i, int j)
{
	return fenwick_sum0(fw, j) - fenwick_sum0(fw, i - 1);
}
