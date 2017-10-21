//
// Created by Марк on 21.10.17.
//

#include <stdlib.h>
#include "FileWorker.h"


void initSystem( int size )
{
    meta.size = size;
}

FWorker setFWorker( char * name, char * type )
{
    FWorker fWorker;
    fWorker.size = meta.size;
    fWorker.name = name;
    fWorker.buffer = malloc(sizeof(int) * meta.size);
    fWorker.pointer = -1;
    if ((fWorker.f = fopen(name, type)) == NULL) {
        printf("Не удалось открыть фаил");
    }

    return fWorker;
}


//заполняет буффер из файла
void readBuffer( FWorker *fWorker )
{
    int i,  c;
    fWorker->pointer = 0;
    for (i = 0; i < fWorker->size; i++)
    {
        if ((c = fgetc(fWorker->f)) != EOF)
            fWorker->buffer[i] = c;
        else
            fWorker->buffer[i] = -1;         //sign about end of file
    }
}


//записывает в фаил буфер
void writeBuffer( FWorker *fWorker )
{
    int i;
    for (i = 0;  i < fWorker->pointer; i++)
    {
        fputc(fWorker->buffer[i], fWorker->f);
    }
    fWorker->pointer = 0;
}

void readPart(FWorker *fWorker, int number, int *str, int i)
{
    int *pointer = &(fWorker->pointer);
    int *buffer = fWorker->buffer;
    int *size = &(fWorker->size);


    for (; *pointer < *size && i < number; (*pointer)++, i++)
    {
        if (buffer[*pointer] == -1)
            break;

        str[i] = buffer[*pointer];
        //printf("%c", buffer[*pointer]);
    }
    if (buffer[*pointer] == -1) {
        printf("\n{log: конец файла}\n");
        str[i] = 0;
    }
    else if (i < number)
    {
        readBuffer(fWorker);
        readPart(fWorker, number, str, i);
    }

}

void read( FWorker *fWorker, int number, int * str )
{
    if (fWorker->pointer == -1)
        readBuffer(fWorker);
    int i = 0;
    readPart(fWorker, number, str, i);
}

void writePart(  FWorker *fWorker, int number, int * str, int i )
{
    int *pointer = &(fWorker->pointer);
    int *buffer = fWorker->buffer;
    int *size = &(fWorker->size);

    for (; (*pointer < *size) && (i < number); i++, (*pointer)++)
    {
        buffer[*pointer] = str[i];
    }
    if (i == number)
        writeBuffer(fWorker);
    else if (*pointer == *size)
    {
        writeBuffer(fWorker);
        writePart(fWorker, number, str, i);
    }
}

void write( FWorker *fWorker, int number, int * str )
{
    int i = 0;
    if (fWorker->pointer == -1)
        fWorker->pointer = 0;
    writePart(fWorker, number - i, str, i);
}



void disposeFWorker( FWorker * fWorker )
{
    fclose(fWorker->f);
    free(fWorker->buffer);
    fWorker = NULL;
}