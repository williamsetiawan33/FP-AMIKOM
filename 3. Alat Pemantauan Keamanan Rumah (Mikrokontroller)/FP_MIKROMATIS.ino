
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLPQ70ihb7"            // template dan device yang dibuat, dapat kita lihat di web blynk cloud
#define BLYNK_DEVICE_NAME "SecurityOne"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"                              // menyertakan library yang diperlukan agar blynk dapat berjalan
//#include <EEPROM.h>
BlynkTimer timer;                                     // membuat objek timer(pewaktu untuk mengirimkan data pembacaan sensor ke blynk secara berinterval)

int magnet = 0;                                       // pin untuk sensor mc-38
int buz = 5;                                          // pin untuk buzzer
bool isReady = 0;                                     // boolean untuk menyimpan kesiapan alarm
//bool kondisiblynk;

BLYNK_WRITE(V0)                               // instruksi blynk ketika button V0(datastream) di blynk ditekan maka akan mengatur
  {                                           // pin buzzer ke kondisi LOW(reset buzzer ketika alarm dipicu)--->mematikan buzzer
    int restartbuz = param.asInt();           // dan mengatur alarm ke kondisi siap.
    if(restartbuz != 0)                       
    {
    isReady = 1;
    digitalWrite(buz, LOW);
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V1, 0);
    }
  }
  
void setup()
{
  //kondisiblynk = Blynk.connected();          // var kondisiblynk akan bernilai false apabila perangkat belum terkoneksi ke blynk.
  //if(kondisiblynk == false)                  // jika var kondisiblynk bernilai 0 maka eeprom akan dibersihkan untuk menghapus ssid dan pass wifi
  //{                                          // serta token blynk yang tersimpan di perangkat
    //EEPROM.begin(512);                       // hal ini dilakukan supaya saat nama ssid(wifi) berubah maka kita dapat mengatur ulang wifi yang digunakan.
  // tulis 0 ke semua 512 bytes EEPROM
  //for (int i = 0; i < 512; i++) {
    //EEPROM.write(i, 0);
  //}  
  //pinMode(13, OUTPUT);
  //digitalWrite(13, LOW);            // hidupkan led ketika pembersihan eeprom selesai.
  //EEPROM.end();
    //}  
  pinMode(magnet, INPUT_PULLUP);
  pinMode(buz, OUTPUT);
  digitalWrite(buz, LOW);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();                        //memulai blynk.
  timer.setInterval(1000L, timer1);           //mengatur interval timer pengiriman data ke blynk sebesar 1 detik.
}

void timer1()                                 // timer untuk mengirimkan data pembacaan sensor secara berinterval ke blynk.
  {
if(digitalRead(magnet) == HIGH && isReady == 1) // jika pintu/jendela terbuka dan alarm sudah siap, maka akan menghidupkan
{                                               // buzzer dan led di blynk.
  digitalWrite(buz, HIGH);
  Blynk.virtualWrite(V2, 1);
  Blynk.virtualWrite(V1, 1);
  }  
  }

void loop() {
  BlynkEdgent.run();                              // mulai jalankan blynk
  timer.run();                                    // ketika perangkat sudah terkoneksi ke blynk maka proses pengiriman data ke blynk akan dimulai
}
