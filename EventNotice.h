#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

/**
 * @enum NoticeType
 * @brief Represents the different types of notices that can occur
 *        during an event.
 */
enum class NoticeType { Open, Close, ScheduleChange, CapacityAlert, NetworkPause, Evacuate };

/**
 * @class EventNotice
 * @brief Represents information about an event notification
 * that is to be passed to observers.
 */
class EventNotice {
public:
    /**
     * @brief Constructs an EventNotice.
     * @param type The type of event notice.
     * @param message A descriptive message explaining the notice.
     * @param value Optional numerical information associated with the
     *              notice. Defaults to 0 when not required.
     */
    EventNotice(NoticeType type, const std::string& message, int value = 0)
        : type(type), message(message), value(value) {}

    /**
     * @brief The type of event notice.
     */
    NoticeType type;
    /**
     * @brief A description of the event notice.
     */
    std::string message;
    /**
     * @brief Additional numerical information associated with the notice.
     */
    int value;
};

#endif
