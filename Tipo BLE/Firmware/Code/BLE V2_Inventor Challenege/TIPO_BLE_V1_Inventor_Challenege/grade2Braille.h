char *alphabeticWordsignsMap[] = {
  "b", "but",
  "c", "can",
  "d", "do",
  "e", "every",
  "f", "from",
  "g", "go",
  "h", "have",
  "j", "just",
  "k", "knowledge",
  "l", "like",
  "m", "more",
  "n", "not",
  "p", "people",
  "q", "quite",
  "r", "rather",
  "s", "so",
  "t", "that",
  "u", "us",
  "v", "very",
  "w", "will",
  "x", "it",
  "y", "you",
  "z", "as",
};

char *shortformWordsMap[] = {
  "ab", "about",
  "abv", "above",
  "ac", "according",
  "acr", "across",
  "af", "after",
  "afn", "afternoon",
  "afw", "afterward",
  "ag", "again",
  "agst", "against",
  "alm", "almost",
  "alr", "already",
  "al", "also",
  "alth", "although",
  "alt", "altogether",
  "alw", "always",
  "bec", "because",
  "bef", "before",
  "beh", "behind",
  "bel", "below",
  "ben", "beneath",
  "bes", "beside",
  "bet", "between",
  "bey", "beyond",
  "bl", "blind",
  "brl", "braille",
  "chn", "children",
  "concv", "conceive",
  "concvg", "conceiving",
  "cd", "could",
  "dcv", "deceive",
  "dcvg", "deceiving",
  "dcl", "declare",
  "dclg", "declaring",
  "ei", "either",
  "fst", "first",
  "fr", "friend",
  "gd", "good",
  "grt", "great",
  "herf", "herself",
  "hm", "him",
  "hmf", "himself",
  "imm", "immediate",
  "xs", "its",
  "xf", "itself",
  "lr", "letter",
  "ll", "little",
  "mch", "much",
  "mst", "must",
  "myf", "myself",
  "nec", "necessary",
  "nei", "neither",
  "onef", "oneself",
  "ourvs", "ourselves",
  "pd", "paid",
  "percv", "perceive",
  "percvg", "perceiving",
  "perh", "perhaps",
  "qk", "quick",
  "rcv", "receive",
  "rcvg", "receiving",
  "rjc", "rejoice",
  "rjcg", "rejoicing",
  "sd", "said",
  "shd", "should",
  "sch", "such",
  "themvs", "themselves",
  "thyf", "thyself",
  "td", "today",
  "tgr", "together",
  "tm", "tomorrow",
  "tn", "tonight",
  "wd", "would",
  "yr", "your",
  "yrf", "yourself",
  "yrvs", "yourselves",
};

char *strongContractionsMap[] = {
  "111101", "and",
  "111111", "for",
  "111011", "of",
  "011101", "the",
  "011111", "with",
};

char *initialLetterContractionsMap[] = {
  "000010", "100110", "day",
  "000010", "100010", "ever",
  "000010", "110100", "father",
  "000010", "110010", "here",
  "000010", "101000", "know",
  "000010", "111000", "lord",
  "000010", "101100", "mother",
  "000010", "101110", "name",
  "000010", "101010", "one",
  "000010", "111100", "part",
  "000010", "111110", "question",
  "000010", "111010", "right",
  "000010", "011100", "some",
  "000010", "011110", "time",
  "000010", "101001", "under",
  "000010", "010111", "work",
  "000010", "101111", "young",
  "000010", "011101", "there",
  "000010", "100001", "character",
  "000010", "100111", "through",
  "000010", "100011", "where",
  "000010", "110011", "ought",
  "000110", "101001", "upon",
  "000110", "010111", "word",
  "000110", "011101", "these",
  "000110", "100111", "those",
  "000110", "100011", "whose",
  "000111", "100100", "cannot",
  "000111", "110010", "had",
  "000111", "101100", "many",
  "000111", "011100", "spirit",
  "000111", "010111", "world",
  "000111", "011101", "their",
};

//Cannot start a word with these
char *finalLetterGroupsignsMap[] = {
  "000101", "100110", "ound",
  "000101", "100010", "ance",
  "000101", "101110", "sion",
  "000101", "011100", "less",
  "000101", "011110", "ount",
  "000011", "100010", "ence",
  "000011", "110110", "ong",
  "000011", "111000", "full",
  "000011", "101110", "tion",
  "000011", "011100", "ness",
  "000011", "011110", "ment",
  "000011", "101111", "ity",
};

char *strongWordsignsMap[] = {
  "ch", "child",
  "sh", "shall",
  "th", "this",
  "wh", "which",
  "ou", "out",
  "st", "still",
  "en", "enough", ///Lower wordsign implemented here
};

char *strongGroupsignsMap[] = {
  "100001", "ch",
  "100101", "sh",
  "100111", "th",
  "100011", "wh",
  "110011", "ou",
  "001100", "st",
  "110001", "gh",
  "110101", "ed",
  "110111", "er",
  "010101", "ow",
  "001110", "ar",
  "001101", "ing",
  "011011", "were", //Lower wordsign implemented here

};

//Lower Groupsigns ea,bb,cc,ff,gg,be,con,dis not implemented
//Lower Wordsigns be,his not implemented
//special consideration needs to be taken when "en" is needed standing alone like in en route


// char *lowerWordsignsMap[] = {
//   "011000", "be",
//   "010001", "enough",
//   "011011", "were",
//   "011001", "his",  //is also ?
//   "001010", "in",
//   "001011", "was",
// };


// char apostrophe = 39;
// //char *papostrophe = &apostrophe;

// char *lowerWordsignsMap[] = {
//   ";", "be",
//   "en", "enough",
//   "gg", "were",
//   "?", "his",  //is also ?
//   "in", "in",
//    &apostrophe, "was",
// };

char *lowerGroupsigns_joining_Map[] = {
  // "010000", "ea",
  // "011000", "bb",
  // "010010", "cc",
  // "011010", "ff",
  // "011011", "gg",
  "010001", "en",
  "001010", "in",
};
char *lowerGroupsigns_starting_Map[] = {
  // "011000", "be",
  // "010010", "con",
  // "010011", "dis",
  "010001", "en",
  "001010", "in",
};





