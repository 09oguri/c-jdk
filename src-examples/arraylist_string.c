#include "lang.String.h"
#include "util.ArrayList.h"

int main() {
    ArrayList_t *list = ArrayList(10);

    list->add(list, 0, String("C"));
    list->add(list, 0, String("C#"));
    list->add(list, 0, String("C++"));
    list->add(list, 0, String("Java"));
    list->add(list, 0, String("Perl"));
    list->add(list, 0, String("Python"));
    list->add(list, 0, String("Ruby"));

    int i;
    for (i = 0; i < list->size(list); i++) {
        String_t *lang = list->get(list, i);
        printf("%s¥n", lang->toString(lang));
    }

    return 0;
}
