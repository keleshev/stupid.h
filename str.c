#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#include "nargs.c"
#include "del.c"

#define log(v)  printf("\n[%s:%d] " #v " == " "%s \n", __func__, __LINE__, v)
#define logd(v) printf("\n[%s:%d] " #v " == " "%d \n", __func__, __LINE__, v)


#define str_auto(s) strcpy(alloca(strlen(s) + 1), s)

#define str_cat_auto(s1, s2) strcat(strcpy(alloca(strlen(s1) + strlen(s2) + 1), s1), s2)

char *_uniq;
#define str_sub_auto(s, begin, end) \
    (_uniq = alloca(end-begin+1), strncpy(_uniq, &s[begin], end-begin), _uniq[end-begin]=0, _uniq) 

#define str_input_auto() "..."

char* str_new(char* s) {
    return strdup(s);
    //return strcpy(malloc(strlen(s) + 1), s);
}

char* str_cat_new(char* s1, char* s2) {
    return strcat(strcpy(malloc(strlen(s1) + strlen(s2) + 1), s1), s2);
}

char* str_sub_new(char* s, unsigned begin, unsigned end) {
    char* r = strncpy(malloc(end - begin + 1), &s[begin], end-begin);
    r[end-begin] = '\0';
    return r;
}

char* str_input_new() {
    char* str = malloc(1);
    char c;
    unsigned i = 0;
    /* Quick & dirty.
       Allocating powers of 2 sizes would be better. */
    while ((str[i++] = getchar()) != '\n') 
        str = realloc(str, i + 1);
    str[i] = '\0';
    return str;
}

char* str_format_new() {
    //asprintf...
}

/*
'capitalize', 'center', 'count', 'decode', 'encode', 'endswith', 'expandtabs', 'find', 'format', 'index', 'isalnum', 'isalpha', 'isdigit', 'islower', 'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower', 'lstrip', 'partition', 'replace', 'rfind', 'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip', 'split', 'splitlines', 'startswith', 'strip', 'swapcase', 'title', 'translate', 'upper', 'zfill'
*/

int main() {

    char* s1 = "one two three";
    char* s2 = "five six seven";

    log(str_auto(s2));
    log(str_cat_auto(s1, s2));
    log(str_sub_auto(s1, 4, 13));
    log(str_sub_auto(str_cat_auto(s1, s2), 8, 17));

    log(str_new(s2));
    log(str_cat_new(s1, s2));
    log(str_sub_new(s1, 4, 13));
    log(str_sub_new(str_cat_new(s1, s2), 8, 17));

    log(str_input_new());

    char* sd = str_new("to be deletedto be deleted");
    char* sd1= str_new("to be deleted");
    char* sd2= str_new("to be deleted");
    delete(sd, sd1, sd2);

    //del(sd);
    null(sd,sd1,sd2);
    logd(sd == NULL);
    logd(sd1 == NULL);
    logd(sd2== NULL);
    log("...");

    //if (NARGS(1,2,3) == 3) printf("args ok.");

}
