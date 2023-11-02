#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include "TrafficLight.h"


/* Implementation of class "TrafficLight" */


TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    //DONE FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop 
    // runs and repeatedly calls the receive function on the message queue. 
    // Once it receives TrafficLightPhase::green, the method returns.
      while (true) {
        TrafficLightPhase phase = _messageQueue.receive();
        if (phase == TrafficLightPhase::green) {
            return;
        }
    }
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    // DONE: FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. To do this, use the thread queue in the base class. 
  threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}
// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases() {
    // DONE: FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles 
    // and toggles the current phase of the traffic light between red and green and sends an update method 
    // to the message queue using move semantics. The cycle duration should be a random value between 4 and 6 seconds. 
    // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles. 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(4000, 6000);
    int cycleDuration = distr(gen);

    auto lastUpdate = std::chrono::system_clock::now();

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        long timeSinceLastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now() - lastUpdate).count();

        if (timeSinceLastUpdate >= cycleDuration) {
            if (_currentPhase == TrafficLightPhase::red) {
                _currentPhase = TrafficLightPhase::green;
            } else {
                _currentPhase = TrafficLightPhase::red;
            }

           TrafficLightPhase currentPhase = getCurrentPhase();

           _messageQueue.send(std::move(_currentPhase));

            cycleDuration = distr(gen);

            lastUpdate = std::chrono::system_clock::now();
        }
    }
}
