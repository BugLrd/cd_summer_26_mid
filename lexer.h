
#ifndef LEXER_H
#define LEXER_H

#include <string>

bool isNumeric(std::string input);
bool isString(std::string input);
bool isValid(std::string str);
void detect(std::string token);
void tokenization(std::string s);

#endif
