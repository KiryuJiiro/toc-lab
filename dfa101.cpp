#include <iostream>
#include <string>

using namespace std;

int delta(int current_state, char symbol) {
    switch (current_state) {
        case 0:
            if (symbol == '0')
                current_state = 0;
            else
                current_state = 1;
            break;
        case 1:
            if (symbol == '1')
                current_state = 2;
            else
                current_state = 1;
            break;
        case 2:
            if (symbol == '0')
                current_state = 3;
            else
                current_state = 1;
            break;
        case 3:
            if (symbol == '1')
                current_state = 3;
            else
                current_state = 1;
            break;
        default:
            current_state = 3;
            break;
    }
    return current_state;
}

int main() {
    string w;
    cout<<"strings need to have substring 101"<<endl;
    cout << "Enter the Input: ";
    cin >> w;

    int current_state = 0;
    for (int i = 0; i < w.length(); i++) {
        current_state = delta(current_state, w[i]);
    }

    if (current_state == 3)
        cout << "String has substrings 101 it's accepted" << endl;
    else
        cout << "String does not have substrings 101 it's rejected" << endl;

    return 0;
}