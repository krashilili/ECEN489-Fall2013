#include <aJSON.h>

unsigned long last_print = 0;
aJsonStream serial_stream(&Serial);
int analogPin =0;

void setup()
{
  Serial.begin(9600);
}

/* Generate message like: { "analog": [0, 200, 400, 600, 800, 1000] } */
aJsonObject *createMessage()
{
  aJsonObject *msg = aJson.createObject(); 
  aJsonObject *id  = aJson.createItem("4"); // id is 1
  aJsonObject *sensor_value = aJson.createItem(analogRead(analogPin));
  aJson.addItemToObject(msg, "sensor_value", sensor_value); // add key 'sensor_value' and its    //value to a JSON object msg
  aJson.addItemToObject(msg, "id", id); // add key 'id' and its value to a JSON object msg
  return msg;
}

/* Process message like: { "pwm": { "8": 0, "9": 128 } } */
void processMessage(aJsonObject *msg)
{
  aJsonObject *pwm = aJson.getObjectItem(msg, "pwm");
  if (!pwm) {
    Serial.println("no pwm data");
    return;
  }

  const static int pins[] = { 8, 9 };
  const static int pins_n = 2;
  for (int i = 0; i < pins_n; i++) {
    char pinstr[3];
    snprintf(pinstr, sizeof(pinstr), "%d", pins[i]);

    aJsonObject *pwmval = aJson.getObjectItem(pwm, pinstr);
    if (!pwmval) continue; /* Value not provided, ok. */
    if (pwmval->type != aJson_Int) {
      Serial.print("invalid data type ");
      Serial.print(pwmval->type, DEC);
      Serial.print(" for pin ");
      Serial.println(pins[i], DEC);
      continue;
    }

    Serial.print("setting pin ");
    Serial.print(pins[i], DEC);
    Serial.print(" to value ");
    Serial.println(pwmval->valueint, DEC);
    analogWrite(pins[i], pwmval->valueint);
  }
}

void loop()
{
  if (millis() - last_print > 200) {
    /* One second elapsed, send message. */
    aJsonObject *msg = createMessage();
    aJson.print(msg, &serial_stream);
    Serial.println(); /* Add newline. */
    aJson.deleteItem(msg);
    last_print = millis();
  }

  if (serial_stream.available()) {
    /* First, skip any accidental whitespace like newlines. */
    serial_stream.skip();
  }

  if (serial_stream.available()) {
    /* Something real on input, let's take a look. */
    aJsonObject *msg = aJson.parse(&serial_stream);
    processMessage(msg);
    aJson.deleteItem(msg);
  }
}
