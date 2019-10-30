#include <iostream>
#include <string>
#include "matroidprocessor.h"
#include <functional>
#include "matroid.h"
#include <omp.h>
using namespace std;




int main()
{
    int intArray[5] = {10,4,68,9,15};
//    void* a = intArray;
//    cout << *(static_cast<int*>(a)+1) << endl;
    string stringArray[6] = {"casa", "palabra","comida","tarea","mouse","dolor"};
    bool boolArray[5] = {true,false,true,false,false};
    Matroid matroid =  Matroid(intArray,5,&Matroid::intFunction,&Matroid::printInt);
    Matroid matroid2 =  Matroid(stringArray,6,&Matroid::stringFunction,&Matroid::printString);
    Matroid matroid3 =  Matroid(boolArray,5,&Matroid::booleanFunction,&Matroid::printBoolean);
    vector<Matroid*> vectorMatroids = vector<Matroid*>();
    vectorMatroids.push_back(&matroid);
    vectorMatroids.push_back(&matroid2);
    vectorMatroids.push_back(&matroid3);

    MatroidProcessor processor = MatroidProcessor(vectorMatroids,3);
    processor.processA();
    int* k = static_cast<int*> (matroid.subsetI);
    int p = *k;
    getchar();

    return 0;
}
