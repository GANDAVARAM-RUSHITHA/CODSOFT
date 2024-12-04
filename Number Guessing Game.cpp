#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(0));
    int randomNumber = std::rand() % 100 + 1; // Generates a random number between 1 and 100
    int guess = 0;

    std::cout << "I have generated a random number between 1 and 100. Can you guess what it is?" << std::endl;

    // Loop until the user guesses the correct number
    while (guess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > randomNumber) {
            std::cout << "Your guess is too high. Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Your guess is too low. Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number: " << randomNumber << std::endl;
        }
    }

    return 0;
}
