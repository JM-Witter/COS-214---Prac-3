#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

/**
 * @class EventComponent
 * @brief Provides the common interface for all components in the event.
 * It is the Gof participant, Component, in the Composite design pattern.
 */

class EventComponent {
public:
    /**
     * @brief Opens the event component.
     * The concrete component determines what opening means for its
     * specific type.
     */
    virtual void open() = 0;
    /**
     * @brief Closes the event component.
     * The concrete component determines what closing means for its
     * specific type.
     */
    virtual void close() = 0;
    /**
     * @brief Reports the current status of the event component.
     * Concrete components provide their own status information.
     */
    virtual void reportStatus() const = 0;
    /**
     * @brief Returns the capacity of the event component.
     * @return The maximum capacity supported by the component.
     */
    virtual int getCapacity() const = 0;
    /**
     * @brief Virtual destructor for polymorphic destruction.
     * The virtual destructor ensures that derived EventComponent objects
     * are destroyed correctly when they are deleted through an
     * EventComponent pointer.
     */
    virtual ~EventComponent() {}
};

#endif
