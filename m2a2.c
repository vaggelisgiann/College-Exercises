#include <stdio.h>
#include <stdlib.h>

//ΕΡΩΤΗΜΑ a) (IMPLEMENTATION WITH A FOR LOOP)
/*
//The function that adds the elements of the array with a for loop
int add(int array[],int n)
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=array[i];
    }
    
    return sum;
}*/

//ΕΡΩΤΗΜΑ b) (IMPLEMENTATION WITH RECURSION)
int add(int array[], int n)
{
    if (n==1)
        return array[0];
    else
        return array[n-1]+add(array,n-1);//the next time this function is used, it will be array[n-2]+add(array,n-2) etc
}

int main()
{
    int n=5;
    int i;
    
    //We create the array dynamically
    int* arr1 = malloc(n*sizeof(int));
    
    for (i=0;i<n;i++)
    {
        printf("Enter arr1[%d]: ",i);
        scanf("%d",&arr1[i]);
    }

    int sum = add(arr1,n);
    
    printf("\nThe sum of all the contents of the array is: %d ",sum);
    
    free(arr1);
    return 0;
}