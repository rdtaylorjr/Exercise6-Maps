/**
 Exercise 6
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file SearchUtilitiesVector.hpp
 @author Russell Taylor
 @date 6/25/20
*/

#ifndef SearchUtilitiesVector_hpp
#define SearchUtilitiesVector_hpp

#include <vector>
using namespace std;

// Sequential Search Using Vector
int seqSearch(vector<int> list, int listLength, int searchItem, int &count);

// Recursive Sequential Search Using Vector
int recSeqSearch(vector<int> list, int listLength, int searchItem, int &count);

// Binary Search Using Vector
int binarySearch(vector<int> list, int listLength, int searchItem, int &count);

// Recursive Binary Search Using Vector
int recBinarySearch(vector<int> list, int listLength, int searchItem, int first, int last, int &count);

// Bubble Sort Using Vector
void bubbleSort(vector<int>& list, int listLength, int &count);

#endif /* SearchUtilitiesVector_hpp */
