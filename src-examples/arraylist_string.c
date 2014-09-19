#include "lang.String.h"
#include "lang.System.h"
#include "util.ArrayList.h"

int main() {
    System_t *sys = System();
    ArrayList_t *list = ArrayList(10);

    list->add(list, 0, String("C"));
    list->add(list, 1, String("C#"));
    list->add(list, 2, String("C++"));
    list->add(list, 3, String("Java"));
    list->add(list, 4, String("Perl"));
    list->add(list, 5, String("Python"));
    list->add(list, 6, String("Ruby"));

    int i;
    for (i = 0; i < list->size(list); i++) {
        String_t *lang = list->get(list, i);
        sys->out->println(lang);
    }

    return 0;
}
