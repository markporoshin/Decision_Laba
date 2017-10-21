//
// Created by Марк on 21.10.17.
//

#ifndef DECISIONLABA_FILEWORKER_H
#define DECISIONLABA_FILEWORKER_H

#include <stdio.h>

typedef struct
{
    int size;
} Meta;
Meta meta;

typedef struct
{
    FILE *f;
    char * name;
    int size;
    int * buffer;
    int pointer;
} FWorker;


void initSystem( int size );
FWorker setFWorker( char * name, char * type );
void read( FWorker *fWorker, int number, int * str );
void write( FWorker *fWorker, int number, int * str );
void disposeFWorker( FWorker * fWorker );

#endif //DECISIONLABA_FILEWORKER_H
