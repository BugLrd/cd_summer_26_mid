
#ifndef LEXER_H
#define LEXER_H

#include <string>

bool isNumeric(std::string input);
bool isString(std::string input);
bool isValid(std::string str);
std::string detect(std::string token);
std::string tokenization(std::string s);

#endif
