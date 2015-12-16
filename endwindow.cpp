#include "endwindow.h"

EndWindow::~EndWindow()
{

}

EndWindow::EndWindow(int *score)
{
    setAttribute(Qt::WA_DeleteOnClose);

    resize(480, 720);

    leave = new QPushButton(tr("OK"), this);
    leave->setGeometry(50, 50, 100, 30);
    connect(leave, SIGNAL(clicked()), this, SLOT(close()));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel(QString::fromUtf8("Gratulacje! Jestes fajny! Twoj wynik: "), this), 0, 0);
    layout->addWidget(new QLabel(QString::number(*score), this), 0, 1);

    layout->addWidget(leave, 1, 0);
    setLayout(layout); //ogarnij cokolwiek wygląd, dodaj możliwość ustawienia tła czy coś
}

