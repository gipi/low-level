#ifndef STRBUILDER_H
#define STRBUILDER_H
/*
 * This implements the StringBuilder pattern to avoid
 * wasting resources while concatenating strings.
 *
 * StringBuilder builder("miao");
 * builder.append("bau");
 * builder.append("kebab");
 *
 * std::string* str = builder.build();
 */
#include <iostream>


class StringBuilder {
public:
    StringBuilder();
    StringBuilder(const char* prefix);
    StringBuilder(const std::string& prefix);
    StringBuilder& append(const std::string& str);
    std::string* build();
};

#endif // STRBUILDER_H
