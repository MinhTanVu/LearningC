#include <stdint.h>
#include <stdio.h>

#define SET_GLOBAL_ENABLE 0x40
#define SET_PORT_ENABLE 0x41
#define GET_GLOBAL_STATUS 0x01
#define GET_PORT_STATUS 0x02

typedef enum { CMD_TYPE_UNKNOWN = 0, CMD_TYPE_GET, CMD_TYPE_SET } CmdType;

typedef struct {
  uint8_t keyId;
  CmdType type;
  const char *name;
} CommandInfo;

CommandInfo commandTable[] = {
    {SET_GLOBAL_ENABLE, CMD_TYPE_SET, "SET_GLOBAL_ENABLE"},
    {SET_PORT_ENABLE, CMD_TYPE_SET, "SET_PORT_ENABLE"},
    {GET_GLOBAL_STATUS, CMD_TYPE_GET, "GET_GLOBAL_STATUS"},
    {GET_PORT_STATUS, CMD_TYPE_GET, "GET_PORT_STATUS"},
    // Thêm các command khác tại đây
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

int main() {
  uint8_t keyId = SET_PORT_ENABLE;
  const char *cmdName;

  CmdType type = findCmdType(keyId, &cmdName);
  printf("KeyID %x is %s command: %s\n", keyId, cmdTypeToStr(type), cmdName);

  return 0;
}
