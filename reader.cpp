#include "token.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool is_alphabet_char(char c) { return std::isalpha(c) || c == '_'; }

char *conv_str_char_arr(std::string s) {

  char *c_a = new char[s.length() + 1];
  std::strcpy(c_a, s.c_str());

  return c_a;
}

void free_char_arr(char *c_a) { delete[] c_a; } // do i need this?

std::vector<Token> tokenizer(std::string source_code) {

  std::vector<Token> v;
  char current_char;
  std::string c = "";
  while (source_code.length() > 0) {

    current_char = source_code[0];
    source_code = source_code.substr(1);

    switch (current_char) {
    case '+': {
      c = "+";
      Token t(PLUS, conv_str_char_arr(c));
      v.push_back(t);
      break;
    }

    case ';': {
      c = ";";
      Token t(SEMICOLON, conv_str_char_arr(c));
      v.push_back(t);
      break;
    }

    case '=': {
      c = "=";
      Token t(EQUAL, conv_str_char_arr(c));
      v.push_back(t);
      break;
    }
    case 'a' ... 'z':
    case 'A' ... 'Z': {
      c = "";
      while (is_alphabet_char(current_char)) {

        c.append(1, current_char);
        current_char = source_code[0];
        if (!is_alphabet_char(current_char) || current_char == ' ') {
          break;
        } else {
          source_code = source_code.substr(1);
        }
      }

      Token t;
      if (c == "var") {
        t.set_token_type(VAR);
      } else if (c == "const") {
        t.set_token_type(CONST);
      } else {
        t.set_token_type(IDENTIFIER);
      }
      t.set_plex(conv_str_char_arr(c));
      v.push_back(t);
      break;
    }
    case '0' ... '9': {
      c = "";
      while (std::isdigit(current_char)) {

        c.append(1, current_char);
        current_char = source_code[0];
        if (!std::isdigit(current_char)) {
          break;
        } else {
          source_code = source_code.substr(1);
        }
      }

      Token t(NUMBER, conv_str_char_arr(c));
      v.push_back(t);
      break;
    }
    }
  }
  return v;
}

int main() {
  std::string src =
      "var foo = 4; var bar = 3; foo = 8; const foo_bar= foo + bar;";
  std::vector<Token> vt = tokenizer(src);
  for (Token t : vt) {
    std::cout << t.get_plex() << " " << t.get_token_type() << std::endl;
  }
}
