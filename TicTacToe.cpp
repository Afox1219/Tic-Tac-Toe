#include <iostream>
#include <ctime>
void drawboard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
bool checkWinner(char* spaces, char players, char computers);
bool checktie(char* spaces);




int main() {
    char player = 'X';
    char computer = 'O';
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    bool running = true;

    drawboard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawboard(spaces);
        computerMove(spaces, computer);
        drawboard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
        }
        else if (checktie(spaces))
        {
            running = false;

        }



    }




    return 0;
}

void drawboard(char* spaces) {
    std::cout << "      |        |      " << '\n';
    std::cout << "  " << spaces[0] << "   |   " << spaces[1] << "    |   " << spaces[2] << "    " << '\n';
    std::cout << "      |        |      " << '\n';
    std::cout << "_______________________" << '\n';
    std::cout << "      |        |      " << '\n';
    std::cout << "  " << spaces[3] << "   |   " << spaces[4] << "    |   " << spaces[5] << "    " << '\n';
    std::cout << "      |        |      " << '\n';
    std::cout << "_______________________" << '\n';
    std::cout << "      |        |      " << '\n';
    std::cout << "  " << spaces[6] << "   |   " << spaces[7] << "    |   " << spaces[8] << "    " << '\n';
    std::cout << "      |        |      " << '\n';
}
void playerMove(char* spaces, char players) {
    int numbers;
    std::cout << "Where to place marker?" << '\n';
    std::cin >> numbers;
    do
    {
        spaces[numbers] = players;
    } while (!numbers < 0 || !numbers > 8);
}
void computerMove(char* spaces, char computer) {
    srand(time(0));
    int numbers = (rand() % 9);
    std::cout << "Where to place marker?" << '\n';
    while(true){
        if(spaces[numbers] == ' '){
            spaces[numbers] = computer;
        }
        break;
    }
}
bool checkWinner(char* spaces, char player, char computer) {
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[6] && spaces[6] == spaces[8])
    {
        spaces[0] == player ? std::cout << "you Win!" << '\n' : std::cout << "You Lose!" << '\n';
    }
    else {
        return false;
    }
    return true;
}
bool checktie(char* spaces) {
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] != ' ') {
            return false;
        }
    }
    std::cout << "Good Game. TIE!" << '\n';
    return true;
}