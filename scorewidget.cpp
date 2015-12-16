#include "scorewidget.h"
#include <QDebug>

ScoreWidget::ScoreWidget(int *arg_score, QWidget *parent) : QWidget(parent)
{
    m_score = arg_score;
    qDebug() << "creation: " << *m_score;
    m_label = new QLabel();
    m_layout = new QHBoxLayout;
    m_scoreText = new QLabel();

    m_scoreText->setText(QString::number(*m_score));
    //m_scoreText->setFont(QFont.Helvetica);
    m_scoreText->setStyleSheet("QLabel { color : yellow ; }");

    QFont font = m_scoreText->font();
    font.setBold(true);
    font.setPointSize(22);
    m_scoreText->setFont(font);

    this->setGeometry(0,0,50,180);
    m_scoreText->setGeometry(0,0,50,60);

    QPixmap p;
    p.load(image_path);

    m_label->setGeometry(0,0,50,120);
    m_label->setPixmap(p);

    m_layout->addWidget(m_label);
    m_layout->addWidget(m_scoreText);
    this->setLayout(m_layout);

}

QLabel* ScoreWidget::getLabel()
{
    return m_label;
}

void ScoreWidget::showScore()
{
    qDebug() << *m_score;
     m_scoreText->setText(QString::number(*m_score));
}

