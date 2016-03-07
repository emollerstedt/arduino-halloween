#include <WaveHC.h>
#include <WaveUtil.h>
#include "WavePlay.h"


WavePlay wave;

void setup() {
  // put your setup code here, to run once:
  wave.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  wave.play("abbe2.WAV");
  delay(3000);
}
