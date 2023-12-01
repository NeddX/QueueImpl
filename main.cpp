#include "Queue.hpp"

int main()
{
    stl::Queue<int> f{ 5, 10, 2, 2 };
    const usize     size = 8;
    for (usize i = 0; i < size / 2; ++i)
        f.Push(std::rand() % 256);

    std::cout << f << std::endl;

    for (usize i = 0; i < (size / 2) / 2; ++i)
        std::cout << f.Pop() << std::endl;

    std::cout << f << std::endl;

    for (usize i = 0; i < size / 2; ++i)
        f.Push(std::rand() % 256);

    std::cout << std::endl;
    std::cout << f << std::endl;
    for (usize i = 0; i < size; ++i)
    {
        try
        {
            std::cout << f.Pop() << std::endl;
            std::cout << f << std::endl;
        }
        catch (std::exception& ex)
        {
        }
    }

    if (!f.Empty())
    {
        std::cout << "First: " << f.Front() << "\nBack: " << f.Back() << std::endl;
    }
    return 0;
}
