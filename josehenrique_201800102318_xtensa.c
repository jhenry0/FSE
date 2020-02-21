#include <ESP8266WiFi.h>

const char *ssid = "Wi-Fi Name"; //  Your Wi-Fi Name

const char *password = "Password"; // Wi-Fi Password

#define LED 2// led connected to GPIO2 (D4)
#define BUTTON 13
WiFiServer server(80);
void setup()
{

    Serial.begin(9600); //Default Baudrate

    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    pinMode()
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    server.begin(); // Starts the Server
    Serial.println(WiFi.localIP());
}

void loop()
{
    WiFiClient client = server.available();

    if (!client)

    {

        return;
    }

    Serial.println("Waiting for new client");

    while (!client.available())
    delay(1);
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();
    int value = LOW;
    if (request.indexOf("/LED=1") != -1)
    {

        digitalWrite(LED, !digitalRead(BUTTON)); 
    }

    //*------------------HTML Page Code---------------------*//
    
    client.println("HTTP/1.1 200 OK"); //
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.print(" Liga ou desliga led: ");
    if (digitalRead(BUTTON) == 1)

    {

        client.print("Ligo");
    }

    else

    {

        client.print("Desligo");
    }

    client.println("<br><br>");

    client.println("<a href=\"/LED=1\"\"><button>LED</button></a><br />");
    client.println("</html>");
    delay(1);
    Serial.println("Client disonnected");

    Serial.println("");
}
