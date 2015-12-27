/*
  ==============================================================================

    BlackAdderSynthesiserVoice.cpp
    Created: 27 Dec 2015 12:13:13pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "BlackAdderSynthesiserVoice.h"

BlackAdderSynthesiserVoice::BlackAdderSynthesiserVoice()
{
    for (int i = 0; i < MAX_PARTIALS; ++i)
        levels[i] = ((float)MAX_PARTIALS - i) / (float)MAX_PARTIALS;
}

BlackAdderSynthesiserVoice::~BlackAdderSynthesiserVoice()
{
    
}

bool BlackAdderSynthesiserVoice::canPlaySound (SynthesiserSound* sound)
{
    return true;
}

void BlackAdderSynthesiserVoice::startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int currentPitchWheelPosition)
{
    isActive = true;
    float baseFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    for (int i = 0; i < MAX_PARTIALS; ++i)
    {
        envelopes[i].trigger();
        oscillators[i].setFrequency(baseFrequency * (i + 1));
    }
}

void BlackAdderSynthesiserVoice::stopNote (float velocity, const bool allowTailOff)
{
    isActive = false;

    if (envelopes[0].getCurrentState() != DEAD_STATE)
        for (int i = 0; i < MAX_PARTIALS; ++i)
            envelopes[i].triggerRelease();
}

void BlackAdderSynthesiserVoice::pitchWheelMoved (const int newValue)
{
    
}

void BlackAdderSynthesiserVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
{
    
}

void BlackAdderSynthesiserVoice::renderNextBlock (AudioSampleBuffer& buffer, int startSample, int numSamples)
{
    float *output = buffer.getWritePointer(0);
    for (int sample = startSample; sample < buffer.getNumSamples(); ++sample) {
        bool isDead = true;
        for (int i = 0; i < MAX_PARTIALS; ++i) {
            output[sample] += oscillators[i].getSample() * envelopes[i].getLevel() * levels[i] * (1.0 / MAX_VOICES);
            oscillators[i].tick();
            envelopes[i].tick();
            if (envelopes[i].isActive())
                isDead = false;
        }
        if (isDead)
            clearCurrentNote();
    }
   
}

void BlackAdderSynthesiserVoice::aftertouchChanged (int newAftertouchValue)
{
    
}

void BlackAdderSynthesiserVoice::setCurrentPlaybackSampleRate (double newRate)
{
    for (int i=0; i < MAX_PARTIALS; ++i)
    {
        envelopes[i].setSampleRate(newRate);
        envelopes[i].setAttackSeconds(0);
        envelopes[i].setDecaySeconds(1);
        envelopes[i].setSustainLevel(0.125f);
        envelopes[i].setReleaseSeconds(1);
        oscillators[i].setSampleRate(newRate);
    }
    currentSampleRate = newRate;
}

bool BlackAdderSynthesiserVoice::isVoiceActive() const
{
    return isActive;
}