#ifndef S_T_B_HPP
#define S_T_B_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"
#include <iostream>

class s_t_b : public tree_bag, public searchable_bag{
    public:
    s_t_b();
    s_t_b(const s_t_b &other);
    s_t_b &operator=(const s_t_b &other);
    virtual ~s_t_b();

    virtual bool has(int v) const;

};

#endif