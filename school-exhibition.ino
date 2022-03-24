/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLFGBOoM9P"
#define BLYNK_DEVICE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "B6SkNZbsXLFQp6D8lh3k3htBVwAGTjkw"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Suhaspai";
char pass[] = "shivam@123";



// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}



void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 100), 8080);
}
BLYNK_WRITE(V0) {
  int relay1 = param.asInt();
  if (relay1 == 1) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
void loop()
{
  Blynk.run();
  pinMode(2, OUTPUT);

}
