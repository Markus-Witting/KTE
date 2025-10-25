#pragma once

struct termios orig;

void SetRawMode(int state);

void HandleKey(char c);



void