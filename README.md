# TIPO
Plug n Play Braille Keyboard for your smartphone
Shows up as a HID device, and behaves just like a Keyboard would.

## TIPO V1
USB HID only implementation using atmega32u4/Adruni Leonardo

## TIPO BLE

BLE HID implementation using ESP32

------------------------------------------------------------------

# Implementation:
How the HID Keypad is implemented for use with Braille

## Grade 1 Braille
The Braille Alphabet—Internationally Standardised
The letters a-z are common and standard for most braille country tables.

### Charecters

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| a |	    ⠁	    | 1 |
| b |	    ⠃	    | 12 |
| c |	    ⠉	    | 14 |
| d |	    ⠙	    | 145 |
| e |	    ⠑	    | 15 |
| f |	    ⠋	    | 124 |
| g |	    ⠛	    | 1245 |
| h |	    ⠓	    | 125 |
| i |	    ⠊	    | 24 |
| j |	    ⠚	    | 245 |
| k |	    ⠅	    | 13 |
| l |	    ⠇	    | 123 |
| m |	    ⠍	    | 134 |
| n |	    ⠝	    | 1345 |
| o |	    ⠕	    | 135 |
| p |	    ⠏	    | 1234 |
| q |	    ⠟	    | 12345 |
| r |	    ⠗	    |1235 |
| s |	    ⠎	    | 234 |
| t |	    ⠞	    | 2345 |
| u |	    ⠥	    | 136 |
| v |	    ⠧	    | 1236 |
| w |	    ⠺	    | 2456 | 
| x |	    ⠭	    | 1346 |
| y |	    ⠽	    | 13456 |
| z |	    ⠵	    | 1356 |

### Numbers

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| number indicator |	⠼ 	| 3456 |
| 1 | 	⠼⠁	| 3456 1 |
| 2 |	⠼⠃	| 3456 12 |
| 3 |	⠼⠉	| 3456 14 |
| 4 |	⠼⠙	| 3456 145 |
| 5 |	⠼⠑	| 3456 15 |
| 6 |	⠼⠋	| 3456 124 |
| 7 |	⠼⠛	| 3456 1245 |
| 8 |	⠼⠓	| 3456 125 |
| 9 |	⠼⠊	| 3456 24 |
| 0 |	⠼⠚	| 3456 245 |

The number indicator is placed before the first digit in a group.

Example:
```100: 	⠼⠁⠚⠚```

### Punctuation

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|,|⠂|2|
|;|	⠆|23|
|:|	⠒|25|
|.|⠲|256|
|?|	⠦|236|
|!|⠖|235|
|apostrophe '|⠄|3|
|open quote " |⠦|236|
|close quote " |⠴|356|
|(|⠐⠣|5 126|
|)|⠐⠜|5 345|
|/|⠸⠌|456 34|
|\|⠸⠡|456 34|
|dash/hyphen|⠤|36|
|long dash or hyphen|⠠⠤|6 36|

### Symbols

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|&|	⠈⠯	|4 12346|
|*|	⠐⠔	|5 35|
|@	|⠈⠁|	4 1|
|©|	⠘⠉	|45 14|
|®	|⠘⠗	|45 1235|
|™	|⠘⠞	|45 2345|
|°	|⠘⠚	|45 245|
|%	|⠨⠴	|46 356|
|+	|⠐⠖	|5 235|
|− (minus)|	⠐⠤	|5 36|
|=	|⠐⠶	|5 2356|
|×|	⠐⠦	|5 236| 
|÷	|⠐⠌	|5 34|
|grade 1 symbol indicator|	⠰	|56|
|capital letter indicator|	⠠	|6|
|capital word indicator| ⠠⠠ |6 6|
|capital paragraph indicator| ⠠⠠⠠ |6 6 6|
|capital terminator indicator| ⠠⠄ |6 3|

Capitals:
```
Use ⠠⠠ to Capitalise proceeding charecter, ⠠⠠ to Capitalise a full word, ⠠⠠⠠ to capitalise a full passage and ⠠⠄
Warning: ⠠⠺⠁⠗⠝⠊⠝⠛
WARNING: ⠠⠠⠺⠁⠗⠝⠊⠝⠛
```

##### TBD:
- Number: using # followed by number untill space, or else #<space> for actually tying pound symbol



#### References:

1. Generate Markdwn tables from https://www.tablesgenerator.com/markdown_tables
2. Braille Code Referance: https://www.pharmabraille.com/braille-codes/unified-english-braille-ueb-code/
3. Test and understand using online braille translator: https://www.branah.com/braille-translator