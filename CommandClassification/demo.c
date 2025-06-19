#include <stdint.h>
#include <stdio.h>

#define SET_GLOBAL_ENABLE 0x40
#define SET_PORT_ENABLE 0x41
#define GET_GLOBAL_STATUS 0x01
#define GET_PORT_STATUS 0x02

typedef enum { CMD_TYPE_UNKNOWN = 0, CMD_TYPE_GET, CMD_TYPE_SET } CmdType;

typedef enum { CMD_LEVEL_UNKNOWN = 0, CMD_GLOBAL, CMD_PORT } CmdLevel;

typedef struct {
  uint8_t keyId;
  CmdType type;
  CmdLevel level;
  const char *name;
} CommandInfo;

CommandInfo commandTable[] = {
    {SET_GLOBAL_ENABLE, CMD_TYPE_SET, CMD_GLOBAL, "SET_GLOBAL_ENABLE"},
    {SET_PORT_ENABLE, CMD_TYPE_SET, CMD_PORT, "SET_PORT_ENABLE"},
    {GET_GLOBAL_STATUS, CMD_TYPE_GET, CMD_GLOBAL, "GET_GLOBAL_STATUS"},
    {GET_PORT_STATUS, CMD_TYPE_GET, CMD_PORT, "GET_PORT_STATUS"},
};

#define CMD_TABLE_SIZE (sizeof(commandTable) / sizeof(CommandInfo))

CmdType findCmdType(uint8_t keyId, const char **name) {
  for (int i = 0; i < CMD_TABLE_SIZE; ++i) {
    if (commandTable[i].keyId == keyId) {
      if (name) *name = commandTable[i].name;
      return commandTable[i].type;
    }
  }
  if (name) *name = "UNKNOWN_COMMAND";
  return CMD_TYPE_UNKNOWN;
}

CmdLevel findCmdLevel(uint8_t keyId, const char **name) {
  for (int i = 0; i < CMD_TABLE_SIZE; ++i) {
    if (commandTable[i].keyId == keyId) {
      if (name) *name = commandTable[i].name;
      return commandTable[i].level;
    }
  }
  if (name) *name = "UNKNOWN_COMMAND";
  return CMD_LEVEL_UNKNOWN;
}

const char *cmdTypeToStr(CmdType type) {
  switch (type) {
    case CMD_TYPE_GET:
      return "GET";
    case CMD_TYPE_SET:
      return "SET";
    default:
      return "UNKNOWN";
  }
}

const char *cmdLevelToStr(CmdLevel level) {
  switch (level) {
    case CMD_GLOBAL:
      return "GLOBAL";
    case CMD_PORT:
      return "PORT";
    default:
      return "UNKNOWN";
  }
}

int main() {
  uint8_t keyId = SET_PORT_ENABLE;
  const char *cmdName;

  switch (keyId) {
    default:
      break;
  }
  CmdType type = findCmdType(keyId, &cmdName);
  CmdLevel level = findCmdLevel(keyId, &cmdName);
  printf("KeyID %2x is %s %s command: %s\n", keyId, cmdTypeToStr(type),
         cmdLevelToStr(level), cmdName);

  return 0;
}
