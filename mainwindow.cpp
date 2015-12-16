#include "mainwindow.h"


//#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

MainWindow::~MainWindow()
{

}

MainWindow::MainWindow(std::vector<int> *opts)
{
    setAttribute(Qt::WA_DeleteOnClose);

    options = opts;

    difficulty.setValue((*options)[0]);
    difficulty.setMinimum((*options)[3]);
    difficulty.setMaximum((*options)[4]);
    game_length.setValue((*options)[2]);
    game_length.setMinimum((*options)[5]);
    game_length.setMaximum((*options)[6]);

    resize(480, 720);
    difficulty.setGeometry(400, 260, 600, 200);

    start = new QPushButton(tr("START"), this);
    start->setGeometry(50, 50, 100, 30);
    connect(start, SIGNAL(clicked()), this, SLOT(zacznij()));

    QGridLayout *layout = new QGridLayout(); //weź ogarnij, żeby to jakoś wyglądało, dodaj możliwość ustawienia tła jako pliku png czy coś
    layout->addWidget(new QLabel(QString::fromUtf8("Poziom trudnosci:"), this), 0, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel(QString::fromUtf8("Liczba tur:"), this), 0, 1);
    layout->addWidget(&difficulty,1,0);
    layout->addWidget(&game_length,1,1);
    layout->addWidget(start,2,0);



    setLayout(layout);
}

void MainWindow::zacznij()
{
    ((*options)[0]) = difficulty.value();
    ((*options)[2]) = game_length.value();
    close();
}
