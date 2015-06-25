#include "gameState.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main() {
  GameState gameState;
  
  cout << "Initial state does nothing for now." << endl;
  
  gameState.SetState(UserState::MainMenu);
  
  auto choices = gameState.GetMainMenuChoices();
  
  cout << "Choose your option.\n" << endl;
  
  for (size_t i = 0; i < choices.size(); ++i) {
    cout << i + 1 << ": " << choices[i] << endl;
  }
  
  int option;
  
  cout << "\n> ";
  std::cin >> option;
  
  switch (option) {
    case 1:
      cout << "Will enter main game." << endl;
      break;
    case 2:
      cout << "Will view high scores." << endl;
      break;
    case 3:
      cout << "Will exit game." << endl;
      break;
    default:
      cout << "Invalid choice. Will force a redo." << endl;
      break;
  }
  
  return 0;
}