#ifndef QSYNTH_H
#define QSYNTH_H

#include <ctime>
#include <QtCore>
#include <mt32emu/mt32emu.h>

#include "MidiEventQueue.h"

enum SynthState {
	SynthState_CLOSED,
	SynthState_OPEN,
	SynthState_CLOSING
};

class QReportHandler : public MT32Emu::ReportHandler {
public:
	void showLCDMessage(const char *message);
};

class QSynth : public QObject {
	Q_OBJECT
private:
	SynthState state;

	// In samples per second.
	unsigned int sampleRate;
	bool reverbEnabled;
	MT32Emu::DACInputMode emuDACInputMode;

	QMutex *synthMutex;
	MidiEventQueue *midiEventQueue;

	volatile bool isOpen;
	// For debugging
	quint64 debugSampleIx;
	quint64 debugLastEventSampleIx;

	MT32Emu::Synth *synth;
	QReportHandler *reportHandler;

	bool openSynth();
	void setState(SynthState newState);

public:
	QSynth(QObject *parent = NULL);
	~QSynth();
	bool open();
	void close();
	bool reset();
	bool pushMIDIShortMessage(MT32Emu::Bit32u msg, SynthTimestamp timestamp);
	bool pushMIDISysex(MT32Emu::Bit8u *sysex, unsigned int sysexLen, SynthTimestamp timestamp);
	unsigned int render(MT32Emu::Bit16s *buf, unsigned int len, SynthTimestamp firstSampleTimestamp, double actualSampleRate);

	void setMasterVolume(MT32Emu::Bit8u pMasterVolume);
	void setReverbEnabled(bool pReverbEnabled);
	void setDACInputMode(MT32Emu::DACInputMode pEmuDACInputMode);

	// This being public is an implementation quirk - do not call
	int handleReport(MT32Emu::ReportType type, const void *reportData);

signals:
	void stateChanged(SynthState state);
};

#endif