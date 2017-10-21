//
// Created by Марк on 21.10.17.
//
#include <stdio.h>
#include "helper.h"


void printMas( int * mas, int begin, int end )
{
    for (; begin < end; begin++)
        printf("%c", mas[begin]);
}