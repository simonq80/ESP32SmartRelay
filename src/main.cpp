#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WebServer.h>

const int switch1 = 16;
const int switch2 = 17;

const char *ssid     = "Qwifi";
const char *password = "Quigleywifi1";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup()
{
    Serial.begin(9600);
    // Initialise relay switches
    pinMode(switch1, OUTPUT);
    pinMode(switch2, OUTPUT);
    
    
    // Connect to wifi
    WiFi.begin(ssid, password);
    while ( WiFi.status() != WL_CONNECTED ) {
        delay ( 500 );
        Serial.print ( "." );
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    timeClient.begin();
}

void loop()
{
    Serial.println("Hello world!");
    // if (state == 0) {
    //     digitalWrite(switch1, HIGH);
    //     digitalWrite(switch2, HIGH);
    //     state = 1;
    // } else {
    //     digitalWrite(switch1, LOW);
    //     digitalWrite(switch2, LOW);
    //     state = 0;
    // }
    timeClient.update();
    Serial.println(timeClient.getFormattedTime());
    delay(1000);
}
