#include "Dijkstra.h"
#include "Iterator.h"
#include <fstream>

using namespace std;

void Algorithm::readList(string file_name) {
    fstream file;
    file.open(file_name, ios::in);
    int string_counter;
    file >> count_of_cities >> string_counter;
    if (file.eof() || count_of_cities == 0)
        throw out_of_range("Graph is empty");

    List_of_adjacency = new List[count_of_cities];
    Price_list = new List[count_of_cities];
    numberName = new City[count_of_cities];
    char* str;
    int str_index = 0;
    int city_index = 0;
    int first_found = -1;
    int second_found = -1;
    int tmp_price;

    for (size_t i = 0; (i < string_counter) && (!file.eof()); i++) {
        str_index = 0;
        str = new char[100];
        file >> str[str_index];
        while (str[str_index] != ';') //gathering first city letter by letter
        {
            str_index++;
            file >> str[str_index];
        }

        first_found = -1;

        for (size_t i = 0; (i < city_index) && (first_found == -1); i++) //looking for city
        {
            if (str_index == numberName[i].name_size)  //check size
            {
                for (size_t j = 0; j < numberName[i].name_size; j++)  //check name
                    if (str[j] == numberName[i].name[j])
                        first_found = i;
                    else {
                        first_found = -1;
                        break;
                    }
            }
        }

        if (first_found == -1)
        {
            numberName[city_index].name_size = str_index;
            numberName[city_index].name = new char[str_index];

            for (size_t i = 0; i < str_index; i++)
                numberName[city_index].name[i] = str[i];

            first_found = city_index;
            city_index++;
        }

        delete str;

        str = new char[100];
        str_index = 0;
        file >> str[str_index];
        while (str[str_index] != ';') //same as for first city but to second
        {
            str_index++;
            file >> str[str_index];
        }

        second_found = -1;
        for (size_t i = 0; (i < city_index) && (second_found == -1); i++) //looking for city
        {
            if (str_index == numberName[i].name_size)  //check size
            {
                for (size_t j = 0; j < numberName[i].name_size; j++)  //check name
                    if (str[j] == numberName[i].name[j])
                        second_found = i;
                    else {
                        second_found = -1;
                        break;
                    }
            }
        }

        if (second_found == -1)
        {
            numberName[city_index].name_size = str_index;
            numberName[city_index].name = new char[str_index];

            for (size_t i = 0; i < str_index; i++)
                numberName[city_index].name[i] = str[i];

            second_found = city_index;
            city_index++;
        }
        delete str;

        str = new char[100];
        str_index = 0;
        file >> str[str_index];

        while (str[str_index] != ';') //gathering first price
        {
            str_index++;
            file >> str[str_index];
        }

        if (str[0] == 'N'){ }

        else {
            tmp_price = 0;
            for (size_t i = 0; i < str_index; i++)
            {
                switch (str[i])
                {
                case '0':
                    tmp_price *= 10; 
                    break;
                case '1':
                    tmp_price = tmp_price * 10 + 1;
                    break;
                case '2':
                    tmp_price = tmp_price * 10 + 2; 
                    break;
                case '3':
                    tmp_price = tmp_price * 10 + 3;
                    break;
                case '4':
                    tmp_price = tmp_price * 10 + 4;
                    break;
                case '5':
                    tmp_price = tmp_price * 10 + 5;
                    break;
                case '6':
                    tmp_price = tmp_price * 10 + 6;
                    break;
                case '7':
                    tmp_price = tmp_price * 10 + 7;
                    break;
                case '8':
                    tmp_price = tmp_price * 10 + 8;
                    break;
                case '9':
                    tmp_price = tmp_price * 10 + 9;
                    break;
                default:
                    break;
                }
            }

            List_of_adjacency[first_found].push_back(second_found);
            Price_list[first_found].push_back(tmp_price);
        }
        delete str;

        str = new char[100];
        str_index = 0;
        file >> str[str_index];

        while (str[str_index] != ';') //gathering second price
        {
            str_index++;
            file >> str[str_index];
        }
        if (str[0] == 'N'){}

        else {
            tmp_price = 0;
            for (size_t i = 0; i < str_index; i++)
            {
                switch (str[i])
                {
                case '0':
                    tmp_price *= 10;
                    break;
                case '1':
                    tmp_price = tmp_price * 10 + 1;
                    break;
                case '2':
                    tmp_price = tmp_price * 10 + 2;
                    break;
                case '3':
                    tmp_price = tmp_price * 10 + 3;
                    break;
                case '4':
                    tmp_price = tmp_price * 10 + 4;
                    break;
                case '5':
                    tmp_price = tmp_price * 10 + 5;
                    break;
                case '6':
                    tmp_price = tmp_price * 10 + 6;
                    break;
                case '7':
                    tmp_price = tmp_price * 10 + 7;
                    break;
                case '8':
                    tmp_price = tmp_price * 10 + 8;
                    break;
                case '9':
                    tmp_price = tmp_price * 10 + 9;
                    break;
                default:
                    break;
                }
            }
            List_of_adjacency[second_found].push_back(first_found);
            Price_list[second_found].push_back(tmp_price);
        }
        delete[] str;
    }

    str_index = 0;
    str = new char[100];
    file >> str[str_index];
    while (str[str_index] != ';') //departure city
    {
        str_index++;
        file >> str[str_index];
    }

    first_found = -1;
    for (size_t i = 0; (i < city_index) && (first_found == -1); i++)
    {
        if (str_index == numberName[i].name_size)  //check size
        {
            for (size_t j = 0; j < numberName[i].name_size; j++)  //check name
                if (str[j] == numberName[i].name[j])
                    first_found = i;
                else {
                    first_found = -1;
                    break;
                }
        }
    }

    if (first_found == -1)
        throw out_of_range("Missing value");

    delete[] str;
    str = new char[100];

    str_index = 0;
    file >> str[str_index];
    while (str[str_index] != ';') //arrival city
    {
        str_index++;
        file >> str[str_index];
    }

    second_found = -1;
    for (size_t i = 0; (i < city_index) && (second_found == -1); i++)
    {
        if (str_index == numberName[i].name_size)  //check size
        {
            for (size_t j = 0; j < numberName[i].name_size; j++)  //check name
                if (str[j] == numberName[i].name[j])
                    second_found = i;
                else {
                    second_found = -1;
                    break;
                }
        }
    }

    if (second_found == -1)
        throw out_of_range("Missing value");

    this->from = first_found;
    this->to = second_found;
    this->result = NULL;
    file.close();
}

int* Algorithm::Dijkstra(int& _result_size) {
    int* distance = new int[count_of_cities];
    int* from_where = new int[count_of_cities];
    bool* visited = new bool[count_of_cities];

    for (size_t i = 0; i < count_of_cities; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    Iterator* priceIt = Price_list[from].create_iterator(0);
    Iterator* adjacIt = List_of_adjacency[from].create_iterator(0);

    int tmp_city, tmp_price;

    while (priceIt->has_next())
    {
        tmp_city = adjacIt->next();
        tmp_price = priceIt->next();
        distance[tmp_city] = tmp_price;
        from_where[tmp_city] = from;
    }

    distance[from] = 0;
    visited[from] = true;
    from_where[from] = from;
    int min, index = 0;

    for (size_t i = 0; i < count_of_cities; i++)
    {
        min = INT_MAX;
        for (size_t j = 0; j < count_of_cities; j++)
        {
            if ((visited[j] == false) && (distance[j] < min))
            {
                min = distance[j];
                index = j;
            }
        }

        visited[index] = true;
        priceIt = Price_list[index].create_iterator(0);
        adjacIt = List_of_adjacency[index].create_iterator(0);
        while (priceIt->has_next())
        {
            tmp_city = adjacIt->next();
            tmp_price = priceIt->next();
            if ((visited[tmp_city] == false) && (distance[index] != INT_MAX) && ((distance[index] + tmp_price) < distance[tmp_city]))
            {
                distance[tmp_city] = distance[index] + tmp_price;
                from_where[tmp_city] = index;
            }
        }
    }

    if (distance[to] == INT_MAX)
        throw out_of_range("Result not found");
    else {
        int count = 2;
        index = to;
        while (from_where[index] != from)
        {
            count++;
            index = from_where[index];
        }
        _result_size = count;
        result = new int[_result_size];
        result[_result_size - 1] = to;
        result[0] = from;
        int i = _result_size - 2;
        index = to;
        while (from_where[index] != from)
        {
            result[i] = from_where[index];
            i--;
            index = from_where[index];
        }
        result_size = _result_size;
        return result;
    }
}

void Algorithm::writeList(string file_name) {
    if (result != NULL) {
        fstream file;
        file.open(file_name, ios::out);

        for (size_t i = 0; i < result_size; i++)
        {
            for (size_t j = 0; j < numberName[result[i]].name_size; j++)
            {
                file << numberName[result[i]].name[j];
            }
            file << endl;
        }
        file.close();
    }
}