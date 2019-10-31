#include <iostream>
#include <string>
#include "matroidprocessor.h"
#include <functional>
#include "matroid.h"
#include <omp.h>
using namespace std;




int main()
{
    //prueba 1
    int intArray[5] = {10,4,68,9,15};
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
    matroid.printSubsetI();
    matroid2.printSubsetI();
    matroid3.printSubsetI();


    //prueba 2
//    int array1[5] = {10,4,68,9,15};
//    int array2[5] = {2,4,7,1,0};
//    int array3[5] = {10,12,80,9,3};
//    int array4[5] = {6,36,50,70,20};
//    int array5[5] = {5,4,8,25,16};
//    Matroid matroidI1 =  Matroid(array1,5,&Matroid::intFunction,&Matroid::printInt);
//    Matroid matroidI2 =  Matroid(array2,5,&Matroid::intFunction,&Matroid::printInt);
//    Matroid matroidI3 =  Matroid(array3,5,&Matroid::intFunction,&Matroid::printInt);
//    Matroid matroidI4 =  Matroid(array4,5,&Matroid::intFunction,&Matroid::printInt);
//    Matroid matroidI5 =  Matroid(array5,5,&Matroid::intFunction,&Matroid::printInt);
//    vector<Matroid*> secondPoint = vector<Matroid*>();
//    secondPoint.push_back(&matroidI1);
//    secondPoint.push_back(&matroidI2);
//    secondPoint.push_back(&matroidI3);
//    secondPoint.push_back(&matroidI4);
//    secondPoint.push_back(&matroidI5);
//    MatroidProcessor processor2 = MatroidProcessor(secondPoint,5);
//    processor2.processB();
//    getchar();

    return 0;
}
