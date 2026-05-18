<<<<<<< HEAD
()
#ifndef S_T_B_HPP
#define S_T_B_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class s_t_b : public array_bag, public searchable_bag{
	public:
		s_t_b();
		s_tb(const s_a_b &other);
		s_t_b &operator=(const s_t_b &other);
		virtual ~s_t_b();
		virtual bool has(int value) const;

};


#endif
=======
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
>>>>>>> refs/remotes/origin/main
