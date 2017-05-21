#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "pilight.h"
#include "dso.h"
#include "common.h"
#include "protocol.h"
#include "westinghouseFan.h"
 
#if !defined(MODULE) && !defined(_WIN32)
__attribute__((weak))
#endif
void dummyInit(void) {
    protocol_register(&westinghouseFan);
    protocol_set_id(westinghouseFan, "westinghouseFan");
    protocol_device_add(westinghouseFan, "westinghouseFan", "Westinghouse Fan protocol");
    dummy->devtype = RAW;
}
 
#if defined(MODULE) && !defined(_WIN32)
void compatibility(struct module_t *module) {
    module->name = "westinghouseFan";
    module->version = "0.1";
    module->reqversion = "5.0";
    module->reqcommit = NULL;
}
 
void init(void) {
    dummyInit();
}
#endif
