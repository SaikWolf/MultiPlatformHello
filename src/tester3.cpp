
#include <iostream>
#include <chrono>
#include <thread>
#include <multiplatformhello/api.h>

void printer(int microdelay, std::string& msg)\
{
    auto begin = std::chrono::steady_clock::now();
    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::microseconds(microdelay));
    auto end = std::chrono::steady_clock::now();
    std::cout << msg << std::endl;
    std::chrono::duration<float> diff = end-start;
    std::chrono::duration<float> res = start-begin;
    std::cout << "Resolution: " << res.count() << std::endl;
    std::cout << "Elapsed: " << diff.count() << std::endl;
}

int main(int argc, char **argv)
{
    std::string message = "Hello World from " + get_platform() + " with compiler " + get_compiler();
    std::thread t(printer,10000,std::ref(message));
    for(int idx = 0; idx < argc; idx++){
        std::cout << argv[idx];
        if(idx < argc - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl << std::endl;

    t.join();
    std::cout << "Version 3" << std::endl;

    return 0;
}