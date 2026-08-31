#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

enum class NoticeType { Open, Close, ScheduleChange, CapacityAlert, NetworkPause, Evacuate };

class EventNotice {
public:
    EventNotice(NoticeType type, const std::string& message, int value = 0)
        : type(type), message(message), value(value) {}

    NoticeType type;
    std::string message;
    int value;
};

#endif
