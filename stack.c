#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h> 

#include "ass.h"
#include "del.h"
#include "str.h"          
#include "log.h"

// forward declarations
//typedef struct type type;
typedef struct element* element;
typedef struct stack* stack;

/*struct type {
    type* parrent;
    char* name;
};*/

struct element {
    char* type;
    //void* data;
    union {
        double kc_float;
        int    kc_int;
        char*  kc_str;
        stack  kc_stack;
    } data;
};  

struct stack {
    //size_t size;
    element top;
    element bottom;
};



stack stack_new() {
    stack s = malloc(sizeof(struct stack));
    s->bottom = NULL;
    s->top = NULL;
    return s;
}



signed stack_size(stack s) {
    signed size;
    if (s->top == NULL && s->bottom == NULL) {
        size = 0;
    } else {
        ass(s->top != NULL);      
        ass(s->bottom != NULL);   
        //size = bottom - top + 1
        //size = 1 + (s->bottom - s->top)/sizeof(element);     
        size = s->top - s->bottom + 1;
    }
         logu(s->bottom); logu(s->top); logu(size);
    return size;
}

element stack_top(stack s) {
    return s->top;
}

stack stack_push(stack s, element e) {
    signed size_new = stack_size(s) + 1;  
    s->bottom = realloc(s->bottom, size_new * sizeof(element)); 
    ass(s->bottom != NULL);
    //top = bottom - size + 1
    //s->top = s->bottom - (size_new - 1)*sizeof(element);  //logu(s->top);
    s->top = &s->bottom[size_new - 1];   // s->bottom + size_new - 1
    //////////////////*(s->top) = e;
    ass(s->top->type != NULL);
 //   ass(s.top->data != NULL);
    return s; 
}

bool type_eq(char* t1, char* t2) {
    return str_eq(t1, t2);
}

void element_del(element e) {
    if (type_eq(e->type, "str")) 
        del(e->data.kc_str);
    else if (type_eq(e->type, "stack")) 
        stack_del(e->data); 
    else ass(type_eq(e->type, "int") || type_eq(e->type, "float"));  
}

void stack_del(stack s) {
    if (stack_size(s) != 0)
        for (element e = s->bottom; e <= s->top; e++) 
            element_del(e);
    free(s);
}

stack stack_pop(stack s) {
    element_del(s->top);
    ass(stack_size(s) > 0);
    unsigned size_new = stack_size(s) - 1;
    ass(size_new >= 0);
    s->bottom = realloc(s->bottom, size_new * sizeof(element));
    ass(s->bottom != NULL);
    //top = bottom - size + 1
    s->top = s->bottom - (1 - size_new)*sizeof(element);
    ass(s->top->type != NULL);
    return s;
}

void stack_print(stack s) {
    if (stack_size(s) == 0) return;
    for (element e = s->bottom; e <= s->top; e++) 
        element_print(e);
}

void element_print(element e) {
    if (str_eq(e->type, "int"))   printf("%i ", e->data.kc_int);
    else if (str_eq(e->type, "float")) printf("%f ", e->data.kc_float);
    else if (str_eq(e->type, "str"))   printf("%s ", e->data.kc_str);
    else if (str_eq(e->type, "stack")) {
        printf("<");
        stack_print(e->data.kc_stack);
        printf(">");
    }
}


element element_new(char* type) {
    element e = malloc(sizeof(struct element));
    e->type = str_new(type);
    return e;
}

int main() {
    printf("===========================================\n");


    element e1 = element_new("int");
    e1->data.kc_int=123;
    element e2 = element_new("float");
    e1->data.kc_float=3.1415;
    element e3 = element_new("str");
    e1->data.kc_str="hello,world";

    stack s = stack_new();
    s = stack_push(s, e1);    logs("push1ok ");
    s = stack_push(s, e2);    logs("push2ok ");
    s = stack_push(s, e3);    logs("push3ok ");

    stack si = stack_new();
    si = stack_push(si, e1);

    element es = element_new("stack");
    es->data.kc_stack = si;

    s = stack_push(s, es);


    stack_print(s);
    printf("\n");
    stack_print(si);
    //element_print(es);


}    
