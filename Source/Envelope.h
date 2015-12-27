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
    
    void setSampleRate(float newSampleRate);
    float getSampleRate();
    
    void setAttackSeconds(float seconds);
    void setDecaySeconds(float seconds);
    void setReleaseSeconds(float seconds);
    void setSustainLevel(float level);
    
    void trigger();
    void triggerRelease();
    void triggerDead();
    
    void tick();
    float getLevel();
    int getCurrentState();
    bool isActive() const;
    
private:
    void triggerDecay();
    void triggerSustain();
    inline float getSegmentCoefficient(float startLevel, float endLevel, int durationInSamples) const;
    void convertSecondsToSamples();
    
    float sampleRate = 0.f;
    
    float attackSeconds = 0.f;
    float decaySeconds = 0.f;
    float sustainLevel = 1.f;
    float releaseSeconds = 0.5;
    
    float level = 0;
    float coefficient = 0;
    float increment = 0;
    
    unsigned long attackSamples = 0;
    unsigned long decaySamples = 0;
    unsigned long releaseSamples = 0;
    
    float currentLevel = 0.f;
    
    int state = DEAD_STATE;
    
};



#endif  // ENVELOPE_H_INCLUDED
