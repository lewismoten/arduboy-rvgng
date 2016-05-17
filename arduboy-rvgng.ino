#include <avr/pgmspace.h>

#include "Arduboy.h"
#include "first_words.h"
#include "middle_words.h"
#include "last_words.h"

Arduboy arduboy;
const char relatedDelimiter = '|';
String relatedWords;
bool wait;
bool discardSimilar;

// draw bottom to top, left to right
static const unsigned PROGMEM char sprite[] = {
  B00001110,
  B01111000,
  B10111100,
  B00110111,
  B00111100,
  B00110111,
  B10111100,
  B01111000,
  B00001110
};

void setup() {
  arduboy.begin();
  arduboy.initRandomSeed();
  showTitle("");
}

void loop() {
  int input = arduboy.getInput();
  discardSimilar = input == B_BUTTON;
  if(input != 0) newGame();
}

void showTitle(String title){

  arduboy.clear();
  arduboy.drawBitmap(1, 1, sprite, 9, 8, WHITE);
  arduboy.setTextWrap(true);

  arduboy.setCursor(12, 3);
  arduboy.print("The Video Game NameGenerator ported from\nhttp://videogamena.me");
  
  arduboy.setCursor(0, 40);
  arduboy.print(title);
  
  arduboy.display();
}

void newGame() {
  if(wait) return;
  wait = true;
  relatedWords = relatedDelimiter;
   
  int firstNum = random(0, 518);
  String firstWord = getWord(firstWords, firstNum);
  String middleWord;
  String lastWord;

  do {
    int middleNum = random(0, 349);
    middleWord = getWord(middleWords, middleNum);
  } while(
    middleWord == firstWord ||
    isRelated(middleWord)
  );
   
  do {
    int lastNum = random(0, 126);//412); // NOT ENOUGH FLASH MEMORY FOR THE REST!!!
    lastWord = getWord(lastWords, lastNum);
  } while(
    lastWord == firstWord ||
    lastWord == middleWord || 
    isRelated(lastWord)
  );

  showTitle(firstWord + ' ' + middleWord + ' ' + lastWord);
  wait = false;
}

String getWord(const char* const words[], int index) {
  char buffer[75];
  const char wordDelimiter = '^';
  
  strcpy_P(buffer, (char*)pgm_read_word(&(words[index])));

  String details = String(buffer);
  String currentWord = details;
  int delimiter = details.indexOf(wordDelimiter);

  if(delimiter != -1) {
    currentWord = details.substring(0, delimiter);
    addRelatedWords(details.substring(delimiter));
  }
  
  return currentWord;
}

void addRelatedWords(String words) {
  relatedWords = relatedWords + words + relatedDelimiter;
}

bool isRelated(String currentWord) {
  if(discardSimilar) return false;
  return relatedWords.indexOf(relatedDelimiter + currentWord + relatedDelimiter) != -1;
}

