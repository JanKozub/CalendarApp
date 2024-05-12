#include "TopBar.h"

TopBar::TopBar(QWidget *parent) {
    auto *addEventButton = new QPushButton("Add Event");
    addEventButton->setStyleSheet("background-color: #C0C3C3;");
    addEventButton->setFixedWidth(150);
    this->addWidget(addEventButton);

    auto *prevWeek = new QPushButton("<");
    prevWeek->setStyleSheet("background-color: #C0C3C3;");
    prevWeek->setFixedWidth(50);
    this->addStretch(1);
    this->addWidget(prevWeek);

    auto *weekLabel = new QLabel("01-31.03.2024");
    this->addStretch();
    this->addWidget(weekLabel);

    auto *nextWeek = new QPushButton(">");
    nextWeek->setStyleSheet("background-color: #C0C3C3;");
    nextWeek->setFixedWidth(50);
    this->addWidget(nextWeek);
}