/*
  ==============================================================================

    Envelope.cpp
    Created: 19 Dec 2015 7:52:36pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "Envelope.h"

void Envelope::setSampleRate(double newSampleRate)
{
    sampleRate = newSampleRate;
}

double Envelope::getSampleRate()
{
    return sampleRate;
}

void Envelope::setAttackSeconds(double seconds)
{
    attackSeconds = seconds;
}

void Envelope::setDecaySeconds(double seconds)
{
    decaySeconds = seconds;
}

void Envelope::setSustainLevel(double level)
{
    sustainLevel = level;
}

void Envelope::setReleaseSeconds(double seconds)
{
    releaseSeconds = seconds;
}

void Envelope::tick() {
    if (envelopeState != DEAD_STATE) {
        if (currentLevel >= 1.0)
            triggerDecay();
        else if (envelopeState == DECAY_STATE && currentLevel <= sustainLevel)
            triggerSustain();
        else if (envelopeState != ATTACK_STATE && currentLevel <= 0.001)
            triggerDead();
    }
}

int Envelope::getCurrentState()
{
    return envelopeState;
}

double Envelope::getLevel()
{
    return sustainLevel;
}

void Envelope::trigger()
{
    envelopeState = ATTACK_STATE;
}

void Envelope::triggerDecay()
{
    envelopeState = DECAY_STATE;
}

void Envelope::triggerSustain()
{
    currentLevel = sustainLevel;
}

void Envelope::triggerRelease()
{
    envelopeState = RELEASE_STATE;
}

void Envelope::triggerDead()
{
    envelopeState = DEAD_STATE;
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
        expect(myEnvelope.getLevel() == 0.f);
        myEnvelope.tick();
        expect(myEnvelope.getCurrentState() == DECAY_STATE);
        expect(myEnvelope.getLevel() == 1.f);
        myEnvelope.tick();
        expect(myEnvelope.getCurrentState() == SUSTAIN_STATE);
        expect(myEnvelope.getLevel() == level);
        myEnvelope.tick();
        expect(myEnvelope.getCurrentState() == SUSTAIN_STATE);
        expect(myEnvelope.getLevel() == level);
        myEnvelope.triggerRelease();
        expect(myEnvelope.getCurrentState() == RELEASE_STATE);
        myEnvelope.tick();
        expect(myEnvelope.getLevel() == 0.f);
        expect(myEnvelope.getCurrentState() == DEAD_STATE);
    }
};

static EnvelopeTests test;

#endif