#pragma once
#include <iostream>
#include <fstream>

class Twelve {
private:
    unsigned char *digits = nullptr;
    size_t size;

    void allocBuffer (size_t bufSize);
    void rmZeros ();

public:
    Twelve (); // конструктор для случая Twelve a;
    Twelve (const size_t &length, unsigned char digit = '0'); // конструктор для случая Twelve a(4, '0');
    Twelve (const std::initializer_list<unsigned char> &list); // конструктор для случая Twelve a({1, 2, 3});
    Twelve (const std::string &str); // конструктор для случая Twelve a("123");
    Twelve (const Twelve &other); // конструктор для случая Twelve a; Twelve b(a);
    Twelve (Twelve &&other) noexcept; // 
    virtual ~Twelve() noexcept;

    bool operator== (const Twelve &other) const;
    bool operator< (const Twelve &other) const;
    bool operator> (const Twelve &other) const;
    Twelve& operator= (const Twelve &other);
    Twelve& operator+= (const Twelve &other);
    Twelve& operator-= (const Twelve &other);

    friend std::ostream& operator<< (std::ostream& os, const Twelve &number);
};

std::ostream& operator<< (std::ostream& os, const Twelve &number);