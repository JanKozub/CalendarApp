#include "EventService.h"

EventService::EventService(string f) {
    filename = std::move(f);
    loadEventsFromJson();
}

vector<Event> *EventService::getEvents() {
    return &events;
}

void EventService::addEventToDatabase(Event e) {
    events.push_back(e);
    return saveEventsToJson(events);
}

void EventService::removeEventFromDatabase(Event target) {
//    auto it = std::remove_if(events.begin(), events.end(),
//                             [&target](const Event &e) { return e.getId() == target.getId(); });
//    if (it != events.end()) {
//        events.erase(it, events.end());
//        saveEventsToJson(events);
//    } else {
//        throw runtime_error("Event not found in database");
//    }
}

void EventService::saveEventsToJson(const vector<Event> &newEvents) {
    nlohmann::json j = newEvents;
    ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    } else {
        throw runtime_error("Unable to open file for writing");
    }
}

void EventService::loadEventsFromJson() {
    if (!fs::exists(filename))
        throw runtime_error("File does not exist");

    ifstream file(filename);
    if (!file.is_open())
        throw runtime_error("Unable to open file for reading");

    nlohmann::json j;
    file >> j;
    file.close();
    events = j.get<vector<Event>>();
}