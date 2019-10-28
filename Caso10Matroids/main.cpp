#include <iostream>
#include <string>
#include "matroidprocessor.h"
#include <functional>
#include "matroid.h"

using namespace std;



void function1(Matroid<int> matroid){
    int subsetIndex = 0;
    for(int elementIndex = 0; elementIndex < matroid.size_; elementIndex++){
        if(matroid.setS[elementIndex] >= 10){
            matroid.subsetI[subsetIndex] = matroid.setS[elementIndex];
        }
    }

}

int main()
{
    int arr[5] = {10,4,68,9,15};
    Matroid<int,void>* matroid = new Matroid(arr,5,std::bind(&function1,this));


    return 0;
}
