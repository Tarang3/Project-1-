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
    enum options { DisplayLeft = 1, DisplayRight = 2, Guess = 3, Change = 4, Exit = 5 };

    // Initialize variables
    string userName;
    int userScore = INITIAL_SCORE;
    int pointGain = POINTS_GAIN_INITIAL;
    int pointLoss = POINTS_LOSS_INITIAL;
    int lowerBound = -1;
    int upperBound = -1;
    int userGuess;
    bool gameOver = false;

    srand(time(0));
    upperBound = rand() % 101 + 100;
    do {
        lowerBound = rand() % 101 + 100;
    } while (upperBound <= lowerBound);

    // Display student information
    cout << "+-------------------------------------------------+" << endl;
    cout << "| Computer Science and Engineering                 |" << endl;
    cout << "| CSCE 1030 - Computer Science I                  |" << endl;
    cout << "| Student Name EUID euid@my.unt.edu               |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    // invalid and valid name
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
            cout << "Error name format is invalid. Please enter a valid name." << endl;
        }
    }

    // While loop
    while (!gameOver && userScore >= 0) {
        // Display lower and upper bounds
        cout << lowerBound << "     " << upperBound << endl;
    }

        // What to display
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change Numbers" << endl;
        cout << "5. Exit" << endl;

        int userChoice;
        cin >> userChoice;

        // Process user choice
        switch (static_cast<options>(userChoice)) {
            case DisplayLeft:
                if (lowerBound == -1) {
                    lowerBound = LOWER_BOUND;
                    pointGain = 1;
                    pointLoss = 10;
                    cout << "Now, you will gain " << pointGain << " points for guessing correctly and lose " << pointLoss << " for guessing incorrectly." << endl;
                } else {
                    cout << "You have already displayed the left boundary, you cannot display both." << endl;
                }
                break;

            case DisplayRight:
                if (upperBound == -1) {
                    upperBound = UPPER_BOUND;
                    pointGain = 1;
                    pointLoss = 10;
                    cout << "Now, you will gain " << pointGain << " points for guessing correctly and lose " << pointLoss << " for guessing incorrectly." << endl;
                } else {
                    cout << "You have already displayed the right boundary, you cannot display both." << endl;
                }
                break;

            case Guess:
                cout << "Enter your guess: ";
                cin >> userGuess;
                if (userGuess > lowerBound && userGuess < upperBound) {
                    userScore += pointGain;
                    cout << "You guessed correctly. You gain " << pointGain << " points." << endl;
                    cout << "Your remaining points = " << userScore << "." << endl;
                } else {
                    userScore -= pointLoss;
                    cout << "You guessed incorrectly. You lose " << pointLoss << " points." << endl;
                    cout << "Your remaining points = " << userScore << "." << endl;
                }
                break;

            case Change:
                cout << "New range has been generated." << endl;
                pointGain = POINTS_GAIN_INITIAL;
                pointLoss = POINTS_LOSS_INITIAL;
                upperBound = rand() % 101 + 100;
                do {
                    lowerBound = rand() % 101 + 100;
                } while (upperBound <= lowerBound);
                lowerBound = -1;
                upperBound = -1;
                userScore--;
                break;

            case Exit:
                gameOver = true;
                cout << "Bye " << userName << " !!!" << endl;
                break;
        }
}
                
    return 0;
