#include "gameState.hpp"

GameState::GameState(): _userState(UserState::ProgramOn) {
  
}

std::vector<std::string> GameState::GetMainMenuChoices() const {
  // TODO: Load these questions from a file perhaps.
  std::vector<std::string> choices { "Start", "Scores", "Exit" };
  return choices;
}

void GameState::SetState(UserState state) {
  _userState = state;
}

UserState GameState::GetState() const {
  return _userState;
}