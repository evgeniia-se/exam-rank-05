#include "bigint.hpp"
#include <algorithm>

// === ОРТОДОКСАЛЬНАЯ КАНОНИЧЕСКАЯ ФОРМА ===
bigint::bigint() : d("0") {}

bigint::bigint(const bigint& other) : d(other.d) {}

bigint& bigint::operator=(const bigint& other) {
    if (this != &other) {
        d = other.d;
    }
    return *this;
}

bigint::~bigint() {}


// === КОНСТРУКТОРЫ ===
bigint::bigint(unsigned long long v) {
    if (v == 0)
		d = "0";
    else {
        while (v > 0) {
			//write reverse number
            d += (char)('0' + (v % 10));
            v /= 10;
        }
    }
}


// === УТИЛИТЫ ===
size_t bigint::to_size_t() const {
    size_t val = 0;
    size_t mult = 1;
    for (size_t i = 0; i < d.size(); ++i) {
        val += (d[i] - '0') * mult;
        mult *= 10;
    }
    return val;
}


// === АРИФМЕТИКА ===
bigint& bigint::operator+=(const bigint& o) {
    int carry = 0;
    size_t max_len = std::max(d.size(), o.d.size());
    for (size_t i = 0; i < max_len || carry; ++i) {
        if (i == d.size()) d += '0'; // Динамически расширяем строку, если нужно
        int sum = (d[i] - '0') + carry;
        if (i < o.d.size()) sum += o.d[i] - '0';
        d[i] = (char)('0' + (sum % 10));
        carry = sum / 10;
    }
    return *this;
}

bigint bigint::operator+(const bigint& o) const {
    bigint res(*this);
    res += o;
    return res;
}

bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint tmp(*this);
    ++(*this);
    return tmp;
}


// === СДВИГИ (DIGITSHIFT) ===
bigint& bigint::operator<<=(size_t shift) {
    if (d != "0" && shift > 0) d.insert(0, shift, '0');
    return *this;
}

bigint bigint::operator<<(size_t shift) const {
    bigint res(*this);
    res <<= shift;
    return res;
}

bigint& bigint::operator>>=(size_t shift) {
    if (shift >= d.size()) d = "0";
    else d.erase(0, shift);
    return *this;
}

bigint bigint::operator>>(size_t shift) const {
    bigint res(*this);
    res >>= shift;
    return res;
}

bigint& bigint::operator<<=(const bigint& shift) { return *this <<= shift.to_size_t(); }
bigint bigint::operator<<(const bigint& shift) const { return *this << shift.to_size_t(); }
bigint& bigint::operator>>=(const bigint& shift) { return *this >>= shift.to_size_t(); }
bigint bigint::operator>>(const bigint& shift) const { return *this >> shift.to_size_t(); }


// === СРАВНЕНИЯ ===
bool bigint::operator==(const bigint& o) const { return d == o.d; }
bool bigint::operator!=(const bigint& o) const { return d != o.d; }

bool bigint::operator<(const bigint& o) const {
    if (d.size() != o.d.size()) return d.size() < o.d.size();
    // Идем с конца строки (то есть со старших разрядов)
    for (int i = (int)d.size() - 1; i >= 0; --i) {
        if (d[i] != o.d[i]) return d[i] < o.d[i];
    }
    return false;
}

bool bigint::operator>(const bigint& o) const { return o < *this; }
bool bigint::operator<=(const bigint& o) const { return !(o < *this); }
bool bigint::operator>=(const bigint& o) const { return !(*this < o); }


// === ВЫВОД В ПОТОК ===
void bigint::print(std::ostream& os) const {
    // Безопасный цикл для C++98 с обычным int
    for (int i = (int)d.size() - 1; i >= 0; --i) {
        os << d[i];
    }
}

std::ostream& operator<<(std::ostream& os, const bigint& b) {
    b.print(os);
    return os;
}
