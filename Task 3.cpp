#include <iostream>
#include <string>
#include <cctype>

bool isStrongPassword(const std::string& password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    if (password.length() < 8) {
        return false; 
    }


    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUpper = true;
        } else if (std::islower(ch)) {
            hasLower = true;
        } else if (std::isdigit(ch)) {
            hasDigit = true;
        } else if (std::ispunct(ch)) {
            hasSpecial = true;
        }
    }

  
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    std::string password;

    std::cout << "Enter a password to assess its strength: ";
    std::getline(std::cin, password);

    if (isStrongPassword(password)) {
        std::cout << "The password is strong." << std::endl;
    } else {
        std::cout << "The password is weak. It must be at least 8 characters long and include uppercase letters, lowercase letters, digits, and special characters." << std::endl;
    }

    return 0;
}