#include <cctype>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "token.h"

bool is_alphabet_char(char c) {
    return std::isalpha(c) || c == '_';
}

std::vector<Token> tokenizer(std::string source_code) {

    std::vector<Token> v;
    char current_char;

    while(source_code.length() > 0) {
        
        current_char = source_code[0]; 
        source_code = source_code.substr(1);

    switch (current_char) {
        case '+': {
                    Token t(PLUS, "+");
                    v.push_back(t);
                    break;
              } 

        case ';': {
                    Token t(SEMICOLON, ";");
                    v.push_back(t);
                    break;
              } 
        
        case '=': {
                    Token t(EQUAL, "=");
                    v.push_back(t);
                    break;
              } 
        case 'a'...'z' :
        case 'A'...'Z' : {
                            std::string c="";
                            while(is_alphabet_char(current_char)) {

                                c.append(1,current_char);
                                current_char = source_code[0];
                                if(!is_alphabet_char(current_char) || current_char == ' '){
                                    break;
                                }else{
                                source_code = source_code.substr(1);
                                }
                            }

                            Token t;
                            if(c == "var") { t.set_token_type(VAR); }
                            else if(c == "const") { t.set_token_type(CONST); }
                            else { t.set_token_type(IDENTIFIER); }
                            t.set_lex(c);
                            v.push_back(t);
                            break;
                     }
        case '0' ...'9': {
                            std::string c="";
                            while(std::isdigit(current_char)) {

                                c.append(1,current_char);
                                current_char = source_code[0];
                                if(!std::isdigit(current_char)){
                                    break;
                                }else{
                                source_code = source_code.substr(1);
                                }
                            }

                            Token t(NUMBER, c);
                            v.push_back(t);
                            break;
                }

        }
    }

    return v;
}

int main() {
    std::string src = "var foo = 4; var bar = 3; foo = 8; const foo_bar= foo + bar;";
    std::vector<Token> vt = tokenizer(src);
    for(Token t: vt) {
        std::cout<<t.get_lex() << " " <<t.get_token_type() <<std::endl;    
    }
}
