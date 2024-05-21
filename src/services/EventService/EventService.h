#ifndef CALENDARAPP_EVENTSERVICE_H
#define CALENDARAPP_EVENTSERVICE_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../../resources/json.hpp"
#include "../../model/Event/Event.h"
#include <filesystem>

using namespace std;
using namespace nlohmann;
namespace fs = std::filesystem;

class EventService {
private:
    string filename;
    vector<Event> events;
    void saveEventsToJson(const vector<Event> &newEvents);

public:
    explicit EventService(string filename);
    vector<Event> getEvents();
    void init();

    void addEventToDatabase(const Event& event);
    void removeEventFromDatabase(Event *event);
    void loadEventsFromJson();
};

#endif //CALENDARAPP_EVENTSERVICE_H