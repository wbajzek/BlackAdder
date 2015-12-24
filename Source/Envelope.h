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

enum envelopeState {
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
    inline double getSegmentCoefficient(double startLevel, double endLevel, int durationInSamples) const;
    void convertSecondsToSamples();
    
    double sampleRate = 0.f;
    
    double attackSeconds = 0.f;
    double decaySeconds = 0.f;
    double sustainLevel = 1.f;
    double releaseSeconds = 0.5;
    
    double level = 0;
    double coefficient = 0;
    double increment = 0;
    
    unsigned long attackSamples = 0;
    unsigned long decaySamples = 0;
    unsigned long releaseSamples = 0;
    
    double currentLevel = 0.f;
    
    int state = DEAD_STATE;
    
};



#endif  // ENVELOPE_H_INCLUDED
