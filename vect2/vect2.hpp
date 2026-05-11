#ifndef VECT2_HPP
#define VECT2_HPP


#include <iostream>
#include <cmath>

class vect2{
    private:
        int _x;
        int _y;
    public:
        vect2();
        vect2(int a, int b);
        vect2(const vect2 &other);
        vect2 &operator=(const vect2 &other);
        ~vect2();

        vect2 &operator++();
        vect2 operator++(int);
        vect2 &operator--();
        vect2 operator--(int);

        vect2 &operator+=(const vect2 &other);
        vect2 operator+(const vect2 &other) const;
        vect2 &operator-=(const vect2 &other);
        vect2 operator-(const vect2 &other) const;  
        vect2 operator-() const;
        vect2 &operator*=(int scalar);
        vect2 operator*(int scalar) const;

        bool operator==(const vect2 &other) const;
        bool operator!=(const vect2 &other) const;
        int	&operator[](int i);          
	    const int	&operator[](int i) const;

};
    vect2 operator*(int scalar, const vect2 &v);
    std::ostream &operator<<(std::ostream &os, const vect2 &obj);


#endif