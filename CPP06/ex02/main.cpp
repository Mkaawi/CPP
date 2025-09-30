#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    static bool seeded = 0;
    if (!seeded)
    {
        std::srand(std::time(0));
        seeded = 1;
    }

    int random = std::rand() % 3;

    switch (random)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return new A();
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {
    }
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        Base *obj = generate();

        std::cout << "Pointer identification: ";
        identify(obj);

        std::cout << "refrence identification: ";
        identify(*obj);

        std::cout << std::endl;
        delete obj;
    }
    return 0;
}