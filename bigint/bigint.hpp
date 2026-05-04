#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint {
private:
    std::string d;

    // Внутренний метод для перевода числа обратно в size_t для сдвигов
    size_t to_size_t() const;

public:
    // --- Ортодоксальная Каноническая Форма ---
    bigint();
    bigint(const bigint& other);
    bigint& operator=(const bigint& other);
    ~bigint();

    // --- Конструктор из числа ---
    bigint(unsigned long long v);

    // --- Арифметика ---
    bigint& operator+=(const bigint& o);
    bigint operator+(const bigint& o) const;

    // --- Инкременты ---
    bigint& operator++();       // Префиксный ++b
    bigint operator++(int);     // Постфиксный b++

    // --- Сдвиги для чисел (size_t) ---
    bigint& operator<<=(size_t shift);
    bigint operator<<(size_t shift) const;
    bigint& operator>>=(size_t shift);
    bigint operator>>(size_t shift) const;

    // --- Сдвиги для объектов (bigint) ---
    bigint& operator<<=(const bigint& shift);
    bigint operator<<(const bigint& shift) const;
    bigint& operator>>=(const bigint& shift);
    bigint operator>>(const bigint& shift) const;

    // --- Сравнения ---
    bool operator==(const bigint& o) const;
    bool operator!=(const bigint& o) const;
    bool operator<(const bigint& o) const;
    bool operator>(const bigint& o) const;
    bool operator<=(const bigint& o) const;
    bool operator>=(const bigint& o) const;

    // --- Метод печати для потока вывода ---
    void print(std::ostream& os) const;
};

// Внешний оператор вывода (без всяких friend)
std::ostream& operator<<(std::ostream& os, const bigint& b);

#endif
