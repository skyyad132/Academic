#include <stdio.h>




int partition(int numbers[], int left, int right)
{
  int pivot; 
  int Temp;
  int p = left;
  
  pivot = numbers[left];
  printf("\nPivot (%3d)=> ",pivot);
  
  while (left < right)
  {
    while ( (numbers[right] > pivot) && (left < right) )
        right--;
    
    while ( (numbers[left] <= pivot) && (left < right) )
        left++;
    
    if (left < right)
    {
        Temp = numbers[right];
        numbers[right] = numbers[left];
        numbers[left] = Temp;
    }
  }
  
  numbers[p] = numbers[right];
  numbers[right] = pivot;
  pivot = right;

  return pivot;
}




void quicksort(int numbers[], int left, int right)
{
    int i, pivot;
    static int Pass = 1;

    pivot = partition(numbers, left, right);
    printf(" Pass %2d: ", Pass++);
    
    for (i = 0; i < 10; i++)
        printf("%3d ",numbers[i]);
    
    if (left < pivot)
        quicksort(numbers, left, pivot - 1);
    
    if (right > pivot)
        quicksort(numbers, pivot + 1, right);
}




int main()
{
  int i,a[10]={56,-90,80,78,234,654,432,12,0,-11};
  int b[10]={56,45,89,90,-30,23,48,67,78,70};
  
  printf("\n Original Array\n");
  for (i = 0; i < 10; i++)
      printf(" %3d ", b[i]);
  
  quicksort(b, 0, 9);
  
  printf("\nQuick Sort: ");
  for (i = 0; i < 10; i++)
      printf(" %3d ",b[i]);

  return 1;
}