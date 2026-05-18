#include "set.hpp"

set::set(searchable_bag &n) : _bag(&n){}

 set::set(const set &other) : _bag(other._bag){}

set &set::operator=(const set &other){
    if (this != &other)
        _bag = other._bag;
    return *this;
}
        set::~set(){}


void set::insert(int value) {
    if(this->_bag != NULL && this->_bag->has(value) == false)
        this->_bag->insert(value);
}

void set::insert(int *arr, int size){
    if(this->_bag != NULL && arr != NULL){
        for (int i = 0; i < size; ++i)
            this->insert(arr[i]);
    }
}

bool set::has(int value) const{
    return _bag ? _bag->has(value) : false;
}

void set::print(void) const{
    if(_bag)
        _bag->print();
}

void set::clear() {
    if(_bag)
        _bag->clear();
}

searchable_bag &set::get_bag() const{
    return *_bag;
}