int pinValue = 0; 
int relay = 8;

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL63pfZfFFw"
#define BLYNK_TEMPLATE_NAME         "alpha"
#define BLYNK_AUTH_TOKEN            "gvoIwiZ41DCdq0_rW2LE68oWw8yYR5Ks"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
// char ssid[] = "PLDTHOMEFIBRYV5Fw";
// char pass[] = "PldtFibr2020?";
char ssid[] = "BOLT!Super4G-509A";
char pass[] = "a2qge47i";

// Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX
 
// Your ESP8266 baud rate:
#define ESP8266_BAUD 38400

ESP8266 wifi(&EspSerial);



BLYNK_WRITE(V1)
{
  pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  static int lastPinValue = pinValue;

  if (pinValue == 1)
  {
    digitalWrite(relay, HIGH);
    Serial.print("status: ");
    Serial.println(pinValue);
  }
  else if (pinValue == 0)
  {
    digitalWrite(relay, LOW);
    Serial.print("status: ");
    Serial.println(pinValue);
  }
}

void setup()
{
  // Debug console
  // Serial.begin(115200);
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);
  pinMode(relay, OUTPUT);
}

void loop()
{
  Blynk.run();
  Blynk.syncVirtual(V1);
 // Add a small delay to prevent excessive loop execution
}
