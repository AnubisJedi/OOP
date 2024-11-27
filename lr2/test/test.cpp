#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/Twelve.h"

// Проверка конструктора по умолчанию
TEST(default_constructor, default_constructor) {
    Twelve number(1, '0');
    Twelve numberDefault;
    
    bool result = number == numberDefault;    
    ASSERT_TRUE(result);
}

// Проверка конструктора с длиной: некорректный символ
TEST(length_constructor, incorrect_digit) {
    EXPECT_THROW(Twelve number(1, 'c'), std::invalid_argument);
    EXPECT_THROW(Twelve number(1, 'd'), std::invalid_argument);
}

// Проверка конструктора с длиной: некорректная длина
TEST(length_constructor, incorrect_length) {
    EXPECT_THROW(Twelve number(0, '0'), std::invalid_argument);
}

// Проверка конструктора с длиной: лидирующие нули
TEST(length_constructor, leading_zeros) {
    Twelve numberMultiZeros(2, '0');
    Twelve numberZero;

    bool result = numberMultiZeros == numberZero;    
    ASSERT_TRUE(result);
}

// Проверка конструктора со списком инициализации
TEST(init_list_constructor, init_list_constructor) {
    Twelve numberRef(3, '1');
    Twelve number{'1', '1', '1'};

    bool result = number == numberRef;    
    ASSERT_TRUE(result);
}

// Проверка конструктора со списком инициализации: некорректный символ
TEST(init_list_constructor, incorrect_digit) {
    EXPECT_THROW(Twelve number({'c'}), std::invalid_argument);
    EXPECT_THROW(Twelve number({'1', '2', 'c', '0'}), std::invalid_argument);
    EXPECT_THROW(Twelve number({'1', '2', '5', '0', 'd'}), std::invalid_argument);
}

// Проверка конструктора со списком инициализации: лидирующие нули
TEST(init_list_constructor, leading_zeros) {
    Twelve number1{'0', '0', '1', '2', '3', '0'};
    Twelve number2{'1', '2', '3', '0'};

    bool result = number1 == number2;    
    ASSERT_TRUE(result);
}

// Проверка конструктора из строки
TEST(str_constructor, str_constructor) {
    Twelve numberRef{'1', '2', '3'};
    Twelve number("123");

    bool result = number == numberRef;
    ASSERT_TRUE(result);
}

// Проверка конструктора из строки: некорректный символ
TEST(str_constructor, incorrect_digit) {
    EXPECT_THROW(Twelve number("c"), std::invalid_argument);
    EXPECT_THROW(Twelve number("12d0"), std::invalid_argument);
    EXPECT_THROW(Twelve number("1a50f"), std::invalid_argument);
}

// Проверка конструктора из строки: лидирующие нули
TEST(str_constructor, leading_zeros) {
    Twelve number1("001230");
    Twelve number2("1230");

    bool result = number1 == number2;    
    ASSERT_TRUE(result);
}

// Проверка конструктора копирования
TEST(copy_constructor, copy_constructor) {
    Twelve number1("1234");
    Twelve number2{number1};

    bool result = number1 == number2;
    ASSERT_TRUE(result);
}

// Проверка конструктора перемещения
TEST(move_constructor, move_constructor) {
    Twelve numberOriginal("1234");
    Twelve numberOriginalCopy{numberOriginal};
    Twelve number{std::move(numberOriginal)};

    bool result = numberOriginalCopy == numberOriginalCopy;
    ASSERT_TRUE(result);
}

// Проверка оператора присваивания
TEST(assigment, common) {
    Twelve number1;
    Twelve number2("1234");

    number1 = number2;
    
    bool result = number1 == number2;
    ASSERT_TRUE(result);
}

// Проверка присваивания самому себе
TEST(assigment, self_assigment_error) {
    Twelve number;
    EXPECT_THROW(number = number, std::logic_error);
}

// Проверка оператора меньше
TEST(less, less) {
    Twelve number("20");

    Twelve numberLessLen("1");
    Twelve numberLess("15");
    Twelve numberEqual("20");
    Twelve numberMore("21");
    Twelve numberMoreLen("111");

    ASSERT_TRUE(numberLessLen < number);
    ASSERT_TRUE(numberLess < number);
    ASSERT_FALSE(numberEqual < number);
    ASSERT_FALSE(numberMore < number);
    ASSERT_FALSE(numberMoreLen < number);
}

// Проверка оператора больше
TEST(more, more) {
    Twelve number("20");

    Twelve numberLessLen("1");
    Twelve numberLess("15");
    Twelve numberEqual("20");
    Twelve numberMore("21");
    Twelve numberMoreLen("111");

    ASSERT_FALSE(numberLessLen > number);
    ASSERT_FALSE(numberLess > number);
    ASSERT_FALSE(numberEqual > number);
    ASSERT_TRUE(numberMore > number);
    ASSERT_TRUE(numberMoreLen > number);
}

// Проверка сложения с нулём
TEST(add, zero) {
    Twelve number1("1234a");
    Twelve number1Copy{number1};
    Twelve numberZero;

    number1 += numberZero;

    ASSERT_TRUE(number1 == number1Copy);
}

// Проверка обычного сложения
TEST(add, common) {
    Twelve number1("1023");
    Twelve number2("35");
    Twelve numberRes("1058");

    number1 += number2;

    ASSERT_TRUE(number1 == numberRes);
}

// Проверка сложения с увеличением длины
TEST(add, extend) {
    Twelve number1("b00a1");
    Twelve number2("a00b3");
    Twelve numberRes("190194");

    number1 += number2;

    ASSERT_TRUE(number1 == numberRes);
}

// Проверка вычитания
TEST(sub, zero) {
    Twelve number1("1234");
    Twelve number1Copy{number1};
    Twelve numberZero;

    number1 -= numberZero;

    ASSERT_TRUE(number1 == number1Copy);
}

// Проверка обычного вычитания
TEST(sub, common) {
    Twelve number1("1023");
    Twelve number2("14");
    Twelve numberRes("100b");

    number1 -= number2;

    ASSERT_TRUE(number1 == numberRes);
}

// Проверка ошибки вычитания большего из меньшего
TEST(sub, less_error) {
    Twelve number1("1");
    Twelve number2("1000");

    EXPECT_THROW(number1 -= number2, std::logic_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


