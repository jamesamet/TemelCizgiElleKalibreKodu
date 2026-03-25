void engelKontrol()
{
  while (digitalRead(MZ80) == 0) {
    motorDurdur(1);
  }
}
