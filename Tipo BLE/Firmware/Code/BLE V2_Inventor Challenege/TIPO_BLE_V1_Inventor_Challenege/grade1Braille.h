

byte grade1CharMap[] = {
  0b100000, 'a',
  0b110000, 'b',
  0b100100, 'c',
  0b100110, 'd',
  0b100010, 'e',
  0b110100, 'f',
  0b110110, 'g',
  0b110010, 'h',
  0b010100, 'i',
  0b010110, 'j',
  0b101000, 'k',
  0b111000, 'l',
  0b101100, 'm',
  0b101110, 'n',
  0b101010, 'o',
  0b111100, 'p',
  0b111110, 'q',
  0b111010, 'r',
  0b011100, 's',
  0b011110, 't',
  0b101001, 'u',
  0b111001, 'v',
  0b010111, 'w',
  0b101101, 'x',
  0b101111, 'y',
  0b101011, 'z',
};

byte grade1PunctuationMap[] = {
  0b010000, ',',
  0b011000, ';',
  0b010010, ':',
  0b010011, '.',
  0b011001, '?',
  0b011010, '!',
  0b001000, char(39),//apostrophe '
  0b001011, '"',
  0b001001, '-',
};


byte numMap[] = {
  0b100000, '1',
  0b110000, '2',
  0b100100, '3',
  0b100110, '4',
  0b100010, '5',
  0b110100, '6',
  0b110110, '7',
  0b110010, '8',
  0b010100, '9',
  0b010110, '0',
  0b010011, '.',
  0b001100, '/',
  0b010000, ',',
};


byte symbolMap[] = {
  0b000100, 0b111101, '&',
  0b000010, 0b001010, '*',
  0b000111, 0b100111, '#',
  0b000100, 0b100000, '@',
  0b000101, 0b001011, '%',
  0b000010, 0b011010, '+',
  0b000010, 0b001001, '-',
  0b000010, 0b011011, '=',
  0b000100, 0b001010, '~',
  0b000110, 0b100001, '`',
  0b000100, 0b010001, '^',
  0b000101, 0b001001, '_',
  0b000111, 0b110011, '|',
  0b000111, 0b001100, '/',
  0b000111, 0b100001, char(92), // Backslash
  0b000010, 0b110001, '(',
  0b000010, 0b001110, ')',
  0b000101, 0b110001, '[',
  0b000101, 0b001110, ']',
  0b000111, 0b110001, '{',
  0b000111, 0b001110, '}',
  0b000100, 0b110001, '<',
  0b000100, 0b001110, '>',
  0b000100, 0b011100, '$',
  0b000001, 0b011011, '"',
};


#define INDICATOR_NUMBER 0b001111
#define INDICATOR_GRADE_1 0b000011
#define INDICATOR_CAPITAL 0b000001
#define INDICATOR_TERMINATOR 0b001000



#define BACKSPACE 0b100000000
#define SPACE     0b1000000000
#define CONTROL   0b100000
#define SHIFT     0b1000000
#define ALT       0b10000000
#define UP        0b10
#define DOWN      0b100
#define LEFT      0b10000
#define RIGHT     0b1000
#define CENTER    0b1
