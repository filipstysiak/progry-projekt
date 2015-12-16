#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QHBoxLayout>

class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreWidget(int *arg_score, QWidget *parent = 0);
    QLabel* getLabel();



signals:

public slots:


private:
    QLabel *m_label;
    QHBoxLayout *m_layout;
    int *m_score;

    QLabel *m_scoreText;

    QString image_path = QString("../superkickassnumbers/assets/score.png");

private slots:
    void showScore();

};

#endif // SCOREWIDGET_H
