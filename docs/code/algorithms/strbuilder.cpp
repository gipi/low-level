#include <string.h>
#include "strbuilder.h"

StringBuilder::StringBuilder(const char* prefix) {
    this->append(prefix);
}

StringBuilder& StringBuilder::append(const std::string& str) {
    ArrayList::append(str);
    return *this;
}

std::string* StringBuilder::build(const char* delimiter) {
    size_t del_size = strlen(delimiter);
    size_t str_size = 0;
    for (size_t idx = 0 ; idx < size ; idx++) {
        str_size += items[idx].size();
    }

    /* we add the size of delimiter */
    str_size += (size - 1) * del_size;

    char* buffer = (char*)malloc(str_size + 1); /* + 1 for the NULL terminating char */
    char* ptr = buffer;
    for (size_t idx = 0 ; idx < size ; idx++) {
        std::string& str = items[idx];
        size_t str_size = str.size();
        strcpy(ptr, str.c_str());
        ptr += str_size;

        if (idx != (size - 1)) {
            strcpy(ptr, delimiter);
            ptr += del_size;
        }
    }

    ptr = NULL;

    std::string* result = new std::string(buffer);

    free(buffer);

    return result;
}
