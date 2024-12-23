#include <iostream>
#include <string>
using namespace std;

int current = 0;

int delta(int current, char symbol);

int main() {
    int i = 0;
    string w;
    cout << "String should end with '01'" << endl;
    cout << "Enter the input: ";
    cin >> w;

    // Process each character in the input
    while (i < w.length()) {
        current = delta(current, w[i]);
        i++;
    }

    // Check if the final state is the accepting state AND the string ends with "01"
    if (current == 2 && w.substr(w.length() - 2) == "01") {
        cout << w << " is accepted";
    } else {
        cout << w << " is rejected";
    }

    return 0;
}

// Define the delta function outside of main
int delta(int current, char symbol) {
    switch (current) {
        case 0:
            if (symbol == '0') {
                current = 1;
            } else {
                current = 0;
            }
            break;
        case 1:
            if (symbol == '0') {
                current = 1;
            } else {
                current = 2;
            }
            break;
        case 2:
            if (symbol == '0') {
                current = 1;
            } else {
                current = 0;
            }
            break;
    }
    return current;
}
