#include "s_a_b.hpp"

    s_a_b::s_a_b(){
        array_bag();
    }
    s_a_b::s_a_b(const s_a_b &other) : array_bag(other){
    }
    s_a_b &s_a_b::operator=(const s_a_b &other){
        if(this != &other)
            array_bag::operator=(other);
        return *this;
    }
    s_a_b::~s_a_b(){}

    bool s_a_b::has(int value) const{
        for(int i = 0; i < size; i++){
            if(data[i] == value)
                return true;
        }
        return false;
    }