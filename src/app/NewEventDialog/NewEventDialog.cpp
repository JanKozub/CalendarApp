#include "NewEventDialog.h"


NewEventDialog::NewEventDialog() {
    QFrame frame;
    QVBoxLayout layout;
    frame.setLayout(&layout);
    frame.setObjectName("event-dialog");
    layout.setAlignment(Qt::AlignCenter);

    QLabel topLabel("New Event");
    topLabel.setAlignment(Qt::AlignCenter);
    layout.addWidget(&topLabel);

    QLabel messageLabel("Message:");
    QLineEdit messageField;
    QHBoxLayout messageTextField;
    messageTextField.addWidget(&messageLabel);
    messageTextField.addWidget(&messageField);
    layout.addLayout(&messageTextField);

    QLabel priorityLabel("Priority:");
    QComboBox comboBox;
    comboBox.addItem("Low");
    comboBox.addItem("Medium");
    comboBox.addItem("High");
    comboBox.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QHBoxLayout priorityDropList;
    priorityDropList.addWidget(&priorityLabel);
    priorityDropList.addWidget(&comboBox);
    layout.addLayout(&priorityDropList);

    auto *button = new QPushButton("Add Event");
    layout.addWidget(button);

    QVBoxLayout overlay;
    overlay.addWidget(&frame);
    this->setLayout(&overlay);
    this->setFixedSize(400,180);
    this->exec();
}
