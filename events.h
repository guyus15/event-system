#pragma once

#include <string>

typedef const char* EventID;

struct GameEvent
{
  explicit GameEvent();

  virtual EventID GetID() const = 0;
};

// Events
struct StartEvent : GameEvent
{
  StartEvent() : GameEvent{} { }

  virtual EventID GetID() const
{
    return s_ID;
  }

  std::string msg = "This is the start event!";

private:
  static constexpr EventID s_ID = "StartEvent";
};

struct EndEvent : GameEvent
{
  EndEvent() : GameEvent{} { };

  virtual EventID GetID() const
{
    return s_ID;
  }

  std::string msg = "This is the end event";

private:
  static constexpr EventID s_ID = "EndEvent";
};

struct SpawnEvent : GameEvent
{
  SpawnEvent() : GameEvent{} { };

  virtual EventID GetID() const
{
    return s_ID;
  }

  float x = 10.0f;
  float y = 5.0f;

private:
  static constexpr EventID s_ID = "SpawnEvent";
};

struct Events
{
  static const StartEvent s_StartEvent;
  static const EndEvent s_EndEvent;
  static const SpawnEvent s_SpawnEvent;
};
