# include <stdio.h>
# include <assert.h>
# include <string.h>
# include "readfile.h"


/*
structure to store the Colletion.txt
*/
typedef struct CollectionContextRep{
    int nPages; // store the name of the url
    int * urlName; // store the digit name of the url
}CollectionContextRep;

/*
structure to store the urlXX.txt
*/
typedef struct UrlContextRep{
    int currentUrl; // current url integer name
    int nUrl; // the number of the current url linked
    int * coUrlName;  // corresponding "web page" name
    int nWords; // the number of the section contexts   
    char ** words; // store the context of the url
}UrlContextRep;


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
        puts(words); // print the context        
        pCol->nPages++; // count the number of url
    }
    printf("the words now is %s\n",words);
    printf("\nafter first count the number then rewind to build array\n\n"); 
    
    // store the integer name of the url
    pCol->urlName = malloc(pCol->nPages*sizeof(int)); // create the array to store the integer urlName
    rewind(fp);// from the file start
    int index=0; // array index;
    while(fscanf(fp,"%s",words)==1) {  //read the body of a section
        puts(words);   // print the file content
        sscanf(words,"%s",buf); // save the each section to buffer
        pCol->urlName[index]=(atoi)(buf+3); //keep the interger name of the url then convert to int
        index++; // count the number of url
        };

    printf("number of pages in %s file  is %d  \n",filename,pCol->nPages);
    printf("there name is\n");
    for (int i=0;i<pCol->nPages;i++) //print the url name
    printf("%d ",pCol->urlName[i]);
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
    printf("\n@@@%s\n",str); // joined string (the filename)
    
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
                puts(words);
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
                
                puts(words);   // print the file content
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

    printf("number of pages in %s file  is %d  \n",str,pUrl->nUrl);
    printf("there name is\n");
    for (int i=0;i<pUrl->nUrl;i++) //print the url name
    printf("%d ",pUrl->coUrlName[i]);
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
    pUrl->words =0;
   
    /*
    open the file
    */
    char str[100]; // temporaily store the filename
    char buffer[100]; // temporaily convert UrlIndex to char type
    sprintf(buffer,"%d",UrlIndex); // convert UrlIndex to char type
    sprintf(str,"%s%s%s","url",buffer,".txt"); // join the str 
    printf("\n@@@%s\n",str); // joined string (the filename)
    
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
                puts(words);
                }else {
                    endflag=1; // change the find flag;
                    break;
                } 
            }
        }
        sprintf(tempwords,"%s",words);
    }
    printf("number of pages in %s file  is %d  \n",str,pUrl->nWords);

     /*
    Store the integer name of url
    */
    pUrl->words = malloc(pUrl->nUrl*sizeof(char *)); // create the array to store the integer urlName
    rewind(fp);// from the file start
    int index=0; // array index;
    char buf[100];// buf to store the sscanf 
    sprintf(tempwords,"%s","");//initial the tempword
    endflag=0; // if find #word the assign flag =1 

    while(fscanf(fp,"%s",words)==1&&endflag==0){ //read the body of a section
        if((strcmp(words,"Section-2")==0)&&(strcmp(tempwords,"#start")==0)){ //start Detection start from the "Section-2 #start"
            while(fscanf(fp,"%s",words)==1){
                if((strcmp(words,"#end")!=0)){ // haven't find the "#end"
                
                puts(words);   // print the file content                
                sscanf(words,"%s",buf); // save the each section to buffer
                
                char * new= malloc(sizeof(words)*sizeof(char));// allocate memory depends on the size of the context
                strcpy(new,words); // copy the context
                int a=strlen(buf);
                int b=strlen(words);
                printf("buf:%d\n",a);
                printf("word:%d\n",b);
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
    
    return pUrl;
}


int main(void){
    CollectionContext p;
    p=ReadCollection("collection.txt"); // read the collection file
    printf("%d\n",p->nPages);// check the nPages
    printf("%d %d",p->urlName[0],p->urlName[1]); // check the array
    ReadUrlSection_1(34);
    printf("------------------------");
    UrlContext p2;
    p2=ReadUrlSection_2(34);
    for(int i=0;i<p2->nWords;i++){
        printf("%s ",p2->words[i]);
    }
    return 0;
}
