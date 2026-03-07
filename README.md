# Aeroderivative Turbine Power Control

Control-oriented modeling and FADEC-inspired control of an aeroderivative gas turbine for stationary power applications.

Inspired by IEEE Spectrum coverage of aeroderivative turbines used for data-center power.

## Project Overview

This repository contains:
- A control-oriented Simulink plant model of an aeroderivative turbine–generator system
- A native C++ embedded supervisory controller skeleton implementing state-based turbine logic

The embedded implementation focuses on decision logic and fuel command scheduling,
independent of low-level control tuning.

[References folder](./references/)


Placeholder update II Mar7