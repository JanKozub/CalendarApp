#ifndef CALENDARAPP_EVENT_H
#define CALENDARAPP_EVENT_H
#include "string"
#include "../../resources/json.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "iostream"
#include "boost/uuid/uuid.hpp"

class Event {
public:
    enum class Priority : int {
        HIGH = 2,
        MEDIUM = 1,
        LOW = 0
    };

private:
    boost::uuids::uuid id;
    int day{};
    int month{};
    int year{};
    std::string message;
    Priority priority;

public:
    Event();
    Event(int day, int month, int year, std::string message, Priority priority);

    const boost::uuids::uuid &getId() const;

    void setId1(const boost::uuids::uuid &id);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    const std::string &getMessage() const;

    void setMessage(const std::string &message);

    Priority getPriority() const;

    void setPriority(Priority priority);

    void setId(const boost::uuids::uuid& newId);

    friend void to_json(nlohmann::json &j, const Event &e);
    friend void from_json(const nlohmann::json &j, Event &e);
};

#endif //CALENDARAPP_EVENT_H