#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee{
    char name [50];
    float salary;
    
}Employee;

int main()
{
    int size,i;
    float sum=0;//This variable will be used to calculate the sum of all salaries
    
    
    //Scanning the number of employees 
    do{
    printf("Please enter how many employees you want to have in the array: \n");
    scanf("%d",&size);
    }while (size<0);
    
    if (size==0)
    {
        printf("Array size=0");
        return 1;
    }
    
    //Dynamically allocating memory for the array employees
    Employee* employees = (Employee*)malloc(size*sizeof(Employee));
    if (employees==NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }
    
    //Asking the user for the data needed for the Employee object initiallization
    for (i=0;i<size;i++)
    {
        printf("Enter the name and salary of the employee: \n");
        scanf(" %s %f",employees[i].name,&employees[i].salary);
    }
    
    //This for loop calculates the sum of all salaries
    for (i=0;i<size;i++)
    {
        sum+=employees[i].salary;
    }
    
    //Printing all the Employees' names and salaries
    for (i=0;i<size;i++)
    {
        printf("Employee name: %s Employee salary: %.2f \n",employees[i].name,employees[i].salary);
    }
    //Printing the sum of all of the Employees' salaries
    printf("The sum of all salaries is: %.2f ",sum);
    free(employees);
    return 0;
}