/**
 Exercise 6
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file SearchUtilitiesMap.cpp
 @author Russell Taylor
 @date 6/25/20
*/

#include <iostream>
#include "SearchUtilitiesMap.hpp"

int seqSearch(map<int, int> list, int listLength, int searchItem, int &count) {
	int loc;
	bool found = false;
    
	for (loc = 0; loc < listLength; ++loc) {
		++count;
		if (list[loc]==searchItem) {
			found = true;
			break;
		}
	}
	if (found)
		return loc;
	else
		return -1;
}

int recSeqSearchActual(map<int, int> list, int listLength, int searchItem, int &count) {
	if (listLength == 0) return -1;
    ++count;
	
    if (list[listLength]==searchItem)
		return listLength;
	else
		return recSeqSearchActual(list, listLength-1, searchItem, count);
}

int recSeqSearch(map<int, int> list, int listLength, int searchItem, int &count) {
	return recSeqSearchActual(list, listLength, searchItem, (count = 0));
}

int binarySearch(map<int, int> list, int listLength, int searchItem, int &count) {
    int first = 0;
    int last = listLength - 1;
    int mid = 0;
    bool found = false;
    
    while (first <= last && !found) {
        count++;
        mid = (first + last) / 2;
        if (list[mid] == searchItem)
            found = true;
        else if (list[mid] > searchItem)
            last = mid - 1;
        else
            first = mid + 1;
    }
    if (found)
        return mid;
    else
        return -1;
}

int recBinarySearchActual(map<int, int> list, int listLength, int searchItem, int first, int last, int &count) {
    count++;
    if (first > last)
        return -1;
    else {
        int mid = (first + last) / 2;
        if (list[mid] == searchItem)
            return mid;
        else if (list[mid] > searchItem)
            return recBinarySearchActual(list, listLength, searchItem, first, mid - 1, count);
        else
            return recBinarySearchActual(list, listLength, searchItem, mid + 1, last, count);
    }
}

int recBinarySearch(map<int, int> list, int listLength, int searchItem, int first, int last, int &count) {
    return recBinarySearchActual(list, listLength, searchItem, first, last, (count = 0));
}

void bubbleSort(map<int, int>& list, int listLength, int &count) {
    for (int i = 1; i < listLength; i++) {
        for (int j = 0; j < listLength - i; j++) {
            count++;
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
