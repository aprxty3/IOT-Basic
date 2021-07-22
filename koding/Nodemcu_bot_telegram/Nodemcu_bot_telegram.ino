#include "CTBot.h"
CTBot myBot;

String ssid = "BOLT!-1A12";     // Sesuikan dengan nama wifi anda
String pass = "anaksoleh"; // sesuaikan password wifi
String token = "1938637412:AAFX992l4Zt22AwBwvtiF5z9gjsqMzPGP0c"; // token bot telegram yang telah dibuat

const int buzzer = 16; //D0
const int pirSensor = 5;  //D1

// defines variables
int motion;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(pirSensor, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection()) {
    Serial.println("\ntestConnection OK");
  }
  else {
    Serial.println("\ntestConnection Not OK");
  }

}

void loop() {
  TBMessage msg;

  if (myBot.getNewMessage(msg)) {

    if (msg.text.equalsIgnoreCase("YA")) {
      myBot.sendMessage(msg.sender.id, "Baik, rumah aman");  //kirim pesan ke bot telegram
    }
    else if (msg.text.equalsIgnoreCase("BUKAN")) {
      myBot.sendMessage(msg.sender.id, "Orang asing masuk ke rumah anda!");  //kirim pesan ke bot telegram
    }
    else {
      // membalas pesan selain kode diatas
      String reply;
      reply = (String)"Welcome " + msg.sender.username + (String)". Gunakan Command: \"YA\" atau \"BUKAN\" ketika untuk membalas pemberitahuan.";
      myBot.sendMessage(msg.sender.id, reply);
    }
  }

  motion = digitalRead(pirSensor);

  if (motion == HIGH) {
    myBot.sendMessage(msg.sender.id, "Ada orang melewati pintu! \nApakah itu anda? (YA / BUKAN)");
    for (int i = 0; i < 10; i++) {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(200);
    }
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
