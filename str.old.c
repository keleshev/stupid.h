#include <stdio.h>
#include <alloca.h>
#define log(v) printf("\n[%s:%d] " #v " == " "%s \n", __func__, __LINE__, v)

typedef char* str;
char *_uniq;
#define concat(a,b) (_uniq = alloca(strlen(a)+strlen(b)+1), strcat(_uniq,a), strcat(_uniq,b), _uniq)

#define array_len(x) (sizeof(x)/sizeof(*(x)))
#define logd(a) printf(" %d ",a)

#define map2(f,a) for(int _i=0; _i<array_len(a); _i++) a[_i]=f(a[_i])
#define map(f,a) _a2; for(int _i=0; _i<array_len(a); _i++) _a2[_i]=f(a[_i]) 
#define foreach(f,a) for(int _i=0; _i<array_len(a); _i++) f(a[_i])

#define square(x) ((x)*(x))
//int square(int x) {return x*x;}

int main() {
    int ar[] = {1, 2, 3, 4, 5};
    int _a2[5];
    char s[] = "Spam & eggs";

    foreach(putchar, s);

    int r[array_len(ar)];
    r = map(square,ar);

    foreach(logd,ar);
    printf("\n========\n");
    


    str a = "h";
    str b = "alsdkfja";
    printf("%u",(unsigned)sizeof(b));   log(b);
    
    //str s = concat(a,b);
    //str s = (_uniq = alloca(sizeof(a)+sizeof(b)+1), strcat(_uniq,a), strcat(_uniq,b), _uniq);
    
    //log(s);log(_uniq); 

}

/*

typedef char* str;


str str(str s) {} 

int str_len(str s) {} 

str str_new( len) {}

void str_del(str s) {} 

str str_sub(str s, int begin, int end) {}

str str_con(str s1, str s2, ...) {}


str s = str_con

str s = str("ha-ha");
str c = str(s);
str w = str_sub(s, 1, -3);
str e = str_con(s, c);
bool n = str_eq(s, e);
int pos = str_srch(":", s);
pos = str_srch_back(":", s);
str spc = str_trunc("  bla  \n", " \n\t");
str str_whsp = str(" \n\r\t");
str m = str_match(s, "*.rkt");

s = str_app(s, "other");

del(s,c,w,e,spc,str_whsp,m);
 */


f = str_new("foo");

fb = str_concat_new(f, "bar");

oo = str_sub_new(fb, 1, 3);

b = str_eq(oo, "oo");

del(f, fb, oo);


