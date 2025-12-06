//#include <stdio.h>

int main()
{
    double sum,x[10],lamda;
    int N,i;
    
    //the variable "N" must be between 0 and 10 as per the excercise
    do{
        
        printf("Give me an integer number N\n");
        scanf("%d",&N);
        
    }while(N<=0 || N>=10);
    
    
        printf("Give me another integer λ\n");
        scanf("%lf",&lamda);
        
        //To save time and resources, if λ=0 then sum=0 and there is no furhter need to contninue the program
        if (lamda==0){
            sum=0.0;
            printf("sum=%lf",sum);
            return -1;
        }
        for (i=0;i<=N;i++){
            printf("Give me the variable x\n");
            scanf("%lf",&x[i]);
        
        }
    //We assign values to the x variable
    sum=0.0;
    for (i=0;i<=N;i++){
        sum+=x[i]+i/(float)N;
    }
    sum=lamda*sum;
    printf("%lf",sum);
    
    return 0;
}