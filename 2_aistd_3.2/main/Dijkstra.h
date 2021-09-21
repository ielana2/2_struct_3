#pragma once
#include "List.h"
class Algorithm
{
private:
    int count_of_cities;
    List* List_of_adjacency;
    List* Price_list;
    int* result;
    int result_size;
    int from, to;

    /*int cityCount;
    dualList* adjacencyList;
    dualList* price;
    int* result;
    int resultSize;
    int from, to;*/

    struct City
    {
        char* name;
        size_t name_size;
    };

    City* numberName;

public:

    void readList(string);
    int* Dijkstra(int&);
    void writeList(string);
};