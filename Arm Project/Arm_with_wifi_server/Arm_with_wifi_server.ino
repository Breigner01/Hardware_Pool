#include <WiFi.h>
#include <AsyncUDP.h>
#include <Servo.h>

const char * ssid = "Arm_Server";
const char * password = "The_Glove42";

WiFiServer server(80);

Servo base;
Servo up_down;
Servo forward_backward;
Servo pick;

const int basePin = 27;
const int up_downPin = 26;
const int forward_backwardPin = 25;
const int pickPin = 33;

int x = 0;
int y = 0;
int z = 0;
int b = 0;

String x_str;
String y_str;
String z_str;
String b_str;

AsyncUDP udp;

void setup()
{
    Serial.begin(115200);

    base.attach(basePin);
    up_down.attach(up_downPin);
    forward_backward.attach(forward_backwardPin);
    pick.attach(pickPin);

    WiFi.softAP(ssid, password);

    if(udp.listen(1234)) {
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.softAPIP());
        udp.onPacket([](AsyncUDPPacket packet) {
            Serial.write(packet.data(), packet.length());
            Serial.println("");
            x = String((char *)packet.data()).indexOf('x');
            y = String((char *)packet.data()).indexOf('y');
            z = String((char *)packet.data()).indexOf('z');
            b = String((char *)packet.data()).indexOf('b');
            x_str = String((char *)packet.data()).substring(x + 1, y);
            y_str = String((char *)packet.data()).substring(y + 1, z);
            z_str = String((char *)packet.data()).substring(z + 1, b);
            b_str = String(b + 1);
            base.write(z_str.toInt());
            up_down.write(x_str.toInt());
            forward_backward.write(y_str.toInt());
            pick.write(b_str.toInt());
        });
    }
}

void loop()
{
    delay(100);
    udp.broadcast("Anyone here?");
}
