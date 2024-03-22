#include "cmdParser.h"

void parseCmd(Cmd *cmd, const uint8_t *line, const uint8_t length) {
    switch (length) {
    case 1:
        if (line[0] == OPEN_FOOD_GATE) {
            cmd->id = OPEN_FOOD_GATE;
        } else if (line[0] == CLOSE_FOOD_GATE) {
            cmd->id = CLOSE_FOOD_GATE;
        }
        break;
    default:
        break;
    }
}