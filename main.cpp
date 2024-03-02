#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

class RPS {
public:
    RPS() {
        elements = {{1, "Rock"}, {2, "Paper"}, {3, "Scissors"}};
    }

    void play() {
        int playerChoice, computerChoice;

        std::cout << "Welcome to Rock, Paper, Scissors!\n";
        std::cout << "Choose:\n1. Rock\n2. Paper\n3. Scissors\n";
        std::cout << "Your choice: ";
        std::cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 3) {
            std::cout << "Incorrect number. Choose again.\n";
            return;
        }

        computerChoice = getRandNumb();

        std::cout << "You chose " << elements[playerChoice] << ".\n";
        std::cout << "Computer chose " << elements[computerChoice] << ".\n";

        determineWinner(playerChoice, computerChoice);
    }

private:
    std::map<int, std::string> elements;

    int getRandNumb() {

        return rand() % 3 + 1;
    }

    void determineWinner(int playerChoice, int computerChoice) {
        if (playerChoice == computerChoice) {
            std::cout << "It's a tie!\n";
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            std::cout << "You win!\n";
        } else {
            std::cout << "Computer wins!\n";
        }
    }
};

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    RPS game;
    char playAgain;

    do {
        game.play();

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing\n";

    return 0;
}
