/**
 * @file headphone.ino
 * @author Phil Schatzmann
 * @brief Headphone Detection Demo
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "AudioKitHAL.h"
#include "SineWaveGenerator.h"


AudioKit kit;
SineWaveGenerator wave;
SineWaveGenerator wave2;
SineWaveGenerator wave3;

const int BUFFER_SIZE = 1024;
uint8_t buffer[BUFFER_SIZE];

void setup() {
  LOGLEVEL_AUDIOKIT = AudioKitInfo; 
  Serial.begin(115200);
  // open in write mode
  auto cfg = kit.defaultConfig(AudioOutput);
  kit.begin(cfg);

  // 1000 hz
  wave.setFrequency(1000);
  wave.setSampleRate(cfg.sampleRate());

    // 500 hz
  wave2.setFrequency(500);
  wave2.setSampleRate(cfg.sampleRate());

      // 300 hz
  wave3.setFrequency(300);
  wave3.setSampleRate(cfg.sampleRate());

}

void loop() {
  size_t l = wave.read(buffer, BUFFER_SIZE);
  kit.write(buffer, l);
//delay(1000);  

  size_t m = wave2.read(buffer, BUFFER_SIZE);
  kit.write(buffer, m);

//delay(1000);  

//  size_t n = wave3.read(buffer, BUFFER_SIZE);
//  kit.write(buffer, n);
  
}
