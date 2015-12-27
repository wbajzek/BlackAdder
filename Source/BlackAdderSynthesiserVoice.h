/*
  ==============================================================================

    BlackAdderSynthesiserVoice.h
    Created: 27 Dec 2015 12:13:13pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef BLACKADDERSYNTHESISERVOICE_H_INCLUDED
#define BLACKADDERSYNTHESISERVOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Synthesizer.h"

class BlackAdderSynthesiserVoice : public SynthesiserVoice
{
public:
    BlackAdderSynthesiserVoice();
    ~BlackAdderSynthesiserVoice();
    
    bool canPlaySound (SynthesiserSound* sound);
    void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int currentPitchWheelPosition);
    void stopNote (float velocity, const bool allowTailOff);
    void pitchWheelMoved (const int newValue);
    void controllerMoved (const int /*controllerNumber*/, const int /*newValue*/);
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
    void aftertouchChanged (int newAftertouchValue);
    void setCurrentPlaybackSampleRate (double newRate);
    bool isVoiceActive () const;
    
private:
    
    double currentSampleRate = 0.f;
    Oscillator oscillators[MAX_PARTIALS];
    Envelope envelopes[MAX_PARTIALS];
    float levels[MAX_PARTIALS];
    bool isActive = false;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BlackAdderSynthesiserVoice)
};




#endif  // BLACKADDERSYNTHESISERVOICE_H_INCLUDED
