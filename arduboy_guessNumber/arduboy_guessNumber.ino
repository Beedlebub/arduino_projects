#include <Arduboy2.h>
Arduboy arduboy;

int playerwin;
int attempts;
int guessednumber;
int randomnumber;

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.initRandomSeed();
  playerwin = 0;
  attempts = 0;
  guessednumber = 0;
  randomnumber = 0;
}

void loop() {
  arduboy.clear();
  if (playerwin == 0) {
    //Ask the player for a number and play the game
  }
  else {
    //Tell the player that they won!
  }
  arduboy.display();
}
