# include <stdlib.h>
/*

readfile 

*/
#define MAX 1000

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


typedef struct CollectionContextRep * CollectionContext;
typedef struct UrlContextRep * UrlContext; 

CollectionContext ReadCollection(char * filename); // read the collection file
UrlContext ReadUrlSection_1(int UrlIndex); // read the url file section1
UrlContext ReadUrlSection_2(int UrlIndex);// read the url file section2
char * normalizeString(char *); // normalize the string,convert it to converting all characters to lowercase,remove the following punctuation marks