#include "mainwindow.h"
#include "gamewindow.h"
#include "endwindow.h"
#include "numbers.h"
#include <QApplication>
#include <utility>

int main(int argc, char *argv[])
{
    int score = 0;
    QApplication a(argc, argv);
    std::vector <int> options {0,0,3,0,0,1,99}; //0 difficulty 1 if_multiplayer 2 game_length 3 difficulty_min 4 difficulty_max 5 game_length_min 6 game_length_max
    // w przyszłości (może) będzie jakiś multiplayer
    QDialog *menu = new MainWindow(&options); //dodaj w każdym oknie button odpowiadający za wyjście z gry
    menu->exec();
    for (int i = 0; i < options[2]; i++) {
        menu = new GameWindow(&options, &score);
        menu->exec();
    }
    menu = new EndWindow(&score);
    menu->exec();
    //nie zamyka się aplikacja po zamknięciu okien i nie wiem, dlaczego
    return a.exec();
}
