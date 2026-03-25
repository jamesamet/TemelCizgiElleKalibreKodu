
void kalibrasyonYap() {
  for (int i = 0; i < 8; i++) {
    sensormin[i] = 1024;
    sensormax[i] = 0;
  }

  for (int i = 0; i < 250; i++)
  {
    for (int j = 0; j < 15; j++) {
      for (int k = 0; k < 8; k++) {
        if (sensormin[k] > analogRead(k)) sensormin[k] = analogRead(k);
        if (sensormax[k] < analogRead(k)) sensormax[k] = analogRead(k);
      }
    }
  }
}
