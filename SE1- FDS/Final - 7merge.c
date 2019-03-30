#include<stdio.h>


void mergeSort(int a[30],int i, int j);
void merge(int a[3], int l, int m, int u);
void mergesort_nonrecurrsive(int A[20],int n);


int main()
{
  int a[30], n, i;
  printf("Enter number of elements : ");
  scanf("%d", &n);

  printf("Enter array elements\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  mergesort_nonrecurrsive(a, n);

  printf("Sorted data is : ");
  for (i = 0; i < n; i++)
  {
    printf(" %d ", a[i]);
  }
}




void mergeSort(int a[30],int i, int j)
{
  int k;
  if (i < j)
  {
    k = (i + j)/2;
    mergeSort(a, i, k);
    mergeSort(a, k + 1, j);
    merge(a, i, k, j);
  }
}//end of merge sort()



void merge(int a[3], int l, int m, int u)
{
  int c[30];
  int i, j, k;

  i = l;      //for first splitted array
  j = m + 1;   //for second splitted array
  k = 0;

  while (i <= m && j <= u)
  {
    if (a[i] <= a[j])
    {
      c[k] = a[i];
      i++;
    }
    else
    {
      c[k] = a[j];
      j++;
    }
    k++;
  }

  while (i <= m)
  {
    c[k] = a[i];
    k++;
    i++;
  }

  while (j <= u)
  {
    c[k] = a[j];
    k++;
    j++;
  }

  for (i = l, j = 0; i <= u; i++, j++)
  {
    a[i] = c[j];
  }
}




void mergesort_nonrecurrsive(int A[20], int n) //non recursive merge sort
{
	int size, low, mid, high, pass;
	
  for (size = 1 , pass = 1 ; size < n ; size = size * 2 , pass++)
	{
		low = 0;
		while ( (low + size) < n )
		{
            mid = low + size - 1;
			      high = low + (2 * size) - 1;
			
            if (high >= n)
			      high = n - 1;
			      printf("\n\tLOW :%d\tMID :%d\tHIGH :%d", low, mid, high);
			      merge(A, low, mid, high);

			      low = high + 1;
		}//while
		
    printf("\n\nArray after pass %d  :",pass);
	          
	}//for
}//non recursive merge sort


