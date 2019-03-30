#include<stdio.h> //standard i/p o/p file
#include<stdlib.h>
#define MAX 20

struct sparse
{
	int row;
	int column;
	int data;
};




void inputmatrix(int matrix[MAX][MAX], int r, int c)          //user defined function to input a matrices
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}




void displaymatrix(int matrix[MAX][MAX],int r,int c)      //user defined function to print two matrices
{
	int i,j;
	for (i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
	printf("\n");
	}
}




int create_sparse(int mat[MAX][MAX], struct sparse spmat1[MAX])
{
	int i, j;
	int count = 0;
	
	for (i = 0; i < spmat1[0].row; i++)
	{
		for (j = 0; j < spmat1[0].column; j++)
		{
			if (mat[i][j] != 0)
			{
				count++;
				spmat1[count].row = i;
				spmat1[count].column = j;
				spmat1[count].data = mat[i][j];
			}
		}
	}
	return(count);
}




void display_sparsemat(struct sparse spmat1[MAX])
{
	int i, j;
	for (i = 0; i <= spmat1[0].data; i++)   // i <= sparce matrix number of values
	{
			printf("\n%d\t%d\t%d\t", spmat1[i].row, spmat1[i].column, spmat1[i].data);
	}
	printf("\n");
}




void simple_transpose(struct sparse spmat1[MAX],struct sparse spmat3[MAX])
{
	int c, term, k = 1;
	
	spmat3[0].row = spmat1[0].column;
	spmat3[0].column = spmat1[0].row;
	spmat3[0].data = spmat1[0].data;
	
	for (c = 0; c < spmat1[0].column; c++)
	{
		for (term = 1; term <= spmat1[0].data; term++)
		{
			if (c == spmat1[term].column)
			{
				spmat3[k].row = spmat1[term].column;
				spmat3[k].column = spmat1[term].row;
				spmat3[k].data = spmat1[term].data;
				k++;
			}//if
		}//inner for
	}//outer for
}




void add_sparse(struct sparse spmat1[MAX],struct sparse spmat2[MAX],struct sparse spmat3[MAX])
{
	int i = 1, j = 1, k = 1;
	
  while( (i <= spmat1[0].data) && ( j <= spmat2[0].data) )
	{
		if ( (spmat1[i].row == spmat2[j].row) && (spmat1[i].column == spmat2[j].column))
		{
			spmat3[k].row = spmat1[i].row;
			spmat3[k].column = spmat1[i].column;
			spmat3[k].data = spmat1[i].data + spmat2[j].data;
			i++;
			j++;
		}
		
    if ( (spmat1[i].row < spmat2[j].row) && (spmat1[i].column == spmat2[j].column) )
		{
			spmat3[k].row = spmat1[i].row;
			spmat3[k].column = spmat1[i].column;
			spmat3[k].data = spmat1[i].data;
			i++;
		}
		
    if ( (spmat1[i].row > spmat2[j].row) && (spmat1[i].column == spmat2[j].column) )
		{
			spmat3[k].row = spmat2[j].row;
			spmat3[k].column = spmat2[j].column;
			spmat3[k].data = spmat2[j].data;
			j++;
		}
		
    if ( (spmat1[i].row == spmat2[j].row) && (spmat1[i].column > spmat2[j].column) )
		{
			spmat3[k].row = spmat2[j].row;
			spmat3[k].column = spmat2[j].column;
			spmat3[k].data = spmat2[j].data;
			j++;
		}
		
    if ( (spmat1[i].row == spmat2[j].row) && (spmat1[i].column < spmat2[j].column) )
		{
			spmat3[k].row = spmat1[i].row;
			spmat3[k].column = spmat1[i].column;
			spmat3[k].data = spmat1[i].data;
			i++;
    }
    k++;
	}//end of first while


	while (i <= spmat1[0].data)
	{
			spmat3[k].row = spmat1[i].row;
			spmat3[k].column = spmat1[i].column;
			spmat3[k].data = spmat1[i].data;
			i++;
			k++;
	}

	while (j <= spmat2[0].data)
	{
		spmat3[k].row = spmat2[j].row;
		spmat3[k].column = spmat2[j].column;
		spmat3[k].data = spmat2[j].data;
		j++;
		k++;
	}

	spmat3[0].row = spmat1[0].column;
	spmat3[0].column = spmat1[0].row;
	spmat3[0].data = k - 1;//spmat1[
}




void fast_transpose(struct sparse spmat1[MAX], struct sparse spmat3[MAX])
{
	int i, j;
	int rpos[MAX] = {0}, rterm[MAX] = {0};
	
	spmat3[0].row = spmat1[0].column;
	spmat3[0].column = spmat1[0].row;
	spmat3[0].data = spmat1[0].data;
	
	for (i = 1; i <= spmat1[0].data; i++)   
		rterm[spmat1[i].column]++;
	
	rpos[0] = 1;
	
	
	for (i = 1; i <= spmat1[0].column; i++)
		rpos[i] = rpos[i - 1] + rterm[i - 1];
	
	
	for (i = 1; i <= spmat1[0].data; i++)
	{
		j = rpos[spmat1[i].column];
		
		spmat3[j].row = spmat1[i].column;
		spmat3[j].column = spmat1[i].row;
		spmat3[j].data = spmat1[i].data;
		
		rpos[spmat1[i].column]++;
	}
}





int main()                       //call to main function
{
	int matrix1[MAX][MAX] = {0}, matrix2[MAX][MAX], matrix3[MAX][MAX], r1, c1, r2, c2, ch, count, pos; //variable declaration
	struct sparse spmat1[MAX];
	struct sparse spmat2[MAX];
	struct sparse spmat3[MAX];
	
	printf("\nEnter size of matrix 1:");
	scanf("%d %d",&r1,&c1);
	
	printf("\nEnter %d elements of matrix1:",r1*c1);
	inputmatrix(matrix1,r1,c1);
	
	spmat1[0].row = r1;
	spmat1[0].column = c1;
	
	count = create_sparse(matrix1, spmat1);
	spmat1[0].data = count;
	
	printf("\nSPARSE MATRIX 1:");
	display_sparsemat(spmat1);

	while(1)
	{
		printf("\n1.Simple Transpose\n2.Fast transpose\n3.Addition of Sparse matrix\n4.Exit");
		printf("\nEnter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				simple_transpose(spmat1,spmat3);
				printf("\nSIMPLE TRANSPOSE IS :");
				display_sparsemat(spmat3);
				break;
			case 2:
				fast_transpose(spmat1,spmat3);
				printf("\nFAST TRANSPOSE IS :");
				display_sparsemat(spmat3);
				break;
			case 3:
			    printf("\nEnter size of matrix 2:");
                scanf("%d %d",&r2,&c2);
                printf("\nEnter %d elements of matrix 2:",r2*c2);
                inputmatrix(matrix2,r2,c2);
                spmat2[0].row=r2;
                spmat2[0].column=c2;
                count=create_sparse(matrix2,spmat2);
                spmat2[0].data=count;
                printf("\nSPARSE MATRIX 2:");
                display_sparsemat(spmat2);
				add_sparse(spmat1,spmat2,spmat3);
				printf("\nADDITION IS :");
				display_sparsemat(spmat3);
				break;
			case 4:
				printf("\nThank u......\n");
				exit(0);
				break;

			default:
				printf("\nWrong choice!!!!");
				break;
		}//end of switch
	}
}//end of main function