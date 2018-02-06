# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int main(int argc,char * argv[]){
    char *** a;
    char *b[] ={"abc","defg","hijkl","mnop","qrst","app","ban","pea","wat","lem","abc","defg","hijkl","mnop","qrst","app","ban","pea","wat","lem"};

    a=malloc(10*sizeof(char**));
    for(int i=0;i<10;i++){
    printf("%s\n",b[i]);
    int c = strlen(b[i]);
    char *new = malloc(sizeof(c));
    strcpy(new,b[i]);
    printf("wordlen:%d\n",c);    
    a[i] = &new;    
    printf("%s\n",*a[0]);
    }

    for(int h=0;h<10;h++){
        printf("%s\n",(*a)[h]);
        printf("@@%s\n",(*a)[0]);
       
    }
    int d=sizeof(char);
    printf("%d\n",d);

}