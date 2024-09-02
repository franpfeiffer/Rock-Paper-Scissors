#include <iostream>
using namespace std;

char userChoice();
char computerChoice(char player);
void showChoice(char choice);
void winner(char player, char computer);
char playAgainChoice(); 

int main() {
    char player, computer;
    char playAgain;

    do {
        player = userChoice();

        cout << "Elegiste: ";
        showChoice(player);

        computer = computerChoice(player);
        cout << "La compu eligio: ";
        showChoice(computer);

        winner(player, computer);

        playAgain = playAgainChoice();

    } while (playAgain == 's' || playAgain == 'S');

    cout << "Chau boludito" << endl;

    return 0;
}

char userChoice() {
    char player;

    cout << "Piedra-Papel-Tijera" << endl;
    cout << " " << endl;
    do {
        cout << "Elige una de las siguientes opciones:" << endl;
        cout << "**************************" << endl;
        cout << "'p' (minuscula) para Piedra" << endl;
        cout << "'P' (mayuscula) para Papel" << endl;
        cout << "'T' para Tijera" << endl;
        cin >> player;

        if (player != 'p' && player != 'T' && player != 'P') {
            cout << "ERROR solo podes elegir 'p', 'P' o 'T'." << endl;
        }

    } while (player != 'p' && player != 'T' && player != 'P');

    return player;
}

char computerChoice(char player) {
    // La compu siempre gana
    if (player == 'p') return 'P';
    else if (player == 'P') return 'T'; 
    else return 'p';
}

void showChoice(char choice) {
    switch (choice) {
        case 'p': cout << "Piedra\n"; break;
        case 'P': cout << "Papel\n"; break;
        case 'T': cout << "Tijera\n"; break;
    }
}

void winner(char player, char computer) {
    if (player == computer) {
        cout << "Empataron" << endl;
    } else if ((player == 'p' && computer == 'T') || (player == 'P' && computer == 'p') || (player == 'T' && computer == 'P')) {
        cout << "Ganaste" << endl;
    } else {
        cout << "Perdiste :(" << endl;
    }
}

char playAgainChoice() {
    char choice;
    do {
        cout << "Queres jugar de nuevo? (s/n): ";
        cin >> choice;

        if (choice != 's' && choice != 'S' && choice != 'n' && choice != 'N') {
            cout << "ERROR solo podes elegir 's' para si o 'n' para no." << endl;
        }

    } while (choice != 's' && choice != 'S' && choice != 'n' && choice != 'N');

    return choice;
}

