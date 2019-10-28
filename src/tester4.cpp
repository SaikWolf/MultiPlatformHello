
#include <iostream>
#include <chrono>
#include <thread>
#include <multiplatformhello/api.h>

void printer(int microdelay, std::string& msg)\
{
    std::this_thread::sleep_for(std::chrono::microseconds(microdelay));
    std::cout << msg << std::endl;
}

int main(int argc, char **argv)
{
    std::string message = "Hello World from " + get_platform() + " with compiler " + get_compiler();
    auto start = std::chrono::steady_clock::now();
    std::thread t(printer,1000,std::ref(message));
    for(int idx = 0; idx < argc; idx++){
        std::cout << argv[idx];
        if(idx < argc - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl << std::endl;

    t.join();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<float> diff = end-start;
    std::cout << "Elapsed: " << diff.count() << std::endl;
    std::cout << "Version 3" << std::endl;

    return 0;
}