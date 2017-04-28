#include <stdio.h>
#include <stdlib.h>

#define SLEN		(500000)
#define ULDIFF		('a' - 'A')

static char S[SLEN];

int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int n;
	int i;
	int x, y;
	if (argc < 3)
		return 1;
	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "r");
	if (!ifp || !ofp)
		return 1;
	n = fread(S, 1, sizeof(S) - 1, ifp);
	S[n] = '\0';
	fclose(ifp);
	if (fscanf(ofp, "%d %d", &x, &y) != 2)
		return 1;
	fclose(ofp);
	for (i = 0; x + i < n && y + i < n; i++)
		if (S[x + i] + ULDIFF != S[y + i] && S[x + i] != S[y + i] + ULDIFF)
			break;
	printf("%d\n", i);
	return 0;
}
