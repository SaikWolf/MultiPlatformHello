
#ifndef INCLUDED_MULTIPLATFORMHELLO_HELLO_H
#define INCLUDED_MULTIPLATFORMHELLO_HELLO_H

#include <multiplatformhello/api.h>


inline std::string say_hello()
{
    return "Hello World from " + get_platform() + " with compiler " + get_compiler();
}


#endif /* INCLUDED_MULTIPLATFORMHELLO_HELLO_H */