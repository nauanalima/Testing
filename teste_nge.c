#include <stdio.h>
#include <stdlib.h>

main() {

	int m=10, i, j, n;
	double a[m][m], b[m], x[m];

	for (n=4; n<=10; n++) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++)
				a[i][j] = (i+1)^(j-1);
			b[i] = (((i+1)^n)-1)/i;
		}
	}
	for (n=4; n<=10; n++) {
		printf("\nn = %d\n", n);
		for(i=1; i<=n; i++)
			printf("%ld\t", x[i]);
	}
}
