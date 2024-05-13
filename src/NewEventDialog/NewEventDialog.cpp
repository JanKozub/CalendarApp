#include "NewEventDialog.h"


NewEventDialog::NewEventDialog() {
    QVBoxLayout layout;

    QLabel topLabel("New Event");
    topLabel.setAlignment(Qt::AlignCenter);
    layout.addWidget(&topLabel);
    layout.setAlignment(Qt::AlignCenter);

    QLabel messageLabel("Message:");
    messageLabel.setAlignment(Qt::AlignRight);
    QLineEdit messageField;
    messageField.setMaximumWidth(320);
    messageField.setStyleSheet("margin-right: 75px;");
    QHBoxLayout messageTextField;
    messageTextField.addWidget(&messageLabel);
    messageTextField.addWidget(&messageField);
    layout.addLayout(&messageTextField);

    QLabel priorityLabel("Priority:");
    QComboBox comboBox;
    comboBox.addItem("Low");
    comboBox.addItem("Medium");
    comboBox.addItem("High");
    comboBox.setMaximumWidth(300);
    QHBoxLayout priorityDropList;
    priorityDropList.addWidget(&priorityLabel);
    priorityDropList.addWidget(&comboBox);
    layout.addLayout(&priorityDropList);

    auto *button = new QPushButton("Add Event");
    layout.addWidget(button);

    this->setLayout(&layout);
    this->resize(500,500);
    this->exec();
}
