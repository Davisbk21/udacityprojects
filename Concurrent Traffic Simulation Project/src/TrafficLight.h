#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"

// forward declarations to avoid include cycle
class Vehicle;
enum TrafficLightPhase {red, green};


// DONE FP.3 Define a class "MessageQueue“ which has the public methods send and receive. 
// Send should take an rvalue reference of type TrafficLightPhase whereas receive should return this type. 
// Also, the class should define an std::dequeue called _queue, which stores objects of type TrafficLightPhase. 
// Also, there should be an std::condition_variable as well as an std::mutex as private members. 

template <class T>
  
class MessageQueue
{
public:
    void send(T&& phase);
    T receive();

private:
    std::deque<T> _queue;
    std::condition_variable _cond;
    std::mutex _mutex;
};

// Send and recieve methods
template <class T>
void MessageQueue<T>::send(T&& phase) {
    std::lock_guard<std::mutex> lock(_mutex);
    _queue.emplace_back(std::move(phase));
    _cond.notify_one();
}

template <class T>
T MessageQueue<T>::receive() {
    std::unique_lock<std::mutex> lock(_mutex);
    _cond.wait(lock, [this] { return !_queue.empty(); });
    TrafficLightPhase phase = std::move(_queue.front());
    _queue.pop_front();
    return std::move(phase);
}

// FP.1 DONE : Define a class „TrafficLight“ which is a child class of TrafficObject. 
// The class shall have the public methods „void waitForGreen()“ and „void simulate()“ 
// as well as „TrafficLightPhase getCurrentPhase()“, where TrafficLightPhase is an enum that 
// can be either „red“ or „green“. Also, add the private method „void cycleThroughPhases()“. 
// Furthermore, there shall be the private member _currentPhase which can take „red“ or „green“ as its value. 

class TrafficLight : public TrafficObject
{
public:
    // constructor / desctructor
        TrafficLight();
        ~TrafficLight(){};

    // getters / setters
    void waitForGreen();
    void simulate();
    TrafficLightPhase getCurrentPhase();

    // typical behaviour methods

private:
    // typical behaviour methods
    void cycleThroughPhases();
    TrafficLightPhase _currentPhase;
    MessageQueue<TrafficLightPhase> _messageQueue;
    
    

    // DONE FP.4b : create a private member of type MessageQueue for messages of type TrafficLightPhase 
    // and use it within the infinite loop to push each new TrafficLightPhase into it by calling 
    // send in conjunction with move semantics.

    std::condition_variable _condition;
    std::mutex _mutex;
};

#endif