#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>

class EndWindow : public QDialog
{
    Q_OBJECT

public:
    EndWindow(int *score);
    ~EndWindow();
private:
    QPushButton *leave;
    int *score;
};

#endif // ENDWINDOW_H
