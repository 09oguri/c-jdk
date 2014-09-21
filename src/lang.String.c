#include "lang.String.h"

char charAt(String_t* self, int32_t index) {
    if ((index < 0) || (index >= self->length(self))) {
        return '\0';
    }
    const char* value = self->toString(self);
    return value[index];
}

int32_t compareTo(String_t* self, String_t* anotherString) {
    int32_t len1 = self->length(self);
    int32_t len2 = anotherString->length(anotherString);
    int lim = (len1 < len2) ? len1 : len2;
    char * v1 = self->toString(self);
    char* v2 = anotherString->toString(anotherString);

    int32_t k = 0;
    while (k < lim) {
        char c1 = v1[k];
        char c2 = v2[k];
        if (c1 != c2) {
            return c1 - c2;
        }
        k++;
    }
    return len1 - len2;
}

String_t concat(String_t* self, String_t* str) {
    if (self == NULL || str == NULL) {
        return String("");
    }

    int32_t len = self->length(self) + str->length(str);
    char value[len];
    strcpy(value, self->toString(self));
    strcat(value, str->toString(str));

    return String(value);
}

void lang_string_del(String_t* self) {
    free(self->_value);
    self->_length = 0;
    free(self);
}

int32_t endsWith(String_t* self, String_t* suffix) {
    return startsWith(self, suffix, self->length(self) - suffix->length(suffix));
}

int32_t equals(String_t* self, String_t* anObject) {
    if (self == anObject) {
        return 1;
    }

    String_t *anotherString = (String_t*) anObject;
    int32_t n = self->length(self);
    if (n == anotherString->length(anotherString)) {
        char* v1 = self->toString(self);
        char* v2 = anotherString->toString(anotherString);
        int i = 0;
        while (n-- != 0) {
            if (v1[i] != v2[i]) {
                return 0;
            }
            i++;
        }
        return 1;
    }
    return 0;
}

int32_t indexOf(String_t* self, int32_t ch, int32_t fromIndex) {
    const int32_t max = self->length(self);
    if (fromIndex < 0) {
        fromIndex = 0;
    } else if (fromIndex >= max) {
        return -1;
    }

    if (ch < MIN_SUPPLEMENTARY_CODE_POINT) {
        const char* value = self->toString(self);
        int i;
        for (i = fromIndex; i < max; i++) {
            if (value[i] == ch) {
                return i;
            }
        }
    }
    return -1;
}

int32_t isEmpty(String_t* self) {
    if (self->length(self) == 0) {
        return 1;
    }
    return 0;
}

int32_t lastIndexOf(String_t* self, int32_t ch, int32_t fromIndex) {
    if (ch < MIN_SUPPLEMENTARY_CODE_POINT) {
        const char* value = self->toString(self);
        int i = (fromIndex < self->length(self)) ? fromIndex : self->length(self);
        for (; i >= 0; i--) {
            if (value[i] == ch) {
                return i;
            }
        }
    }
    return -1;
}

int32_t length(String_t* self) {
    return self->_length;
}

String_t replace(String_t* self, char oldChar, char newChar) {
    if (oldChar != newChar) {
        int len = self->length(self);
        int i = -1;
        char* val = self->toString(self);

        while (++i < len) {
            if (val[i] == oldChar) {
                break;
            }
        }
        if (i < len) {
            char buf[len + 1];
            int j;
            for (j = 0; j < i; j++) {
                buf[j] = val[j];
            }
            while (i < len) {
                char c = val[i];
                buf[i] = (c == oldChar) ? newChar : c;
                i++;
            }
            buf[i] = '\0';
            return String(buf);
        }
    }
    return String("");
}

int32_t startsWith(String_t* self, String_t* prefix, int32_t toffset) {
    char ta[self->length(self)];
    strcpy(ta, self->toString(self));
    int32_t to = toffset;
    char pa[prefix->length(prefix)];
    strcpy(pa, prefix->toString(prefix));
    int32_t po = 0;
    int32_t pc = prefix->length(prefix);

    if ((toffset < 0) || (toffset > self->length(self) - pc)) {
        return 0;
    }
    while (--pc >= 0) {
        if (ta[to++] != pa[po++]) {
            return 0;
        }
    }
    return 1;
}

char* toString(String_t* self) {
    return self->_value;
}

String_t String(char* value) {
    return (String_t) {value, strlen(value), charAt, compareTo, concat, lang_string_del, endsWith, equals,
        indexOf, isEmpty, lastIndexOf, length, replace, startsWith, toString};
}
