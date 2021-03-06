#include "convolution3d.h"

void convolution3d(data_t A[SIZE], data_t B[SIZE]) {
<PRAGMA>
	data_t c11, c12, c13, c21, c22, c23, c31, c32, c33;
	c11 = 2.0; c21 = 5.0; c31 = -8.0;
	c12 = -3.0; c22 = 6.0; c32 = -9.0;
	c13 = 4.0; c23 = 7.0; c33 = 10.0;

	for(int i = 1; i < (NI - 1); i++) {
		for(int j = 1; j < (NJ - 1); j++) {
<PRAGMA2>
			for(int k = 1; k < (NK - 1); k++) {
<PRAGMA3>
				B[i * (NK * NJ) + j * NK + k] = c11 * A[(i - 1) * (NK * NJ) + (j - 1) * NK + (k - 1)]  +  c13 * A[(i + 1) * (NK * NJ) + (j - 1) * NK + (k - 1)]
					+ c21 * A[(i - 1) * (NK * NJ) + (j - 1) * NK + (k - 1)]  +  c23 * A[(i + 1) * (NK * NJ) + (j - 1) * NK + (k - 1)]
					+ c31 * A[(i - 1) * (NK * NJ) + (j - 1) * NK + (k - 1)]  +  c33 * A[(i + 1) * (NK * NJ) + (j - 1) * NK + (k - 1)]
					+ c12 * A[(i + 0) * (NK * NJ) + (j - 1) * NK + (k + 0)]  +  c22 * A[(i + 0) * (NK * NJ) + (j + 0) * NK + (k + 0)]
					+ c32 * A[(i + 0) * (NK * NJ) + (j + 1) * NK + (k + 0)]  +  c11 * A[(i - 1) * (NK * NJ) + (j - 1) * NK + (k + 1)]
					+ c13 * A[(i + 1) * (NK * NJ) + (j - 1) * NK + (k + 1)]  +  c21 * A[(i - 1) * (NK * NJ) + (j + 0) * NK + (k + 1)]
					+ c23 * A[(i + 1) * (NK * NJ) + (j + 0) * NK + (k + 1)]  +  c31 * A[(i - 1) * (NK * NJ) + (j + 1) * NK + (k + 1)]
					+ c33 * A[(i + 1) * (NK * NJ) + (j + 1) * NK + (k + 1)];
			}
		}
	}
}
