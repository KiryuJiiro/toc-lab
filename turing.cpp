#include <iostream>
#include <string.h>
#define max 100
using namespace std;

enum states { q0, q1, q2, q3, q4, qf };

int main() {
    char input[100];
    enum states curr_state = q0;
    int i = 0;

    // Initialize input array with null characters
    for (i = 0; i < 100; i++) {
        input[i] = '\0';
    }

    cout << "\nEnter a binary string: ";
    cin >> input;

    i = 0;
    while (true) {
        switch (curr_state) {
            case q0:
                if (input[i] == '0') {
                    curr_state = q1;
                    input[i] = 'X';
                    i++;
                } else if (input[i] == '1') {
                    curr_state = qf;
                } else {
                    curr_state = qf;
                }
                break;

            case q1:
                if (input[i] == '0') {
                    curr_state = q1;
                    i++;
                } else if (input[i] == '1') {
                    curr_state = q2;
                    input[i] = 'Y';
                    i--;
                } else {
                    curr_state = qf;
                }
                break;

            case q2:
                if (input[i] == '0') {
                    curr_state = q2;
                    i--;
                } else if (input[i] == 'X') {
                    curr_state = q0;
                    i++;
                } else {
                    curr_state = qf;
                }
                break;

            case q3:
                if (input[i] == 'Y') {
                    curr_state = q3;
                    i++;
                } else {
                    curr_state = qf;
                }
                break;

            case q4:
                cout << "\nThe string is accepted";
                return 0;

            case qf:
                cout << "\nThe string is not accepted";
                return 0;
        }

        // Exit the loop if it reaches the accepting (q4) or rejecting (qf) state
        if (curr_state == qf || curr_state == q4) {
            break;
        }
    }

    // Final output based on the last state
    if (curr_state == q4)
        cout << "\nThe string is not accepted";
    else
        cout << "\nThe string is  accepted";

    return 0;
}
