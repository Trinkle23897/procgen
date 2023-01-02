#include <stdexcept>

#include "game-registry.h"

std::map<std::string, std::function<std::shared_ptr<Game>()>> *globalGameRegistry = nullptr;

std::shared_ptr<Game> make_game(const std::string& name) {
  if (name == "bigfish") {
    return make_bigfish();
  }
  if (name == "bossfight") {
    return make_bossfight();
  }
  if (name == "caveflyer") {
    return make_caveflyer();
  }
  if (name == "chaser") {
    return make_chaser();
  }
  if (name == "climber") {
    return make_climber();
  }
  if (name == "coinrun") {
    return make_coinrun();
  }
  if (name == "dodgeball") {
    return make_dodgeball();
  }
  if (name == "fruitbot") {
    return make_fruitbot();
  }
  if (name == "heist") {
    return make_heist();
  }
  if (name == "jumper") {
    return make_jumper();
  }
  if (name == "leaper") {
    return make_leaper();
  }
  if (name == "maze") {
    return make_maze();
  }
  if (name == "miner") {
    return make_miner();
  }
  if (name == "ninja") {
    return make_ninja();
  }
  if (name == "plunder") {
    return make_plunder();
  }
  if (name == "starpilot") {
    return make_starpilot();
  }
  // not supposed to reach here
  throw std::runtime_error("Unknown env_name " + name);
}
