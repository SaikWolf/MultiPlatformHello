
#include <iostream>
#include <multiplatformhello/hello.h>
#include <multiplatformhello/input.h>

int main(int argc, char **argv)
{
    InputReplicate maker(argc,argv);
    std::cout << maker.get_input() << std::endl << std::endl;

    std::cout << say_hello() << std::endl;

    return 0;
}