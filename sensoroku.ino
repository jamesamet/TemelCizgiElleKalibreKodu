int sensoroku() {
  unsigned long ortalama = 0;
  unsigned int toplam = 0;
  cizgivar = 0;
  gorensensor = 0;

  for (int i = 0; i < 8; i++) {
    int minmaksfark = sensormax[i] - sensormin[i];
    if (minmaksfark <= 0) minmaksfark = 1;

    long int hesaplama = analogRead(i) - sensormin[i];
    hesaplama = hesaplama * 1000;
    hesaplama = hesaplama / minmaksfark;
    SVal[i] = constrain(hesaplama, 0, 1000);
    SValx[i] = 1000 - SVal[i];
  }

  for (int i = 0; i < 8; i++) {
    if (SValx[i] > 250)  {
      cizgivar = 1;
      gorensensor++;
    }
    if (SValx[i] > 100) {
      ortalama += SValx[i] * i ;
      toplam += SValx[i];
    }
  }

  if (cizgivar == 0) {
    cizgiKayipSayaci++;

    if (cizgiKayipSayaci < 3) {
      return sondeger;
    }

    if (sondeger < 3250)  return 600;
    if (sondeger > 3750)  return 6400;
    return 3500;
  }

  cizgiKayipSayaci = 0;
  ortalama = ortalama * 1000;
  sondeger = ortalama / toplam;
  return sondeger;
}

void degerokuma() {
   Serial.begin(9600);
  while(1){
    sensoroku();
  for (int i = 0; i < 8; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(SVal[i]);
    Serial.print("  ");
  }
Serial.println("  ");
  delay(500);
  }
}
