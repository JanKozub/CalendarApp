#include "EventService.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

EventService::EventService::Event::Event() : id(to_string(boost::uuids::random_generator()())), day(0), month(0),
                                             year(0),
                                             message(), priority(EventService::Event::Priority::LOW) {}

EventService::Event::Event(int day, int month, int year, std::string message, Priority priority)
        : id(to_string(boost::uuids::random_generator()())),
          day(day),
          month(month),
          year(year),
          message(std::move(message)),
          priority(priority) {}

const string &EventService::Event::getId() const { return id; }

int EventService::Event::getDay() const { return day; }

void EventService::Event::setDay(int day) { EventService::Event::day = day; }

int EventService::Event::getMonth() const { return month; }

void EventService::Event::setMonth(int month) { EventService::Event::month = month; }

int EventService::Event::getYear() const { return year; }

void EventService::Event::setYear(int year) { EventService::Event::year = year; }

const std::string &EventService::Event::getMessage() const { return message; }

void EventService::Event::setMessage(const std::string &message) { EventService::Event::message = message; }

EventService::Event::Priority EventService::Event::getPriority() const { return priority; }

void
EventService::Event::setPriority(EventService::Event::Priority priority) { EventService::Event::priority = priority; }


void to_json(nlohmann::json &j, const EventService::Event &e) {
    j = nlohmann::json{{"id",       e.id},
                       {"day",      e.day},
                       {"month",    e.month},
                       {"year",     e.year},
                       {"message",  e.message},
                       {"priority", e.priority}};
}

void from_json(const nlohmann::json &j, EventService::Event &e) {
    j.at("id").get_to(e.id);
    j.at("day").get_to(e.day);
    j.at("month").get_to(e.month);
    j.at("year").get_to(e.year);
    j.at("message").get_to(e.message);
    j.at("priority").get_to(e.priority);
}

