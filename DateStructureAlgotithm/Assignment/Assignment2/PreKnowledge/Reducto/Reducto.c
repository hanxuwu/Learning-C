# include <stdio.h>
# include <stdlib.h> // 调用 exit()
# include <string.h> // 为 strcpy() 和 strcat() 函数提供原型
# define LEN 40
/*

文件压缩程序

gcc Reducto.c -o Recucto       Generate  Reducto.exe


./Reducto test.txt


input:abcdefghijklmnopq     (text.txt)

output:adgjmp     (text.txt.red)



*/
int main(int argc, char * argv[]){

   FILE * in,* out;  // 声明FILE 指针  同时打开两个文件
   int ch;
   char name[LEN];  // 用于存储用户名
   int count = 0;

// 检查命令行
if (argc<2){
    fprintf(stderr,"Usage:%s filename\n",argv[0]);
    exit(1);
}

// input
if((in = fopen(argv[1],"r"))==NULL){
    fprintf(stderr,"I couldn't open file \"%s\" \n",argv[1]);
    // 使用 stderr 指针把错误消息发送到标准错误文件
    exit(2);
}

// output

strcpy(name,argv[1]); // 把文件名复制到数组中
strcat(name,".red"); // 在文件名后添加 .red
if((out = fopen(name,"w"))==NULL) //打开文件以写入
{
    fprintf(stderr,"Can't create output file.\n");
    exit(3);
}

// copy the data
while((ch=getc(in))!=EOF)
    if(count++%3==0)
        putc(ch,out); //打印每三个字符中的一个


if(fclose(in)!=0||fclose(out)!=0){
    fprintf(stderr,"Error in closing files\n");
}

}







