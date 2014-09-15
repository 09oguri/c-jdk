#include "string.h"

int main() {
    String_t *s = String("こんにちは");
    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("isEmpty : %d\n", s->isEmpty(s));

    printf("##################\n");

    String_t *str = String("、世界");
    String_t *s2 = s->concat(s, str);
    printf("%s : length = %d\n", s2->toString(s2), s2->length(s2));
    printf("isEmpty : %d\n", s->isEmpty(s2));

    printf("##################\n");

    s->del(s);
    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("isEmpty : %d\n", s->isEmpty(s));

    printf("##################\n");

    s = String("hello, world");
    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("indexOf('o', 0) : %d\n", s->indexOf(s, 'o', 0));
    printf("indexOf('o', 5) : %d\n", s->indexOf(s, 'o', 5));

    printf("lastIndexOf('o', 0) : %d\n", s->lastIndexOf(s, 'o', 0));
    printf("lastIndexOf('o', 5) : %d\n", s->lastIndexOf(s, 'o', 5));

    printf("##################\n");

    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("charAt(9) : %c\n", s->charAt(s, 9));

    printf("##################\n");

    String_t *prefix = String("hello");
    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("startsWith(\"hello\") : %d\n", s->startsWith(s, prefix, 0));

    printf("##################\n");

    String_t *suffix = String("ld");
    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("endsWith(\"ld\") : %d\n", s->endsWith(s, suffix));
    printf("charAt(11) : %c\n", s->charAt(s, 11));

    printf("##################\n");

    String_t *s1 = s;
    printf("%s : length = %d\n", s->toString(s), s->length(s));
    printf("equals(s, s1) : %d\n", s->equals(s, s1));
    printf("equals(s, s2) : %d\n", s->equals(s, s2));

    printf("##################\n");

    String_t *s3 = s->replace(s, 'o', '?');
    printf("%s : length = %d\n", s3->toString(s3), s3->length(s3));
    printf("isEmpty : %d\n", s3->isEmpty(s3));

    return 0;
}
