#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // Constants
    const int INITIAL_SCORE = 100;
    const int POINTS_GAIN_INITIAL = 5;
    const int POINTS_LOSS_INITIAL = 5;
    const int LOWER_BOUND = 100;
    const int UPPER_BOUND = 200;

    // Enumeration for menu choices
    enum options { DisplayLeft = 1, DisplayRight = 2, Guess = 3, Change = 4, Exit = 5};

    // Variable initialization
    int userScore = INITIAL_SCORE;
    int pointGain = POINTS_GAIN_INITIAL;
    int pointLoss = POINTS_LOSS_INITIAL;
    int lowerBound = -1;
    int upperBound = -1;
    string userName;
    bool gameOver = false;

    // Display student information
    cout << "+-------------------------------------------------+" << endl;
    cout << "| Computer Science and Engineering                |" << endl;
    cout << "| CSCE 1030 - Computer Science I                  |" << endl;
    cout << "| Student Name EUID euid@my.unt.edu               |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    // Get and validate user's name
    while (true) {
        cout << "Enter your name: ";
        getline(cin, userName);
        bool validName = true;
        for (char c : userName) {
            if (!isalpha(c) && !isspace(c)) {
                validName = false;
                break;
            }
        }
        if (validName) {
            for (char &c : userName) {
                if (isalpha(c)) {
                    c = toupper(c);
                } else {
                    c = tolower(c);
                }
            }
            break;
        } else {
            cout << "Invalid name format. Please enter a valid name." << endl;
        }
    }

    // Game loop
    while (!gameOver && userScore >= 0) {
        // Display lower and upper bounds
        cout << lowerBound << "     " << upperBound << endl;

        // Display menu
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change Numbers" << endl;
        cout << "5. Exit" << endl;

        int userChoice;
        cin >> userChoice;

        // Process user choice
        switch (static_cast<MenuChoice>(userChoice)) {
            case DisplayLeft:
                if (lowerBound == -1) {
                    lowerBound = LOWER_BOUND;
                    pointGain = 1;
                    pointLoss = 10;
                    cout << "You will only get 1 point for guessing correctly and lose 10 points for guessing incorrectly, now." << endl;
                } else {
                    cout << "You have already displayed the left boundary, you cannot display both." << endl;
                }
                break;

            case DisplayRight:
                if (upperBound == -1) {
                    upperBound = UPPER_BOUND;
                    pointGain = 1;
                    pointLoss = 10;
                    cout << "You will only get 1 point for guessing correctly and lose 10 points for guessing incorrectly, now." << endl;
                } else {
                    cout << "You have already displayed the right boundary, you cannot display both." << endl;
                }
                break;

            case Guess:
                int userGuess;
                cout << "Enter your guess: ";
                cin >> userGuess;
                if (userGuess > lowerBound && userGuess < upperBound) {
                    userScore += pointGain;
                    cout << "You guessed correctly. You get " << pointGain << " points." << endl;
                    cout << "Your remaining points=" << userScore << endl;
                } else {
                    userScore -= pointLoss;
                    cout << "You guessed incorrectly. You lose " << pointLoss << " points." << endl;
                    cout << "Your remaining points=" << userScore << endl;
                }
                break;

            case Change:
                srand(time(0));
                do {
                    lowerBound = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
                    upperBound = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
                } while (lowerBound >= upperBound);
                pointGain = POINTS_GAIN_INITIAL;
                pointLoss = POINTS_LOSS_INITIAL;
                userScore--;
                cout << "New range has been generated." << endl;
                cout << "Points deducted for changing numbers. Your updated points balance: " << userScore << endl;
                break;

            case Exit:
                gameOver = true;
                cout << "Bye " << userName << " !!!" << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    // Display final results using a while loop
    if (userScore < 0) {
        cout << "You are out of points." << endl;
    } else {
        cout << "Your final points balance: " << userScore << endl;
    }

    return 0;
}
