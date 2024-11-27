#include <stdexcept>
#include "../include/Twelve.h"

unsigned char validateDigit (unsigned char digit);
unsigned char digitToChar(int digit);
int charToDigit(unsigned char digit);

void Twelve::allocBuffer (size_t bufSize) {
    size = bufSize;
    digits = new(std::nothrow) unsigned char[size];
    if (!digits) throw std::runtime_error("Allocation failed");
}

void Twelve::rmZeros() {
    int firstNonZero = size - 1;

    while (firstNonZero >= 0 && digits[firstNonZero] == '0') {
        --firstNonZero;
    }

    if (firstNonZero < 0) {
        // Если все нули, оставляем одно значение '0'
        allocBuffer(1);
        digits[0] = '0';
        return;
    }

    int newSize = firstNonZero + 1;
    unsigned char* newDigits = new unsigned char[newSize];

    for (int i = 0; i < newSize; ++i) {
        newDigits[i] = digits[i];
    }

    delete[] digits;
    digits = newDigits;
    size = newSize;
}

Twelve::Twelve() {
    allocBuffer(1);
    digits[0] = '0';
}

Twelve::Twelve(const size_t &length, unsigned char digit) {
    validateDigit(digit);

    if (length <= 0) throw std::invalid_argument("Length must be positive");

    allocBuffer(length);
    for (int i = 0; i < size; i++) digits[i] = digit;

    rmZeros();
}

Twelve::Twelve(const std::initializer_list<unsigned char> &list) {
    allocBuffer(list.size());

    int bufferPos = size - 1;
    for (const unsigned char &digit : list) {
        digits[bufferPos--] = validateDigit(digit);
    } 

    rmZeros();
}

Twelve::Twelve(const std::string &str) {
    allocBuffer(str.length());

    for (int i = 0; i < size; i++) {
        digits[size - 1 - i] = validateDigit(str[i]);
    } 

    rmZeros();
}

Twelve::Twelve(const Twelve& other) {
    delete [] digits;
    allocBuffer(other.size);

    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }
}

Twelve::Twelve(Twelve&& other) noexcept {
    size = other.size;
    digits = other.digits;
    other.size = 0;
    other.digits = nullptr;
}

Twelve::~Twelve() noexcept {
    delete [] digits;
}

bool Twelve::operator== (const Twelve &other) const {
    if (size != other.size) return false;

    for (int i = 0; i < size; i++) {
        if (digits[i] != other.digits[i]) return false;
    }

    return true;
}

bool Twelve::operator< (const Twelve &other) const {
    if (size < other.size) return true;
    if (size > other.size) return false;

    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] - '0' < other.digits[i] - '0') return true;
        if (digits[i] - '0' > other.digits[i] - '0') return false;
    }

    return false;
}

bool Twelve::operator> (const Twelve &other) const {
    if (size > other.size) return true;
    if (size < other.size) return false;

    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] - '0' > other.digits[i] - '0') return true;
        if (digits[i] - '0' < other.digits[i] - '0') return false;
    }

    return false;
}

Twelve& Twelve::operator= (const Twelve &other) {
    if (this == &other) {
        throw std::logic_error("Self asigment");
    }

    if (digits) delete [] digits;
    allocBuffer(other.size);

    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }

    return *this;
}


std::ostream& operator<< (std::ostream& os, const Twelve &number) {
    os << "0t";
    for (int i = number.size - 1; i >= 0; i--) {
        os << digitToChar(charToDigit(number.digits[i]));
    }
    return os;
};

Twelve& Twelve::operator+=(const Twelve& other) {
    size_t maxSize = std::max(size, other.size) + 1; // Запас на перенос
    unsigned char* newDigits = new unsigned char[maxSize]();

    int carry = 0;
    for (int i = 0; i < maxSize - 1; ++i) {
        int thisDigit = i < size ? charToDigit(digits[i]) : 0;
        int otherDigit = i < other.size ? charToDigit(other.digits[i]) : 0;

        int sum = thisDigit + otherDigit + carry;
        carry = sum / 12;
        newDigits[i] = digitToChar(sum % 12);
    }

    if (carry > 0) {
        newDigits[maxSize - 1] = digitToChar(carry);
    } else {
        --maxSize; // Уменьшить длину, если перенос отсутствует
    }

    delete[] digits;
    digits = newDigits;
    size = maxSize;

    rmZeros(); // Удаление лидирующих нулей, если нужно
    return *this;
}

Twelve& Twelve::operator-=(const Twelve& other) {
    if (*this < other) throw std::logic_error("Cannot subtract larger number from smaller one");

    int borrow = 0;
    for (int i = 0; i < size; ++i) {
        int thisDigit = i < size ? charToDigit(digits[i]) : 0;
        int otherDigit = i < other.size ? charToDigit(other.digits[i]) : 0;

        int diff = thisDigit - otherDigit - borrow;
        if (diff < 0) {
            diff += 12;
            borrow = 1;
        } else {
            borrow = 0;
        }

        digits[i] = digitToChar(diff);
    }

    rmZeros(); // Удаление лидирующих нулей
    return *this;
}


unsigned char validateDigit (unsigned char digit) {
    if ((digit >= '0' && digit <= '9') || (digit >= 'a' && digit <= 'b')) {
        return digit;
    }
    throw std::invalid_argument("Invalid digit");
}

int charToDigit(unsigned char digit) {
    return (digit >= '0' && digit <= '9') ? (digit - '0') : (digit - 'a' + 10);
}

unsigned char digitToChar(int digit) {
    return (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
}