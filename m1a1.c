#include <stdio.h>

int main()
{
    float income,tax;
    char answer;
    
    //Entering the income;
    do{
    printf("Please enter the employee's income\n");
    scanf("%f",&income);
    }while(income<0);
    
    
    
    /*if (income<0){
        printf("There has been an error, you can't enter a negative income\n");
        return -1; (These lines of code must be added if we want the program to stop when a negative value is entered)
    }*/
    
    //Parameters for the range of given income
    if (income==0){
        tax=0;
    }else if (income>0 && income<10000){
        tax=0.09;
    }else if (income>10000 && income<20000){
        tax=0.22;
    }else if (income>20000 && income<40000){
        tax=0.30;
    }else if (income>40000){
        tax=0.50;
    }
    do {
    printf("Did the employee pay his/her tax during the first month? Write Y for yes or N for no\n");
    scanf(" %c",&answer);
    }while(answer!='Y' && answer!='N');
    if (answer=='Y'){
        tax = tax-(tax*0.1);
        printf("The employee has gained a 10%% tax discount\n");
    }else if (answer=='N'){
        printf("The employee is not eligible for a tax discount\n");
    }
    
    
    printf("The employee's salary is %f € and the tax is %f %%",income,tax*100);
    
    return 0;
}