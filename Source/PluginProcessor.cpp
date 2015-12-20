/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BlackAdderAudioProcessor::BlackAdderAudioProcessor()
{
#if BLACKADDER_UNIT_TESTS
    UnitTestRunner runner;
    runner.runAllTests();
#endif
}

BlackAdderAudioProcessor::~BlackAdderAudioProcessor()
{
}

//==============================================================================
const String BlackAdderAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

const String BlackAdderAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String BlackAdderAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool BlackAdderAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool BlackAdderAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool BlackAdderAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BlackAdderAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BlackAdderAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double BlackAdderAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BlackAdderAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BlackAdderAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BlackAdderAudioProcessor::setCurrentProgram (int index)
{
}

const String BlackAdderAudioProcessor::getProgramName (int index)
{
    return String();
}

void BlackAdderAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void BlackAdderAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    currentSampleRate = sampleRate;
    oscillator.setSampleRate(sampleRate);
    oscillator.setFrequency(440.f);
}



void BlackAdderAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void BlackAdderAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    
    const float level = 0.125f;

    for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
        const float currentSample = oscillator.getSample();

        for (int channel = 0; channel < getNumOutputChannels(); ++channel)
        {
            float* channelData = buffer.getWritePointer (channel);
            channelData[sample] = currentSample * level;
        }
        
        oscillator.tick();
    }
}

//==============================================================================
bool BlackAdderAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BlackAdderAudioProcessor::createEditor()
{
    return new BlackAdderAudioProcessorEditor (*this);
}

//==============================================================================
void BlackAdderAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void BlackAdderAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BlackAdderAudioProcessor();
}
