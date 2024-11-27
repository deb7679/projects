#include <bits/stdc++.h>
#include <ctime>

void drawBoard(char *space);
void playerMove(char *space, char player);
void computerMove(char *space, char computer);
bool checkWinner(char *space, char player, char computer);
bool checkTie(char *space);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)) {
            std::cout << "Player wins!\n";
            break;
        }
        if (checkTie(spaces)) {
            std::cout << "It's a tie!\n";
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)) {
            std::cout << "Computer wins!\n";
            break;
        }
        if (checkTie(spaces)) {
            std::cout << "It's a tie!\n";
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << '\n';
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    std::cout << "     |     |     \n\n";
}

void playerMove(char *space, char player) {
    int number;
    while (true) {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--; // Convert to 0-indexed

        if (number >= 0 && number < 9 && space[number] == ' ') {
            space[number] = player;
            break;
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

void computerMove(char *space, char computer) {
    srand(time(0));
    int number;
    while (true) {
        number = rand() % 9; // Random index between 0 and 8
        if (space[number] == ' ') {
            space[number] = computer;
            std::cout << "Computer placed at position " << number + 1 << ".\n";
            break;
        }
    }
}

bool checkWinner(char *space, char player, char computer) {
    // All winning combinations
    int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (auto &condition : winConditions) {
        if (space[condition[0]] != ' ' &&
            space[condition[0]] == space[condition[1]] &&
            space[condition[1]] == space[condition[2]]) {
            return true;
        }
    }
    return false;
}

bool checkTie(char *space) {
    for (int i = 0; i < 9; i++) {
        if (space[i] == ' ') {
            return false;
        }
    }
    return true;
}
