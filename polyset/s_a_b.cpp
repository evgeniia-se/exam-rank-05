<<<<<<< HEAD
#include "s_t_b.hpp"

s_t_b::s_t_b(){
	tree_bag();
}

	s_t_b::s_t_b(const s_t_b &other){
		tree_bag(other);
	}
	s_t_b &s_t_b::operator=(const s_t_b &other){
		if(this != &other)
			tree_bag::operator=(other);
		return *this;
	}
	s_t_b::~s_t_b(){}

	bool s_t_b::has(int value) const{
		node *tmp = this->tree;

		while(tmp != NULL){
			if(tmp->value == value)
				return true;
			if(value < tmp->value)
				tmp = tmp->l;
			else
				tmp = tmp->r;
		}
		return false;
	}


void insert(int value){
	if(this->_bag != NULL && this->bag->has(value) == false)
		this->insert(value);
}


set::set(searchable &bag){
	_bag(&bag);

}

_bag(other._bag)
=======
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
>>>>>>> refs/remotes/origin/main
