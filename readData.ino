#include <SPI.h>
#include <WiFi101.h>
char ssid[] = "";
char pass[] = "";
char serverAddress[] = "serverOfYourProjectFunction.com";


WiFiSSLClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Connecting to WiFi...");
  connectToWiFi();

  Serial.println("Sending HTTP request...");

}

void loop() {
  // ideal sensor's data f.e. int a = analogRead(sensor1); 
  int a = 2;
  int b = 3;
  int c = 4;
  
  
 
 
    
    // creating the URL fields with data to send
    String statoA = "co2=" + String(a);
    String statoB = "&oss=" + String(b);
    String statoC = "&ozo=" + String(c);
    String final = statoA + statoB + statoC;

  
  // making GET request to HTTP server
  if (client.connectSSL(serverAddress, 443)) {                     // port 80 for HTTP, port 443 for HTTPS
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET /saveData?" + finalGeneral + " HTTP/1.1");
    client.println("Host: yourServerAddress");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Connection not established.");
  }
  



  Serial.println("Disconnected");
  client.stop();

  //set your interval 
  delay(60000); 
}

void connectToWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
    delay(5000);
    Serial.println("Connecting...");
  }
  Serial.println("Connection established");
}
