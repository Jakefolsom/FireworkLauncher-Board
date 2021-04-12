

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "🎆 JFC Firework System 🎆";
const char* password = "jfcfirework";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String relay1State = "off";
String relay2State = "off";
String relay3State = "off";
String relay4State = "off";
String relay5State = "off";
String relay6State = "off";
String relay7State = "off";
String relay8State = "off";
String relay9State = "off";
String relay10State = "off";
String relay11State = "off";
String relay12State = "off";
String relay13State = "off";
String relay14State = "off";
String relay15State = "off";
String relay16State = "off";
String statusLightState = "off";
String alertSoundState = "Off";

// Assign output variables to GPIO pins
const int relay1 = 4;
const int relay2 = 5;
const int relay3 = 13;
const int relay4 = 14;
const int relay5 = 15;
const int relay6 = 16;
const int relay7 = 17;
const int relay8 = 18;
const int relay9 = 19;
const int relay10 = 20;
const int relay11 = 21;
const int relay12 = 22;
const int relay13 = 23;
const int relay14 = 24;
const int relay15 = 25;
const int relay16 = 26;
const int statusLight = 27;
const int alertSound = 32;

void setup() {
    Serial.begin(115200);
    // Initialize the output variables as outputs
    pinMode(relay1, INPUT);
    pinMode(relay2, INPUT);
    pinMode(relay3, INPUT);
    pinMode(relay4, INPUT);
    pinMode(relay5, INPUT);
    pinMode(relay6, INPUT);
    pinMode(relay7, INPUT);
    pinMode(relay8, INPUT);
    pinMode(relay9, INPUT);
    pinMode(relay10, INPUT);
    pinMode(relay11, INPUT);
    pinMode(relay12, INPUT);
    pinMode(relay13, INPUT);
    pinMode(relay14, INPUT);
    pinMode(relay15, INPUT);
    pinMode(relay16, INPUT);
    pinMode(statusLight, INPUT);
    pinMode(alertSound, OUTPUT);

    // Connect to Wi-Fi network with SSID and password
    Serial.print("Setting AP (Access Point)…");
    // Remove the password parameter, if you want the AP (Access Point) to be open
    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    server.begin();
}

void loop() {
    WiFiClient client = server.available();   // Listen for incoming clients

    if (client) {                             // If a new client connects,
        
        Serial.println("New Client.");          // print a message out in the serial port
        String currentLine = "";                // make a String to hold incoming data from the client
        while (client.connected()) {            // loop while the client's connected
            if (client.available()) {             // if there's bytes to read from the client,
                char c = client.read();             // read a byte, then
                Serial.write(c);                    // print it out the serial monitor
                header += c;
                if (c == '\n') {                    // if the byte is a newline character
                    // if the current line is blank, you got two newline characters in a row.
                    // that's the end of the client HTTP request, so send a response:
                    if (currentLine.length() == 0) {
                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();

                        // turns the GPIOs on and off
                        if (header.indexOf("GET /relay1/on") >= 0) {
                            Serial.println("relay1 on");
                            relay1State = "on";
                            pinMode(relay1, OUTPUT);
                            digitalWrite(relay1, LOW);
                        } else if (header.indexOf("GET /relay1/off") >= 0) {
                            Serial.println("relay1 off");
                            relay1State = "off";
                            pinMode(relay1, INPUT);
                        } else if (header.indexOf("GET /relay2/on") >= 0) {
                            Serial.println("relay2 on");
                            relay2State = "on";
                            pinMode(relay2, OUTPUT);
                            digitalWrite(relay2, LOW);
                        } else if (header.indexOf("GET /relay2/off") >= 0) {
                            Serial.println("relay2 off");
                            relay2State = "off";
                            pinMode(relay2, INPUT);
                        } else if (header.indexOf("GET /relay3/on") >= 0) {
                            Serial.println("relay3 on");
                            relay3State = "on";
                            pinMode(relay3, OUTPUT);
                            digitalWrite(relay3, LOW);
                        } else if (header.indexOf("GET /relay3/off") >= 0) {
                            Serial.println("relay3 off");
                            relay3State = "off";
                            pinMode(relay3, INPUT);
                        } else if (header.indexOf("GET /relay4/on") >= 0) {
                            Serial.println("relay4 on");
                            relay4State = "on";
                            pinMode(relay4, OUTPUT);
                            digitalWrite(relay4, LOW);
                        } else if (header.indexOf("GET /relay4/off") >= 0) {
                            Serial.println("relay4 off");
                            relay4State = "off";
                            pinMode(relay4, INPUT);
                        } else if (header.indexOf("GET /relay5/on") >= 0) {
                            Serial.println("relay5 on");
                            relay5State = "on";
                            pinMode(relay5, OUTPUT);
                            digitalWrite(relay5, LOW);
                        } else if (header.indexOf("GET /relay5/off") >= 0) {
                            Serial.println("relay5 off");
                            relay5State = "off";
                            pinMode(relay5, INPUT);
                        } else if (header.indexOf("GET /relay6/on") >= 0) {
                            Serial.println("relay6 on");
                            relay6State = "on";
                            pinMode(relay6, OUTPUT);
                            digitalWrite(relay6, LOW);
                        } else if (header.indexOf("GET /relay6/off") >= 0) {
                            Serial.println("relay6 off");
                            relay6State = "off";
                            pinMode(relay6, INPUT);
                        } else if (header.indexOf("GET /relay7/on") >= 0) {
                            Serial.println("relay7 on");
                            relay7State = "on";
                            pinMode(relay7, OUTPUT);
                            digitalWrite(relay7, LOW);
                        } else if (header.indexOf("GET /relay7/off") >= 0) {
                            Serial.println("relay7 off");
                            relay7State = "off";
                            pinMode(relay7, INPUT);
                        } else if (header.indexOf("GET /relay8/on") >= 0) {
                            Serial.println("relay8 on");
                            relay8State = "on";
                            pinMode(relay8, OUTPUT);
                            digitalWrite(relay8, LOW);
                        } else if (header.indexOf("GET /relay8/off") >= 0) {
                            Serial.println("relay8 off");
                            relay8State = "off";
                            pinMode(relay8, INPUT);
                        } else if (header.indexOf("GET /relay9/on") >= 0) {
                            Serial.println("relay9 on");
                            relay9State = "on";
                            pinMode(relay9, OUTPUT);
                            digitalWrite(relay9, LOW);
                        } else if (header.indexOf("GET /relay9/off") >= 0) {
                            Serial.println("relay9 off");
                            relay9State = "off";
                            pinMode(relay9, INPUT);
                        } else if (header.indexOf("GET /relay10/on") >= 0) {
                            Serial.println("relay10 on");
                            relay10State = "on";
                            pinMode(relay10, OUTPUT);
                            digitalWrite(relay10, LOW);
                        } else if (header.indexOf("GET /relay10/off") >= 0) {
                            Serial.println("relay10 off");
                            relay10State = "off";
                            pinMode(relay10, INPUT);
                        } else if (header.indexOf("GET /relay11/on") >= 0) {
                            Serial.println("relay11 on");
                            relay11State = "on";
                            pinMode(relay11, OUTPUT);
                            digitalWrite(relay11, LOW);
                        } else if (header.indexOf("GET /relay11/off") >= 0) {
                            Serial.println("relay11 off");
                            relay11State = "off";
                            pinMode(relay11, INPUT);
                        } else if (header.indexOf("GET /relay12/on") >= 0) {
                            Serial.println("relay12 on");
                            relay12State = "on";
                            pinMode(relay12, OUTPUT);
                            digitalWrite(relay12, LOW);
                        } else if (header.indexOf("GET /relay12/off") >= 0) {
                            Serial.println("relay12 off");
                            relay12State = "off";
                            pinMode(relay12, INPUT);
                        } else if (header.indexOf("GET /relay13/on") >= 0) {
                            Serial.println("relay13 on");
                            relay13State = "on";
                            pinMode(relay13, OUTPUT);
                            digitalWrite(relay13, LOW);
                        } else if (header.indexOf("GET /relay13/off") >= 0) {
                            Serial.println("relay13 off");
                            relay13State = "off";
                            pinMode(relay13, INPUT);
                        } else if (header.indexOf("GET /relay14/on") >= 0) {
                            Serial.println("relay14 on");
                            relay14State = "on";
                            pinMode(relay14, OUTPUT);
                            digitalWrite(relay14, LOW);
                        } else if (header.indexOf("GET /relay14/off") >= 0) {
                            Serial.println("relay14 off");
                            relay14State = "off";
                            pinMode(relay14, INPUT);
                        } else if (header.indexOf("GET /relay15/on") >= 0) {
                            Serial.println("relay15 on");
                            relay15State = "on";
                            pinMode(relay15, OUTPUT);
                            digitalWrite(relay15, LOW);
                        } else if (header.indexOf("GET /relay15/off") >= 0) {
                            Serial.println("relay15 off");
                            relay15State = "off";
                            pinMode(relay15, INPUT);
                        } else if (header.indexOf("GET /relay16/on") >= 0) {
                            Serial.println("relay16 on");
                            relay16State = "on";
                            pinMode(relay16, OUTPUT);
                            digitalWrite(relay16, LOW);
                        } else if (header.indexOf("GET /relay16/off") >= 0) {
                            Serial.println("relay16 off");
                            relay16State = "off";
                            pinMode(relay16, INPUT);
                        } else if (header.indexOf("GET /statusLight/on") >= 0) {
                            Serial.println("statusLight on");
                            statusLightState = "on";
                            pinMode(statusLight, OUTPUT);
                            digitalWrite(statusLight, HIGH);

                        } else if (header.indexOf("GET /statusLight/off") >= 0) {
                            Serial.println("statusLight off");
                            statusLightState = "off";
                            digitalWrite(statusLight, LOW);
                        }
                        else if (header.indexOf("GET /verifyConnection") >=0){
                          int i = 0;
                          while(i <= 2) {
                              digitalWrite(alertSound, HIGH);
                              delay(1000);
                              digitalWrite(alertSound, LOW);
                              delay(1000);
                              i++;
                          }
                        }

                        // Display the HTML web page
                        client.println("<!DOCTYPE html><html>");
                        client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                        client.println("<link rel=\"icon\" href=\"data:,\">");
                        // CSS to style the on/off buttons
                        // Feel free to change the background-color and font-size attributes to fit your preferences
                        client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
                        client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
                        client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
                        client.println(".button2 {background-color: #555555;}</style></head>");

                        // Web Page Heading
                        client.println("<body><h1>JFC Fireworks</h1>");

                        client.println("<p>Relay 1 - State " + relay1State + "</p>");
                        if (relay1State=="off") {
                            client.println("<p><a href=\"/relay1/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay1/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 2 - State " + relay2State + "</p>");
                        if (relay2State=="off") {
                            client.println("<p><a href=\"/relay2/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay2/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 3 - State " + relay3State + "</p>");
                        if (relay3State=="off") {
                            client.println("<p><a href=\"/relay3/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay3/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 4 - State " + relay4State + "</p>");
                        if (relay4State=="off") {
                            client.println("<p><a href=\"/relay4/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay4/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 5 - State " + relay5State + "</p>");
                        if (relay5State=="off") {
                            client.println("<p><a href=\"/relay5/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay5/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 6 - State " + relay6State + "</p>");
                        if (relay6State=="off") {
                            client.println("<p><a href=\"/relay6/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay6/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 7 - State " + relay7State + "</p>");
                        if (relay7State=="off") {
                            client.println("<p><a href=\"/relay7/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay7/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 8 - State " + relay8State + "</p>");
                        if (relay8State=="off") {
                            client.println("<p><a href=\"/relay8/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay8/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 9 - State " + relay9State + "</p>");
                        if (relay9State=="off") {
                            client.println("<p><a href=\"/relay9/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay9/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 10 - State " + relay10State + "</p>");
                        if (relay10State=="off") {
                            client.println("<p><a href=\"/relay10/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay10/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 11 - State " + relay11State + "</p>");
                        if (relay11State=="off") {
                            client.println("<p><a href=\"/relay11/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay11/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 12 - State " + relay12State + "</p>");
                        if (relay12State=="off") {
                            client.println("<p><a href=\"/relay12/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay12/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 13 - State " + relay13State + "</p>");
                        if (relay13State=="off") {
                            client.println("<p><a href=\"/relay13/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay13/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 14 - State " + relay14State + "</p>");
                        if (relay14State=="off") {
                            client.println("<p><a href=\"/relay14/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay14/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 15- State " + relay15State + "</p>");
                        if (relay15State=="off") {
                            client.println("<p><a href=\"/relay15/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay15/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Relay 16 - State " + relay16State + "</p>");
                        if (relay16State=="off") {
                            client.println("<p><a href=\"/relay16/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/relay16/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("<p>Status Light- State " + statusLightState + "</p>");
                        if (statusLightState=="off") {
                            client.println("<p><a href=\"/statusLight/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/statusLight/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("</body></html>");

                        // The HTTP response ends with another blank line
                        client.println();
                        // Break out of the while loop
                        break;
                    } else { // if you got a newline, then clear currentLine
                        currentLine = "";
                    }
                } else if (c != '\r') {  // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }
            }
        }
        // Clear the header variable
        header = "";
        // Close the connection
        client.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
    }
}
