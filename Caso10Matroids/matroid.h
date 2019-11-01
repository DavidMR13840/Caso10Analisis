#ifndef MATROID_H
#define MATROID_H

#include <iostream>
#include <string>
#include <matroidprocessor.h>
#include <functional>
#include <vector>

using namespace std;

class Matroid
{
private:

public:
    template <typename F>
    Matroid(void* elements, int size,F functionToCall, F printFunction);
    function<void()> matroidFunction;
    function<void()> printSubsetI;
    void* setS;
    void* subsetI;
    int size_;
    int subsetSize;
    vector<void*> Result;
    void intFunction();
    void stringFunction();
    void booleanFunction();
    void printInt();
    void printBoolean();
    void printString();
    bool findSubset(int item);
};


template <typename F>
Matroid::Matroid(void* elements, int size,F functionToCall, F printFunction){
    subsetI = NULL;
    size_ = size;
    setS = elements;
    matroidFunction = std::bind(functionToCall,this);
    printSubsetI = std::bind(printFunction,this);
}

void Matroid::intFunction(){
#pragma omp parallel for
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if(*(static_cast<int*>(setS)+elementIndex) <= 10){
            Result.push_back((static_cast<int*>(setS)+elementIndex));

        }
        printf("Sec Thread %d, iteration %d\n",omp_get_thread_num(),elementIndex);
    }

}

void Matroid::booleanFunction(){
    #pragma omp parallel for
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if(*(static_cast<bool*>(setS)+elementIndex) == true){
            Result.push_back((static_cast<bool*>(setS)+elementIndex));

        }
        printf("Sec Thread %d, iteration %d\n",omp_get_thread_num(),elementIndex);
    }
}

bool Matroid::findSubset(int item){
    bool inSubset = false;
    vector<void*>::iterator subIterator;
    for(subIterator = Result.begin(); subIterator != Result.end(); ++subIterator){
        if(item == *(static_cast<int*>(*subIterator))){
                inSubset = true;
                break;
        }
    }
//    for(int subsetIndex = 0; subsetIndex < Result.size(); subsetIndex++){
//        if(item ==  *(static_cast<int*>(Result[subsetIndex])) ){
//            inSubset = true;
//            break;
//        }
//    }
    return inSubset;
}
void Matroid::stringFunction(){
    #pragma omp parallel for
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if((*(static_cast<string*>(setS)+elementIndex)).length() <= 6 ){
            Result.push_back((static_cast<string*>(setS)+elementIndex));

        }
        printf("Sec Thread %d, iteration %d\n",omp_get_thread_num(),elementIndex);
    }
}

void Matroid::printString(){
    for(int items = 0; items < Result.size(); items++){
        cout << *(static_cast<string*>(Result[items])) << " ";
    }
    cout << endl;
}

void Matroid::printBoolean(){
    for(int items = 0; items < Result.size(); items++){
        cout << *(static_cast<bool*>(Result[items])) << " ";
    }
    cout << endl;
}

void Matroid::printInt(){
    for(int items = 0; items < Result.size(); items++){
        cout << *(static_cast<int*>(Result[items])) << " ";
    }
    cout << endl;
}




#endif // MATROID_H
