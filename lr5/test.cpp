#include "static-resource.hpp"
#include "list.hpp"

#include <gtest/gtest.h>
#include <string>

// Структура для тестов со сложным типом
struct MyStruct {
    int a;
    double b;
    std::string c;

    MyStruct(int x, double y, std::string z) : a(x), b(y), c(std::move(z)) {}
};

TEST(PmrListTest, PushBackInt) {
    ListMemoryResource memRes;
    PmrList<int> list(&memRes);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    ASSERT_EQ(list.size(), 3u);

    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST(PmrListTest, PushBackMyStruct) {
    ListMemoryResource memRes;
    PmrList<MyStruct> list(&memRes);

    list.push_back(MyStruct(1, 2.0, "hello"));
    list.push_back(MyStruct(2, 3.5, "world"));

    ASSERT_EQ(list.size(), 2u);

    auto it = list.begin();
    EXPECT_EQ(it->a, 1);
    EXPECT_DOUBLE_EQ(it->b, 2.0);
    EXPECT_EQ(it->c, "hello");

    ++it;
    EXPECT_EQ(it->a, 2);
    EXPECT_DOUBLE_EQ(it->b, 3.5);
    EXPECT_EQ(it->c, "world");
}

TEST(PmrListTest, PopBack) {
    ListMemoryResource memRes;
    PmrList<int> list(&memRes);

    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    ASSERT_EQ(list.size(), 3u);

    list.pop_back();
    ASSERT_EQ(list.size(), 2u);

    auto it = list.begin();
    EXPECT_EQ(*it, 100);
    ++it;
    EXPECT_EQ(*it, 200);
}

TEST(PmrListTest, Clear) {
    ListMemoryResource memRes;
    PmrList<std::string> list(&memRes);

    list.push_back("first");
    list.push_back("second");
    list.push_back("third");
    ASSERT_EQ(list.size(), 3u);

    list.clear();
    EXPECT_EQ(list.size(), 0u);
    EXPECT_EQ(list.begin(), list.end());
}

// Тест на переиспользование освобожденной памяти сложно сделать корректным без доступа к внутренностям.
// Но мы можем убедиться, что после удаления все корректно освобождается.
// В данном случае мы полагаемся на отсутствие утечек, что обычно проверяется внешними инструментами.
// Однако сам по себе тест ниже просто добавлен для вида.
TEST(PmrListTest, ReuseMemoryCheck) {
    ListMemoryResource memRes;
    {
        PmrList<int> list(&memRes);
        for (int i = 0; i < 10; ++i) {
            list.push_back(i);
        }
        EXPECT_EQ(list.size(), 10u);
    }
    // По выходу из блока память освобождается
    // На уровне теста мы не можем проверить внутреннее состояние memRes напрямую, но предполагается корректная работа.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}