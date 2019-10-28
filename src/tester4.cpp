
#include <iostream>
#include <chrono>
#include <thread>
#include <multiplatformhello/hello.h>
#include <multiplatformhello/input.h>


void printer(int microdelay, int mode, InputReplicate& maker)
{
    auto begin = std::chrono::steady_clock::now();
    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::microseconds(microdelay));
    auto end = std::chrono::steady_clock::now();
    if(mode==0){
        std::cout << maker.get_input() << std::endl;
    }
    else{
        std::cout << say_hello() << std::endl;
    }
    std::chrono::duration<float> diff = end-start;
    std::chrono::duration<float> res = start-begin;
    std::cout << "Resolution: " << res.count() << std::endl;
    std::cout << "Elapsed: " << diff.count() << std::endl << std::endl;
}

int main(int argc, char **argv)
{
    InputReplicate maker(argc,argv);
    std::thread t1(printer,10,0,std::ref(maker));
    std::thread t2(printer,10000,1,std::ref(maker));

    t1.join();
    t2.join();
    std::cout << "Version 4" << std::endl;

    return 0;
}