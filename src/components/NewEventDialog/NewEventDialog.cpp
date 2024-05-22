#include "NewEventDialog.h"

NewEventDialog::NewEventDialog(EventService *es, int dayOfMonth, tm *date, bool isDisabled, const vector<EventService::Event> &events)
        : eventService(es) {
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

    EventTable eventTable(this, events);
    if (isDisabled) layout.addWidget(&eventTable);

    QVBoxLayout overlay;
    overlay.addWidget(&frame);
    this->setLayout(&overlay);
    this->setFixedSize(400, 400);
    this->exec();
}

void NewEventDialog::createNewEvent(const QDate &date, const QString &msg, const QString &priorityStr) {
    EventService::Event::Priority priority;
    if (priorityStr == "Low") priority = EventService::Event::Priority::LOW;
    else if (priorityStr == "Medium") priority = EventService::Event::Priority::MEDIUM;
    else priority = EventService::Event::Priority::HIGH;

    eventService->addEventToDatabase(EventService::Event(date.day(), date.month(), date.year(), msg.toStdString(), priority));
    close();
}
