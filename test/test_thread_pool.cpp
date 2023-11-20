#include <ftd/ThreadPool.h>

#include <cstdlib>
#include <iostream>


int f(int x, int y) { return static_cast<int>(std::pow(x, y)); }

std::mutex m;

void g(int i)
{
    std::lock_guard<std::mutex> lock{ m };
    std::cout << "g(" << i <<")" << std::endl;
}

constexpr static int kTasks = 10000;

int main(int argc, char* argv[])
{
    ftd::ThreadPool tp{};

    auto res = tp.submit(f, 2, 9);

    std::cout << res.get() << std::endl;

    for (auto i = 0; i < kTasks; ++i)
        tp.submit(g, i);

    while (!tp.completed());

    return EXIT_SUCCESS;
}
