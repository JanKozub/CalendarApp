#include "NewEventDialog.h"

NewEventDialog::NewEventDialog(EventService *es, int dayOfMonth, tm *date, bool isDisabled) : eventService(es) {
    QFrame frame;
    QVBoxLayout layout;
    frame.setLayout(&layout);
    frame.setObjectName("event-dialog");
    layout.setAlignment(Qt::AlignCenter);

    QLabel topLabel("New Event");
    topLabel.setAlignment(Qt::AlignCenter);
    layout.addWidget(&topLabel);

    auto *dateEdit = new QDateEdit();
    dateEdit->setDisabled(isDisabled);
    dateEdit->setCalendarPopup(isDisabled);
    QDate qDate(1900 + date->tm_year, date->tm_mon, dayOfMonth);
    dateEdit->setDate(qDate);
    layout.addWidget(dateEdit);

    QLabel messageLabel("Message:");
    auto *messageField = new QLineEdit();
    QHBoxLayout messageTextField;
    messageTextField.addWidget(&messageLabel);
    messageTextField.addWidget(messageField);
    layout.addLayout(&messageTextField);

    QLabel priorityLabel("Priority:");
    auto comboBox = new QComboBox();
    comboBox->addItem("Low");
    comboBox->addItem("Medium");
    comboBox->addItem("High");
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QHBoxLayout priorityDropList;
    priorityDropList.addWidget(&priorityLabel);
    priorityDropList.addWidget(comboBox);
    layout.addLayout(&priorityDropList);

    auto button = new QPushButton("Add Event");
    connect(button, &QPushButton::clicked, this,
            [=]() { createNewEvent(dateEdit->date(), messageField->text(), comboBox->currentText()); });
    layout.addWidget(button);

    QVBoxLayout overlay;
    overlay.addWidget(&frame);
    this->setLayout(&overlay);
    this->setFixedSize(400, 180);
    this->exec();
}

void NewEventDialog::createNewEvent(const QDate &date, const QString &msg, const QString &priorityStr) {
    Event::Priority priority;
    if (priorityStr == "Low") priority = Event::Priority::LOW;
    else if (priorityStr == "Medium") priority = Event::Priority::MEDIUM;
    else priority = Event::Priority::HIGH;

    eventService->addEventToDatabase(Event(date.day(), date.month(), date.year(), msg.toStdString(), priority));
    close();
}
