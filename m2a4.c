#include <stdio.h>
#include <stdlib.h>

typedef struct Playerstats {
    float goals;
    float fouls;
}Playerstats;

//The function that initializes and creates the array containing the number of players and their stats
void create_array(Playerstats*** array, int* N, int* M)
{
    int i,j;
    do{
        printf("Please enter the columns (N): ");
        scanf("%d",N);
    }while(*N<=0);
    
    do{
        printf("Please enter the rows (M): ");
        scanf("%d",M);
    }while(*M<=0);
    
    *array=(Playerstats**)malloc((*N)*sizeof(Playerstats*));
    for (i=0;i<(*N);i++)
        (*array)[i]=(Playerstats*)malloc((*M)*sizeof(Playerstats));
    
    //Entering values to the array
    
    for (i=0;i<(*N);i++)
    {
        for (j=0;j<(*M);j++)
        {
            printf("Player %d, Match %d (goals fouls): ", i+1, j+1);
            scanf("%f %f",&(*array)[i][j].goals,&(*array)[i][j].fouls);
        }
    }
    
//this struct creates the variables that calculate the sums and averages of the goals and fouls per player
}
typedef struct Playersummary{
    float sumGoals;
    float sumFouls;
    float avgGoals;
    float avgFouls;
} Playersummary;

//This function calculates the sum and the average of the goals and fouls
Playersummary* playerstats (Playerstats** array, int n, int m)
{
    int i,j;
    
    Playersummary* result = (Playersummary*)malloc(n*sizeof(Playersummary));
    
    for (i=0;i<n;i++)
    {
        float sumGoals = 0;
        float sumFouls = 0;

        
        for (j=0;j<m;j++)
        {
            sumGoals+=array[i][j].goals;
            sumFouls+=array[i][j].fouls;
        }
        result[i].sumGoals = sumGoals;
        result[i].sumFouls = sumFouls;
        result[i].avgGoals = sumGoals / m;
        result[i].avgFouls = sumFouls / m;
        
    }
    return result;
}


int main()
{
    Playerstats** arr;
    int m,n,i,j;
    
    Playersummary* stats;
    
    create_array(&arr,&n,&m);
    stats=playerstats(arr,n,m);
    
    printf("Player stats: \n");
    for (i = 0; i < n; i++)
{
    printf("Player #%d -> Total goals: %.2f, Total fouls: %.2f, Average goals: %.2f, Average fouls: %.2f\n",
           i+1, stats[i].sumGoals, stats[i].sumFouls, stats[i].avgGoals, stats[i].avgFouls);
}
    
//Freeing the created arrays
    for (i=0;i<n;i++)
        free(arr[i]);
        
    free(arr);
    
    free(stats);
    
    return 0;
}