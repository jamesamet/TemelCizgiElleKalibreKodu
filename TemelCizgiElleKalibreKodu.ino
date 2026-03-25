/****** Hatay Robot Yarismasi ******/
/* Temel Cizgi Izleyen Egitim Kodu */
/************** 2025 ***************/
// Sabitler
#define sagmotor1 7
#define sagmotor2 8
#define sagmotorpwmpin 6
#define solmotor1 3
#define solmotor2 4
#define solmotorpwmpin 5
#define MZ80 2
#define LED 13


// Degiskenler
int ortalamaHIZ = 75;  // maksimum 255
int minDonusHizi = 24;
byte K, gorensensor;
float Kp = 0.075, Kd = 0.55, Ki = 0.00005;  // PID Degiskenleri
int sensormin[8]; int sensormax[8]; int SVal[8]; int SValx[8];
int sagmotorpwm = 0; int solmotorpwm = 0; int sonhata = 0; byte cizgivar;
unsigned int pozisyon = 3500; int integral = 0; int hata = 0; int sondeger = 3500;
byte cizgiKayipSayaci = 0;

void setup() {
  pinMode(MZ80, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(sagmotor1, OUTPUT);
  pinMode(sagmotor2, OUTPUT);
  pinMode(solmotor1, OUTPUT);
  pinMode(solmotor2, OUTPUT);
  digitalWrite(LED, LOW);  // LED Sondur
  motorDurdur(2000);       // 2 saniye motorlari durdur
  digitalWrite(LED, HIGH); // LED Yak
  kalibrasyonYap();
  digitalWrite(LED, LOW);  // LED Sondur
  delay(1000);
  engelKontrol();
  //degerokuma();
}

void loop() {
  engelKontrol();
  pozisyon = sensoroku();
  PIDhesap();
  motorkontrol(solmotorpwm, sagmotorpwm);
}
