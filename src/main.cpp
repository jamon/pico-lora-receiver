#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

//Inlude Library
#include "LoRa-RP2040.h"
#define LORA_RESET_PIN 20
#define LORA_DIO0_PIN 21
int main() {

   stdio_init_all();
    LoRa.setPins(PICO_DEFAULT_SPI_CSN_PIN, LORA_RESET_PIN, LORA_DIO0_PIN);
  sleep_ms(5000);
   if (!LoRa.begin(915E6)) {
      printf("Starting LoRa failed!\n");
      while (1);
   }

   printf("LoRa Started\n");
   
   int counter = 0;
   
   while (1) {
      int packetSize = LoRa.parsePacket();
      if (packetSize) {
         // received a packet
         printf("Received packet %d\n'", packetSize);

         // read packet
         while (LoRa.available()) {
            printf("%c", LoRa.read());
         }

         // print RSSI of packet
         printf("' with RSSI %d\n", LoRa.packetRssi());
      }
  }

  return 1;
}