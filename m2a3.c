#include <stdio.h>
#include <stdlib.h>

/*IMPLEMENTATION WITHOUT A FOR LOOP
//This function solves the problem without the need of a for loop 
float distance(int t)
{
    if (t==0)
        return 0;
    else if (t==1)
        return 1;
    else    
    return 0.1f*(t*t)+distance(t-1)+0.2f*distance(t-2); 
}*/

//IMPLEMENTATION WITH A FOR LOOP 
float distance(int t)
{
    float d[t+1];
    //We know that for t=0 d=0 and for t=1 d=1
        d[0]=0.0f;
        d[1]=1.0f;
        //the for loop fuction that calculates the distance covered
        for (int i=2;i<=t;i++)
            d[i]=0.1f*(i*i)+d[i-1]+0.2f*d[i-2];
            return d[t];
}

int main()
{
    int t=10;
    float y = distance(t);
    printf("The distance covered after 10 minutes is: %.2f km",y);
}