// include the library code for LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float value;
int pressureinbar = 0;
String ssid
= "Simulator Wifi"; // SSID to connect to
String password = ""; // Our virtual wifi has no password (so dont do your banking
String host
= "api.thingspeak.com"; // Open Weather Map API
const int httpPort = 80;
String uri
= "/update?api_key=PWVX09BUXSNJ7IGJ&field1=";
int setupESP8266(void) {
// Start our ESP8266 Serial Communication
Serial.begin(115200); // Serial connection over USB to computer
Serial.println("AT"); // Serial connection on Tx / Rx port to ESP8266
delay(10);
// Wait a little for the ESP to respond
if (!Serial.find("OK")) return 1;
// Connect to 123D Circuits Simulator Wifi
Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");delay(10);
// Wait a little for the ESP to respond
if (!Serial.find("OK")) return 2;
// Open TCP connection to the host:
Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
delay(50);
// Wait a little for the ESP to respond
if (!Serial.find("OK")) return 3;
return 0;
}
void anydata(int pressureinbar) {
	int temp = map(analogRead(A0),20,358,-40,125);
	int tempi = map(pressureinbar,20,358,-40,125);
// Construct our HTTP call
	String httpPacket = "GET " + uri + String(temp) + "&field2=" + String(tempi) + "HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
	int length = httpPacket.length();
// Send our message length
	Serial.print("AT+CIPSEND=");
Serial.println(length);delay(10); // Wait a little for the ESP to respond if (!Serial.find(">")) return -1;
// Send our http request
Serial.print(httpPacket);
delay(10); // Wait a little for the ESP to respond
if (!Serial.find("SEND OK\r\n")) return;
}
void setup() {
// set up the LCD's number of columns and rows:
	lcd.begin(16, 2);
	setupESP8266();
}
void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
	value = analogRead(A0)*0.004882814;
	value = (value - 0.5) * 100.0;
	lcd.setCursor(0,0);
	lcd.print("Temp:");
	lcd.print(value);
	lcd.print("C");
	float pressureSensorVal = analogRead(A1);float barVoltage = (pressureSensorVal/1024.0) * 5.0;
	if (pressureSensorVal < 102.00 || pressureSensorVal == 102.00){
		pressureinbar = 0;
	}
	else {
		float pressureinbarToRound = ((barVoltage * 155.0) / 0.5) * 1.333 ;
		pressureinbar = (int)roundf(pressureinbarToRound);
	}
	lcd.setCursor(0,1);
	lcd.print("Pressure:");
	lcd.print(pressureinbar);
	lcd.print("mb");
	anydata(pressureinbar);
	delay(10000);
}
