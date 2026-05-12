#include "s_t_b.hpp"

    s_t_b::s_t_b(){
        tree_bag();
    }
    s_t_b::s_t_b(const s_t_b &other) : tree_bag(other){
    }
    s_t_b &s_t_b::operator=(const s_t_b &other){
        if (this != &other)
            tree_bag::operator=(other);
        return *this;
    }
     s_t_b::~s_t_b(){}

     bool s_t_b::has(int v) const{
        node *tmp = this->tree;
        while (tmp != NULL)
        {
            if(tmp->value == v)
                return true;
            if(v < tmp->value)
                tmp = tmp->l;
            else
                tmp = tmp->r;
        }
        return false;
     }