/*
  ==============================================================================

    BlackAdderSynthesiserSound.h
    Created: 27 Dec 2015 1:24:08pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef BLACKADDERSYNTHESISERSOUND_H_INCLUDED
#define BLACKADDERSYNTHESISERSOUND_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Synthesizer.h"

class BlackAdderSynthesiserSound : public SynthesiserSound
{
public:
    BlackAdderSynthesiserSound();
    ~BlackAdderSynthesiserSound();
    
    bool appliesToNote(const int /*midiNoteNumber*/);
    bool appliesToChannel(const int /*midiChannel*/);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BlackAdderSynthesiserSound);
};




#endif  // BLACKADDERSYNTHESISERSOUND_H_INCLUDED
