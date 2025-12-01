#include "utils.h"
#include <cstdlib>
#include <cstring>
#include <ctime>

void generateRandomString(char* str, size_t length) {
    constexpr size_t ALPHABET_SIZE = 26;
    for (size_t i = 0; i < length - 1; i++) {
        str[i] = static_cast<char>(rand() % ALPHABET_SIZE + 'a');
    }
    str[length - 1] = '\0';
}

void generateRandomStruct(MyStruct& s) {
    generateRandomString(s.value1, STRING_SIZE);
    s.value2 = rand() % 1000;
    generateRandomString(s.value3, STRING_SIZE);
}

int compareStructs(const MyStruct& a, const MyStruct& b) {
    int result = strcmp(a.value3, b.value3);
    if (result != 0) return result;

    if (a.value2 != b.value2) return a.value2 - b.value2;

    return strcmp(a.value1, b.value1);
}

int compareStructs_qsort(const void* p1, const void* p2) {
    const MyStruct* a = static_cast<const MyStruct*>(p1);
    const MyStruct* b = static_cast<const MyStruct*>(p2);
    return compareStructs(*a, *b);
}

bool areArraysEqual(const MyStruct a[], const MyStruct b[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (compareStructs(a[i], b[i]) != 0) {
            return false;
        }
    }
    return true;
}