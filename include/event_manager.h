#pragma once

#include "events.h"

#include <functional>
#include <unordered_map>
#include <vector>

using Listener = std::function<void(GameEvent&)>;

struct EventManager
{
  template<typename T>
  /*
  * Assigns an listener to a given event type.
  */
  static void AddListener(Listener&& listener);

  template<typename T>
  /*
  * Removes the last added event listener from the given event type.
  */
  static void RemoveListener();

  /*
  * Notifies all event listeners of the given event type that an event has
  * been triggered.
  */
  static void Broadcast(GameEvent& evt);

private:
  static std::unordered_map<EventID, std::vector<Listener>> s_EventListeners;
};

inline void EventManager::Broadcast(GameEvent& evt)
{
  for (const auto& listener : s_EventListeners[evt.GetID()])
{
    listener(evt);
  }
}

template<typename T>
void EventManager::AddListener(Listener&& listener)
{
  s_EventListeners[T{}.GetID()].push_back(listener);
}

template<typename T>
void EventManager::RemoveListener()
{
  auto iter = s_EventListeners[T{}.GetID()].end() - 1;
  s_EventListeners[T{}.GetID()].erase(iter);
}

std::unordered_map<EventID, std::vector<Listener>> EventManager::s_EventListeners;