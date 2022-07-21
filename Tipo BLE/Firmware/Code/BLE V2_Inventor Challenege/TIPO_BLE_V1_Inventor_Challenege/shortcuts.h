
void appList_selectAll() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('a');
  bleKeyboard.releaseAll();
}

void back() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_BACKSPACE);
  bleKeyboard.releaseAll();
}
void cut() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('x');
  bleKeyboard.releaseAll();
}
void copy() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('c');
  bleKeyboard.releaseAll();
}
void paste() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('v');
  bleKeyboard.releaseAll();
}

void home() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('h');
  bleKeyboard.releaseAll();
}

void recentApps() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('r');
  bleKeyboard.releaseAll();
}

void notifications() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('n');
  bleKeyboard.releaseAll();
}

void searchScreen() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('/');
  bleKeyboard.releaseAll();
}

void pauseResumeTalkBack() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('z');
  bleKeyboard.releaseAll();
}

void talkBackMenu() { // sus
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(' ');
  bleKeyboard.releaseAll();
}

void actionList() {
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(' ');
  bleKeyboard.releaseAll();
}

void assistant() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.releaseAll();
}

void contacts() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('c');
  bleKeyboard.releaseAll();
}

void email() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('e');
  bleKeyboard.releaseAll();
}

void messages() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('s');
  bleKeyboard.releaseAll();
}

void maps() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('m');
  bleKeyboard.releaseAll();
}

void music() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('p');
  bleKeyboard.releaseAll();
}

void youTube() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('y');
  bleKeyboard.releaseAll();
}

void calender() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('l');
  bleKeyboard.releaseAll();
}

