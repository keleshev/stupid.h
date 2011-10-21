#include "str.h"
#include "log.h"
#include "ass.h"

#define b() printf("\n")

int main() {
    char* s = "one two three";
    
    // str_new
    char* s1n = str_new(s);
    ass(str_eq(s, s1n));
    
    s1n[0] = '1';
    ass(str_eq(s, s1n));
    
    // str_auto
    char* s1a = str_auto(s);
    ass(str_eq(s, s1a));
    
    s1a[0] = '1';
    ass(str_eq(s, s1a));
    ass(str_eq(s, s1a), "My message!");
    ass(str_eq(s, s1a),  "My message!", some thing, else );

    int num = 30;
    int k = 30;
    ass(num== 100);

    char* str1 = "abc";
    char* str2 = "ABC";
    ass(str1== str2);

    ass(num == 31, /*sdf*/ "Num should be equal to k!");

    any_print("any print 1");
    char* any2 = "any print 2";
    any_print(any2);
    char any3[] = "any print 3";
    any_print(any3);
    any_print(44444444);
    char ch = '!';
    any_print(ch);
    double d = 623.456;
    float f = 7.13e-12;
    any_print(d);
    any_print(f);
    any_print(8.8);


}
