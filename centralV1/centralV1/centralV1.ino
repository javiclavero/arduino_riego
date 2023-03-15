void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Configura el LED_BUILTIN como salida
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED integrado
  delay(1000); // Espera 1 segundo
  digitalWrite(LED_BUILTIN, LOW); // Apaga el LED integrado
  delay(1000); // Espera 1 segundo
}