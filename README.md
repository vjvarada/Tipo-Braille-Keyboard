# TIPO
Plug n Play Braille Keyboard for your smartphone
Shows up as a HID device, and behaves just like a Keyboard would.

## TIPO V1
USB HID only implementation using atmega32u4/Adruni Leonardo

## TIPO BLE

BLE HID implementation using ESP32

------------------------------------------------------------------
# Hardware Connections

## Architecture
![Hardware Architecture](https://github.com/vjvarada/Tipo-Braille-Keyboard/blob/master/Reference/Tipo%20V2%20Hardware%20Architeture.drawio.png?raw=true)

## Button Map:

| Button | ESP32 Pin # |
| :------: | :-----------:|
| BTN1 | 25|
| BTN2 | 26|
| BTN3 | 27|
| BTN4 | 13|
| BTN5 | 15|
| BTN6 | 2 |
| BTN7 | 19|
| BTN8 | 18|
| BTN9 | 17|
| BTN10| 16|
| BTN11| 4 |
| CNT | 33|
| UP | 34 |
| DWN | 35|
| LFT | 36|
| RGT | 39|


# Implementation:
How the HID Keypad is implemented for use with Braille

## Alphabetic Shortcuts

| CHARACTER   |      Shortcut      |  Key Combo |
|----------|:-------------:|------:|
| a | Assistant | win |
| b | Back | alt + backspace |
| l | Apps List / Select All | Ctrl + a |
| c | Copy | ctrl + c |
| x | Cut | ctrl + x |
| v | Paste | ctrl + v |
| d | Maps | win + m |
| e | Email | win + e |
| h | Home | ctrl + alt + h |
| r | Recent apps | ctrl + alt + r |
| s | Music | win + p |
| m | Messages | win + s |
| n | notifications | ctrl + alt + n |
| f | Screen Search | ctrl + alt + / |
| p | Contacts | win + c |
| y | Youtube | win + y |
| t | Calender | win + l |
| z | Pause/Resume Talkback | alt + ctrl + z


## Item Navigation controls

|      Key Combo      |  Equivalent Action | Action |
|----------|:-------------:|------:|
| Alt + Left | Swipe Left | Navigate to the next item|
| Alt + Right | Swipe Right | Navigate to the previous item |
| Alt + Up | - | Navigate to the item above |
| Alt + Down | - | Navigate to the item below|
| Alt + Ctrl + Left | - | Navigate to First Item |
| Alt + Ctrl + Right | - | Navigate to Last Item |
| Alt + Ctrl + Down | -  | Navigate to Next Window |
| Alt + Ctrl + Up | - | Navigate to Previous Window |
| Alt + Enter | Tap | Select an item |
| Alt + Shift + Enter | - |Long press | 



## Reading controls

|      Key Combo      |  Equivalent Action | Action |
|----------|:-------------:|------:|
| Alt  + Shift + Right | - | Navigate to Next Character |
| Alt  + Shift + Left | - | Navigate to Previous Character |
| Alt + Ctrl + Shift + Right | - | Navigate to Next Word |
| Alt + Ctrl + Shift + Left | - | Navigate to Previous Word |

## Continuous Reading controls

|      Key Combo      |  Equivalent Action | Action |
|----------|:-------------:|------:|
| Alt + Ctrl + Enter | - | Continuous read from top |
| Alt + Ctrl + Shift + Enter | - | Continuous read from Next Item |
| Alt + Right | Swipe Right | Fast-forwards the text.|
| Alt + Left | Swipe Left | Rewinds the text. |



// Magnification Settigns
//Talkback Menu
//Select config
//Swipe up/Down
// WIdgets
// view options - alt + space

- clear BT communication
- BT pair button



## Grade 1 Braille
The Braille Alphabet—Internationally Standardised
The letters a-z are common and standard for most braille country tables.

Grade 1 braille is a letter-for-letter substitution of its printed counterpart. This is the preferred code for beginners because it allows people to get familiar with, and recognize different aspects of, the code while learning how to read braille. 

English grade 1 braille consists of the 26 standard letters of the alphabet as well as punctuation.
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

The number indicator (⠼) is placed before the first digit in a group. Space, hyphen, grade 1 indicator or clears it

Example:
```
100: 	⠼⠁⠚⠚

using Grade 1 indicator/Letter sign (⠰) to specify end of number
221b:	⠼⠃⠃⠁⠰⠃

```



### Punctuation

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|,|                     ⠂   |2|
|;|                  	⠆   |23|
|:|                    	⠒   |25|
|.(Period)|             ⠲   |256|
|?|     	            ⠦   |236|
|!|                     ⠖   |235|
|apostrophe '|          ⠄   |3|
|quote " |              ⠴   |356|
|hyphen - |             ⠤   |36|


### Symbols

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| & |	                 ⠈⠯	    | 4 12346|
| * |	                 ⠐⠔	    | 5 35|
| # |                    ⠸⠹        | 456 1456|
| @	|                    ⠈⠁        | 4 1|
| %	|                    ⠨⠴	    | 46 356|
| +	|                    ⠐⠖	    | 5 235|
| − (minus) |            ⠐⠤	    | 5 36|
| =	|                    ⠐⠶	    | 5 2356|
| ~ |                    ⠈⠔        | 4 35 |
| ` |                    ⠘⠡        | 45 16
| ^ |                    ⠈⠢        |4 26 |
| Underscore _ |         ⠨⠤        |46 36|
| Verical Line |         ⠸⠳        |456 1256| 
| / |                    ⠸⠌        |456 34|
| \ |                    ⠸⠡        |456 16|
| ( |                    ⠐⠣        |5 126|
| ) |                    ⠐⠜        |5 345|
| [ |                    ⠨⠣        |46 126|
| ] |                    ⠨⠜        |46 345|
| { |                    ⠸⠣        |456 126|
| } |                    ⠸⠜        |456 345|
| < |                    ⠈⠣        |4 126|
| > |                    ⠈⠜        |4 345|
| $ |                    ⠈⠎        |4 234 |
| " |                    ⠠⠶        |6 2346 |



### Indicators

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| number indicator |                	⠼    	| 3456 |
| grade 1 letter indicator |           ⠰	    | 56|
| grade 1 word indicator |             ⠰⠰	    | 56 56|
| grade 1 lock indicator |             ⠰⠰⠰	    | 56 56|
| grade 1 terminator indicator |       ⠰⠄	    | 56 3|
| capital letter indicator |           ⠠	    | 6|
| capital word indicator |             ⠠⠠      | 6 6|
| capital lock indicator |             ⠠⠠⠠     | 6 6 6|
| capital terminator indicator |       ⠠⠄      | 6 3|






```
The capital(ization) sign ⠠ marks the first letter of a word as capitalized. 
It may occur in the middle of a word for camel case, as in the name deAngelo. 
It is doubled to place a word in all caps; this must be repeated for each word of an all-cap text.
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
## Grade 2 Braille 

The literary braille code, grade 2, uses “contractions” that substitute shorter sequences for the full spelling of commonly-occurring letter groups. The contractions are similar to English print contractions, like “cannot” versus “can’t”, in the way that a word is shortened. For example, “the” is usually a single character in braille. 
Grade 2 braille is the most commonly used form of braille code and is found in books, public signage, and restaurant menus to name a few. It consists of the 26 standard letters of the alphabet, punctuation, and contractions.


```
letter sign  (⠰) used to mark a character as standing for a letter rather than for a word. For example,
 ⠃ ⟨b⟩ on its own is normally read as the word but; to indicate that it is instead the letter b, 
the letter sign is used: ⠰⠃ b. Plurals of letters (mind your ps and qs) always use an apostrophe in braille,
but other derivations may not, as in ⠰⠝⠹ nth [time]: ⠠⠎⠬ is Sing, ⠰⠠⠎⠬ is S-ing/Essing.[27] The letter sign 
is also used to mark lower-case Roman numbers, as in ⠰⠊⠊⠊ ⟨iii⟩.
```
### Alphabetic Wordsigns

| CHARACTER   | WORD    |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|:-------------:|------:|
| b | but |	            ⠃	    | 12 |
| c | can |	            ⠉	    | 14 |
| d | do |	            ⠙	    | 145 |
| e | every|            ⠑	    | 15 |
| f | from |            ⠋	    | 124 |
| g | go |              ⠛	    | 1245 |
| h | have |            ⠓	    | 125 |
| j | just |            ⠚	    | 245 |
| k | knowledge |	    ⠅	    | 13 |
| l | like |	        ⠇	    | 123 |
| m | more |	        ⠍	    | 134 |
| n | not |	            ⠝	    | 1345 |
| p | people |	        ⠏	    | 1234 |
| q | quite |	        ⠟	    | 12345 |
| r | rather |	        ⠗	    |1235 |
| s | so |	            ⠎	    | 234 |
| t | that |	        ⠞	    | 2345 |
| u | us |	            ⠥	    | 136 |
| v | very |	        ⠧	    | 1236 |
| w | will |	        ⠺	    | 2456 | 
| x | it |	            ⠭	    | 1346 |
| y | you |	            ⠽	    | 13456 |
| z | as |	            ⠵	    | 1356 |

### Strong Contractions (Part and Whole Word)

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| and |	    ⠯	    | 12346 |
| for |	    ⠿	    | 123456 |
| of |	    ⠷	    | 12356 |
| the |	    ⠮	    | 2346 |
| with |    ⠾	    | 23456 |

### Strong Wordsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| child |	    ⠡	    | 16 |
| shall |	    ⠩	    | 146 |
| this |	    ⠹	    | 1456 |
| which |	    ⠱	    | 156 |
| out |	        ⠳	    | 1256 |
| still |	    ⠌	    | 34 |

isStandingAlone?

### Strong Groupsigns


| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # | Note |
|----------|:-------------:|:------:|------:|
| -ch- |	    ⠡	    | 16 | Letter join on either side|
| -sh- |	    ⠩	    | 146 |Letter join on either side|
| -th- |        ⠹	    | 1456 |Letter join on either side|
| -wh- |	    ⠱	    | 156 |Letter join on either side|
| -ou- |	    ⠳	    | 1256 |Letter join on either side|
| -st- |	    ⠌	    | 34 |Letter join on either side|
|------|----------------|----| -------------------------|
| gh |	        ⠣	    | 126 |
| ed |	        ⠫	    | 1246 |
| er |	        ⠻	    | 12456 |
| ow |          ⠪	    | 246 |
| ar |  	    ⠜	    | 345 |
| -ing |	    ⠬	    | 346 |Letter join on one side only, cannot be used to start a word|


### Lower Groupsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # | Note |
|----------|:-------------:|:------:|------:|
| -ea- |      ⠂	    | 2|Letters join on both side|
| -bb- |      ⠆	    | 23 |Letters join on both side|
| -cc- |      ⠒	    | 25 |Letters join on both side|
| -ff- |	  ⠖	    | 235 |Letters join on both side|
| -gg- |      ⠶	    | 2356 |Letters join on both side|
|------|----------------|----| -------------------------|
| be- |	      ⠆	    | 23 | |
| con- |	  ⠒	    | 25 |Letters join on one side only |
| dis- |	  ⠲	    | 256 |Letters join on one side only |
| -en- |	  ⠢	    | 26 |Letter join on either side|
| in |	      ⠔	    | 35 | |


### Lower Wordsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| be |      ⠆	    | 23 |
| enough |  ⠢	    | 26 |
| were |    ⠶	    | 2356 |
| his |	    ⠦	    | 236 |
| in |	    ⠔	    | 35 |
| was |	    ⠴	    | 356 |


### Initial Letter Contractions

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|    day |  |5 145
|   ever |  |5 15
|  father | |5 124
|    here | |5 125
|    know | |5 13
|    lord | |5 123
|    mother |   |5 134
|    name | |5 1345
|    one |  |5 135
|    part | |5 1234
|    question | |5 12345
|    right |    |5 1235
|    some | |5 234
|    time | |5 2345
|    under | |5 136
|    work | |5 2456
|    young | |5 13456
|    there | |5 2346
|    character | |5 16
|    through | |5 1456
|    where | |5 156
|    ought | |5 1256
|    upon | |45 136
|    word | |45 2456
|    these | |45 2346
|    those | |45 1456
|    whose | |45 156
|    cannot | |456 14
|    had | |456 125
|    many | |456 134
|    spirit | |456 234
|    world | |456 2456
|    their | |456 2346

### final Letter Groupsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
|ound| | 46 145 |
|ance| | 46 15 |
|sion| | 46 1345 |
|less| | 46 234|
|ount| | 46 2345|
|ence| | 56 15|
|ong| | 56 1245|
|ful| | 56 123|
|tion| | 56 1345|
|ness| | 56 234|
|ment| | 56 2345|
|ity| | 56 13456|




#### References:

1. Generate Markdwn tables from https://www.tablesgenerator.com/markdown_tables
2. Braille Code Referance: https://www.pharmabraille.com/braille-codes/unified-english-braille-ueb-code/
3. Test and understand using online braille translator: https://www.branah.com/braille-translator
4. Wikipedia entry https://en.wikipedia.org/wiki/English_Braille
5. http://www.dotlessbraille.org/brailleindicators.htm#markup
6. Android & TalkBack Mobile Accessibility Cheat Sheet https://pauljadam.com/demos/talkbackcheatsheet.html
7. Keyboard Shortcuts https://www.cnet.com/culture/keyboard-shortcuts-for-android-phones/
8. Talkback Shortcuts https://dequeuniversity.com/screenreaders/talkback-shortcuts
9. Braille to Binary encoder https://www.dcode.fr/braille-alphabet