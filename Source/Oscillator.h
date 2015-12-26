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
    void setSampleRate(double newSampleRate);
    double getSampleRate();
    
    void setFrequency(double frequency);
    double getFrequency();
    
    void tick();
    double getSample();

private:
    double sampleRate = 0.f;
    double frequency = 0.f;
    unsigned long index = 0;
    int freqTL = 0;
    double increment = 0;
    
};


#endif  // OSCILLATOR_H_INCLUDED
