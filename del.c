#include <stdarg.h>
#include "nargs.c"


#define del(s) do {free(s); s=NULL;} while(0)

#define delete(...) _delete(NARGS(__VA_ARGS__), __VA_ARGS__)

#define null0(...) do {GETARG(1,__VA_ARGS__)=NULL; GETARG(2,__VA_ARGS__)=NULL;} while(0)

#define null1(...) do {                                     \
    for(int _i=1; _i<= NARGS(__VA_ARGS__); _i++) {         \
        GETARG(i,__VA_ARGS__) = NULL;                      \
    }                                                      \
} while(0)

#define null2(...) do {                                               \
    if (NARGS(__VA_ARGS__) >= 1) GETARG(1, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 2) GETARG(2, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 3) GETARG(3, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 4) GETARG(4, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 5) GETARG(5, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 6) GETARG(6, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 7) GETARG(7, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 8) GETARG(8, __VA_ARGS__) = NULL;      \
    if (NARGS(__VA_ARGS__) >= 9) GETARG(9, __VA_ARGS__) = NULL;      \
} while(0)

#define null(...) NULL_N(NARGS(__VA_ARGS__), __VA_ARGS__)

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
                 
void _delete(int nargs, ...) {
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















