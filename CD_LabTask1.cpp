#include <iostream>
#include <string>
using namespace std;

void isNumeric(string input) {
    bool flag = true;

    for (int i = 0; i < input.length(); i++) {
        if (!(input[i] >= 48 && input[i] <= 57)) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;
}

void findOperators(string s) {
    int n = 1;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == 43)
            cout << "Operator " << n++ << ": + (addition)" << endl;

        else if (s[i] == 45)
            cout << "Operator " << n++ << ": - (subtraction)" << endl;

        else if (s[i] == 42)
            cout << "Operator " << n++ << ": * (multiplication)" << endl;

        else if (s[i] == 47)
            cout << "Operator " << n++ << ": / (division)" << endl;

        else if (s[i] == 37)
            cout << "Operator " << n++ << ": % (modulus)" << endl;

        else if (s[i] == 61)
            cout << "Operator " << n++ << ": = (equal)" << endl;
    }
}

void isComment(string s) {
    int l = s.length();

    for (int i = 0; i < l; i++) {

        if (i + 1 < l && s[i] == 47 && s[i + 1] == 47) {
            cout << "Single Line Comment" << endl;
            return;
        }

        else if (i + 1 < l && s[i] == 47 && s[i + 1] == 42) {

            if (s[l - 2] == 42 && s[l - 1] == 47) {
                cout << "Multi Line Comment" << endl;
                return;
            }
        }
    }

    cout << "Not a Comment" << endl;
}

void isValid(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start <= end && str[start] == 32)
        start++;

    while (end >= start && str[end] == 32)
        end--;

    bool valid = true;

    if (start > end) {
        valid = false;
    }

    else {

        if (str[start] >= 48 && str[start] <= 57)
            valid = false;

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

    if (valid)
        cout << "Valid Identifier" << endl;
    else
        cout << "Invalid Identifier" << endl;
}

int main() {

    string input;

    cout << "Input: ";
    getline(cin, input);

    isNumeric(input);

    isValid(input);

    isComment(input);

    findOperators(input);

    return 0;
}
