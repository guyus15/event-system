#include "events.h"

GameEvent::GameEvent() { }

// Instantiating static variables
const StartEvent Events::s_StartEvent;
const EndEvent Events::s_EndEvent;
const SpawnEvent Events::s_SpawnEvent;
