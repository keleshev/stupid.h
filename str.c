#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>
#define log(v) printf("\n[%s:%d] " #v " == " "%s \n", __func__, __LINE__, v)

char *_uniq;

#define str_auto(s) \
    (_uniq = alloca(strlen(s) + 1), strcpy(_uniq, s), _uniq) 

#define str_cat_auto(s1, s2) \
    (_uniq = alloca(strlen(s1) + strlen(s2) + 1), strcpy(_uniq, s1), strcat(_uniq, s2), _uniq)

#define str_sub_auto(s, begin, end) \
    (_uniq = alloca(end-begin+1), strncpy(_uniq, &s[begin], end-begin), _uniq[end-begin]=0, _uniq) 

#define str_input_auto() "..."

char* str_new(char* s) {
    return strcpy(malloc(strlen(s) + 1), s);
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
    /*while (c = getchar(), c != '\n') {
        str[i++] = c;
        str = realloc(str, 1+i);
    }*/
    while ((str[i++] = getchar()) != '\n') 
        str = realloc(str, i + 1);
    str[i] = '\0';
    return str;
}


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
}
