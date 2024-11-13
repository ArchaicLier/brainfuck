#include "runner.hpp"
#include <iostream>

int main(int cargs, char** args){
 
    Brainfuck::Runner runner{};

    runner.run_program(args[1]);

};