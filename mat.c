#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(double **matrix, int row, int col){
	int i, j;
	printf("\nMatriz: \n");
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) { 
			printf("%5.2lf\t",matrix[i][j]);
		}	  
		printf("\n");
	}
	printf("\n");
}

double **read(char *archive, int *rows, int *columns) {
	int i, j, R, C;
	double **matrix;
	FILE *arch;

	arch = fopen(archive, "r");

    if(!arch) {
        printf("\nERRO! Arquivo não encontrado!\n\n");
        exit(1);
    }

	fscanf(arch,"%d",&R);
    fscanf(arch,"%d",&C);

	matrix = malloc(R*sizeof(double *));
	for (i=0; i<R; i++)
		matrix[i] = (double *)malloc(C*sizeof(double));

	for(i=0; i<R; i++)	{
		for (j=0; j<C; j++)
			fscanf(arch,"%lf",&matrix[i][j]);
	}
	*rows = R;
    *columns = C;
	return matrix;

}

void exchangelines (double *line1, double *line2, int row) {
	double temp;
	int i;

	for (i=0; i<=row; i++) {
		temp = line1[i];
		line1[i] = line2[i];
		line2[i] = temp;
	}
}

int uppertriangular (double **matrix, int row, int col) {
	int i, j, k, k1, test, pivot;
	double m, temp;

	int steps = 0; 

	for (k=0; k<row; k++) {
		for (j=k; j<row; j++) {
			test = -1;
			if (fabs(matrix[j][k]) > matrix[k][k]) {
				test = j;
			}
			if (test!=-1) {
				exchangelines(matrix[k], matrix[test], row);
				steps++;
				printf("\nSteps: %d", steps);
			}
		}
		for (i=k+1; i<row; i++) {
			m = matrix[i][k]/matrix[k][k];
			for (j=k; j<=col; j++)
				matrix[i][j] = matrix[i][j] - m*matrix[k][j];
		}
		printf("\nEstágio da matriz:");
		print(matrix,row,col);
	}
	printf("\n\n ---------------- fim do pivoteamento ------------------\n\n");
	return steps;		
}

double determinant (double **matrix, int dim) {
	int i;
	double det = 1;

	for (i=0; i<dim; i++)
		det *= matrix[i][i];

	if (pivoteamento(matrix,dim,dim) != 0)
		det = -1*det;

	return det;

}

double *reversesub (double **matrix, const int dim) {
	int j, k, n;
	double sum, *roots = (double*)malloc(dim*sizeof(double));
	roots[dim-1] = matrix[dim-1][dim]/matrix[dim-1][dim-1];
	k = dim-2;
	while (k>=0) {
		sum = matrix[k][dim];
		for (j=k+1; j<dim; j++) 
			sum = sum - matrix[k][j]*roots[j];
		roots[k] = sum/matrix[k][k];
		k--;
	}
	return roots;
}

double **multiplication (double **matrix1, double **matrix2, int row1, int rowcol, int col2) {

    double **matrix3, sum;
    int i, j, k;

    matrix3 = malloc(row1*sizeof(double*));
    for (i=0; i<row; i++)
        matrix3[i] = (double*)malloc(col2*sizeof(double));

    for (k=0; k<col2; k++) {
        for (i=0; i<row1; i++) {
            sum = 0;
            for (j=0; j<col; j++)
                sum += matrix1[i][j]*matrix2[j][k];
            matrix3[i][k] = sum;
        }
    }
    return matrix3;
}

int main(int argc, char **argv) {
	double **M, *raizes, det;
	int i, row, col, step;

	M=read(argv[1],&row,&col);
	print(M,row,col);
	step=uppertriangular(M,row,col);
	printf("Passos: %d\n", step);
	print(M,row,col);
    
	return 0;
}