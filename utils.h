#ifndef UTILS_H
#define UTILS_H

#include "my_struct.h"
#include <cstddef>

void generateRandomString(char* str, size_t length);
void generateRandomStruct(MyStruct& s);
int compareStructs(const MyStruct& a, const MyStruct& b);
int compareStructs_qsort(const void* p1, const void* p2);
bool areArraysEqual(const MyStruct a[], const MyStruct b[], size_t n);

#endif // UTILS_H