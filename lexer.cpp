
#include "lexer.h"
#include <iostream>

using namespace std;

bool isNumeric(string input) {
    bool flag = true;
    for (int i = 0; i < input.length(); i++) {
        if (!(input[i] >= 48 && input[i] <= 57)) {
            return false;
        }
    }
    return true;
}

bool isString(string input) {
    if (input.length() >= 2 && input[0] == '"' && input[input.length() - 1] == '"') {
        return true;
    }
    return false;
}

bool isValid(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start <= end && str[start] == 32) start++;
    while (end >= start && str[end] == 32) end--;

    bool valid = true;
    if (start > end) {
        valid = false;
    } else {
        if (str[start] >= 48 && str[start] <= 57) valid = false;

        for (int i = start; i <= end && valid; i++) {
            if (str[i] == 32) {
                valid = false;
                break;
            }
            if (!((str[i] >= 65 && str[i] <= 90) ||
                  (str[i] >= 97 && str[i] <= 122) ||
                  (str[i] >= 48 && str[i] <= 57) ||
                   str[i] == 95)) {
                valid = false;
            }
        }
    }
    return valid;
}

string trim(string s) {
    int start = 0;
    while (start < s.length() && (s[start] == ' ' || s[start] == '\t' || s[start] == '\n' || s[start] == '\r' || s[start] == '\v' || s[start] == '\f')) {
        start++;
    }

    if (start == s.length()) {
        return "";
    }

    int end = s.length() - 1;
    while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n' || s[end] == '\r' || s[end] == '\v' || s[end] == '\f')) {
        end--;
    }

    return s.substr(start, end - start + 1);
}

void detect(string token) {
    string keywords[] = {"cout", "endl", "return", "return", "int", "float"};
    string operators[] = {"+", "-", "*", "/", "<<", ">>" };
    char punctuation[] = {';', ',', '(', ')', '{', '}'};

    for (string kw : keywords) {
        if (token == kw) {
            cout << token << " -> Keyword" << endl;
            return;
        }
    }

    for (string op : operators) {
        if (token == op) {
            cout << token << " -> Operator" << endl;
            return;
        }
    }

    if (token.length() == 1) {
        for (char p : punctuation) {
            if (token[0] == p) {
                cout << token << " -> Punctuation" << endl;
                return;
            }
        }
    }

    if (isNumeric(token)) {
        cout << token << " -> Numeric Constant" << endl;
        return;
    }

    if (isValid(token)) {
        cout << token << " -> Identifier" << endl;
        return;
    }

    if (isString(token)) {
        cout << token << " -> String" << endl;
        return;
    }

    cout << token << " -> Unknown Token" << endl;
}

void tokenization(string s, ofstream& outfile) {
    s = trim(s);
    cout << "Tokenizing: " << s << endl;
    outfile << "Tokenizing: " << s << endl;

    int start = 0;
    int i = 0;

    while (i < s.length()) {
        if (s[i] == ' ') {
            detect(s.substr(start, i - start));
            start = i + 1;
        }
        i++;
    }

    if (start < s.length()) {
        detect(s.substr(start));
    }
}
