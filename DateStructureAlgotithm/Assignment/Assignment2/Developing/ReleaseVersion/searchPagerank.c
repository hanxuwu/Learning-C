/**
 * COMP9024 Assignment2 
 *
 * TASK3 : SearchPagerank
 *  
 * Date: 23/1/2018 
 *
 * Name: HANXU WU
 * 
 * ZID: 5148463
 * 
 * use:  gcc -Wall -lm -Werror *.c  -o searchPagerank
 * 
 * **/

# include <stdio.h>
# include <string.h>
# include <assert.h>
# include "readfile.h"
# include "InvertedIdx.h"
# include "DLListStr.h"

#define MAX_OUT_NUMBER 30


typedef struct SearchStructRep{
    int nSearchWord; // the number of the words input
    char * SearchWord; // input keywords
    int nUrlIndex; // number of the last keywords
    DLListStr urlIndex; // search result of the last keywords
    int nSetUrlIndex;  // number of the current keywords
    DLListStr SetUrlIndex; // search result of the intersection of last keywords and current 
}SearchStructRep;

typedef struct SearchStructRep * SearchStruct;

/*

Initialize the SearchStruct

*/


SearchStruct initSearchStruct(int argc){
    SearchStruct new= malloc(sizeof(SearchStructRep));
    new->nSearchWord = argc-1; // the number of the words need searching
    new->SearchWord = NULL;
    new->nUrlIndex =0;
    new->urlIndex = newDLListStr(); // all the urlindex
    new->nSetUrlIndex =0;
    new->SetUrlIndex = newDLListStr(); // all urlindex set
    return new;
}

int CheckandCount(char *url,SearchStruct *sst){
    char * new = malloc(sizeof(char*));
    assert(NULL!=new);
    strcpy(new,url); // copy the url name
    (*sst)->nUrlIndex++;
    add((*sst)->urlIndex,new); // all the url
    
    if(insertSetOrd((*sst)->SetUrlIndex,new)==1) (*sst)->nSetUrlIndex++;  // without duplicated
    
    return 0;
}

/*

store all search result to DLList

*/

int findIntersectionIndex(char* filename,char* keywords,SearchStruct *sst){
    FILE * fp; // pointer to file
    if((fp=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Can't open file \"%s \" ",filename);
        exit(1);
    }
    // count the number of url
    char delim[2] = " ";// the dividor
    int endflag=0;
    int findflag=0; // find the words 
    char buffer[512]; 
    while(fgets(buffer,511,fp)!=NULL&&endflag==0){ //read the body by lines
        //printf("%s",buffer);//TODO: 
        if ((strstr(buffer, keywords))){ // find the keywords
            
            char *url = strtok(buffer,delim); //get token 
            if(strcmp(url,keywords)==0){ // ensure it's keysword not like   "dd" find "add"
            findflag=1;
            //printf("@%s\n",url);//TODO:
            
            while((url=strtok(NULL,delim))&&(strstr(url,"url")!=NULL)){ // get rid of the empty token
            CheckandCount(url,sst); // add to the DLLlist
            //printf("@%s\n",url);//TODO:
            }
            break;
            }
        }
        
       
        //sprintf(tempwords,"%s",words);
    }
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n"); // check if the file close
    if(findflag==0) return 1; // no word in the index
    return 0;

}

DLListStr  urlIndexCounter(SearchStruct *sst,int target){
     DLListStr new=newDLListStr(); // DDList store the  result
     int nUrlIndex=(*sst)->nUrlIndex; 
     //printf("%d\n",nUrlIndex);//TODO:
     int nSetUrlIndex=(*sst)->nSetUrlIndex;
     //printf("%d\n",nSetUrlIndex);//TODO:
     DLListNode * currset;
     currset = (*sst)->SetUrlIndex->first->next->next; // first->next is cursor
     char *current =malloc(sizeof(char*));
     int i;
     for(i=0;i<nSetUrlIndex;i++){
        strcpy(current,currset->value);
        //printf("^^^^^^^^^^^^^%s\n",current);//TODO:
        DLListNode * currall;
        currall=(*sst)->urlIndex->first->next; // traverse all the list
        int counter=0;
        int j;
        for(j=0;j<nUrlIndex;j++){
            int intc=(atoi)(current+3);
            int inta=(atoi)(currall->value+3);
            //if(strcmp(current,currall->value)==0) counter++; // if the result show N times,it's the final result
            if(inta==intc) counter++;  // compate the number otherwize the space may effect the result
            //printf("***%d\n",counter);
            currall=currall->next;
        }
        //if (counter==(*sst)->nSearchWord) add(new,current);
        if (counter==target) add(new,current);
        currset=currset->next;
    }
     //printf("--------------------------------");//TODO:
     //showDLListStr(new);//TODO:
     //printf("%d",new->nitems);//TODO:
     free(current);
     return new;
}

char * getthepangrank(char* filename,DLListStr list,int* nprint){
    if (*nprint==MAX_OUT_NUMBER) return NULL;
    FILE * fp; //pointer to file
    char words[MAX];// store the vertex name
    
    if((fp=fopen(filename,"r"))==NULL){
        fprintf(stderr,"Can't open file \"%s\" \n",filename);
    }
    DLListNode * current;
    current=list->first->next;
    //int index=0;
    
        char * normalwords=malloc(1000*sizeof(char));
        char * currentkeyword = current->value;
        while(fscanf(fp,"%s",words)==1){
            
            strcpy(normalwords,words); // for normalize
            normalizeString(normalwords); // delete the comma
            //printf("\n**%s\n",normalwords);
            
            if ((strstr(words, "url"))) {
                //printf("\n**%s\n",normalwords);
                int i;
                for(i=0;i<list->nitems;i++){
                //printf("\n---%s***%s\n",currentkeyword,words);
                int intc=(atoi)(currentkeyword+3);
                int inta=(atoi)(normalwords+3);
                //if(strcmp(currentkeyword,normalwords)==0){
                if(inta==intc){
                    //printf("\n---%s***%s\n",currentkeyword,words);
                    //fprintf(stdout,currentkeyword);
                    //printf("%s",new[0]);
                    //strcpy(new,words);
                    //printf("%s\n",normalwords);
                    fprintf(stdout,"%s\n",normalwords);
                    //index++;
                    (*nprint)++;
                    if (*nprint==MAX_OUT_NUMBER) return NULL;
                    current=list->first->next;
                    currentkeyword = current->value;
                    break;
                    
                    
                }
                current=current->next;
                currentkeyword = current->value;
                
                
                
                
                }
                current=list->first->next;
                currentkeyword = current->value;
                
                
            //printf(words);
            }

        }
        


    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n"); // check if the file close
    free(normalwords);
    return NULL;

}






int main(int argc,char * argv[]){
    
    //Normalize the string input to lowercase and get rid of the precision comma;
    
    if(argc>1){
        SearchStruct sst = initSearchStruct(argc); // initialize the Search struct
        int i;
        for(i=1;i<argc;i++){
            //printf("***********%s***********",argv[i]);//TODO:
            normalizeString(argv[i]);
            //printf("%s\n",argv[i]);
            findIntersectionIndex("invertedIndex.txt",argv[i],&sst);
            //if(flag==1){
            //    fprintf(stderr,"There is no such word in index");
            //    exit(0);
            //}
        }
        //showDLListStr(sst->urlIndex);//TODO:
        //showDLListStr(sst->SetUrlIndex);   //TODO:
        int ncount;
        int nprint;
        nprint=0;
        for(ncount=(sst)->nSearchWord;ncount>0;ncount--){
        DLListStr urllist=urlIndexCounter(&sst,ncount);
        //printf("%d",ncount);
        //showDLListStr(urllist);
        getthepangrank("pagerankList.txt",urllist,&nprint);
        }

    }
    else{
        fprintf(stderr,"No words,Incorrect input");
        exit(1);
    }
    return 0;
    
    
}