cmake_minimum_required(VERSION 3.22)
project(NeuralBeanPod)

# JUCE setup
include(FetchContent)
FetchContent_Declare(
  juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 8.0.0
)
FetchContent_MakeAvailable(juce)

# NAM core (add as submodule or FetchContent later)

juce_add_plugin(NeuralBeanPod
    COMPANY_NAME "MACAVELLESWAG"
    PLUGIN_MANUFACTURER_CODE "MBVG"
    PLUGIN_CODE "QAMP"
    FORMATS VST3 AU Standalone
    PRODUCT_NAME "Neural Bean Pod - Quantum Amp"
)

juce_generate_juce_header(NeuralBeanPod)

target_sources(NeuralBeanPod PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_compile_definitions(NeuralBeanPod PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(NeuralBeanPod PRIVATE
    juce::juce_audio_utils
    juce::juce_gui_basics
    # NAM library here
)
