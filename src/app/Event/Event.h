#ifndef CALENDARAPP_EVENT_H
#define CALENDARAPP_EVENT_H
#include "string"

enum class Priority : int {
    HIGH = 2,
    MEDIUM = 1,
    LOW = 0
};

class Event {
private:
    long id{};
    long timestamp;
    std::string message;
    Priority priority;

public:
    Event(long timestamp, std::string message, Priority priority);

    long getId() const;

    void setId(long id);

    long getTimestamp() const;

    void setTimestamp(long timestamp);

    const std::string &getMessage() const;

    void setMessage(const std::string &message);

    Priority getPriority() const;

    void setPriority(Priority priority);
};




#endif //CALENDARAPP_EVENT_H
