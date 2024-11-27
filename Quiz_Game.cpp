#include <iostream>
#include <cctype>

int main() {
    std::string questions[] = {
        "1. Find the missing number in the series: 2, 6, 12, 20, 30, ? ",
        "2. In a certain code language, \"APPLE\" is written as \"ELPPA\". How is \"ORANGE\" written in that language? ",
        "3. If 4 + 5 = 41, 6 + 7 = 61, and 8 + 9 = 81, what is 3 + 4? ",
        "4. Ravi is taller than Suresh but shorter than Amit. Suresh is taller than Vijay. Who is the tallest? ",
        "5. If A is coded as 1, B as 2, C as 3, and so on, what is the code for the word \"CAB\"? ",
        "6. Find the next number in the series: 3, 6, 11, 18, 27, ? ",
    };

    std::string options[][4] = {
        {"a. 40", "b. 42", "c. 50", "d. 60"},
        {"a. EGNAOR", "b. GNEARO", "c. EGNARO", "d. RONGAE"},
        {"a. 21", "b. 31", "c. 41", "d. 51"},
        {"a. Ravi", "b. Amit", "c. Suresh", "d. Vijay"},
        {"a. 312", "b. 123", "c. 213", "d. 132"},
        {"a. 38", "b. 40", "c. 35", "d. 36"}
    };

    char answerKey[] = {'B', 'C', 'B', 'B', 'A', 'A'}; // Use uppercase for consistency
    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    for (int i = 0; i < size; i++) {
        std::cout << "**********************\n";
        std::cout << questions[i] << '\n';
        std::cout << "**********************\n";

        for (int j = 0; j < 4; j++) { // Only loop through the 4 defined options
            std::cout << options[i][j] << '\n';
        }

        std::cin >> guess;
        guess = toupper(guess);

        if (guess == answerKey[i]) {
            std::cout << "CORRECT\n";
            score++;
        } else {
            std::cout << "WRONG!\n";
            int correctIndex = answerKey[i] - 'A'; // Correct index based on uppercase keys
            std::cout << "Answer: " << options[i][correctIndex] << '\n';
        }
    }

    std::cout << "\nFinal Score: " << score << " / " << size << '\n';
    return 0;
}
