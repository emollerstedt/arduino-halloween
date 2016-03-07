#include <WavePlay.h>

WavePlay::WavePlay()
{
}

void WavePlay::init()
{
    //  if (!_card.init(true)) { //play with 4 MHz spi if 8MHz isn't working for you
  if (!_card.init()) {         //play with 8 MHz spi (default faster!)  
    // error("Card init. failed!");  // Something went wrong, lets print out why
  }
  
  // enable optimize read - some cards may timeout. Disable if you're having problems
  _card.partialBlockRead(true);
  
  // Now we will look for a FAT partition!
  uint8_t part;
  for (part = 0; part < 5; part++) {   // we have up to 5 slots to look in
    if (_vol.init(_card, part)) 
      break;                           // we found one, lets bail
  }
  if (part == 5) {                     // if we ended up not finding one  :(
    // error("No valid FAT partition!");  // Something went wrong, lets print out why
  }
  
  // Lets tell the user about what we found
  putstring("Using partition ");
  Serial.print(part, DEC);
  putstring(", type is FAT");
  Serial.println(_vol.fatType(), DEC);     // FAT16 or FAT32?
  
  // Try to open the root directory
  if (!_root.openRoot(_vol)) {
    // error("Can't open root dir!");      // Something went wrong,
  }
  
  // Whew! We got past the tough parts.
  putstring_nl("Files found (* = fragmented):");

  // Print out all of the files in all the directories.
  _root.ls(LS_R | LS_FLAG_FRAGMENTED);
}

void WavePlay::play(char *name)
{
  if (_wave.isplaying) {// already playing something, so stop it!
    _wave.stop(); // stop it
  }
  // look in the root directory and open the file
  if (!_f.open(_root, name)) {
    putstring("Couldn't open file "); Serial.print(name); return;
  }
  // OK read the file and turn it into a wave object
  if (!_wave.create(_f)) {
    putstring_nl("Not a valid WAV"); return;
  }

  // ok time to play! start playback
  _wave.play();
  
}