// AntelliPuckBoard.cpp
#include "AntelliPuckBoard.h"
// DIO1 is the wakeup pin

  void AntelliPuckBoard::begin() {
    ESP32Board::begin();

    esp_reset_reason_t reason = esp_reset_reason();
    if (reason == ESP_RST_DEEPSLEEP) {
      long wakeup_source = esp_sleep_get_gpio_wakeup_status();
      if (wakeup_source & (1 << P_LORA_DIO_1)) {  // received a LoRa packet (while in deep sleep)
        startup_reason = BD_STARTUP_RX_PACKET;
      }

      // rtc_gpio_hold_dis((gpio_num_t)P_LORA_NSS);
      // rtc_gpio_deinit((gpio_num_t)P_LORA_DIO_1);
    }
  }

  void AntelliPuckBoard::powerOff() {
    // // Turn off PA
    // digitalWrite(P_LORA_PA_POWER, LOW);
    // rtc_gpio_hold_en((gpio_num_t)P_LORA_PA_POWER);

    ESP32Board::powerOff();
  }


  // const char* AntelliPuckBoard::getManufacturerName() const {
  //   return "Antelli Puck";
  // }

  
