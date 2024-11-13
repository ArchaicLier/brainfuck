#include "runner.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace Brainfuck {

Runner::Runner(){

    memory_len = 10;
    memory = new unsigned char[memory_len];
    cursor = memory;

}

void Runner::run_program(std::string string){


    int pos = 0;
    while (pos<string.length()){
        
        //std::cout<<"pos: "<<pos<<'\n';
        const char c = string[pos];

        //TODO: Rewrite to switch.
        if (c=='+'){
            *(cursor)+=1;
        }

        if (c=='-'){
            *(cursor)-=1;
        }

        if (c=='>'){
            move_cursor_right();
        }

        if (c=='<'){
            cursor--;
            if (cursor-memory<0){
                cursor++;
            }
        }

        if (c=='.'){
            std::cout<<*(cursor);
        }

        if (c==','){
            std::cin>>*(cursor);
        }

        if (c=='['){
            bracket_level++;
            if (*cursor==0){
                while (bracket_level>0){
                    //jmp to ]
                    pos++;
                    switch (string[pos]) {
                        case '[':
                            bracket_level++;
                            break;
                        case ']':
                            bracket_level--;
                            break;
                    }
                }
            }
            
        }

        if (c==']'){
            if (static_cast<int>(*cursor)!=0){
                int braces = 1;
                while (braces!=0){
                    pos--;
                    switch (string[pos]) {
                        case '[':
                            braces--;
                            break;
                        case ']':
                            braces++;
                            break;
                    }
                }
            }
        }

        pos++;
    }

    


}

// private

void Runner::move_cursor_right(){

    if ( cursor-memory > memory_len-1 ){
        int pos = cursor-memory;
        memory_len+=10;
        unsigned char* new_memory = new unsigned char[memory_len];
        std::copy(memory, memory+(memory_len-10), new_memory);
        delete memory;
        memory = new_memory;
        cursor = memory;
        cursor+=pos;
    }
    cursor++;
    //std::cout<<"point: "<<cursor-memory<<"\n";

}

}