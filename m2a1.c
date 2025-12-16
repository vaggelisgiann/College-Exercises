#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int N)
{
    //Creating the array
    int* array=malloc(N*sizeof(int));
    if (array==NULL)
    {
        printf("Memory not alocated");
        return NULL;
    }
    
    //This for loop is resposible for providing as many random numbers as the length of the array
    for (int i=0;i<N;i++)
    {
        array[i]=rand()%11;
    }
        return array;
}

int* product(int arr1[],int arr2[], int n)
{
    //the array prd_array with the same length as the previous 2 arrays, that will be the result of the product
    int*prd_array=malloc(n*sizeof(int));
    
    if (prd_array==NULL)
        return NULL;
    
    //This for loop is the algorithm of the product of two arrays
    for (int i=0;i<n;i++)
        prd_array[i]=arr1[i]*arr2[i];
        
    return prd_array;
    
}

int main()
{
    //This seed give us random numbers
    srand((unsigned) time(NULL));

    //Creating an array with random numbers
    int N = 10;
    int* array1 = create_array(N);
    
    for (int i=0;i<N;i++)
    {
        printf("array[%d]=%d\n",i,array1[i]);
    }
    
    printf("\n");
    //Creating 2 arrays
    int* array2 = create_array(N);
    int* array3 = create_array(N);
    
    //using the function product that will find the product of arrays array2 and array3
    int* prd = product(array2,array3,N);
    
    for (int i=0;i<N;i++)
    {
        printf("array2[%d]=%d , array3[%d]=%d\n", i,array2[i],i,array3[i]);
    }
    
    //Printing the product
    printf("The product of arrays array2 and array3 is: ");
    
    printf("[");
    for (int i=0;i<N;i++)
    {
        
        for (i=0;i<N;i++)
        {
            printf("%d ",prd[i]);
        }
    }
    printf("]");
    
        return 0;
}