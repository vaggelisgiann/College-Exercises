#include <stdio.h>
#include <string.h>

//Creating the struct User
typedef struct User{
    char name[50];
   struct User* follower;//this pointer points at the next user that the current one is following
}User;

int main()
{
    //Creating the users 
    User giannis;
    strcpy(giannis.name,"Γιάννης");
    giannis.follower=NULL;
    
    User maria;
    strcpy(maria.name,"Μαρία");
    maria.follower=&giannis;
    
    User anna;
    strcpy(anna.name,"Άννα");
    anna.follower=&maria;
        
    User kostas;
    strcpy(kostas.name,"Κώστας");
    kostas.follower=&anna;
    
    //Initializing the pointer user
    User* user = &kostas;
    
    while(user!=NULL)
    {
    printf("%s ",user->name);
    user=user->follower;
    }
    
}