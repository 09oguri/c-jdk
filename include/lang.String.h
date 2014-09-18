#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SUPPLEMENTARY_CODE_POINT 0x10000

typedef struct String_t {
    char *_value;
    int32_t _length;

    char (*charAt)(struct String_t*, int32_t);
    int32_t (*compareTo)(struct String_t*, struct String_t*);
    struct String_t* (*concat)(struct String_t*, struct String_t*);
    void (*del)(struct String_t*);
    int32_t (*endsWith)(struct String_t*, struct String_t*);
    int32_t (*equals)(struct String_t*, struct String_t*);
    int32_t (*indexOf)(struct String_t*, int32_t, int32_t);
    int32_t (*isEmpty)(struct String_t*);
    int32_t (*lastIndexOf)(struct String_t*, int32_t, int32_t);
    int32_t (*length)(struct String_t*);
    struct String_t* (*replace)(struct String_t*, char, char);
    int32_t (*startsWith)(struct String_t*, struct String_t*, int32_t);
    char* (*toString)(struct String_t*);
} String_t;

char charAt(String_t* self, int32_t index);
int32_t compareTo(String_t* self, String_t* anotherString);
String_t* concat(String_t* self, String_t* str);
void del(String_t* self);
int32_t endsWith(String_t* self, String_t* suffix);
int32_t equals(String_t* self, String_t* anObject);
int32_t indexOf(String_t* self, int32_t ch, int32_t fromIndex);
int32_t isEmpty(String_t* self);
int32_t lastIndexOf(String_t* self, int32_t ch, int32_t fromIndex);
int32_t length(String_t* self);
String_t* replace(String_t* self, char oldChar, char newChar);
int32_t startsWith(String_t* self, String_t* prefix, int32_t toffset);
char* toString(String_t* self);
String_t* String(char* value);

#endif
