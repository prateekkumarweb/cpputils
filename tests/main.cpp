#include <iostream>
#include "cppopts.h"

int main(int argc, char **argv) {
  cppopts::Options opts;
  opts.addOption("abc", 'a', "Desc", "val");
  opts.addOption("abcd", 'b', "Desc1", "val1");
  opts.parse(argc, argv);
  std::cout << "abc"
            << " - " << opts[std::string("abc")].getValue() << std::endl;
  std::cout << "abcd"
            << " - " << opts[std::string("abcd")].getValue() << std::endl;
  return 0;
}
