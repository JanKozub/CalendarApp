#include "Event.h"

Event::Event() : id(boost::uuids::random_generator()()) {}

Event::Event(long timestamp, std::string message, Priority priority)
        : id(boost::uuids::random_generator()()),
          timestamp(timestamp),
          message(std::move(message)),
          priority(priority) {}

boost::uuids::uuid Event::getId() { return id; }

long Event::getTimestamp() const { return timestamp; }

void Event::setTimestamp(long t) { this->timestamp = t; }

const std::string &Event::getMessage() const { return message; }

void Event::setMessage(const std::string &m) { this->message = m; }

Priority Event::getPriority() const { return priority; }

void Event::setPriority(Priority p) { this->priority = p; }

void Event::setId(const boost::uuids::uuid &newId) { id = newId; }

void to_json(nlohmann::json &j, const Event &e) {
    j = nlohmann::json{{"id",        boost::uuids::to_string(e.id)},
                       {"timestamp", e.timestamp},
                       {"message",   e.message},
                       {"priority",  e.priority}};
}

void from_json(const nlohmann::json &j, Event &e) {
    std::string id_str;
    j.at("id").get_to(id_str);
    std::cout << id_str;
    boost::uuids::string_generator gen;
    e.id = gen(id_str);

    j.at("timestamp").get_to(e.timestamp);
    j.at("message").get_to(e.message);
    j.at("priority").get_to(e.priority);
}