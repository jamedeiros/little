#include <entity.h>
#include <iostream>

using namespace std;

int main(void) {
    Foo foo = Foo(10);

    std::cout << "Hello World!" << std::endl;
    std::cout << foo.bar() << std::endl;
    return 0;
}