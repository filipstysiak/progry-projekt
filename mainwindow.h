#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDialog>
#include <QSpinBox>
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include <QLayout>
#include <QLabel>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(std::vector<int> *opts);
    ~MainWindow();
private:
    QSpinBox difficulty;
    QSpinBox game_length;
    QPushButton *start;
    std::vector<int> *options;
private slots:
    void zacznij();
};




//namespace Ui {
//class MainWindow;
//}

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit MainWindow(QWidget *parent = 0);
//    ~MainWindow();

//private:
//    Ui::MainWindow *ui;
//};

#endif // MAINWINDOW_H
