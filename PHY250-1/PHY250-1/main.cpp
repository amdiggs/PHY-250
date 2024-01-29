//
//  main.cpp
//  PHY250-1
//
//  Created by Andrew Diggs on 1/10/24.
//

#include <iostream>
#include "MyClass.hpp"




int main(int argc, const char * argv[]) {
    PHY::vec3 A(2.0,2.0,2.0);
    PHY::vec3 B(1.0,2.0,3.0);
    
    A+=B;
    
    for(int i = 0; i < 3; i++){
        printf("arr[%d] = %.1f\n",i,A[i]);
    }
}

//=======================================================================================================
