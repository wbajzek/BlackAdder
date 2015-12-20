/*
  ==============================================================================

    Oscillator.h
    Created: 19 Dec 2015 6:42:08pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class Oscillator
{
public:
    void setSampleRate(float newSampleRate);
    float getSampleRate();
    
    void setFrequency(float frequency);
    float getFrequency();

private:
    float sampleRate;
    float frequency;
};


#endif  // OSCILLATOR_H_INCLUDED
