#include <iostream>
#include <fstream>
#include "List.h"
#include "Dijkstra.h"
using namespace std;

int main()
{
    string input_file_name = "input.txt";
    string output_file_name = "output.txt";
    Algorithm Alg;
    int size;
    Alg.readList(input_file_name);
    Alg.Dijkstra(size);
    Alg.writeList(output_file_name);
}
