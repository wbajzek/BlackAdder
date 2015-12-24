/*
  ==============================================================================

    Envelope.cpp
    Created: 19 Dec 2015 7:52:36pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "Envelope.h"

void Envelope::convertSecondsToSamples()
{
    attackSamples = sampleRate * attackSeconds;
    decaySamples = sampleRate * decaySeconds;
    releaseSamples = sampleRate * releaseSeconds;
}

void Envelope::setSampleRate(double newSampleRate)
{
    sampleRate = newSampleRate;
    convertSecondsToSamples();
}

double Envelope::getSampleRate()
{
    return sampleRate;
}

void Envelope::setAttackSeconds(double seconds)
{
    attackSeconds = seconds;
    convertSecondsToSamples();
}

void Envelope::setDecaySeconds(double seconds)
{
    decaySeconds = seconds;
    convertSecondsToSamples();
}

void Envelope::setSustainLevel(double level)
{
    sustainLevel = level;
}

void Envelope::setReleaseSeconds(double seconds)
{
    releaseSeconds = seconds;
    convertSecondsToSamples();
}

void Envelope::tick() {
    if (state != DEAD_STATE) {
        level += increment + (coefficient * level);
        if (level >= 1.0)
            triggerDecay();
        else if (state == DECAY_STATE && level <= sustainLevel)
            triggerSustain();
        else if (state != ATTACK_STATE && level <= 0.001)
            triggerDead();
    }
}

inline double Envelope::getSegmentCoefficient(double startLevel, double endLevel, int durationInSamples) const
{
    // add a tiny fudge factor when calculating because it doesn't work when levels are exactly 0.0
    return (log((endLevel + 0.0001)) - log(startLevel + 0.0001)) / durationInSamples;
}

int Envelope::getCurrentState()
{
    return state;
}

double Envelope::getLevel()
{
    return level;
}

void Envelope::trigger()
{
    state = ATTACK_STATE;
    if (attackSamples == 0)
    {
        level = 1.0;
        increment = 0.0;
        triggerDecay();
    }
    else
    {
        increment = 1.0 / attackSamples;
        coefficient = 0.0;
    }
}

void Envelope::triggerDecay()
{
    state = DECAY_STATE;
    increment = 0.0;
    coefficient = getSegmentCoefficient(level, sustainLevel, decaySamples);
}

void Envelope::triggerSustain()
{
    state = SUSTAIN_STATE;
    level = sustainLevel;
    increment = 0.0;
    coefficient = 0.0;
}

void Envelope::triggerRelease()
{
    state = RELEASE_STATE;
    increment = 0.0;
    coefficient = getSegmentCoefficient(level, 0.0, releaseSamples);
}

void Envelope::triggerDead()
{
    state = DEAD_STATE;
    currentLevel = 0.0;
}

#if BLACKADDER_UNIT_TESTS
class EnvelopeTests : public UnitTest
{
public:
    EnvelopeTests() : UnitTest("Envelope tests") {}
    
    void runTest() override
    {
        double seconds = 1.f;
        double level = 0.8f;
        double sampleRate = 1.f;
        double currentLevel;
        Envelope myEnvelope;
        beginTest("Envelope");
        
        myEnvelope.setSampleRate(sampleRate);
        expect(myEnvelope.getSampleRate() == sampleRate);
        
        myEnvelope.setAttackSeconds(seconds);
        myEnvelope.setDecaySeconds(seconds);
        myEnvelope.setSustainLevel(level);
        myEnvelope.setReleaseSeconds(seconds);
        
        expect(myEnvelope.getCurrentState() == DEAD_STATE);
        myEnvelope.trigger();
        expect(myEnvelope.getCurrentState() == ATTACK_STATE);
        currentLevel = myEnvelope.getLevel();

        myEnvelope.tick();
        expect(myEnvelope.getLevel() > currentLevel);
        expect(myEnvelope.getCurrentState() == DECAY_STATE);
        currentLevel = myEnvelope.getLevel();

        myEnvelope.tick();
        expect(myEnvelope.getLevel() < currentLevel);
        myEnvelope.tick();

        expect(myEnvelope.getCurrentState() == SUSTAIN_STATE);
        expect(myEnvelope.getLevel() == level);
        
        myEnvelope.tick();
        expect(myEnvelope.getCurrentState() == SUSTAIN_STATE);
        expect(myEnvelope.getLevel() == level);
        
        myEnvelope.triggerRelease();
        expect(myEnvelope.getCurrentState() == RELEASE_STATE);

        myEnvelope.tick();
        expect(myEnvelope.getLevel() <= 0.f);
        expect(myEnvelope.getCurrentState() == DEAD_STATE);
    }
};

static EnvelopeTests test;

#endif