   #include "vect2.hpp"

   vect2::vect2() : _x(0), _y(0) {}

    vect2::vect2(int a, int b) : _x(a), _y(b){}

    vect2::vect2(const vect2 &other) : _x(other._x), _y(other._y){}

    vect2 &vect2::operator=(const vect2 &other){
        if(this!= &other){
            _x = other._x;
            _y = other._y;
        }
        return *this;

    }

    vect2::~vect2(){}

    vect2 &vect2::operator+=(const vect2 &other){
        _x += other._x;
        _y += other._y;
        return *this;
    }
    vect2 vect2::operator+(const vect2 &other) const{
        return vect2(*this) += other;
    }
    vect2 &vect2::operator++(){
        _x++;
        _y++;
            return *this;
        }
    vect2 vect2::operator++(int){
            vect2 tmp(*this);
            ++(*this);
            return tmp;
        }

    vect2 &vect2::operator-=(const vect2 &other){
        _x -= other._x;
        _y -= other._y;
        return *this;
    }
    vect2 vect2::operator-(const vect2 &other) const{
        return vect2(*this) -= other;
    }

    vect2 &vect2::operator--(){
        _x--;
        _y--;
        return *this ;
    }
    vect2 vect2::operator--(int){
        vect2 tmp(*this);
            --(*this);
            return tmp;
        }


    vect2 vect2::operator-() const{
        return vect2(-_x, -_y);

    }
    vect2 &vect2::operator*=(int scalar){
        _x *= scalar;
        _y *= scalar;
        return *this;
    }
    vect2 vect2::operator*(int scalar) const{
        return vect2(*this) *= scalar;
    }

    bool vect2::operator==(const vect2 &other) const{
        return (_x == other._x && _y == other._y);
    }
    bool vect2::operator!=(const vect2 &other) const{
        return !(*this == other);
    }
    int	&vect2::operator[](int i){
        return (i == 0) ? _x : _y;
    }
    const int	&vect2::operator[](int i) const{
        return (i == 0) ? _x : _y;
    }

    vect2 operator*(int scalar, const vect2 &v){
        return v * scalar;
    }
    std::ostream &operator<<(std::ostream &os, const vect2 &obj){
        os << "{" << obj[0] << ", " << obj[1] << "}";
        return os;
    }
