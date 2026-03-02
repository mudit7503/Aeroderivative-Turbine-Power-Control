#pragma once

enum class TurbineState {
    INIT,
    STARTUP,
    RUN,
    LOAD_CHANGE,
    FAULT,
    SHUTDOWN
};

struct ControllerContext {
    float speed = 0.0f;
    float fuel_cmd = 0.0f;
    float load_request = 0.0f;
    bool fault = false;
    TurbineState state = TurbineState::INIT;
};