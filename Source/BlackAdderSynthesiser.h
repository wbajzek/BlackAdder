/*
  ==============================================================================

    BlackAdderSynthesiser.h
    Created: 27 Dec 2015 12:02:46pm
    Author:  William Bajzek

  ==============================================================================
*/

#ifndef BLACKADDERSYNTHESISER_H_INCLUDED
#define BLACKADDERSYNTHESISER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class BlackAdderSynthesiser : public Synthesiser
{
public:
    BlackAdderSynthesiser();
    ~BlackAdderSynthesiser();
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BlackAdderSynthesiser)
};



#endif  // BLACKADDERSYNTHESISER_H_INCLUDED
