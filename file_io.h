#ifndef FILE_IO_H
#define FILE_IO_H

#include "my_struct.h"
#include <cstddef>

void writeToFile(const char* filename, const MyStruct arr[], size_t n);

#endif // FILE_IO_H
