/*
  ==============================================================================

    Oscillator.cpp
    Created: 19 Dec 2015 6:42:08pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "Oscillator.h"

void Oscillator::setSampleRate(double newSampleRate)
{
    sampleRate = newSampleRate;
    freqTL = WAVE_TABLE_LENGTH / sampleRate;
}

double Oscillator::getSampleRate()
{
    return sampleRate;
}

void Oscillator::setFrequency(double newFrequency)
{
    frequency = newFrequency;
    increment = freqTL * frequency;
}

double Oscillator::getFrequency()
{
    return frequency;
}

void Oscillator::tick()
{
    if ((index += increment) >= WAVE_TABLE_LENGTH)
        index -= WAVE_TABLE_LENGTH;
}

double Oscillator::getSample()
{
    return sineWaveTable[index];
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
        
        double sampleRate = 44100.f;
        double frequency = 440.f;
        
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