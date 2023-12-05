#include <Arduino.h>
// pin index
// pb-14 pada nucleo ke pin 10 arduino

// pin pulse
// pd-2 pada nucleo ke pin 9 arduino
const int pulsePin = 9;  // Pin untuk sinyal pulsa
const int indexPin = 10; // Pin untuk sinyal index
const int resolusiEncoder = 2500;
const int delayPulse = 50;

int pulseCount = 0; // Variabel untuk menghitung jumlah pulsa

void setup()
{
  pinMode(pulsePin, OUTPUT);
  pinMode(indexPin, OUTPUT);

  // Menginisialisasi Serial Monitor
  Serial.begin(9600);
}

void loop()
{
  // Simulasi pulsa dari encoder
  digitalWrite(pulsePin, HIGH);
  delayMicroseconds(delayPulse); // Sesuaikan delay sesuai dengan kecepatan encoder
  digitalWrite(pulsePin, LOW);

  // Menghitung jumlah pulsa
  pulseCount++;

  // Memeriksa apakah sudah mencapai 2500 pulsa
  if (pulseCount == resolusiEncoder)
  {
    // Memberikan pulsa pada pin index
    digitalWrite(indexPin, HIGH);
    delayMicroseconds(delayPulse); // Sesuaikan delay sesuai dengan kecepatan encoder
    digitalWrite(indexPin, LOW);

    // Mereset jumlah pulsa
    pulseCount = 0;

    // Menampilkan pesan di Serial Monitor
    Serial.println("Index pulse generated!");
  }

  // Tambahkan delay sesuai dengan kecepatan encoder
  delayMicroseconds(delayPulse);
}
