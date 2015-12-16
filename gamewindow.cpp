#include "gamewindow.h"
#include "scorewidget.h"
#include "constants.h"
#include <QDebug>
#include <QFile>
#include <QDirIterator>
#include <QDir>
#include <QApplication>

GameWindow::~GameWindow()
{

}

GameWindow::GameWindow(std::vector<int> *opts, int *global_score)
{

    score = global_score;
    options = opts;
    liczby = new std::vector<QCheckBox*>;

    std::pair <int, std::vector<int> > * gotCase;
    gotCase = generate((*opts)[0]);

    warunek = gotCase->first;
    wylosowane = &(gotCase->second);
    wybrane = new std::vector<int>;

    resize(480, 720);

    submit = new QPushButton(tr("OK"), this);
    submit->setGeometry(50, 50, 100, 30);
    connect(submit, SIGNAL(clicked()), this, SLOT(submitResult()));



    /*
     *  Setting the logo
     */

    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QImage("../superkickassnumbers/assets/bcg.jpg")));
    this->setPalette(palette);


    /* end of setting the logo */

    /*
     *  creating score widget
     */

     m_score_widget = new ScoreWidget(score);
     connect(submit, SIGNAL(clicked()), m_score_widget, SLOT(showScore()));


    /* end score widget */


     QVBoxLayout *root_layout = new QVBoxLayout;
     QGridLayout *layout = new QGridLayout();

     /*Instead of one grid layout we use one Vertical layout with four children:
        1) empty field to push everything below the logo;
        2) Horizontal layout to keep the current score;
        3) Grid layout populated in the game;
        4) Lower bar for the button.
      */

     layout->addWidget(m_score_widget, 1, 1);

     QHBoxLayout *empty_layout = new QHBoxLayout();
     QRect empty_rect = QRect(0,0,const_screen_height, (const_screen_width/3));

     QLabel *empty_label = new QLabel();
     empty_label->setGeometry(empty_rect);

     empty_layout->addWidget(empty_label);
     root_layout->addLayout(empty_layout);

     QHBoxLayout *score_layout = new QHBoxLayout();
//     score_layout->addWidget(sw,0,Qt::AlignLeft);

     root_layout->addLayout(score_layout);







//    layout->addWidget(new QLabel(QString::fromUtf8("Wynik: "), this), 1, 0);
//    layout->addWidget(new QLabel(QString::number(*score), this), 1, 1);
    layout->addWidget(new QLabel(QString::fromUtf8(description(warunek)->c_str()), this), 1, 0);

    for (int i = 0; i < (*wylosowane).size(); i++)
    {
        liczby->push_back(new QCheckBox(QString::number((*wylosowane)[i]), this));
        layout->addWidget((*liczby)[i],i+3,0);
    }

    layout->addWidget(submit, (*wylosowane).size()+3, 0);
    setLayout(layout); //ogarnij cokolwiek wygląd, dodaj możliwość ustawienia tła czy coś
}

void GameWindow::submitResult()
{
    for (int i = 0; i < (*wylosowane).size(); i++)
    {
        if ((*liczby)[i]->isChecked())
        {
            wybrane->push_back((*wylosowane)[i]);
        }
    }
    (*score) = (*score) + (check(warunek, wybrane)) * ((*wybrane).size());

    close();
}

