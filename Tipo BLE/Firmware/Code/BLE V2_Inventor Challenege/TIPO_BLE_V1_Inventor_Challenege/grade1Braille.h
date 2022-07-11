byte grade1CharMap[] = {
  B100000, 'a',
  B110000, 'b',
  B100100, 'c',
  B100110, 'd',
  B100010, 'e',
  B110100, 'f',
  B110110, 'g',
  B110010, 'h',
  B010100, 'i',
  B010110, 'j',
  B101000, 'k',
  B111000, 'l',
  B101100, 'm',
  B101110, 'n',
  B101010, 'o',
  B111100, 'p',
  B111110, 'q',
  B111010, 'r',
  B011100, 's',
  B011110, 't',
  B101001, 'u',
  B111001, 'v',
  B010111, 'w',
  B101101, 'x',
  B101111, 'y',
  B101011, 'z',
  B010000, ',',
  B011000, ';',
  B010010, ':',
  B010011, '.',
  B011001, '?',
  B011010, '!',
  B001000, char(39),//apostrophe '
  B001011, '"',
  B001001, '-',
};

byte grade1NumMap[] = {
  B100000, '1',
  B110000, '2',
  B100100, '3',
  B100110, '4',
  B100010, '5',
  B110100, '6',
  B110110, '7',
  B110010, '8',
  B010100, '9',
  B010110, '0',
  B010011, '.',
  B001100, '/',
  B010000, ',',
};

byte grade1CapCharMap[] = {
  B100000, 'A',
  B110000, 'B',
  B100100, 'C',
  B100110, 'D',
  B100010, 'E',
  B110100, 'F',
  B110110, 'G',
  B110010, 'H',
  B010100, 'I',
  B010110, 'J',
  B101000, 'K',
  B111000, 'L',
  B101100, 'M',
  B101110, 'N',
  B101010, 'O',
  B111100, 'P',
  B111110, 'Q',
  B111010, 'R',
  B011100, 'S',
  B011110, 'T',
  B101001, 'U',
  B111001, 'V',
  B010111, 'W',
  B101101, 'X',
  B101111, 'Y',
  B101011, 'Z',
  B010000, ',',
  B011000, ';',
  B010010, ':',
  B010011, '.',
  B011001, '?',
  B011010, '!',
  B001000, char(39),//apostrophe '
  B001011, '"',
  B001001, '-',
};

#define INDICATOR_NUMBER B001111
#define INDICATOR_GRADE_1 B000011
#define INDICATOR_CAPITAL B000001
#define INDICATOR_TERMINATOR B001000



#define BACKSPACE 0b100000000
#define SPACE     0b010000000
#define CONTROL   0b001000000
#define SHIFT     0b000100000
//#define ALT       0b000000000
#define UP        0b000000100
#define DOWN      0b000000001
#define LEFT      0b000001000
#define RIGHT     0b000000010
#define CENTER    0b000010000 
        
