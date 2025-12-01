#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "my_struct.h"
#include "utils.h"
#include "sort.h"
#include "file_io.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    MyStruct original[ARRAY_SIZE];
    MyStruct bubbleSorted[ARRAY_SIZE];
    MyStruct qsortSorted[ARRAY_SIZE];

    // Generate array
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        generateRandomStruct(original[i]);
    }

    // Copy arrays
    std::memcpy(bubbleSorted, original, sizeof(original));
    std::memcpy(qsortSorted, original, sizeof(original));

    // Bubble sort with timing
    clock_t startBubble = clock();
    bubbleSort(bubbleSorted, ARRAY_SIZE);
    clock_t endBubble = clock();
    double timeBubble = static_cast<double>(endBubble - startBubble) / CLOCKS_PER_SEC;

    // QSort with timing
    clock_t startQSort = clock();
    std::qsort(qsortSorted, ARRAY_SIZE, sizeof(MyStruct), compareStructs_qsort);
    clock_t endQSort = clock();
    double timeQSort = static_cast<double>(endQSort - startQSort) / CLOCKS_PER_SEC;

    // Output timing results
    std::cout << "Array size: " << ARRAY_SIZE << "\n";
    std::cout << "Bubble Sort time: " << timeBubble << " seconds\n";
    std::cout << "QSort time: " << timeQSort << " seconds\n";
    std::cout << "Speed ratio (QSort/Bubble): " << timeQSort / timeBubble << "\n";

    // Compare results
    if (areArraysEqual(bubbleSorted, qsortSorted, ARRAY_SIZE)) {
        std::cout << "Arrays are equal. Writing to file...\n";
        writeToFile("sorted_output.txt", bubbleSorted, ARRAY_SIZE);
        std::cout << "Data written to sorted_output.txt\n";
    }
    else {
        std::cout << "ERROR: Sorted arrays are NOT equal!\n";
        return 1;
    }

    return 0;
}