#include <stdio.h>
#include <memory.h>
#include "FileWorker.h"
#include "helper.h"
int main()
{
    int str[100];

    initSystem(10);
    FWorker f = setFWorker("/Users/mark/CLionProjects/DecisionLaba/forRead.txt", "r");
    FWorker f1 = setFWorker("/Users/mark/CLionProjects/DecisionLaba/forWrite.txt", "w");
    read(&f, 20, str);
    write(&f1, 10, str);
    printMas(str, 0, 19);

    return 0;
}