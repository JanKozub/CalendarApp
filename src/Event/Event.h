#ifndef CALENDARAPP_EVENT_H
#define CALENDARAPP_EVENT_H
#include "string"
#include "../../resources/json.hpp"
#include "Priority.cpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "iostream"

class Event {
private:
    boost::uuids::uuid id;
    long timestamp{};
    std::string message;
    Priority priority;

public:
    Event();
    Event(long timestamp, std::string message, Priority priority);

    boost::uuids::uuid getId();
    long getTimestamp() const;
    void setTimestamp(long t);
    const std::string &getMessage() const;
    void setMessage(const std::string &m);
    Priority getPriority() const;
    void setPriority(Priority p);

    void setId(const boost::uuids::uuid& newId);

    friend void to_json(nlohmann::json &j, const Event &e);
    friend void from_json(const nlohmann::json &j, Event &e);
};

#endif //CALENDARAPP_EVENT_H