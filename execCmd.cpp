#include "execCmd.h"
#include "cmdParser.h"
#include "deivces.h"

void execCmd(Cmd *cmd) {
    switch (cmd->id) {
    case OPEN_FOOD_GATE:
        foodGate.open();
        break;
    case CLOSE_FOOD_GATE:
        foodGate.close();
        break;
    default:
        break;
    }
}