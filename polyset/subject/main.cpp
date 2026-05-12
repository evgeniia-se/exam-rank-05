#include "s_t_b.hpp"
#include "s_a_b.hpp"
#include <cstdlib>
#include <iostream>
#include "set.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		return 1;

	searchable_bag	*t = new s_t_b;
	searchable_bag	*a = new s_a_b;

	for (int i = 1; i < ac; i++)
	{
		t->insert(atoi(av[i]));
		a->insert(atoi(av[i]));
	}
	t->print();
	a->print();

	for (int i = 1; i < ac; i++)
	{
		std::cout << t->has(atoi(av[i])) << std::endl;
		std::cout << a->has(atoi(av[i])) << std::endl;
		std::cout << t->has(atoi(av[i]) - 1) << std::endl;
		std::cout << a->has(atoi(av[i]) - 1) << std::endl;
	}
	t->clear();
	a->clear();

	const s_a_b	tmp(static_cast<s_a_b &>(*a));
	tmp.print();
	tmp.has(1);

	set	sa(*a);
	set	st(*a);

	for (int i = 1; i < ac; i++)
	{
		st.insert(atoi(av[i]));
		sa.insert(atoi(av[i]));
	}
	sa.has(atoi(av[1]));
	sa.print();
	sa.get_bag().print();
	st.print();
	sa.clear();

 	int	arr[] = {1, 2, 3, 4,};
	sa.insert(arr, 4);

	return 0;
}