#ifndef WavePlay_h
#define WavePlay_h

#include <Arduino.h>
#include <WaveHC.h>
#include <WaveUtil.h>

class WavePlay
{
  public:
    WavePlay();
    void init();
    void play(char *wave);
  private:
    SdReader _card;
    FatVolume _vol;
    FatReader _root;
    FatReader _f;
    WaveHC _wave;
};





#endif