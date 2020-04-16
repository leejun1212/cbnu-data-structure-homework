/*
 * hw4.c
 *
 *  Created on: 2020. 4. 17.
 *      Author: yb
 */
#include <stdio.h>
#include <stdlib.h>
/* create a 2d array whose size is row x col using malloc() and return the 2d array */
int** create_matrix(int row, int col);
/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col);
/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col);
/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col);
/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col);
/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col);
/* matrix_axt = matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col);


int main(void)

{

	int** matrix_a;  /*���������� �迭 ���� ����*/
	int** matrix_b;
	int** matrix_sum;
	int** matrix_sub;
	int** matrix_t;
	int** matrix_axt;

	int row, col;
    scanf("%d %d",&row, &col);  /*��� �� �� �Է�*/

	matrix_a = create_matrix(row, col); /*���������� �迭 ������ �����Ҵ�*/
	matrix_b = create_matrix(row, col);
	matrix_sum = create_matrix(row, col);
	matrix_sub = create_matrix(row, col);
	matrix_t = create_matrix(col, row);
	matrix_axt = create_matrix(row, row);

	fill_data(matrix_a, row, col);  /*�����Ҵ�� 2���� �迭�� 0~19������ ������ �� ����*/
	fill_data(matrix_b, row, col);
	addition_matrix(matrix_a, matrix_b, matrix_sum, row, col); /*�� ������ 2���� �迭�� ��*/
	subtraction_matrix(matrix_a, matrix_b, matrix_sub, row, col); /*�� ������ 2���� �迭�� ��*/
	transpose_matrix(matrix_a, matrix_t, row, col); /* 2���� �迭 A�� ��ġ �迭*/
	multiply_matrix(matrix_a, matrix_t, matrix_axt, row, col);  /* 2���� �迭 A�� �� ��ġ �迭�� �� �迭*/

	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");
	print_matrix(matrix_a, row, col); /*�����Ҵ�� 2���� �迭�� ��� ����Ʈ*/
	print_matrix(matrix_b,  row,  col);
	print_matrix(matrix_sum,  row,  col);
	print_matrix(matrix_sub,  row,  col);
	print_matrix(matrix_t,  col,  row);
	print_matrix(matrix_axt,  row,  row);

	free_matrix(matrix_a,  row,  col); /*�����Ҵ�� 2���� �迭�� �޸� ����*/
	free_matrix(matrix_b,  row,  col);
	free_matrix(matrix_sum,  row,  col);
	free_matrix(matrix_sub,  row,  col);
	free_matrix(matrix_t,  col,  row);
	free_matrix(matrix_axt,  row,  row);

	return 0;

}

int** create_matrix(int row, int col) /*���������� �迭 ������ �����Ҵ�*/
{
	/* check pre conditions */
	int** matrix;

	if (row <= 0 || col <= 0)

	{
		printf("Check the sizes of row and col!\n");

		return -1;

	}

	else
	{


		matrix = (int**)malloc(sizeof(int*) * row);


		for (int i = 0; i < row; i++)
		{
			matrix[i] = malloc(sizeof(int) * col);

		}




	}
             if(matrix == NULL)

               { return -1; }

	return matrix;

}


int fill_data(int** matrix, int row, int col) /*�����Ҵ�� 2���� �迭�� 0~19������ ������ �� ����*/
{
              if(matrix == NULL)

               { return -1; }
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = rand()%20;
		}
	}



	return 0;
}

int addition_matrix(int** matrix_a, int** matrix_b, int** matrix_sum, int row, int col) /*�� ������ 2���� �迭�� ��*/
{
             if(matrix_a == NULL || matrix_b== NULL)

                 { return -1; }

             for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}



	return 0;
}

int subtraction_matrix(int** matrix_a, int** matrix_b, int** matrix_sub, int row, int col) /*�� ������ 2���� �迭�� ��*/
{
                if(matrix_a == NULL || matrix_b== NULL)

                 { return -1; }
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
		}
	}


	return 0;
}

int transpose_matrix(int** matrix, int** matrix_t, int row, int col) /* 2���� �迭 A�� ��ġ �迭*/
{
               if(matrix == NULL)

               { return -1; }
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			matrix_t[i][j] = matrix[j][i];
		}
	}


	return 0;
}


int multiply_matrix(int** matrix_a, int** matrix_t, int** matrix_axt, int row, int col) /* 2���� �迭 A�� �� ��ġ �迭�� �� �迭*/
{
	if(matrix_a == NULL || matrix_t==NULL)
           { return -1; }

	int i;
	int sum;
	int j;
	for ( i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			sum = 0;
			for (int k = 0; k < col; k++)
			{
				sum += matrix_a[i][k] * matrix_t[k][j];
			}

			matrix_axt[i][j] = sum;
		}
	}



	return 0;
}

void print_matrix(int** matrix, int row, int col) /*�����Ҵ�� 2���� �迭�� ��� ����Ʈ*/
{
             if(matrix == NULL)

               { return -1; }
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t", matrix[i][j]);
		}

		printf("\n");

	}
	printf("\n");
}

int free_matrix(int** matrix, int row, int col) /*�����Ҵ�� 2���� �迭�� �޸� ����*/
{
	for (int i=0; i < row; i++)
						{

							{
								free(matrix[i]);

							}
							free(matrix);
						}

              if(matrix == NULL)

               { return 0; }
	 else
               {return -1;}
}


