#include <iostream>
#include <string>
#include "matroidprocessor.h"
#include <functional>
#include "matroid.h"

using namespace std;




int main()
{
    int arr[5] = {10,4,68,9,15};
    Matroid* matroid = new Matroid(arr,5,&Matroid::intFunction);
    matroid->matroidFunction();
    getchar();

    return 0;
}
