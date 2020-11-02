/**
 Exercise 6
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file SearchUtilitiesMap.hpp
 @author Russell Taylor
 @date 6/25/20
*/

#ifndef SearchUtilitiesMap_hpp
#define SearchUtilitiesMap_hpp

#include <map>
using namespace std;

// Sequential Search Using Map
int seqSearch(map<int, int> list, int listLength, int searchItem, int &count);

// Recursive Sequential Search Using Map
int recSeqSearch(map<int, int> list, int listLength, int searchItem, int &count);

// Binary Search Using Map
int binarySearch(map<int, int> list, int listLength, int searchItem, int &count);

// Recursive Binary Search Using Map
int recBinarySearch(map<int, int> list, int listLength, int searchItem, int first, int last, int &count);

// Bubble Sort Using Map
void bubbleSort(map<int, int>& list, int listLength, int &count);

#endif /* SearchUtilitiesMap_hpp */
