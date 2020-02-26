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
#include "arraylist.h"


class StringBuilder : ArrayList<std::string> {
public:
    StringBuilder();
    StringBuilder(const char* prefix);
    StringBuilder(const std::string& prefix);
    StringBuilder(const StringBuilder&) = delete;
    StringBuilder& append(const std::string& str);
    std::string* build(const char* delimiter = "");
};

#endif // STRBUILDER_H
