#ifndef __RUNNER__
#define __RUNNER__
#include <cstddef>
#include <string>
#include <vector>

namespace Brainfuck {

class Runner{
public:

    unsigned char* memory;
    size_t memory_len;
    unsigned char* cursor;

    char* program;
    int bracket_level;

    Runner();

    void run_program(std::string string);
    void run_op(const char c);

private:
    void move_cursor_right();

};


}
#endif