#ifndef CALENDARAPP_EVENTSERVICE_H
#define CALENDARAPP_EVENTSERVICE_H

#include <iostream>
#include <fstream>
#include "../EventService/lib/json.hpp"
#include <filesystem>

using namespace std;
using namespace nlohmann;
namespace fs = std::filesystem;

class EventService {
public:
    class Event {
    public:
        enum class Priority : int {
            HIGH = 2,
            MEDIUM = 1,
            LOW = 0
        };

    private:
        string id;
        int day{};
        int month{};
        int year{};
        std::string message;
        Priority priority;

    public:
        Event();

        Event(int day, int month, int year, std::string message, Priority priority);

        const string &getId() const;

        void setId(const string &id);

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

        friend void to_json(nlohmann::json &j, const Event &e);

        friend void from_json(const nlohmann::json &j, Event &e);
    };

private:
    string filename;
    vector<Event> events;

    void saveEventsToJson(const vector<Event> &newEvents);

public:
    explicit EventService(string filename);

    vector<Event> getEvents();

    void init();

    void addEventToDatabase(const Event &event);

    void removeEventFromDatabase(Event *event);

    void loadEventsFromJson();
};

#endif //CALENDARAPP_EVENTSERVICE_H