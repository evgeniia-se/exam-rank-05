#ifndef S_A_B_HPP
#define S_A_B_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class s_a_b : public array_bag, public searchable_bag{
    public:
    s_a_b();
    s_a_b(const s_a_b &other);
    s_a_b &operator=(const s_a_b &other);
    virtual ~s_a_b();

    virtual bool has(int value) const;

};

#endif