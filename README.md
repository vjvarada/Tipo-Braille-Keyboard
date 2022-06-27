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

##### TBD:
- Number: using # followed by number untill space, or else #<space> for actually tying pound symbol



#### References:

1. Generate Markdwn tables from https://www.tablesgenerator.com/markdown_tables