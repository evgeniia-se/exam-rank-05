#ifndef EXAM_ASSIGNMENTS_SORTABLE_HPP
# define EXAM_ASSIGNMENTS_SORTABLE_HPP

# include "bag.hpp"

class searchable_bag :
	virtual public bag
{
public:
	/* --- Core Methods --- */
	virtual bool	has(int) const = 0;
};

#endif