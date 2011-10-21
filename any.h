 /*
  * any.h -- usefull polymorphic macros.
  *          GCC-specific.
  */

#ifndef ANY_H
#define ANY_H


                              
#define any_print(value) any_output(stdout, value)

#define any_output(stream, value)                               \
    do {                                                        \
        char* _f;                                               \
        if(type_eq(value, char*))        _f = "\"%s\"";         \
        else if(type_eq(value, char[]))  _f = "\"%s\"";         \
        else if(type_eq(value, char) )   _f = "'%c'";           \
        else if(type_eq(value, int))     _f = "%i";             \
        else if(type_eq(value, double))  _f = "%g";             \
        else if(type_eq(value, float))   _f = "%g";             \
        else _f = "%p";                                         \
        fprintf(stream, _f, value);                             \
    } while(0)

#define type_eq(t1, t2) __builtin_types_compatible_p(__typeof__(t1), __typeof__(t2))


#endif // guard
