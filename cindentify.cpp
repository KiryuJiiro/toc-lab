#include <iostream>
#include <string>
#include <cctype> // Use cctype instead of ctype.h
using namespace std;

int current_state = 0;

void state0(char c) {
    if (isalpha(c) || c == '_') {
        current_state = 1; // Valid start of identifier
    } else {
        current_state = -1; // Invalid identifier
    }
}

void state1(char c) {
    if (isalnum(c) || c == '_') {
        current_state = 1; // Still valid
    } else {
        current_state = -1; // Invalid identifier
    }
}

int DFA_for_Identifier(string z) {
    current_state = 0; // Reset state
    int len = z.length();
    for (int i = 0; i < len; i++) {
        if (current_state == 0) {
            state0(z[i]);
        } else if (current_state == 1) {
            state1(z[i]);
        } else {
            return 0; // Invalid state
        }
    }

    return (current_state == 1) ? 1 : 0; // Return if it's a valid identifier
}

int IsKeyword(string z) {
    string keywords[] = {
        "auto", "break", "case", "char", "continue", "do", "default",
        "const", "double", "else", "enum", "extern", "for", "if", "goto",
        "float", "int", "long", "return", "signed", "static", "sizeof",
        "short", "struct", "switch", "typedef", "union", "void", "while",
        "volatile", "unsigned"
    };

    for (const string& keyword : keywords) {
        if (z == keyword) {
            return 1; // It is a keyword
        }
    }
    return 0; // Not a keyword
}

int main() {
    string a;
    cout << "Enter string: ";
    cin >> a;

    if (IsKeyword(a) == 1) {
        current_state = -1; // Set state to invalid if it's a keyword
    } else {
        current_state = DFA_for_Identifier(a); // Check if it's a valid identifier
    }

    if (current_state == -1) { // Check the condition properly
        cout << a << ": valid Identifier" << endl;
    } else {
        cout << a << ": InValid Identifier" << endl; // Added output for valid identifiers
    }

    return 0;
}
