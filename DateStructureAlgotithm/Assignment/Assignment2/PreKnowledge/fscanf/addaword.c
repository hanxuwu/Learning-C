/*
addaword.c  使用fprintf(),fscanf(),和rewind() 函数

gcc addaword.c -o addaword            generate  addaword.exe

./addaword   

Enter words to add to the file;
press the Enterkey at the beginning of a line to terminate.


qwertyuiop


file contents:
qwertyuiop


generate word

*/


# include <stdio.h>
# include <stdlib.h>
# define MAX 40
int main(void){
    FILE *fp;
    char words[MAX];

    if((fp=fopen("word","a+"))==NULL){ //程序可以对文件进行读写操作
        fprintf(stdout,"Can't open \"word\" file.\n");
        exit(1);
    }

    puts("Enter words to add to the file;press the Enter");
    puts("key at the beginning of a line to terminate.");
    while(gets(words)!=NULL && words[0]!='\0') //键入空行 gets() 函数将数组第一个元素置为空字符，程序据此来终止循环 
        fprintf(fp,"%s ",words);
    puts("file contents:");
    rewind(fp); // 回到文件开始处
    while(fscanf(fp,"%s",words)==1)
        puts(words);
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n");
    return 0;


}