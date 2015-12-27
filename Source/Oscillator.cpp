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
    nyquist = sampleRate / 2.0;
    freqTL = (float) WAVE_TABLE_LENGTH / sampleRate;
}

float Oscillator::getSampleRate()
{
    return sampleRate;
}

void Oscillator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
    increment = freqTL * frequency;
}

float Oscillator::getFrequency()
{
    return frequency;
}

void Oscillator::tick()
{
    index += increment;
    index %= WAVE_TABLE_LENGTH;
}

float Oscillator::getSample()
{
    return (frequency >= nyquist) ? 0.0 : sineWaveTable[index];
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
        
        // not a very good test. 
        expect(myOscillator.getSample() == 0.f);
        myOscillator.tick();
        expect(myOscillator.getSample() != 0.f);
        
    }
};

static OscillatorTests test;

#endif