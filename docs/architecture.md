# Turbine Controller – System Architecture

## Purpose
This document describes the **high-level architecture** of the embedded
supervisory controller implemented in this repository.

The goal is to clarify **design intent**, **control philosophy**, and
**separation of responsibilities**, independent of tuning or hardware.

---

## Control Layers

The system is structured into three conceptual layers:

### 1. Plant (External)
- Turbine–generator dynamics
- Shaft inertia
- Load torque disturbances

These dynamics are **not implemented in embedded code** and are treated as
external to the controller.

---

### 2. Supervisory Controller (This Project)
Implemented in native C++.

Responsibilities:
- Operating state management
- Fuel command scheduling
- Reaction to load changes
- Fault handling and safe shutdown logic

The controller operates as a **finite state machine (FSM)**.

---

### 3. Low-Level Control (Future Work)
Not implemented here.

Examples:
- PID / LQR speed control
- Actuator-level loops
- Hardware drivers

These would run **below** the supervisory layer.

---

## Finite State Machine (FSM)

The controller uses explicit operating states:

- INIT  
- STARTUP  
- RUN  
- LOAD_CHANGE  
- FAULT  
- SHUTDOWN  

State transitions are driven by:
- Measured speed
- Load request
- Fault conditions

This mirrors industrial turbine control systems, where
**mode logic dominates behavior**.

---

## Fuel Command Philosophy

Fuel commands are:
- Generated based on state
- Bounded for safety
- Adjusted during load transitions

The controller does **not** attempt continuous regulation at this stage.

This reflects real-world practice:
supervisory logic **commands intent**, not dynamics.

---

## Validation Strategy

Logic is validated using a **native C++ test harness**:
- No hardware dependency
- Deterministic execution
- Easy inspection of state transitions

This allows early verification before:
- Control tuning
- Hardware porting
- Real-time constraints

---

## Design Intent Summary

This implementation prioritizes:
- Clarity over completeness
- Architecture over tuning
- Safety over performance

It is intended as a **foundation**, not a finished controller.