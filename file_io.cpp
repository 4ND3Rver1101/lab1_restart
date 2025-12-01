#include "file_io.h"
#include <fstream>

void writeToFile(const char* filename, const MyStruct arr[], size_t n) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        return;
    }

    for (size_t i = 0; i < n; i++) {
        file << "Index: " << i << "\n";
        file << "Data:\n";
        file << arr[i].value1 << ";\n";
        file << arr[i].value2 << ";\n";
        file << arr[i].value3 << ";\n\n";
    }

    file.close();
}