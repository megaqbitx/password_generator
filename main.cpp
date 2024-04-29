#include <iostream>
#include <random>
#include <ctime>
#include <string>

// Function to generate a random password of specified length
std::string generatePassword(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string password;

    // Initialize a random number generator using a time-based seed
    std::mt19937 mt(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(0, characters.size() - 1);

    // Generate random characters to form the password
    for (int i = 0; i < length; ++i) {
        int index = dist(mt); // Get a random index within the range of characters
        password += characters[index]; // Append the randomly chosen character to the password
    }

    return password;
}

int main() {
    int length;

    // Prompt user to enter desired password length
    std::cout << "Enter the desired length of the password: ";
    std::cin >> length;

    // Generate a random password
    std::string generatedPassword = generatePassword(length);

    // Display the generated password to the user
    std::cout << "Generated password: " << generatedPassword << std::endl;

    return 0;
}
