#include <stdio.h>


int main()
{
    float a,b,result;
    char operation;
    int count=0;
    do{
    printf("Enter a, b and operation (+ or - or * or / ). Enter $ as a operation to end the program: ");
    scanf("%f %f %c",&a ,&b, &operation);
    
    if (operation=='/' && b==0)
    {
        printf("Error: Cannot divide by 0.0. Operation has failed\n");
        continue; //return -1 if I want the program to end when b==0
    }
    if (operation=='$')//The program stops if operation==$
    {
        printf("Program has eneded");
        break;
    }
    if (operation=='+')
    {
        result=a+b;
    }
    else if (operation=='-')
    {
        result=a-b;
    }
    else if (operation=='*')
    {
        result=a*b;
    }
        else{
            if (operation!='/')
            {
                printf("Error: undefined operaτion: %c", operation);
                continue; //return -1 if I want the program to end when a non acceptable value is given
            }
                result=a/b;
        }
        
        printf("Success! Result of %f %c %f = %f \n", a, operation, b, result);
        count++;
        printf("Calculated %d operations. \n" ,count);
        
    }while(operation!='$');//The program keeps working while operation!=$
   
    return 0;
}