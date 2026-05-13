#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD (alamat tergantung chip, bisa 0x27 atau 0x3F biasanya)
Adafruit_LiquidCrystal lcd(0);  // Sesuaikan jika perlu

// Lyrics - "Anything You Want"
const char* lyrics[] = {
  // Verse 1
  "Trails of smoke",
  "trapped in a two by two",
  "Wasting the night",
  "feels right",
  "when I'm with you",
  "It's the shimmer",
  "in your eyes",
  "And the way you",
  "let down your disguise",
  // Pre-Chorus
  "I feel like I've",
  "known you for ages",
  "I feel like with you",
  "I'm going places",
  "Ahh, ahh",
  // Chorus 1
  "The same song",
  "on repeat",
  "You can call me",
  "anything you want",
  "It's fine by me",
  "Number two",
  "out of three",
  "He says that it's",
  "his favorite",
  "And I can't disagree",
  // Verse 2
  "We talk about",
  "everything",
  "The important",
  "and the mundane",
  "You know I think",
  "you know everything",
  "But the night's",
  "still young",
  "And there's still",
  "so much to gain",
  // Pre-Chorus 2
  "I feel like I've",
  "known you for ages",
  "I feel like with you",
  "I'm going places",
  "Ahh, ahh",
  // Chorus 2
  "The same song",
  "on repeat",
  "You can call me",
  "anything you want",
  "It's fine by me",
  "Number two",
  "out of three",
  "He says that it's",
  "his favorite",
  "And I can't disagree",
  // Chorus 3 (final)
  "The same song",
  "on repeat",
  "You can call me",
  "anything you want",
  "It's fine by me",
  "Number two",
  "out of three",
  "He says that it's",
  "his favorite",
  "And I can't disagree",
  // Outro
  "The same song",
  "on repeat",
  "You can call me",
  "anything you want",
  "It's fine by me",
  "Number two",
};

// Duration per line in seconds
const float timings[] = {
  // Verse 1
  1.3, // Trails of smoke
  1.5, // trapped in a two by two
  1.3, // Wasting the night
  0.8, // feels right
  1.4, // when I'm with you
  1.3, // It's the shimmer
  1.0, // in your eyes
  1.3, // And the way you
  1.5, // let down your disguise
  // Pre-Chorus
  1.3, // I feel like I've
  1.5, // known you for ages
  1.3, // I feel like with you
  1.5, // I'm going places
  1.8, // Ahh, ahh
  // Chorus 1
  1.0, // The same song
  1.0, // on repeat
  1.0, // You can call me
  1.4, // anything you want
  1.4, // It's fine by me
  0.9, // Number two
  1.0, // out of three
  1.0, // He says that it's
  1.0, // his favorite
  1.5, // And I can't disagree
  // Verse 2
  1.0, // We talk about
  1.0, // everything
  1.0, // The important
  1.3, // and the mundane
  1.0, // You know I think
  1.4, // you know everything
  1.0, // But the night's
  0.9, // still young
  1.0, // And there's still
  1.5, // so much to gain
  // Pre-Chorus 2
  1.3, // I feel like I've
  1.5, // known you for ages
  1.3, // I feel like with you
  1.5, // I'm going places
  1.8, // Ahh, ahh
  // Chorus 2
  1.0, // The same song
  1.0, // on repeat
  1.0, // You can call me
  1.4, // anything you want
  1.4, // It's fine by me
  0.9, // Number two
  1.0, // out of three
  1.0, // He says that it's
  1.0, // his favorite
  1.5, // And I can't disagree
  // Chorus 3 (final)
  1.0, // The same song
  1.0, // on repeat
  1.0, // You can call me
  1.4, // anything you want
  1.4, // It's fine by me
  0.9, // Number two
  1.0, // out of three
  1.0, // He says that it's
  1.0, // his favorite
  1.8, // And I can't disagree
  // Outro
  1.0, // The same song
  1.0, // on repeat
  1.0, // You can call me
  1.4, // anything you want
  1.4, // It's fine by me
  1.8, // Number two
};

const int numLines = sizeof(lyrics) / sizeof(lyrics[0]);

void setup() {
  lcd.begin(16, 2);    // 16 kolom, 2 baris
  lcd.setBacklight(1); // Nyalakan backlight
}

void loop() {
  for (int i = 0; i < numLines; i++) {
    String line = lyrics[i];
    int len = line.length();

    lcd.clear();

    // Jika lebih dari 16 karakter, pecah rapi jadi 2 baris
    if (len > 16) {
      int breakPoint = line.lastIndexOf(' ', 16);
      if (breakPoint == -1) breakPoint = 16;

      String first = line.substring(0, breakPoint);
      String second = line.substring(breakPoint + 1); // Hindari spasi di awal baris 2

      lcd.setCursor((16 - first.length()) / 2, 0);
      lcd.print(first);

      lcd.setCursor((16 - second.length()) / 2, 1);
      lcd.print(second);
    } else {
      lcd.setCursor((16 - len) / 2, 0);
      lcd.print(line);
    }

    delay(timings[i] * 1000);
  }

  while (true); // stop setelah selesai
}
