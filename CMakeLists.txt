# Neural Bean Pod - Quantum Amp

cmake_minimum_required(VERSION 3.22)
project(NeuralBeanPod LANGUAGES CXX)

# Fetch JUCE
include(FetchContent)
FetchContent_Declare(
  JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 8.0.0
)
FetchContent_MakeAvailable(JUCE)

# Add NAM core (you'll need to add NeuralAmpModeler as submodule or include manually)
# For simplicity, we'll stub it first

juce_add_plugin(NeuralBeanPod
    COMPANY_NAME "MACAVELLESWAG"
    PLUGIN_MANUFACTURER_CODE "MBPG"
    PLUGIN_CODE "NBQA"
    FORMATS VST3 AU Standalone
    PRODUCT_NAME "Neural Bean Pod - Quantum Amp"
)

# Source files
target_sources(NeuralBeanPod PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_compile_definitions(NeuralBeanPod PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)

juce_generate_juce_header(NeuralBeanPod)

target_link_libraries(NeuralBeanPod PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
)

# TODO: Add NAM integration
message(STATUS "Neural Bean Pod project ready - add NAM core next!")