// AntelliPuckBoard.h
#pragma once

#include <Arduino.h>
#include <helpers/RefCountedDigitalPin.h>
#include <helpers/ESP32Board.h>

class AntelliPuckBoard : public ESP32Board {
protected:
public:
  void begin();
  void powerOff();
  // getManufacturerName();
  const char* getManufacturerName() const {
    return "Antelli Puck";
  }
};
