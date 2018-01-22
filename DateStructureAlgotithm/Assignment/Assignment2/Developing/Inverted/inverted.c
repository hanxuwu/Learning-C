/**
 * COMP9024 Assignment2 
 *
 * TASK2 : Inverted
 *  
 * Date: 20/1/2018 
 *
 * Name: HANXU WU
 * 
 * ZID: 5148463
 * 
 * use:  gcc -Wall -lm -Werror *.c  -o pagerank
 * 
 * **/

# include <stdio.h>
# include <string.h>
# include "readfile.h"
# include "InvertedIdx.h"
# include "DLListStr.h"

/*

   removing leading and trailing spaces,
   converting all characters to lowercase,
   remove the following punctuation marks, if they appear at the end of a word:
'.' (dot), ',' (comma), ';' (semicolon), ? (question mark)

*/
Tree normalise(CollectionContext p){
    UrlContext p2;
    Tree wordtree=newTree(); // create the tree to store the inverted
    Tree curTree=NULL;
    for(int i=0;i<p->nPages;i++){ // traverse all the url file
    p2=ReadUrlSection_2(p->urlName[i]); // read the url file section2
    
    printf("%d\n",p2->nWords);
     for(int i=0;i<p2->nWords;i++){ // traverse all the word in url context
        int foundchar=0; // find the word's end
        for(int lword=strlen(p2->words[i]);lword!=-1;lword--){ // travers all the char in each word
        //printf("%d",lword);
        //printf("%c\n",p2->words[i][lword]);
        if((foundchar==0)&&(p2->words[i][lword]!='?')&&(p2->words[i][lword]!='.')&&(p2->words[i][lword]!=',')&&(p2->words[i][lword]!=';')&&(p2->words[i][lword]!='\0')){
            foundchar=1; //end is the first char that not equal to punctuation marks,if find the end other no need to delete
        } 
        if(p2->words[i][lword]>='A'&&p2->words[i][lword]<='Z'){//converting all characters to lowercase
            p2->words[i][lword]+=32;       
        }
        else if((p2->words[i][lword]=='?'||p2->words[i][lword]=='.'||p2->words[i][lword]==','||p2->words[i][lword]==';')&&(foundchar==0))
            p2->words[i][lword]='\0'; // if the end char is  (dot), ',' (comma), ';' (semicolon), ? (question mark) the reassignment the end
        }

        Tree located;
        TreeInsert(wordtree,p2->words[i],&located); // insert the sort to the tree
        printf("*%s \n",located->data);

        // get the name of the url
        char str[100]; // temporaily store the filename
        char buffer[100]; // temporaily convert UrlIndex to char type
        sprintf(buffer,"%d",p2->currentUrl); // convert UrlIndex to char type
        sprintf(str,"%s%s","url",buffer); // join the str 

        //Tree TreeNul;
        //TreeInsert(located->treeurl,str,&TreeNul);

        //add(located->list,str);
        insertSetOrd(located->list,str);//inserted in L, L is ordered (increasing) with no duplicates
        
        //printf("@%s \n",p2->words[i]);
    }
    }
    
    return wordtree;
}

// traverse Tree sideways
void traverseTreeR(Tree t, int depth,FILE * fp) {
   if (t != NULL) {      
      traverseTreeR(left(t), depth+1,fp); // alphabet order so traverse the left branch first
      if(depth!=0) { // no need to write the root
          printf("%s\n", data(t));
          fputs(data(t),fp); // write the word name
          fputs("  ",fp);
          showDLListStr(t->list);
          struct DLListNode * curr;  
          curr = t->list->first->next;
          while(curr->next!=t->list->last){ // traverse  the DLList except the last one
              if(curr != t->list->curr){
                fputs(curr->value,fp); // write the urlname with space
                fputs(" ",fp);
        }
        curr = curr->next;
    }
    fputs(curr->value,fp);   // write the last urlname with out space
    fputs("\n",fp);
    
          };
      traverseTreeR(right(t), depth+1,fp);
   }
}

void writefile(Tree t,char* filename) {
   FILE * fp; // pointer to file 
   if((fp = fopen(filename,"w"))==NULL)  // open the file 
{
    fprintf(stderr,"Can't create output file.\n");
    exit(3);
}
   traverseTreeR(t, 0,fp); // traverse the Tree

   if(fclose(fp)!=0){  // close the file 
    fprintf(stderr,"Error in closing files\n");
}
}



int main(int argc,char * argv[]){

    CollectionContext p;
    p=ReadCollection("collection.txt"); // read the collection file
    printf("the name of the collection in main function\n");
    for(int i=0;i<p->nPages;i++){
        printf("%d ",p->urlName[i]);// check the stored integer name
    }
    printf("\n");
    printf("------SECTION2------");

    // nomolize all the urlcontext    
    Tree wordtree=normalise(p);
    //showTree(wordtree);
    writefile(wordtree,"invertedIndex.txt"); // create the invertedIndex
}