/*
  Hello, World! example
  June 11, 2015
  Copyright (C) 2015 David Martinez
  All rights reserved.
  This code is the most basic barebones code for writing a program for Arduboy.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
*/

// Add Aruboy library support
#include <Arduboy2.h>

// Initialize Arudoy object
Arduboy2 arduboy;

//Initialize counter variable
int counter;

void setup() {
  // This function runs once in your game.
  // use it for anything that needs to be set only once in your game.

  // Start Arduboy and show logo
  arduboy.begin();
  // Clears screen
  arduboy.clear();
  // Assign counter an initial value of zero
  counter = 0;
}

void loop() {
  // our main game loop, this runs once every cycle/frame.
  // this is where our game logic goes.

  // Clear the screen at top of each loop
  arduboy.clear();
  //Check if the UP_BUTTON is being pressed
  if ( arduboy.pressed(UP_BUTTON) ) {
    //Increase counter by 1
    counter = counter + 1;
  }
  //Check if the DOWN_BUTTON is being pressed
  if ( arduboy.pressed(DOWN_BUTTON) ) {
    //Decrease counter
    counter = counter - 1;
  }
  //Check if counter is equal to 36
  if ( counter == 36 ) {
    arduboy.setCursor(30, 30);
    arduboy.print("Yay!");
  }
  // Set cursor locarion to top left corner of screen
  arduboy.setCursor(0, 0);
  // Print out the counter's value on the Arduboy's screen
  arduboy.print(counter);
  // Refresh the screen with whatever we printed to it
  arduboy.display();
}
