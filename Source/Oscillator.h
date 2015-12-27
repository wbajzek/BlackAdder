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
    
    void tick() noexcept;
    float getSample() const noexcept;

private:
    float sampleRate = 0.f;
    float frequency = 0.f;
    unsigned long index = 0;
    float freqTL = 0.f;
    float increment = 0;
    float nyquist = 0.0;
};


#endif  // OSCILLATOR_H_INCLUDED
