#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
#include <QDesktopServices>

class AudioController : public QObject
{
Q_OBJECT
Q_ENUMS(Sounds)

public:
    explicit AudioController(QObject *parent = 0);
    ~AudioController();
    enum Sounds
    {
        SHOOT1,
        SHOOT2,
        SHOOT3,
        RELEASE,
        KRAKENWARN,
        KRAKENDESTROY,
        DIE
    };

signals:

public slots:

    void playSound(AudioController::Sounds, double dist);
    void printState(Phonon::State, Phonon::State);


private:

    QVector<Phonon::MediaObject *>  mediaObjects;
    QVector<Phonon::AudioOutput *>  audioOutputs;
    QMap<Sounds, QString>           soundFiles;
    int                             current, audioOutCount;
    Phonon::MediaObject             *media;

    int getNextAvailable();
    void createFilePaths();
    void writeFile(QString message);


};

#endif // AUDIOCONTROLLER_H
