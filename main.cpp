/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string toWord(int x) {
    if (x == 1) return "Rock";
    if (x == 2) return "Paper";
    return "Scissors";
}

int main() {
    srand(time(0));

    int choice, cpu, play = 1;
    int wins = 0, losses = 0, ties = 0;

    cout << "=== Rock - Paper - Scissors ===\n";

    while (play == 1) {

        cout << "\nChoose:\n";
        cout << "1 - Rock\n2 - Paper\n3 - Scissors\n";
        cout << "Enter choice: ";

        cin >> choice;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Restarting round...\n";
            continue;
        }

        
        if (choice < 1 || choice > 3) {
            cout << "Please enter 1, 2, or 3.\n";
            continue;
        }

        cpu = rand() % 3 + 1;

        cout << "You: " << toWord(choice) << "\n";
        cout << "CPU: " << toWord(cpu) << "\n";

        if (choice == cpu) {
            cout << "Tie!\n";
            ties++;
        }
        else if ((choice == 1 && cpu == 3) ||
                 (choice == 2 && cpu == 1) ||
                 (choice == 3 && cpu == 2)) {
            cout << "You win!\n";
            wins++;
        }
        else {
            cout << "You lose!\n";
            losses++;
        }

        cout << "\nPlay again? (1 = yes, 0 = no): ";
        cin >> play;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            play = 0; 
        }
    }

    cout << "\n=== Final Score ===\n";
    cout << "Wins: " << wins << "\n";
    cout << "Losses: " << losses << "\n";
    cout << "Ties: " << ties << "\n";

    return 0;
}