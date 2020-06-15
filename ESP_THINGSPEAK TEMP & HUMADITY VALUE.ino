#include <DHT.h>  
#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h>  
#define DHTPIN D2 
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);  
const char* ssid = "PRINCE";  //put your wifi name
const char* password ="PRINCE748@";  //put your wifi password
WiFiClient client;  
unsigned long myChannelNumber = 817276;  //put your channel number of Thingspeak
const char * myWriteAPIKey = "VP7662DCQCE6QIT5";   //put your API Key of Thingspeak
uint8_t temperature, humidity;  
void setup()  
{  
  Serial.begin(9600);  
  dht.begin();  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
}  
void loop()   
{  
  static boolean data_state = false;  
  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();  
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
  Serial.println("C");  
  Serial.print("Humidity Value is :");  
  Serial.print(humidity);  
  Serial.println("%");  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1.  
 
   
   ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);  
    
  
   ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);  
    
    
  delay(1000);
}
// ThingSpeak will only accept updates every 15 seconds.
