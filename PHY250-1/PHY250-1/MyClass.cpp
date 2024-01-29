//
//  MyClass.cpp
//  PHY250-1
//
//  Created by Andrew Diggs on 1/15/24.
//

#include "MyClass.hpp"


PHY::vecN::vecN(){};
PHY::vecN::vecN(int num)
{
    INIT(num);
};


PHY::vecN::~vecN(){
    if(is_init){
        //delete[] m_vals;
        free(m_vals);
    }
}

void PHY::vecN::INIT(int num){
    m_num_el = num;
    //m_vals = new float[m_num_el];
    m_vals = (float*)malloc(m_num_el*sizeof(float));
    is_init = true;
    Fill();
}


void PHY::vecN::Fill(){
    for(int i=0; i<m_num_el; i++){
        m_vals[i] = i;
    }
}

float* PHY::vecN::Get_Vals(){
    return m_vals;
}


PHY::vecN& PHY::vecN::operator=(const PHY::vecN& other){
    if(!is_init){
        this->INIT(other.m_num_el);
        this->m_num_el = other.m_num_el;
    }
    else if(this->m_num_el != other.m_num_el){
        printf("WHAT ARE YOU TRYING TO DO FOOL!!!!!!\n");
        exit(10);
    }
    for(int i=0; i<m_num_el; i++) {
        this->m_vals[i] = other.m_vals[i];
    }
    return *this;
}

float& PHY::vecN::operator[](const int index){
    if(!is_init){
        printf("Vector is not initialized!!!\nExiting\n");
        exit(10);
    }
    
    if(index >= m_num_el){
        printf("Out of bounds access. Vector[%d] is an undefined value!\n",index);
        exit(10);
    }
    
    return m_vals[index];
}
    
PHY::vecN PHY::vecN::operator+(vecN& other){
    if(other.Get_Num() != this->Get_Num()){
        printf("Sizes do not match\n");
        exit(10);
    }
    PHY::vecN ret(this->Get_Num());
    for(int i=0; i<this->Get_Num();i++){
        ret[i] = this->m_vals[i] + other[i];
    }
    
    return ret;
}

int PHY::vecN::Get_Num(){
    return m_num_el;
}

void PHY::vecN::Print(){
    if(!is_init){
        printf("I am a blank array\n");
        return;
        }
    printf("I am an array with %d floats\n", m_num_el);
    for(int i = 0; i < m_num_el; i++){
        printf("Vals[%d] = %.2f\n",i, m_vals[i]);
    }
}



//###########################################################################################
//###########################################################################################
//###########################################################################################
//###########################################################################################

PHY::vec3::vec3()
:x(0.0), y(0.0), z(0.0)
{}

PHY::vec3::vec3(float ex, float ey, float ez)
:x(ex), y(ey), z(ez)
{}

PHY::vec3::~vec3()
{}

float& PHY::vec3::operator[](const int index) {
    return (&x)[index];
}

PHY::vec3 PHY::vec3::operator+(const PHY::vec3 &other) const {
    float rx = this->x + other.x;
    float ry = this->y + other.y;
    float rz = this->z + other.z;
    
    return PHY::vec3(rx,ry,rz);
}

PHY::vec3 PHY::vec3::operator-(const PHY::vec3 &other) const {
    float rx = this->x - other.x;
    float ry = this->y - other.y;
    float rz = this->z - other.z;
    
    return PHY::vec3(rx,ry,rz);
}

PHY::vec3 PHY::vec3::operator*(const PHY::vec3 &other) const {
    float rx = this->x * other.x;
    float ry = this->y * other.y;
    float rz = this->z * other.z;
    
    return PHY::vec3(rx,ry,rz);
}

PHY::vec3 PHY::vec3::operator/(const PHY::vec3 &other) const {
    float rx = this->x / other.x;
    float ry = this->y / other.y;
    float rz = this->z / other.z;
    
    return PHY::vec3(rx,ry,rz);
}


void PHY::vec3::operator+=(const PHY::vec3& other){
    this->x = this->x + other.x;
    this->y = this->y + other.y;
    this->z = this->z + other.z;
}
