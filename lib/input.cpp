

#include <multiplatformhello/input.h>

InputReplicate::InputReplicate(int argc, char **argv)
  : d_argc(argc),
    d_argv(argc)
{
  d_input = "";
  for(int idx = 0; idx < argc; idx++){
    d_input += std::string(argv[idx]);
    if(idx < argc-1) d_input += " ";
  }
}

InputReplicate::~InputReplicate()
{
}

std::string& InputReplicate::get_input()
{
  return d_input;
}