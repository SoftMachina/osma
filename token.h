enum TOKENTYPE {
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
  char *plex;

public:
  Token(TOKENTYPE tt, char *pplex) {
    t = tt;
    plex = pplex;
  }

  Token() {}

  TOKENTYPE get_token_type() { return this->t; }
  char* get_plex() { return this->plex; }

  void set_token_type(TOKENTYPE tt) { this->t = tt; }
  void set_plex(char *pplex) { this->plex = pplex; }
};
