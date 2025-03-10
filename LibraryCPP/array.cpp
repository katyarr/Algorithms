#include "array.h"

struct Array
{
    size_t number;
    Data* data;
    Array(size_t size)
    {
        number = size;
        data = new Data[size];
    }
    ~Array()
    {
        delete[] data;
    }
};

// create array
Array* array_create(size_t size)
{
    return new Array(size);
}

// delete array, free memory
void array_delete(Array* arr)
{
    delete arr->data;
}

// returns specified array element
Data array_get(const Array* arr, size_t index)
{
    if (index >= array_size(arr))
        return 0;
    else
        return (arr->data[index]);
}

// sets the specified array element to the value
void array_set(Array* arr, size_t index, Data value)
{
    if (index >= array_size(arr))
        return;
    else
        arr->data[index] = value;
}

// returns array size
size_t array_size(const Array* arr)
{
    return arr->number;
}