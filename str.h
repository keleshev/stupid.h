 /* 
  * str.h -- stupid string library.
  *
  * Conventions:
  *
  *     Functions ending with _dest:
  *         These functions require destination-string as first argument.
  *         Does not allocate any memory. Requires destination-string
  *         to be big enough to hold the result.
  *
  *     Functions ending with _new:
  *         Return pointer to heap-allocated (malloc) string.
  *         Needs to be freed either using free(s) or using
  *         del(s1, s2, s3, ...) from "del.h". 
  *
  *     Functions ending with _auto:
  *         Return pointer to stack-allocated (alloca) string.
  *         Will be freed automatically (as all automatic variables),
  *         when the functions where they are declared returns.
  *
  *     All other functions:
  *         Do not allocate any memory. No special treatment needed.
  *
  *     Things starting with underscore are reserved.
  *
  */

#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>
#include <stdbool.h>
#include <ctype.h>


 /*
  * str_dest(dest, s) 
  * str_auto(s)
  * str_new(s)
  *
  * Return copy of string s.
  */

char* str_dest(char* dest, char* s) {
    return strcpy(dest, s);
}

//#define str_new(s)  str_dest(malloc(strlen(s) + 1), s)
char* str_new(char* s) {
    return str_dest(malloc(strlen(s) + 1), s);
}

#define str_auto(s) str_dest(alloca(strlen(s) + 1), s)


 /*
  * str_cat_dest(dest, s1, s2)
  * str_cat_new(s1, s2)
  * str_cat_auto(s1, s2)
  *
  * Return catenation result of s1 and s2.
  */

char* str_cat_dest(char* dest, char* s1, char* s2) {
    return strcat(strcpy(dest, s1), s2);
}

char* str_cat_new(char* s1, char* s2) {
    return str_cat_dest(malloc(strlen(s1) + strlen(s2) + 1), s1, s2);
}

#define str_cat_auto(s1, s2) strcat(strcpy(alloca(strlen(s1) + strlen(s2) + 1), s1), s2)


 /*
  * str_sub_dest(dest, s, begin, end) 
  * str_sub_new(s, begin, end)
  * str_sub_auto(s, begin, end)
  *
  * Return substring indexed as [begin:end). 
  */
char* str_sub_dest(char* dest, char* s, signed begin, signed end) {
    if (end - begin < 0) {
        dest[0] = '\0';  // empty string
    } else {
        dest = strncpy(dest, &s[begin], end - begin);
        dest[end-begin] = '\0';
    }
    return dest;
}

char* str_sub_new(char* s, signed begin, signed end) {
    return str_sub_dest(
            malloc(_to_unsigned(end - begin) + 1), s, begin, end);
}

#define str_sub_auto(s, begin, end) \
    str_sub_dest(alloca(_to_unsigned(end - begin) + 1), s, begin, end)
 

 /*
  * str_slice_dest(dest, s, begin, end) 
  * str_slice_new(s, begin, end)
  * str_slice_auto(s, begin, end)
  *
  * Return substring indexed as [begin:end). 
  * Negative begin or end counts from end of string (Python-style).
  *
  * Example:        0   1   2   3   4   5   6
  *                -6  -5  -4  -3  -2  -1   0
  *     char s[] = { 'f' 'o' 'o' 'b' 'a' 'r' };
  *
  *     char* s1 = str_slice_auto(s, 0, 3);  // "foo"
  *     char* s2 = str_slice_auto(s, 3, 6);  // "bar"
  *     char* s3 = str_slice_auto(s,-6,-3);  // "foo"
  *     char* s4 = str_slice_auto(s,-3, 0);  // "bar"
  *     char* s5 = str_slice_auto(s, 1,-1);  // "ooba"
  *     char* s6 = str_slice_auto(s,-1, 1);  // "", negative range.
  */

char* str_slice_dest(char* dest, char* s, signed begin, signed end) {
    signed len = strlen(s);
    if (begin < 0) begin = len + begin;
    if (end == 0) end = len;
    else if (end < 0) end = len + end;
    return str_sub_dest(dest, s, begin, end);
}

char* str_slice_new(char* s, signed b, signed e) {
    return 
     str_slice_dest(
      malloc(_to_unsigned(e - b + strlen(s)*((b < 0) - (e < 0))) + 1), s, b, e);
}

#define str_slice_auto(s, b, e) \
    str_slice_dest( \
     alloca(_to_unsigned(e - b + strlen(s)*((b < 0) - (e < 0))) + 1), s, b, e)

unsigned _to_unsigned(signed x) {
    return (x < 0 ? 0 : x);
}




 /*
  * str_input_dest(dest)
  * str_input_new()
  * str_input_auto()
  */

char* str_input_dest(char* dest) {
    unsigned i = 0;
    while ((dest[i++] = getchar()) != '\n');
    dest[i] = '\0';
    return dest;
}

char* str_input_new() {
    char* str = malloc(1);
    unsigned i = 0;
    /* Quick & dirty.
       Allocating powers of 2 sizes would be better. */
    while ((str[i++] = getchar()) != '\n') 
        str = realloc(str, i + 1);
    str[i] = '\0';
    return str;
}

// HACK i/o and alloca don't go together well 
#define str_input_auto() \
    (char* _d = str_input_new(), char* _a = str_auto(_d), free(_d), _a)
        

 /*
  * str_format_dest(dest, format, ...)
  * str_format_new(format, ...)
  * str_format_auto(format, ...)
  */

#define str_format_dest sprintf
//#define str_format_dest(dest, format, ...) sprintf(dest, format, __VA_ARGS__)

#define str_format_new asprintf
//#define str_format_new(format, ...) asprintf(format, __VA_ARGS__)

// HACK i/o and alloca don't go together well 
#define str_format_auto(format, ...) \
    (char* _d = str_format_new(format, __VA_ARGS__), char* _a = str_auto(_d), free(_d), _a)







 /*
  *
  * Other
  *
  */

#define str_len strlen

bool str_eq(char* s1, char* s2) {
    return (strcmp(s1, s2) == 0);
}

bool str_is_alpha(char* s) {
    unsigned i = 0;
    while(s[i] != '\0') if(!isalpha(s[i++])) return false;
    return true;
}












/* Python strings methods:
'capitalize', 'center', 'count', 'decode', 'encode', 'endswith', 'expandtabs', 'find', 'format', 'index', 'isalnum', 'isalpha', 'isdigit', 'islower', 'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower', 'lstrip', 'partition', 'replace', 'rfind', 'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip', 'split', 'splitlines', 'startswith', 'strip', 'swapcase', 'title', 'translate', 'upper', 'zfill'
*/


#endif // guard