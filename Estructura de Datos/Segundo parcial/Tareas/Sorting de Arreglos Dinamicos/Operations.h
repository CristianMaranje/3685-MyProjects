#include "Vector.h"
#define dim 100
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Genera e imprime un arreglo de numeros 
Autor: Cristian maranje											       
Fecha: 06/07/2021													   
Fecha de modificacion: 7/07/2021								   
*/

int *generate()
{
    int *_vector = (int *)malloc(dim);
    for (int i = 0; i < dim; i++)
    {
        *(_vector + i) = rand() % (1001);
    }
    return _vector;
}

void print(Vector vector)
{
    int *tmpVector;
    tmpVector = vector.getVector();
    for (int i = 0; i < dim; i++)
    {
        std::cout << "Posicion " << i + 1 << " Valor: " << *(tmpVector + i) << std::endl;
    }
}

int *bubbleSort(int *arr)
{

    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = 0; j < dim - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                std::swap(*(arr + j), *(arr + j + 1));
            }
        }
    }
    return arr;
}

void quickSortAux(int *array, int leftLimit, int rightLimit)
{
    int left = leftLimit;
    int right = rightLimit;
    int pivot = *(array + (left + right) / 2);
    int temp;
    do
    {
        while (*(array + left) < pivot && left < rightLimit)
        {
            ++left;
        }
        while (pivot < *(array + right) && right > leftLimit)
        {
            --right;
        }
        if (left <= right)
        {
            std::swap(*(array + left), *(array + right));
            ++left;
            --right;
        }
    } while (left <= right);
    if (leftLimit < right)
    {
        quickSortAux(array, leftLimit, right);
    }
    if (rightLimit > left)
    {
        quickSortAux(array, left, rightLimit);
    }
}

void quickSort(int *array)
{
    quickSortAux(array, 0, dim - 1);
}

void insertionSort(int *arr)
{
    int key,j;
    for (int i = 1; i < dim; i++)
    {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        {
            *(arr + (j + 1)) = *(arr + j);
            j = j - 1;
        }
        *(arr + (j+1)) = key;
    }
}

int shellSort(int *arr)
{
    for (int gap = dim/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < dim; i += 1)
        {
            int temp = *(arr + i);
            int j;           
            for (j = i; j >= gap && *(arr +(j-gap))> temp; j -= gap)
                *(arr + j) = *(arr + (j - gap));
            *(arr + j) = temp;
        }
    }
    return 0;
}
