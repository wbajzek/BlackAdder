/*
  ==============================================================================

    Oscillator.h
    Created: 19 Dec 2015 6:42:08pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "Synthesizer.h"
#include "SineWaveTable.h"

class Oscillator
{
public:
    void setSampleRate(float newSampleRate);
    float getSampleRate();
    
    void setFrequency(float frequency);
    float getFrequency();
    
    void tick();
    float getSample();

private:
    float sampleRate = 0.f;
    float frequency = 0.f;
    unsigned long index = 0;
    int freqTL = 0;
    float increment = 0;
    
};


#endif  // OSCILLATOR_H_INCLUDED
