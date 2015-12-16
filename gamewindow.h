#include <QDialog>
#include <QCheckBox>
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include "numbers.h"
#include <QString>
#include <QLabel>
#include <scorewidget.h>

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    GameWindow(std::vector<int> *opts, int *global_score);
    ~GameWindow();
private:
    QPushButton *submit;
    std::vector<int> *options;
    int *score;
    int warunek;
    std::vector<int> *wylosowane;
    std::vector<int> *wybrane;
    std::vector<QCheckBox*> *liczby;

    ScoreWidget *m_score_widget;
private slots:
    void submitResult();
};
