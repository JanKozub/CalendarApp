#include "Event.h"
#include "boost/uuid/uuid.hpp"

Event::Event() : id(boost::uuids::random_generator()()), day(0), month(0), year(0),
                 message(), priority(Priority::LOW) {}

Event::Event(int day, int month, int year, std::string message, Priority priority)
        : id(boost::uuids::random_generator()()),
          day(day),
          month(month),
          year(year),
          message(std::move(message)),
          priority(priority) {}

const boost::uuids::uuid &Event::getId() const { return id; }

int Event::getDay() const { return day; }

void Event::setDay(int day) { Event::day = day; }

int Event::getMonth() const { return month; }

void Event::setMonth(int month) { Event::month = month; }

int Event::getYear() const { return year; }

void Event::setYear(int year) { Event::year = year; }

const std::string &Event::getMessage() const { return message; }

void Event::setMessage(const std::string &message) { Event::message = message; }

Priority Event::getPriority() const { return priority; }

void Event::setPriority(Priority priority) { Event::priority = priority; }


void to_json(nlohmann::json &j, const Event &e) {
    j = nlohmann::json{{"id",        boost::uuids::to_string(e.id)},
                       {"day", e.day},
                       {"month", e.month},
                       {"year", e.year},
                       {"message",   e.message},
                       {"priority",  e.priority}};
}

void from_json(const nlohmann::json &j, Event &e) {
    std::string id_str;
    j.at("id").get_to(id_str);
    boost::uuids::string_generator gen;
    e.id = gen(id_str);

    j.at("day").get_to(e.day);
    j.at("month").get_to(e.month);
    j.at("year").get_to(e.year);
    j.at("message").get_to(e.message);
    j.at("priority").get_to(e.priority);
}

