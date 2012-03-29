#include "audiocontroller.h"
#include <iostream>
AudioController::AudioController(QObject *parent) :
    QObject(parent)
{
    createFilePaths();
    for(int i = 0; i < 5; i++)
    {
        mediaObjects.push_back(new Phonon::MediaObject(this));
        audioOutputs.push_back(new Phonon::AudioOutput(Phonon::GameCategory, this));
        Phonon::createPath(mediaObjects.back(), audioOutputs.back());
        mediaObjects.back()->setCurrentSource(Phonon::MediaSource("../audio/cannon.ogg"));
    }
    current = 0;
    audioOutCount = 0;
}


AudioController::~AudioController()
{
    for(int i = 0; i < mediaObjects.size(); i++)
    {
        delete mediaObjects[i];
        delete audioOutputs[i];
    }
    delete media;
}


void AudioController::createFilePaths()
{
    soundFiles[SHOOT1] = "../audio/cannon.ogg";
    soundFiles[SHOOT2] = "../audio/cannon2.ogg";
    soundFiles[SHOOT3] = "../audio/aaGun.ogg";
    soundFiles[RELEASE] = "../audio/release.ogg";
    soundFiles[KRAKENWARN] = "../audio/krakenPart.ogg";
    soundFiles[KRAKENDESTROY] = "../audio/mainKraken.ogg";
    soundFiles[DIE] = "../audio/mainExplosion.ogg";
}


void AudioController::playSound(AudioController::Sounds sound)
{
    if((media = getNextAvailable()) != NULL)
    {
        media->setCurrentSource(Phonon::MediaSource(soundFiles[sound]));
        media->play();
    }
}

void AudioController::printState(Phonon::State newState,Phonon::State oldState)
{
    std::cout << (int)oldState << "  " << newState <<  std::endl ;
}


Phonon::MediaObject* AudioController::getNextAvailable()
{
    for(int i = 0; i < mediaObjects.size(); i++)
    {
        if(mediaObjects[(i + current) % mediaObjects.size()]->state() == Phonon::StoppedState)
        {
            Phonon::MediaObject * result = mediaObjects[(i + current) % mediaObjects.size()];
            current = (current + i + 1) % mediaObjects.size();
            std::cout << current << std::endl;
            return result;
        }
    }
    audioOutCount ++;
    writeFile("No Available Audio Outputs: " + audioOutCount);
    return NULL;
}


void AudioController::writeFile(QString message)
{
    QFile logFile("soundErrorLog.txt");

    QTextStream out(&logFile);

    out << message;
    out << endl;

    logFile.close();
}

