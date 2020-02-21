#include "strbuilder.h"

StringBuilder::StringBuilder(const char* prefix) {
    this->append(prefix);
}

StringBuilder& StringBuilder::append(const std::string& str) {
    return *this;
}

std::string* StringBuilder::build() {

}
