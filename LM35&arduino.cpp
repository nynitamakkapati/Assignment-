// Declare two integer variables: val and v1
int val, v1;

void setup() {
  // Configure the built-in LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read analog value from pin A0 (0-1023)
  val = analogRead(A0);

  // Convert analog value to millivolts (0-5000mV)
  float mv = (val / 1024.0) * 5000;

  // Convert millivolts to Celsius (assuming linear relationship and 10mV/°C)
  float cel = mv / 10;

  // Print temperature to serial monitor
  Serial.print("TEMPERATURE ");
  Serial.print(cel);
  Serial.print("C");
  Serial.println();

  // Turn on LED if temperature is below 30°C
  if (cel < 30) {
    for (v1 = 0; v1 < 2500; v1++) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
  } else {
    // Otherwise, turn on LED for a longer duration
    for (v1 = 0; v1 < 5000; v1++) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
