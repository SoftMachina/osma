#include <iostream>
enum TOKENTYPE{
    SEMICOLON,
    PLUS,
    VAR,
    CONST,
    EQUAL,
    IDENTIFIER,
    NUMBER,
};

class Token {
    private:
        TOKENTYPE t;
        std::string lex;
    public:
        Token(TOKENTYPE tt, std::string llex){
            t = tt;
            lex = llex;
        }
        
        Token(){}
        
        TOKENTYPE get_token_type() {return this->t;}
        std::string get_lex() {return this->lex;}

        void set_token_type(TOKENTYPE tt) {this->t = tt;}
        void set_lex(std::string llex) {this->lex = llex;}

};
