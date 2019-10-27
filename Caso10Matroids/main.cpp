#include <iostream>
#include <string>
#include <matroidprocessor.h>

using namespace std;


class MatroidOne
{
private:
    int* setS;
    int* subsetI;
    int size_;
public:
    MatroidOne(int array[], int size);
    void operator()();
};

MatroidOne::MatroidOne(int array[], int size){
    subsetI = NULL;
    size_ = size;
    for(int counter = 0; counter < size; counter++){
        setS[counter] = array[counter];
    }

}
void MatroidOne::operator ()(){
    int currentIndex = 0;
    for(int element = 0; element < size_;element++){
        if(setS[element] >= 10){
            subsetI[currentIndex] = setS[element];
            currentIndex++;
        }
    }
}

class MatroidTwo
{
private:
    bool* setS;
    bool* subsetI;
    int size_;
public:
    MatroidTwo(bool array[], int size);
    void operator()();
};

MatroidTwo::MatroidTwo(bool array[], int size){
    subsetI = NULL;
    size_ = size;
    for(int counter = 0; counter < size; counter++){
        setS[counter] = array[counter];
    }

}
void MatroidTwo::operator ()(){
    int currentIndex = 0;
    for(int element = 0; element < size_;element++){
        if(setS[element] == true){
            subsetI[currentIndex] = setS[element];
            currentIndex++;
        }
    }
}

class MatroidThree
{
private:
    string* setS;
    string* subsetI;
    int size_;
public:
    MatroidThree(string array[], int size);
    void operator()();
};

MatroidThree::MatroidThree(string array[], int size){
    subsetI = NULL;
    size_ = size;
    for(int counter = 0; counter < size; counter++){
        setS[counter] = array[counter];
    }

}
void MatroidThree::operator ()(){
    int currentIndex = 0;
    for(int element = 0; element < size_;element++){
        if(setS[element].length() >= 6){
            subsetI[currentIndex] = setS[element];
            currentIndex++;
        }
    }
}

int main()
{
    MatroidOne first = new MatroidOne( new int{5,7,15,17,20},5);
    MatroidTwo second = new MatroidTwo({true,false,true,false,false,false},6);
    MatroidThree third = new MatroidThree({"carro","prueba","silaba","casa","palabra"},5);

    MatroidProcessor processor = new MatroidProcessor({first,second,third},3);

    return 0;
}
