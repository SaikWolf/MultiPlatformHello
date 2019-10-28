
#include <iostream>
#include <multiplatformhello/api.h>

int main(int argc, char **argv)
{
    for(int idx = 0; idx < argc; idx++){
        std::cout << argv[idx];
        if(idx < argc - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl << std::endl;

    std::cout << "Hello World from " << get_platform() << " with compiler " << get_compiler() << std::endl;
    std::cout << "Version 1" << std::endl;

    return 0;
}