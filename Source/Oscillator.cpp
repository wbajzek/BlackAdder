/*
  ==============================================================================

    Oscillator.cpp
    Created: 19 Dec 2015 6:42:08pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "Oscillator.h"

void Oscillator::setSampleRate(float newSampleRate)
{
    sampleRate = newSampleRate;
}

float Oscillator::getSampleRate()
{
    return sampleRate;
}

void Oscillator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
}

float Oscillator::getFrequency()
{
    return frequency;
}

#if BLACKADDER_UNIT_TESTS
class OscillatorTests : public UnitTest
{
public:
    OscillatorTests() : UnitTest("Oscillator tests") {}
    
    void runTest() override
    {
        Oscillator myOscillator;
        beginTest("Oscillator");
        
        float sampleRate = 44100.f;
        float frequency = 440.f;
        
        myOscillator.setSampleRate(sampleRate);
        expect(myOscillator.getSampleRate() == sampleRate);

        myOscillator.setFrequency(frequency);
        expect(myOscillator.getFrequency() == frequency);
        
    }
};

static OscillatorTests test;

#endif