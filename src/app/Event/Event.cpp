#include "Event.h"

#include <utility>

Event::Event(long timestamp, std::string message, Priority priority) : timestamp(timestamp), message(std::move(message)),
                                                                              priority(priority) {}

long Event::getId() const {
    return id;
}

void Event::setId(long id) {
    Event::id = id;
}

long Event::getTimestamp() const {
    return timestamp;
}

void Event::setTimestamp(long timestamp) {
    Event::timestamp = timestamp;
}

const std::string &Event::getMessage() const {
    return message;
}

void Event::setMessage(const std::string &message) {
    Event::message = message;
}

Priority Event::getPriority() const {
    return priority;
}

void Event::setPriority(Priority priority) {
    Event::priority = priority;
}
