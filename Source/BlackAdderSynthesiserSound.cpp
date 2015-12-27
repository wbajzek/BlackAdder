/*
  ==============================================================================

    BlackAdderSynthesiserSound.cpp
    Created: 27 Dec 2015 1:24:08pm
    Author:  William Bajzek

  ==============================================================================
*/

#include "BlackAdderSynthesiserSound.h"

BlackAdderSynthesiserSound::BlackAdderSynthesiserSound()
{
}

BlackAdderSynthesiserSound::~BlackAdderSynthesiserSound()
{
}

bool BlackAdderSynthesiserSound::appliesToChannel(int channel)
{
    return true;
}

bool BlackAdderSynthesiserSound::appliesToNote(int channel)
{
    return true;
}
