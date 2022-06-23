#include <stdio.h>

#define SIZE 500
#define NUM 1000

void chmax(int* a, int b)
{
	if (*a < b) *a = b;
}

int main()
{
	int i, N, Q, a[500001];
	scanf("%d %d", &N, &Q);
	for (i = 0; i < N; i++) scanf("%d", &(a[i]));

	int j, jj, n = (N - 1) / SIZE, block_max[NUM] = {}, block_div[NUM], block_all[NUM], block_sum[NUM] = {};
	for (i = 0; i <= n; i++) {
		block_div[i] = 1;
		block_all[i] = -1;
		for (j = i * SIZE; j < (i + 1) * SIZE; j++) {
			if (j >= N) a[j] = 0;
			chmax(&(block_max[i]), a[j]);
			block_sum[i] += a[j];
		}
	}

	int t, x, y, L, R;
	long long ans;
	while (Q--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &L, &R, &x);
			L--;
			R--;

			i = L / SIZE;
			if (block_all[i] >= 0) {
				for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] = block_all[i];
				block_all[i] = -1;
			}
			if (block_div[i] != 1) {
				for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] /= block_div[i];
				block_div[i] = 1;
			}
			for (j = L; j < (i + 1) * SIZE && j <= R; j++) a[j] /= x;
			for (jj = i * SIZE, block_max[i] = 0, block_sum[i] = 0; jj < (i + 1) * SIZE; jj++) {
				chmax(&(block_max[i]), a[jj]);
				block_sum[i] += a[jj];
			}
			if (j <= R) {
				for (i = j / SIZE; (i + 1) * SIZE <= R; i++) {
					if (block_max[i] / block_div[i] / x == 0) {
						block_div[i] = 1;
						block_all[i] = 0;
						block_max[i] = 0;
						block_sum[i] = 0;
					} else block_div[i] *= x;
				}

				if (block_all[i] >= 0) {
					for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] = block_all[i];
					block_all[i] = -1;
				}
				if (block_div[i] != 1) {
					for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] /= block_div[i];
					block_div[i] = 1;
				}
				for (j = i * SIZE; j <= R; j++) a[j] /= x;
				for (jj = i * SIZE, block_max[i] = 0, block_sum[i] = 0; jj < (i + 1) * SIZE; jj++) {
					chmax(&(block_max[i]), a[jj]);
					block_sum[i] += a[jj];
				}
			}
		} else if (t == 2) {
			scanf("%d %d %d", &L, &R, &y);
			L--;
			R--;

			i = L / SIZE;
			if (block_all[i] >= 0) {
				for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] = block_all[i];
				block_all[i] = -1;
			}
			if (block_div[i] != 1) {
				for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] /= block_div[i];
				block_div[i] = 1;
			}
			for (j = L; j < (i + 1) * SIZE && j <= R; j++) a[j] = y;
			for (jj = i * SIZE, block_max[i] = 0, block_sum[i] = 0; jj < (i + 1) * SIZE; jj++) {
				chmax(&(block_max[i]), a[jj]);
				block_sum[i] += a[jj];
			}
			if (j <= R) {
				for (i = j / SIZE; (i + 1) * SIZE <= R; i++) {
					block_div[i] = 1;
					block_all[i] = y;
					block_max[i] = y;
					block_sum[i] = y * SIZE;
				}

				if (block_all[i] >= 0) {
					for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] = block_all[i];
					block_all[i] = -1;
				}
				if (block_div[i] != 1) {
					for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] /= block_div[i];
					block_div[i] = 1;
				}
				for (j = i * SIZE; j <= R; j++) a[j] = y;
				for (jj = i * SIZE, block_max[i] = 0, block_sum[i] = 0; jj < (i + 1) * SIZE; jj++) {
					chmax(&(block_max[i]), a[jj]);
					block_sum[i] += a[jj];
				}
			}
		} else {
			scanf("%d %d", &L, &R);
			L--;
			R--;

			ans = 0;
			i = L / SIZE;
			if (block_all[i] >= 0) {
				for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] = block_all[i];
				block_all[i] = -1;
			}
			if (block_div[i] != 1) {
				block_max[i] = 0;
				block_sum[i] = 0;
				for (j = i * SIZE; j < (i + 1) * SIZE; j++) {
					a[j] /= block_div[i];
					chmax(&(block_max[i]), a[j]);
					block_sum[i] += a[j];
				}
				block_div[i] = 1;
			}
			for (j = L; j < (i + 1) * SIZE && j <= R; j++) ans += a[j];
			if (j <= R) {
				for (i = j / SIZE; (i + 1) * SIZE <= R; i++) {
					if (block_div[i] != 1) {
						if (block_all[i] >= 0) {
							block_all[i] /= block_div[i];
							block_max[i] = block_all[i];
							block_sum[i] = block_all[i] * SIZE;
						} else {
							block_max[i] = 0;
							block_sum[i] = 0;
							for (j = i * SIZE; j < (i + 1) * SIZE; j++) {
								a[j] /= block_div[i];
								chmax(&(block_max[i]), a[j]);
								block_sum[i] += a[j];
							}
						}
						block_div[i] = 1;
					}
					ans += block_sum[i];
				}

				if (block_all[i] >= 0) {
					for (j = i * SIZE; j < (i + 1) * SIZE; j++) a[j] = block_all[i];
					block_all[i] = -1;
				}
				if (block_div[i] != 1) {
					block_max[i] = 0;
					block_sum[i] = 0;
					for (j = i * SIZE; j < (i + 1) * SIZE; j++) {
						a[j] /= block_div[i];
						chmax(&(block_max[i]), a[j]);
						block_sum[i] += a[j];
					}
					block_div[i] = 1;
				}
				for (j = i * SIZE; j <= R; j++) ans += a[j];
			}
			printf("%lld\n", ans);
		}
	}
	fflush(stdout);
	return 0;
}
