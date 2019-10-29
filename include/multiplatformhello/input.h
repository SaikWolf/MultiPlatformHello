#ifndef INCLUDED_MULTIPLATFORMHELLO_INPUT_H
#define INCLUDED_MULTIPLATFORMHELLO_INPUT_H

#include <vector>
#include <string>
#include <multiplatformhello/api.h>

class MULTIPLATFORMHELLO_API InputReplicate
{
 private:
  int d_argc;
  std::vector<std::string> d_argv;
  std::string d_input;

 public:
  InputReplicate(int argc, char **argv);
  ~InputReplicate();

  std::string& get_input();
};

#endif /* INCLUDED_MULTIPLATFORMHELLO_INPUT_H */
