# include <stdio.h>
# include <assert.h>
# include <string.h>
# include "readfile.h"


//read the collection.txt
CollectionContext ReadCollection(char * filename){
    FILE *fp; // pointer to file
    CollectionContext pCol; // pointer to collection struction
    char words[MAX];// store the vertex name
    char buf[100];// buf to store the sscanf 
    
    pCol = malloc(sizeof(CollectionContextRep));//create Collection struction
    assert(NULL!=pCol);
    pCol->nPages = 0; // inital the collection structure 
    pCol->urlName = NULL;
    
    if ((fp=fopen(filename,"r"))==NULL){ // check the file  could be open or not
        fprintf(stderr,"Can't open file \" %s \" \n",filename);
        exit(1);
    }

    // count the number of url
    while(fscanf(fp,"%s",words)==1){  //read the body of a section
        puts(words); // print the context TODO:        
        pCol->nPages++; // count the number of url
    }
    printf("the words now is %s\n",words);//TODO:
    printf("\nafter first count the number then rewind to build array\n\n"); //TODO:
    
    // store the integer name of the url
    pCol->urlName = malloc(pCol->nPages*sizeof(int)); // create the array to store the integer urlName
    rewind(fp);// from the file start
    int index=0; // array index;
    while(fscanf(fp,"%s",words)==1) {  //read the body of a section
        puts(words);   // print the file content TODO:
        sscanf(words,"%s",buf); // save the each section to buffer
        pCol->urlName[index]=(atoi)(buf+3); //keep the interger name of the url then convert to int
        index++; // count the number of url
        };

    printf("number of pages in %s file  is %d  \n",filename,pCol->nPages);//TODO:
    printf("there name is\n");//TODO:
    for (int i=0;i<pCol->nPages;i++) //print the url name//TODO:
    printf("%d ",pCol->urlName[i]);//TODO:
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n"); // check if the file close
    return pCol;
}

// read urlXXX.txt section_1
UrlContext ReadUrlSection_1(int UrlIndex){
    /*
    Initilization
    */
    FILE * fp;//pointer to file
    UrlContext pUrl; // pointer to Url structure
    char words[MAX];// store the vertex name

    pUrl = malloc(sizeof(UrlContextRep)); // allocate memory for the url structure;
    assert(NULL!=pUrl);
    pUrl->currentUrl = UrlIndex; // initial current str index
    pUrl->nUrl = 0;  // initial number of the url linked
    pUrl->coUrlName = NULL; // initial the corresponding "web page" name
    
    /*
    open the file
    */
    char str[100]; // temporaily store the filename
    char buffer[100]; // temporaily convert UrlIndex to char type
    sprintf(buffer,"%d",UrlIndex); // convert UrlIndex to char type
    sprintf(str,"%s%s%s","url",buffer,".txt"); // join the str 
    printf("\n@@@%s\n",str); // joined string (the filename)TODO:
    
    if((fp=fopen(str,"r"))==NULL){  //TODO: learn how to strcat
     fprintf(stderr,"Can't open file \" url%d \" \n",UrlIndex);
     exit(1);    
    }
    
    /*
    count the number of url in  the section-1
    */
    char tempwords[1000]=""; // tempory store the char urlname
    int endflag=0; // if find #word the assign flag =1 
    while(fscanf(fp,"%s",words)==1&&endflag==0){ //read the body of a section
        if((strcmp(words,"Section-1")==0)&&(strcmp(tempwords,"#start")==0)){ //start Detection start from the "Section-1 #start"
            while(fscanf(fp,"%s",words)==1){
                if((strcmp(words,"#end")!=0)){ // haven't find the "#end"
                pUrl->nUrl++; // count the number of url
                puts(words);//TODO:
                }else {
                    endflag=1; // change the find flag;
                    break;
                } 
            }
        }
        sprintf(tempwords,"%s",words);
    }

    /*
    Store the integer name of url
    */
    pUrl->coUrlName = malloc(pUrl->nUrl*sizeof(int)); // create the array to store the integer urlName
    rewind(fp);// from the file start
    int index=0; // array index;
    char buf[100];// buf to store the sscanf 
    sprintf(tempwords,"%s","");//initial the tempword
    endflag=0; // if find #word the assign flag =1 
    
    while(fscanf(fp,"%s",words)==1&&endflag==0){ //read the body of a section
        if((strcmp(words,"Section-1")==0)&&(strcmp(tempwords,"#start")==0)){ //start Detection start from the "Section-1 #start"
            while(fscanf(fp,"%s",words)==1){
                if((strcmp(words,"#end")!=0)){ // haven't find the "#end"
                
                puts(words);   // print the file content //TODO:
                sscanf(words,"%s",buf); // save the each section to buffer
                pUrl->coUrlName[index]=(atoi)(buf+3); //keep the interger name of the url then convert to int
                index++; // count the number of url
                }else {
                    endflag=1; // change the find flag;
                    break;
                } 
            }
        }
        sprintf(tempwords,"%s",words);
    }

    printf("number of pages in %s file  is %d  \n",str,pUrl->nUrl);//TODO:
    printf("there name is\n");//TODO:
    for (int i=0;i<pUrl->nUrl;i++) //print the url name//TODO:
    printf("%d ",pUrl->coUrlName[i]);//TODO:
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n"); // check if the file close
    return pUrl;
}

// read urlXXX.txt section_1 and section_2
UrlContext ReadUrlSection_2(int UrlIndex){
    /*
    Initilization
    */
    FILE * fp;//pointer to file
    UrlContext pUrl; // pointer to Url structure
    pUrl = ReadUrlSection_1(UrlIndex);
    pUrl->nWords = 0; // initialize the number of the words
    pUrl->words =NULL;
   
    /*
    open the file
    */
    char str[100]; // temporaily store the filename
    char buffer[100]; // temporaily convert UrlIndex to char type
    sprintf(buffer,"%d",UrlIndex); // convert UrlIndex to char type
    sprintf(str,"%s%s%s","url",buffer,".txt"); // join the str 
    printf("\n@@@%s\n",str); // joined string (the filename)TODO:
    
    if((fp=fopen(str,"r"))==NULL){  //TODO: learn how to strcat
     fprintf(stderr,"Can't open file \" url%d \" \n",UrlIndex);
     exit(1);    
    }
    
    
    /*
    count the number of url in  the section-1
    */
    char words[MAX];// temporily store the section content
    char tempwords[1000]=""; // tempory store the char urlname
    int endflag=0; // if find #word the assign flag =1 
    while(fscanf(fp,"%s",words)==1&&endflag==0){ //read the body of a section
        if((strcmp(words,"Section-2")==0)&&(strcmp(tempwords,"#start")==0)){ //start Detection start from the "Section-2 #start"
            while(fscanf(fp,"%s",words)==1){
                if((strcmp(words,"#end")!=0)){ // haven't find the "#end"
                pUrl->nWords++; // count the number of url
                puts(words);//TODO:
                }else {
                    endflag=1; // change the find flag;
                    break;
                } 
            }
        }
        sprintf(tempwords,"%s",words);
    }
    printf("number of pages in %s file  is %d  \n",str,pUrl->nWords);//TODO:

     /*
    Store the integer name of url
    */
    
    pUrl->words = malloc(pUrl->nWords*sizeof(char *)); // create the array to store the integer urlName
    assert(NULL!=pUrl->words);
    rewind(fp);// from the file start
    int index=0; // array index;
    char buf[100];// buf to store the sscanf 
    sprintf(tempwords,"%s","");//initial the tempword
    endflag=0; // if find #word the assign flag =1 

    while(fscanf(fp,"%s",words)==1&&endflag==0){ //read the body of a section
        if((strcmp(words,"Section-2")==0)&&(strcmp(tempwords,"#start")==0)){ //start Detection start from the "Section-2 #start"
            while(fscanf(fp,"%s",words)==1){
                if((strcmp(words,"#end")!=0)){ // haven't find the "#end"
                
                puts(words);   // print the file content        TODO:        
                sscanf(words,"%s",buf); // save the each section to buffer
                
                char * new= malloc(sizeof(words)*sizeof(char));// allocate memory depends on the size of the context          
                strcpy(new,words); // copy the context
                int a=strlen(buf);//TODO:
                int b=strlen(words);//TODO:
                printf("buf:%d\n",a);//TODO:
                printf("word:%d\n",b);//TODO:          
                pUrl->words[index]=new; 
                index++; // count the number of url
                }else {
                    endflag=1; // change the find flag;
                    break;
                } 
            }
        }
        sprintf(tempwords,"%s",words);
    }
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n"); // check if the file close
    return pUrl;
}


/*

   removing leading and trailing spaces,
   converting all characters to lowercase,
   remove the following punctuation marks, if they appear at the end of a word:
'.' (dot), ',' (comma), ';' (semicolon), ? (question mark)

*/
char * normalizeString(char * word){
    int foundchar=0;
    int lword;
    for(lword=strlen(word);lword!=-1;lword--){ // travers all the char in each word
        //printf("%d",lword);
        //printf("%c\n",p2->words[i][lword]);
        if((foundchar==0)&&(word[lword]!='?')&&(word[lword]!='.')&&(word[lword]!=',')&&(word[lword]!=';')&&(word[lword]!='\0')){
            foundchar=1; //end is the first char that not equal to punctuation marks,if find the end other no need to delete
        } 
        if(word[lword]>='A'&&word[lword]<='Z'){//converting all characters to lowercase
            word[lword]+=32;       
        }
        else if((word[lword]=='?'||word[lword]=='.'||word[lword]==','||word[lword]==';')&&(foundchar==0))
            word[lword]='\0'; // if the end char is  (dot), ',' (comma), ';' (semicolon), ? (question mark) the reassignment the end
        }
        return word;

}