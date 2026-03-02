#include <iostream>
#include "controller.h"

void update_state(ControllerContext& c) {
    if (c.state == TurbineState::INIT)
        c.state = TurbineState::STARTUP;
    else if (c.state == TurbineState::STARTUP && c.speed > 0.5f)
        c.state = TurbineState::RUN;
    else if (c.state == TurbineState::RUN && c.load_request > 0.2f)
        c.state = TurbineState::LOAD_CHANGE;
    else if (c.state == TurbineState::LOAD_CHANGE)
        c.state = TurbineState::RUN;
}

void update_fuel(ControllerContext& c) {
    if (c.state == TurbineState::STARTUP)
        c.fuel_cmd += 0.01f;
    if (c.state == TurbineState::LOAD_CHANGE)
        c.fuel_cmd += 0.02f;

    if (c.fuel_cmd > 1.0f) c.fuel_cmd = 1.0f;
}

void simulate_plant(ControllerContext& c) {
    c.speed += c.fuel_cmd * 0.01f;
    if (c.load_request > 0.0f)
        c.speed -= c.load_request * 0.005f;
}

int main() {
    ControllerContext c;

    for (int t = 0; t < 500; t++) {
        if (t == 200) c.load_request = 0.3f;

        update_state(c);
        update_fuel(c);
        simulate_plant(c);

        std::cout
            << "t=" << t
            << " speed=" << c.speed
            << " fuel=" << c.fuel_cmd
            << " state=" << static_cast<int>(c.state)
            << "\n";
    }
}