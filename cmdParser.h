#ifndef CMDPARSER_H
#define CMDPARSER_H

#include <iostream>

enum CmdId {
    OPEN_FOOD_GATE = 0,
    CLOSE_FOOD_GATE,
};

typedef struct Cmd {
    CmdId id;
    
} Cmd;

void parseCmd(Cmd *cmd, const uint8_t *line, const uint8_t length);

#endif // CMDPARSER_H