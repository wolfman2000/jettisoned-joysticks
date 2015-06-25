#ifndef GAME_STATE_HPP_
#define GAME_STATE_HPP_

#include <vector>
#include <string>
#include "userState.hpp"

class GameState {
public:
  GameState();
  
  std::vector<std::string> GetMainMenuChoices() const;
  
  void SetState(UserState);
  UserState GetState() const;
private:
  UserState _userState;
};

#endif

