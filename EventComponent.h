#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

// Component

class EventComponent {
public:
	virtual void add(EventComponent*) = 0;
	
    virtual void open() = 0;
    virtual void close() = 0;

    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;

    virtual ~EventComponent() {}; 
};

#endif 