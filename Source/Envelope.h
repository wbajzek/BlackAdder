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

enum EnvelopeState {
    ATTACK_STATE,
    DECAY_STATE,
    SUSTAIN_STATE,
    RELEASE_STATE,
    DEAD_STATE,
};

class Envelope
{
public:
    
    void setSampleRate(double newSampleRate);
    double getSampleRate();
    
    void setAttackSeconds(double seconds);
    void setDecaySeconds(double seconds);
    void setReleaseSeconds(double seconds);
    void setSustainLevel(double level);
    
    void trigger();
    void triggerRelease();
    void triggerDead();
    
    void tick();
    double getLevel();
    int getCurrentState();
    
private:
    void triggerDecay();
    void triggerSustain();
    
    double sampleRate = 0.f;

    bool gateIsOn = false;
    
    double attackSeconds = 0.f;
    double decaySeconds = 0.f;
    double sustainLevel = 1.f;
    double releaseSeconds = 0.5;
    
    double currentLevel = 0.f;
    
    int envelopeState = DEAD_STATE;
    
};



#endif  // ENVELOPE_H_INCLUDED
