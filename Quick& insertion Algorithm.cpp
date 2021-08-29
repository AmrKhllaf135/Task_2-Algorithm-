#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insetrtion_func(int arr[] , int n)
{
	/*Time Complexity :
	Best case = Array is Sorted Big O(n)
	Avg case = Big O(n^2)
	Worst case = Big O(n^2)
	Memory complexity:
	in place(don't need extra places) Big O(1)*/
	int i;
	int key;
	int index;
	for(i = 1 ; i<n ; i++)
	{
		key = arr[i];
		index = i-1;
		while(index>=0&&key<arr[index])
			{
				arr[index+1] = arr[index];
				index--;
			}
			arr[index+1] = key;


	}

}
int partition(int arr[] , int start , int end)
	{
		int pivot = arr[end];
		int P_index = start;
		int i;
		for(i =start ; i<end ; i++)
			{
				if(arr[i] <= pivot)
					{
						int temp = arr[i];
						arr[i] = arr[P_index];
						arr[P_index] = temp;
						P_index++;
					}
			}
		int temp_ = arr[end];
		arr[end]=arr[P_index];
		arr[P_index] = temp_;
		return P_index;
	}


void Quick_sort(int arr[] , int start , int end)
	{
		/*
			Time Complexity is Big O(n log n)
			space Complexity is Big O(1)*/
		if(start < end)
		{
			int P_index = partition(arr , start ,end);
			Quick_sort  ( arr , start , P_index-1);
			Quick_sort  ( arr ,P_index+1 , end);
		 }

	}
int main(void)
{
   int n;
   int lower = 0;
   int upper = 100000;

   printf("Enter the size of array from 1 to 100000 : ");
   scanf("%d",&n);
   int arr[n],arr_2[n],i;
   int size_ = sizeof(arr) / sizeof(arr[0]);

   for(i=0;i<n;i++)
    {
       arr[i]=(rand() % (upper - lower + 1)) + lower;    //Generate number between 0 to 100000

    }
    arr_2[n] = arr[n];
    clock_t t;
    t = clock();

    insetrtion_func(arr , n);
    t = clock() - t;
    double time_spent = ((double)t)/CLOCKS_PER_SEC;
    printf("the array is sorted using insertion sort = %f\n", time_spent);
    clock_t t_1;
    t_1 = clock();
    Quick_sort(arr_2,lower,size_);
    t_1 = clock() - t_1;
    double time_spent_1 = ((double)t_1)/CLOCKS_PER_SEC;
    printf("the array is sorted using quick sort = %f\n", time_spent_1);


   /*printf("\nElements of the array::\n");
   for(i=0;i<n;i++)
   {
     printf("Element number %d::%d\n",i+1,arr[i]);
   }*/

   return 0;
}

