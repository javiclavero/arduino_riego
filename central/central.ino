#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24(8,53); //CE, CSN

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println(nrf24.init());
  if(!nrf24.init())
    Serial.println("fallo de inicialización");
  if(!nrf24.setChannel(2))
    Serial.println("fallo en establecer canal");
  if(!nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("fallo en opciones RF");

    Serial.println("Base iniciada");
}

void loop() {

  if(nrf24.available())
  {
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if(nrf24.recv(buf, &len))
    {
      Serial.print("Recibido: ");
      Serial.println((char*)buf);

      uint8_t data[] = "Hola amigo remoto";
      nrf24.send(data, sizeof(data));
      nrf24.waitPacketSent();
      Serial.println("Respondiendo");
           
    }

  }
}
