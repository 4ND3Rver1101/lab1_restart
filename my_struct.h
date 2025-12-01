#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#include <cstddef>

const size_t STRING_SIZE = 32;
const size_t ARRAY_SIZE = 14;

struct MyStruct {
    char value1[STRING_SIZE];
    int value2;
    char value3[STRING_SIZE];
};

#endif // MY_STRUCT_H