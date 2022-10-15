#include "event_manager.h"

#include <iostream>

void OnStart(GameEvent& evt)
{
  StartEvent& startEvt = static_cast<StartEvent&>(evt);

  std::cout << startEvt.msg << std::endl;
}

void OnStartTwo(GameEvent& evt)
{
  StartEvent& startEvt = static_cast<StartEvent&>(evt);

  std::cout << startEvt.msg << " The second!" << std::endl;
}

void OnEnd(GameEvent& evt)
{
  EndEvent& endEvt = static_cast<EndEvent&>(evt);

  std::cout << endEvt.msg << std::endl;
}

void OnSpawn(GameEvent& evt)
{
  SpawnEvent& spawnEvt = static_cast<SpawnEvent&>(evt);

  std::cout << "Player coordinates: X: " << spawnEvt.x << " Y: " << spawnEvt.y << std::endl;
}

int main()
{
  // Set up event listeners for StartEvent.
  EventManager::AddListener<StartEvent>(OnStart);
  EventManager::AddListener<StartEvent>(OnStartTwo);

  // Remove last event listener for StartEvent.
  EventManager::RemoveListener<StartEvent>();

  // Set up event listeners for EndEvent.
  EventManager::AddListener<EndEvent>(OnEnd);

  // Set up event listeners for SpawnEvent.
  EventManager::AddListener<SpawnEvent>(OnSpawn);

  // Creating a broadcasting events for demo purposes.
  // Typically events would be broadcasted from elsewhere in the code
  StartEvent startEvt = Events::s_StartEvent;
  EventManager::Broadcast(startEvt);

  EndEvent endEvt = Events::s_EndEvent;
  EventManager::Broadcast(endEvt);

  SpawnEvent spawnEvt = Events::s_SpawnEvent;
  EventManager::Broadcast(spawnEvt);

  return 0;
}