# include <stdio.h>
# include <stdlib.h>


/*

12/1/2018  

C Primer Plus 13.1  


calling this function

gcc -c count.c         generate count.o

gcc count.c -o love     generate love.exe

execute: ./love test.txt

output: 123456789File test.txt has 9 characters

execute: ./love test2.txt
1 2 3 4 5 6 7 8 9File test2.txt has 17 characters

*/

int main(int argc,char *argv[]){
    int ch;
    FILE *fp; // stdio.h 中定义的一种派生类型
              // 指针fp并不指向实际的文件，而是指向一个关于文件的信息的数据包
    long count = 0;

    if(argc!=2){
        printf("Usage:%s filename\n",argv[0]);
        exit(1);
    }
//  如果不能打开文件，fopen 返回空指针
// 磁盘已满，文件名非法，存取权限不够或者硬件问题等都会导致 fopen失败

    if((fp=fopen(argv[1],"r"))==NULL){ // "r":read only "w":write "r+":read and write
        printf("Can't open %s\n",argv[1]);
        exit(1);
    }

    // ch = getchar();  从标准输入获得一个字符
    // ch = getc(fp);  从指针fp指定的文件中获得一个字符
    // putc (ch,fpout); 表示将字符ch写入到FILE指针fpout 指定的文件中


    while((ch = getc(fp))!=EOF){ // 到达结尾 getc()函数会返回一个特殊值EOF
        putc(ch,stdout); // 处理输入   相当于 print
        count++;
    }
     

    if(fclose(fp)!=0)// 关闭由指针 fp 指定的文件，同时根据需要刷新缓冲区
     printf("Error in closing file %s \n",argv[1]);


    printf("File %s has %ld characters\n",argv[1],count);
    return 0;
} 


