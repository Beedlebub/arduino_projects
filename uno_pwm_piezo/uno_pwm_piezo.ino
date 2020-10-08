#define PIEZO_PIN  5      // Pin connected to the piezo buzzer.

// Define list of tone frequencies to play.
int toneFreq[] = { 262,   // C4
                   294,   // D4
                   330,   // E4
                   349,   // F4
                   392,   // G4
                   440,   // A4
                   494 }; // B4
int toneCount = sizeof(toneFreq)/sizeof(int);

void setup() {
  // No setup necessary!
}

void loop() {
  // Loop up through all the tones from start to finish.
  for (int i=0; i < toneCount; ++i) {
    tone(PIEZO_PIN, toneFreq[i]);
    delay(500);  // Pause for half a second.
  }
  // Loop down through all the tones from finish to start again.
  for (int i=toneCount-1; i >= 0; --i) {
    tone(PIEZO_PIN, toneFreq[i]);
    delay(500);
  }
  // Remember you can stop tone playback with the noTone function:
  // noTone(PIEZEO_PIN);
}
