# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int main(void){
    char *a[] = {"May","the","force","be","with","you"};
    char **b=NULL;

    b = malloc(sizeof(char*));
    for(int i=0;i<6;i++){
        char * new = malloc(sizeof(a[i]));
        strcpy(new,a[i]);
        b[i] = new;
        printf("%s ",b[i]);
        
    }

    

}