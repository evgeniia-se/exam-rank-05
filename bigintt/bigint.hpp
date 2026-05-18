#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class bigint{
		private:
		std::vector<int> _digits;
		void _remouveLeadingZeros();
		int _toInt() const;
	public:
		bigint();
		bigint(unsigned long long n);
		bigint(const bigint &other);
		bigint &operator=(const bigint &other);
		~bigint();

		bigint &operator+=(const bigint &other);
		bigint operator+(const bigint &other) const;

		bigint &operator++();
		bigint operator++(int);

		bigint &operator<<=(unsigned int n);
		bigint operator<<(unsigned int n) const;


		bigint &operator>>=(unsigned int n);
		bigint operator>>(unsigned int n) const;
		bigint &operator>>=(const bigint &other);
		bigint operator>>(const bigint &other) const;

		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator>=(const bigint &other) const;

		void print(std::ostream &os) const;

};
std::ostream &operator<<(std::ostream &os, const bigint &obj);

#endif

