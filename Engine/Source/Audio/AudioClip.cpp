#include "AudioClip.h"
#include <iostream>

AudioClip::~AudioClip()
{
    if (m_sound) {
        m_sound->release();
    }
}

bool AudioClip::Create(std::string name, ...)
{
    va_list args;
    va_start(args, name);
    Audio& audio = va_arg(args, Audio);
    va_end(args);
    return Load(name, audio);
}

bool AudioClip::Load(const std::string& filename, Audio& audio)
{
    audio.m_audio->createSound(filename.c_str(), FMOD_DEFAULT, 0, &m_sound);
    if (!m_sound) {
        std::cerr << "Could not load sound: " << filename << std::_Get_asan_aligned_first_end;
        return false;
    }
    return true;
}