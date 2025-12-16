#include <stdio.h>
#include <stdlib.h>

int main()
{
    //The variables needed for the first part of the excercise
    int i,size=10;
    float total=0;
    float avg=0;
    float* sales;
    char ans;
    
    //Creating the array sales dynamically
    sales = (float*)malloc(10*sizeof(float));
    if (sales==NULL)
    {
        printf("Memory alocation failed. ");
        return 1;
    }
    
    printf("Welcome. Please enter the sales figures for the 10 selected stores.\n");
   
    for (i=0;i<size;i++)
    {
        do{
        printf("Please enter the sales figue of store #%d \n",i+1);
        scanf("%f",&sales[i]);
        }while (sales[i]<0);
    }
    
    //ΕΡΩΤΗΜΑ b)
    
    //The do-while loop that allows the program to be re-run, stopped or re-run with an extra store
    do
    {
    //This function calculates the total amount of all sales
    total=0;
    for (i=0;i<size;i++)
    {
        total+=sales[i];
    }
    
    //ΕΡΩΤΗΜΑ a)
    //Now we can calculate the average with this algorithm
    avg=total/size;
    
    
    printf("The average of all sales from all the stores is: %.2f",avg);
        
        //ΕΡΩΤΗΜΑ c)
        //Asking the user if they want to re-run the program, re-run in with an extra store or exit 
        printf("\nEnter r if you want to re-run the program, a if you want the program to re-run with an extra store or e if you want to exit: \n");
        scanf(" %c",&ans);
        if (ans=='a')
        {
            size++;
            sales=realloc(sales,size*sizeof(float));
            if (sales==NULL)
            {
                printf("Memory Reallocation failed");
                return 1;
            }
            
            
            //Adding the new value. No for loop is required, due to the size changing by 1 every time the do-while loop is running
            do{
            printf("Enter new sales values from store #%d: \n",size);
            scanf("%f",&sales[size-1]);
            }while(sales[size-1]<0);
            
            total=0;
            for (i=0;i<size;i++)
            {
                total+=sales[i];
            }
            
            //Reallocating the variable avg. We know that size=size++>0 
            avg=total/size;
            printf("The new average from the sales is %.2f \n",avg);
            
        }
    
 
    }while (ans=='r'||ans=='a');
    
    if (ans=='e')
    {
        printf("\nEnding the program. ");
        return 0;
    }else
    {
        printf("Error, character not recognized");
        return 1;
    }
       free(sales);
       sales=NULL;
       return 0;
    
}   