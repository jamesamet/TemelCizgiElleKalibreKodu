void PIDhesap()
{
  hata = pozisyon - 3500;
  int mutlakHata = abs(hata);

  integral += hata;
  integral = constrain(integral, -4000, 4000);

  if (mutlakHata > 2200) integral = 0;

  int duzeltmehizi = Kp * hata + Kd * (hata - sonhata) + Ki * integral;
  duzeltmehizi = constrain(duzeltmehizi, -90, 90);
  sonhata = hata;

  int tabanHiz = map(mutlakHata, 0, 3500, ortalamaHIZ, minDonusHizi);
  tabanHiz = constrain(tabanHiz, minDonusHizi, ortalamaHIZ);

  sagmotorpwm = tabanHiz + duzeltmehizi;
  solmotorpwm = tabanHiz - duzeltmehizi;
  sagmotorpwm = constrain(sagmotorpwm, -55, 255); // Hiz araligi
  solmotorpwm = constrain(solmotorpwm, -55, 255);
}
