//
//  MyClass.hpp
//  PHY250-1
//
//  Created by Andrew Diggs on 1/15/24.
//

#ifndef MyClass_hpp
#define MyClass_hpp

#include <stdio.h>
#include <stdlib.h>

namespace PHY {


class vecN{
    
private:
    int m_num_el = 0;
    float* m_vals = NULL;
    bool is_init = false;
    
public:
    vecN();
    vecN(int num);
    ~vecN();
    
    void INIT(int num);
    void Fill();
    float* Get_Vals();
    int Get_Num();
    
    //Operators to make our lives easy
    vecN& operator=(const vecN& other);
    float& operator[](const int index);
    vecN operator+(vecN& other);
    
    void Print();
    
};



class vec3{
private:
    float x;
    float y;
    float z;
public:
    vec3();
    vec3(float ex, float ey, float ez);
    ~vec3();
    
    float& operator[](const int index);
    vec3 operator+(const vec3& other) const;
    vec3 operator-(const vec3& other) const;
    vec3 operator*(const vec3& other) const;
    vec3 operator/(const vec3& other) const;
    
    void operator+=(const vec3& other);
    
};

struct VEC3{
    double x, y, z;
};








} //End namespace


#endif /* MyClass_hpp */
