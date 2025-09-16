void setup() {
  Serial.begin(9600);

  //выходы порта в
  DDRB = 0b00111100;

  //входы порта d
  DDRD &= ~0b00001110;

  PORTD |= 0b00001110;
}

void loop() {
  // чтение порта d
  if (!(PIND & 0b00000010)) {
    PORTB |= 0b00100000; // включаем d13
    Serial.println("считан с позиции PD1 (D1) - красный");
    Serial.println("0b00100000");
  }
  else if (!(PIND & 0b00000100)) {
    PORTB |= 0b00010000; // включаем d12
    Serial.println("считан с позиции PD2 (D2) - желтый");
    Serial.println("0b00010000");
  }
  else if (!(PIND & 0b00001000)) {
    PORTB |= 0b00001000; // включаем d11
    Serial.println("считан с позиции PD3 (D3) - зеленый");
    Serial.println("0b00001000");
  }
  else {
  
    PORTB &= ~0b00111100;
  }

  delay(50);
}