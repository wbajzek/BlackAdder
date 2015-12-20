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
    void setSampleRate(double newSampleRate);
    double getSampleRate();
    
    void setFrequency(double frequency);
    double getFrequency();
    
    double getSample();

private:
    double sampleRate = 0.f;
    double frequency = 0.f;
    double currentAngle = 0.f;
    double angleDelta = 0.f;
    
};


#endif  // OSCILLATOR_H_INCLUDED
