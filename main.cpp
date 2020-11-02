/**
 Exercise 6
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file main.cpp
 @author Russell Taylor
 @date 6/25/20
 
 Assignment: Maps
 "Choose one of the methods for sorting the list from input file in.txt (provided) using vector.
 Sort the same data from provided input file using map. Write program."
 
 @pre An input file containing four search items and lists of integers
 @post Outputs the results of four types of searches on the lists, first using a vector to store the data, then using a map to store the data
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "SearchUtilitiesVector.hpp"
#include "SearchUtilitiesMap.hpp"
using namespace std;

void vectorSearches() {
    cout << "----------------- Vector Searches -----------------" << endl;
    string searchType;
	int searchItem, num;
	ifstream fin("in.txt");
    
    // Sequential Search Using Vector
    vector<int> a;
	fin >> searchType >> searchItem;
    while (fin >> num && num != -999)
        a.push_back(num);
    int size = (int) a.size();
    
	cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    
    int count = 0;
    int position = seqSearch(a, size, searchItem, count);
    
    cout << "\nSearch item " << searchItem;
	if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    
    // Recursive Sequential Search Using Vector
    vector<int> b;
    fin >> searchType >> searchItem;
    while (fin >> num && num != -999)
        b.push_back(num);
    size = (int) b.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << b[i] << " ";
    
    count = 0;
    position = recSeqSearch(b, size, searchItem, count);
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    
	// Binary Search Using Vector
    vector<int> c;
    fin >> searchType >> searchItem;
    while (fin >> num && num != -999)
        c.push_back(num);
    size = (int) c.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << c[i] << " ";
    
    count = 0;
    bubbleSort(c, size, count);
    cout << "\nNumber of item comparisons in bubble sort = " << count << endl;
    for (int i = 0; i < size; i++)
        cout << c[i] << " ";
    
    count = 0;
    position = binarySearch(c, size, searchItem, count);
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    
	// Recursive Binary Search Using Vector
    vector<int> d;
    fin >> searchType >> searchItem;
    while (fin >> num && num != -999)
        d.push_back(num);
    size = (int) d.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << d[i] << " ";
    
    count = 0;
    bubbleSort(d, size, count);
    cout << "\nNumber of item comparisons in bubble sort = " << count << endl;
    for (int i = 0; i < size; i++)
        cout << d[i] << " ";
    
    count = 0;
    int first = 0, last = size - 1;
    position = recBinarySearch(d, size, searchItem, first, last, count);
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
	fin.close();
}

void mapSearches() {
    cout << "------------------ Map Searches ------------------" << endl;
    string searchType;
    int searchItem, num;
    ifstream fin("in.txt");
    
    // Sequential Search Using Map
    map<int, int> a;
    fin >> searchType >> searchItem;
    for (int i = 0; fin >> num && num != -999; i++)
        a.insert({i, num});
    int size = (int) a.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    
    int count = 0;
    int position = seqSearch(a, size, searchItem, count);
    
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    
    // Recursive Sequential Search Using Map
    map<int, int> b;
    fin >> searchType >> searchItem;
    for (int i = 0; fin >> num && num != -999; i++)
        b.insert({i, num});
    size = (int) b.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << b[i] << " ";
    
    count = 0;
    position = recSeqSearch(b, size, searchItem, count);
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    
    // Binary Search Using Map
    map<int, int> c;
    fin >> searchType >> searchItem;
    for (int i = 0; fin >> num && num != -999; i++)
        c.insert({i, num});
    size = (int) c.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << c[i] << " ";
    
    count = 0;
    bubbleSort(c, size, count);
    cout << "\nNumber of item comparisons in bubble sort = " << count << endl;
    for (int i = 0; i < size; i++)
        cout << c[i] << " ";
    
    count = 0;
    position = binarySearch(c, size, searchItem, count);
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    
    // Recursive Binary Search Using Map
    map<int, int> d;
    fin >> searchType >> searchItem;
    for (int i = 0; fin >> num && num != -999; i++)
        d.insert({i, num});
    size = (int) d.size();
    
    cout << "Search Type: " << searchType << endl;
    for (int i = 0; i < size; i++)
        cout << d[i] << " ";
    
    count = 0;
    bubbleSort(d, size, count);
    cout << "\nNumber of item comparisons in bubble sort = " << count << endl;
    for (int i = 0; i < size; i++)
        cout << d[i] << " ";
    
    count = 0;
    int first = 0, last = size - 1;
    position = recBinarySearch(d, size, searchItem, first, last, count);
    cout << "\nSearch item " << searchItem;
    if (position >= 0) cout << " is in position " << position << endl;
    else cout << " is not in the list" << endl;
    cout << "Number of item comparisons = " << count << endl << endl;
    
    fin.close();
}

int main() {
    vectorSearches();
    mapSearches();
}

