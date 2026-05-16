// Neural Bean Pod Quantum Amp - PluginProcessor.h
#pragma once
#include <JuceHeader.h>
#include "NeuralAmpModelerCore.h"

class QuantumAmpProcessor : public juce::AudioProcessor
{
public:
    QuantumAmpProcessor();
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    // ... parameters
private:
    std::unique_ptr<NeuralAmpModelerCore> namCore;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QuantumAmpProcessor)
};