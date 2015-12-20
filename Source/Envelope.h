/*
  ==============================================================================

    Envelope.h
    Created: 19 Dec 2015 7:52:36pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "Synthesizer.h"

class Envelope
{
public:
    void setSampleRate(double newSampleRate);
    double getSampleRate();
    
    void setAttackSeconds(double seconds);
    void setDecaySeconds(double seconds);
    void setReleaseSeconds(double seconds);
    void setSustainLevel(double level);
    
    void tick();
    double getLevel();
    
private:
    double sampleRate = 0.f;

    double attackSeconds = 0.f;
    double decaySeconds = 0.f;
    double sustainLevel = 1.f;
    double releaseSeconds = 0.5;
};



#endif  // ENVELOPE_H_INCLUDED
