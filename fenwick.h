struct fenwick *fenwick_make(int n);
void fenwick_free(struct fenwick *fw);
void fenwick_update(struct fenwick *fw, int i, int x);
long fenwick_sum(struct fenwick *fw, int i, int j);
