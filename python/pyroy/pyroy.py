import wave

import pyaudio

CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 2
RATE = 4410
RECORD_SECONDS = 5
WAVE_OUTPUT_FILENAME = "output.wav"

if __name__ == "__main__":
    p = pyaudio.PyAudio()

    stream = p.open(format=FORMAT,
                    channels=CHANNELS,
                    rate=RATE,
                    input=True,
                    frames_per_buffer=CHUNK)

    print("* first recording")

    first_frames = []

    for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
        data = stream.read(CHUNK)
        first_frames.append(data)

    print("* done first recording")

    print("* second recording")

    second_frames = []

    for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
        data = stream.read(CHUNK)
        second_frames.append(data)

    print("* done second recording")

    stream.stop_stream()
    stream.close()
    p.terminate()

    print(len(first_frames))
    print(len(second_frames))

    frames = first_frames[:]

    for x in second_frames:
        frames.append(x)

    wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
    wf.setnchannels(CHANNELS)
    wf.setsampwidth(p.get_sample_size(FORMAT))
    wf.setframerate(RATE)
    wf.writeframes(b''.join(frames))
    wf.close()
