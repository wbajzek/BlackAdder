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
}

double Envelope::getLevel()
{
    return sustainLevel;
}

#if BLACKADDER_UNIT_TESTS
class EnvelopeTests : public UnitTest
{
public:
    EnvelopeTests() : UnitTest("Envelope tests") {}
    
    void runTest() override
    {
        double seconds = 1.0f;
        double level = 0.8f;
        double sampleRate = 44100.f;

        Envelope myEnvelope;
        beginTest("Envelope");
        
        myEnvelope.setSampleRate(sampleRate);
        expect(myEnvelope.getSampleRate() == sampleRate);
        
        myEnvelope.setAttackSeconds(seconds);
        myEnvelope.setDecaySeconds(seconds);
        myEnvelope.setSustainLevel(level);
        myEnvelope.setReleaseSeconds(seconds);
        
        myEnvelope.tick();
        
        expect(myEnvelope.getLevel() == level);
    }
};

static EnvelopeTests test;

#endif