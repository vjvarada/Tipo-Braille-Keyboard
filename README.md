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
|quote " |        ⠴   |356|
|dash/hyphen - |        ⠤   |36|


### Symbols

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| & |	                          ⠈⠯	    | 4 12346|
| * |	                          ⠐⠔	    | 5 35|
| # |                             ⠸⠹       | 456 1456|
| @	|                             ⠈⠁       | 4 1|
| © |	                          ⠘⠉	    | 45 14|
| ®	|                             ⠘⠗	    | 45 1235|
| ™	|                             ⠘⠞	    | 45 2345|
| °	|                             ⠘⠚	    | 45 245|
| %	|                             ⠨⠴	    | 46 356|
| +	|                             ⠐⠖	    | 5 235|
| − (minus) |                 	  ⠐⠤	    | 5 36|
| =	|                             ⠐⠶	    | 5 2356|
| ×|	                          ⠐⠦	    | 5 236| 
| ÷	|                             ⠐⠌	    | 5 34|
|(|                    ⠐⠣   |5 126|
|)|                    ⠐⠜   |5 345|
| / |                    ⠸⠌   |456 34|
| \ |                    ⠸⠡   |456 16|
|[|                    ⠨⠣   |46 126|
|]|                    ⠨⠜   |46 344|
|{|                    ⠸⠣   |456 126|
|}|                    ⠸⠜   |456 345|
| < |                    ⠈⠣   |4 34|
| > |                    ⠈⠜   |4 345|
|Underscore _|⠨⠤|6 36|


### Indicators

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| number indicator |	⠼ 	| 3456 |
| grade 1 letter indicator |       ⠰	    | 56|
| grade 1 word indicator |       ⠰⠰	    | 56 56|
| grade 1 lock indicator |       ⠰⠰⠰	    | 56 56|
| grade 1 terminator indicator |       ⠰⠄	    | 56 3|
| capital letter indicator |      ⠠	        | 6|
| capital word indicator |        ⠠⠠       | 6 6|
| capital lock indicator |        ⠠⠠⠠       | 6 6 6|
| capital terminator indicator |  ⠠⠄       | 6 3|

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
| and |	    ⠯	    | 14 |
| for |	    ⠙	    | 145 |
| of |	    ⠑	    | 15 |
| the |	    ⠋	    | 124 |
| with |    ⠛	    | 1245 |

### Strong Wordsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| child |	    ⠡	    | 14 |
| shall |	    ⠩	    | 145 |
| this |	    ⠑	    | 15 |
| which |	    ⠋	    | 124 |
| out |	        ⠛	    | 1245 |
| still |	    ⠛	    | 1245 |


### Strong Groupsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| ch |	    ⠁	    | 1 |
| sh |	    ⠃	    | 12 |
| th |    ⠓	    | 125 |
| wh |	    ⠊	    | 24 |
| ou |	    ⠚	    | 245 |
| st |	    ⠅	    | 13 |
| gh |	    ⠇	    | 123 |
| ed |	    ⠍	    | 134 |
| er |	    ⠝	    | 1345 |
| ow |	    ⠕	    | 135 |
| ar |	    ⠏	    | 1234 |
| ing |	    ⠟	    | 12345 |


### Lower Groupsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| ea |    ⠗	    |1235 |
| bb |    ⠎	    | 234 |
| cc |	    ⠞	    | 2345 |
| ff |	    ⠥	    | 136 |
| gg |    ⠧	    | 1236 |
| be |	    ⠺	    | 2456 | 
| con |	    ⠭	    | 1346 |
| dis |	    ⠽	    | 13456 |
| en |	    ⠵	    | 1356 |
| in |	    ⠽	    | 13456 |


### Lower Wordsigns

| CHARACTER   |      BRAILLE      |  BRAILLE DOT/BUTTON # |
|----------|:-------------:|------:|
| be |      ⠉	    | 14 |
| enough |  ⠙	    | 145 |
| were |    ⠑	    | 15 |
| his |	    ⠋	    | 124 |
| in |	    ⠛	    | 1245 |
| was |	    ⠛	    | 1245 |


##### TBD:
- Number: using # followed by number until space, or else #<space> for actually tying pound symbol
- Initial Letter Contractions
- Final Letter Contractions
- Shortform words
- Navigation



#### References:

1. Generate Markdwn tables from https://www.tablesgenerator.com/markdown_tables
2. Braille Code Referance: https://www.pharmabraille.com/braille-codes/unified-english-braille-ueb-code/
3. Test and understand using online braille translator: https://www.branah.com/braille-translator
4. Wikipedia entry https://en.wikipedia.org/wiki/English_Braille
5. http://www.dotlessbraille.org/brailleindicators.htm#markup
6. Android & TalkBack Mobile Accessibility Cheat Sheet https://pauljadam.com/demos/talkbackcheatsheet.html
7. Keyboard Shortcuts https://www.cnet.com/culture/keyboard-shortcuts-for-android-phones/
8. Talkback Shortcuts https://dequeuniversity.com/screenreaders/talkback-shortcuts
