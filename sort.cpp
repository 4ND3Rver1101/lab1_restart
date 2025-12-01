#include "sort.h"
#include "utils.h"
#include <algorithm>

void bubbleSort(MyStruct arr[], size_t n) {
    bool swapped;

    for (size_t i = 0; i < n - 1; i++) {
        swapped = false;

        for (size_t j = 0; j < n - i - 1; j++) {
            if (compareStructs(arr[j], arr[j + 1]) > 0) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}