#include <stdarg.h>
#include "nargs.c"

 /*
  * del(...) 
  *
  * Will free() and null() all its arguments.
  * (works with 1 to 16 arguments)
  *
  * E.g. del(a,b,c) will have the same effect as:
  *     free(a); free(b); free(c);
  *     a = b = c = NULL;
  */
#define del(...) do { _del(NARGS(__VA_ARGS__), __VA_ARGS__); null(__VA_ARGS__); } while(0)

 /*
  * null(...) 
  *
  * Will assign NULL to all its arguments.
  * (works with 1 to 16 arguments)
  *
  * E.g. null(a,b,c) will have the same effect as:
  *     a = b = c = NULL;
  */
#define null(...) NULL_N(NARGS(__VA_ARGS__), __VA_ARGS__)

 /*
  * Crap that was necessary to implement the above macros
  */

#define TOKENPASTE2(x, y) x ## y
#define TOKENPASTE(x, y) TOKENPASTE2(x, y)

#define NULL_N(n, ...) TOKENPASTE(NULL_,n)(__VA_ARGS__)

#define NULL_1(_1) do { _1 = NULL; } while(0)
#define NULL_2(_1,_2) do { _1=_2=NULL; } while(0)
#define NULL_3(_1,_2,_3) do { _1=_2=_3=NULL; } while(0)
#define NULL_4(_1,_2,_3,_4) do { _1=_2=_3=_4=NULL; } while(0)
#define NULL_5(_1,_2,_3,_4,_5) do { _1=_2=_3=_4=_5=NULL; } while(0)
#define NULL_6(_1,_2,_3,_4,_5,_6) do { _1=_2=_3=_4=_5=_6=NULL; } while(0)
#define NULL_7(_1,_2,_3,_4,_5,_6,_7) do { _1=_2=_3=_4=_5=_6=_7=NULL; } while(0)
#define NULL_8(_1,_2,_3,_4,_5,_6,_7,_8) do { _1=_2=_3=_4=_5=_6=_7=_8=NULL; } while(0)
#define NULL_9(_1,_2,_3,_4,_5,_6,_7,_8,_9) do { _1=_2=_3=_4=_5=_6=_7=_8=_9=NULL; } while(0)
#define NULL_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=NULL; } while(0)
#define NULL_11(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=_11=NULL; } while(0)
#define NULL_12(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=_11,_12=NULL; } while(0)
#define NULL_13(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=_11=_12=_13=NULL; } while(0)
#define NULL_14(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=_11=_12=_13=_14=NULL; } while(0)
#define NULL_15(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=_11=_12=_13=_14=_15=NULL; } while(0)
#define NULL_16(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16) \
           do { _1=_2=_3=_4=_5=_6=_7=_8=_9=_10=_11=_12=_13=_14=_15=_16=NULL; } while(0)
                 
void _del(int nargs, ...) {
    void* p;
    va_list al;
    va_start(al, nargs); 
    for (int i = 1; i <= nargs; i++) { // = va_arg(al, int))
        p = va_arg(al, void*);
        free(p);
        p = NULL;
        //printf("%p ", va_arg(al, char*));
    }
    va_end(al);
}















