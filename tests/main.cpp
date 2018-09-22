#include <iostream>
#include "cppopts.h"

int main(int argc, char **argv) {
    cppopts::Options opts;
    opts.addOption("abc", 'a', "Desc", "val");
    opts.addOption("abcd", 'b', "Desc1", "val1");
    opts.parse(argc, argv);
    std::cout << "abc" << " - " << opts["abc"].getString() << std::endl;
    std::cout << "abcd" << " - " << opts["abcd"].getString() << std::endl;
    return 0;
}