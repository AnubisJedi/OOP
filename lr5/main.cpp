#include "static-resource.hpp"
#include "list.hpp"
#include <string>
#include <iostream>

struct MyStruct {
    int a;
    double b;
    std::string c;

    MyStruct(int x, double y, std::string z) : a(x), b(y), c(std::move(z)) {}
};

int main() {
    ListMemoryResource myMemRes;

    {
        PmrList<int> intList(&myMemRes);
        intList.push_back(1);
        intList.push_back(2);
        intList.push_back(3);

        std::cout << "intList: ";
        for (auto& val : intList) {
            std::cout << val << " ";
        }
        std::cout << "\n";

        PmrList<MyStruct> structList(&myMemRes);
        structList.push_back(MyStruct(10, 3.14, "Hello"));
        structList.push_back(MyStruct(20, 2.71, "World"));
        structList.push_back(MyStruct(30, 1.61, "!!!"));

        std::cout << "structList:\n";
        for (auto& obj : structList) {
            std::cout << "  a=" << obj.a << ", b=" << obj.b << ", c=" << obj.c << "\n";
        }
    }

    return 0;
}