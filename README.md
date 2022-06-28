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
| letter sign | ⠰ | 56|
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

The number indicator is placed before the first digit in a group. Space, hyphen or clears it

Example:
```100: 	⠼⠁⠚⠚```


### Punctuation

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|,|⠂|2|
|;|	⠆|23|
|:|	⠒|25|
|.(Period)|⠲|256|
|.(Decimal)|⠨|46|
|?|	⠦|236|
|!|⠖|235|
|apostrophe '|⠄|3|
|open quote " |⠦|236|
|close quote " |⠴|356|
|(|⠐⠣|5 126|
|)|⠐⠜|5 345|
|/|⠸⠌|456 34|
|\|⠸⠡|456 34|
|[|⠨⠣|456 34|
|]|⠨⠜|456 34|
|{|⠸⠣|456 34|
|}|⠸⠜|456 34|
|<|⠈⠣|456 34|
|>|⠈⠜|456 34|
|dash/hyphen|⠤|36|
|long dash or hyphen|⠠⠤|6 36|

### Symbols

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|&|	⠈⠯	|4 12346|
|*|	⠐⠔	|5 35|
|#| ⠸⠹ | 456 1456|
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
|capital terminator indicator| ⠠⠄ |6 3|
|Keypad CapsLock(Activate)| ⠠⠠ |6 6|

Capitals:
The capital(ization) sign ⠠ marks the first letter of a word as capitalized. It may occur in the middle of a word for camel case, as in the name deAngelo. It is doubled to place a word in all caps; this must be repeated for each word of an all-cap text.
```
Use ⠠⠠ to Capitalise proceeding charecter, ⠠⠠ to Capitalise a full word,
⠠⠠⠠ to capitalise a full passage and ⠠⠄ to terminate. Using space/hyphen 
etc resets to normal unless not using paragraph caps. 
Warning: ⠠⠺⠁⠗⠝⠊⠝⠛
WARNING: ⠠⠠⠺⠁⠗⠝⠊⠝⠛
```
```
Note: The letter sign (grade 1 symbol indicator) ⠰ is used to force the end of a series of numbers.
For example, ⠙⠁ ⟨da⟩ preceded by a number sign, ⠼⠙⠁, is read as 41. 
If instead 4a is intended (as in a section or apartment number), 
then the letter sign is used to force a reading of a rather than 1 for the final character: ⠼⠙⠰⠁ ⟨4a⟩.

It is also used to mark a character as standing for a letter rather than for a word. For example, ⠃ ⟨b⟩ on its own is normally read as the word but;
to indicate that it is instead the letter b, the letter sign is used: ⠰⠃ b. Plurals of letters (mind your ps and qs)
always use an apostrophe in braille, but other derivations may not, as in ⠰⠝⠹ nth [time]: ⠠⠎⠬ is Sing, ⠰⠠⠎⠬ is S-ing/Essing. The letter sign is also used to mark lower-case Roman numbers, as in ⠰⠊⠊⠊ ⟨iii⟩.
 ```

##### TBD:
- Number: using # followed by number until space, or else #<space> for actually tying pound symbol



#### References:

1. Generate Markdwn tables from https://www.tablesgenerator.com/markdown_tables
2. Braille Code Referance: https://www.pharmabraille.com/braille-codes/unified-english-braille-ueb-code/
3. Test and understand using online braille translator: https://www.branah.com/braille-translator
4. Wikipedia entry https://en.wikipedia.org/wiki/English_Braille