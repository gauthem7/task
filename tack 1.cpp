#include <iostream>
#include <string>

using namespace std;

string encrypt(const string &text, int shift) {
    string result = "";

    for (char c : text) {
      
        if (isupper(c)) {
            result += char(int(c + shift - 'A') % 26 + 'A');
        }
      
        else if (islower(c)) {
            result += char(int(c + shift - 'a') % 26 + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

string decrypt(const string &text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    string text;
    int shift;
    char choice;

    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the shift value: ";
    cin >> shift;

    shift = shift % 26;

    cout << "Do you want to (E)ncrypt or (D)ecrypt? ";
    cin >> choice;

    if (choice == 'E' || choice == 'e') {
        string encryptedText = encrypt(text, shift);
        cout << "Encrypted Text: " << encryptedText << endl;
    } else if (choice == 'D' || choice == 'd') {
        string decryptedText = decrypt(text, shift);
        cout << "Decrypted Text: " << decryptedText << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}