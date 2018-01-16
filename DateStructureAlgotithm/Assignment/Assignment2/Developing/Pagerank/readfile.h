# include <stdlib.h>
/*

readfile 

*/
#define MAX 1000


typedef struct CollectionContextRep * CollectionContext;
typedef struct UrlContextRep * UrlContext; 

CollectionContext ReadCollection(char * filename); // read the collection file
UrlContext ReadUrlSection_1(int UrlIndex); // read the url file section1
UrlContext ReadUrlSection_2(int UrlIndex);// read the url file section2