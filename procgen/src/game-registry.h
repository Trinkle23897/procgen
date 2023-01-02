#pragma once

/*

This is a way to register game classes without having to update a central index of games

Each game should include "game-registry.h" and call REGISTER_GAME("name", GameSubClass)

*/

#include <vector>
#include <string>
#include <map>
#include <functional>
#include <memory>
#include "cpp-utils.h"

class Game;

#define REGISTER_GAME(name, cls)                                         \
    static auto UNUSED_FUNCTION(_registration) = registerGame(name, [] { \
        return std::make_shared<cls>();                                  \
    })

extern std::map<std::string, std::function<std::shared_ptr<Game>()>> *globalGameRegistry;

template <typename Func>
int registerGame(std::string name, Func fn) {
    if (globalGameRegistry == nullptr) {
        // because global initialization order is undefined in C++, supposedly
        // we have to set this here
        globalGameRegistry = new std::map<std::string, std::function<std::shared_ptr<Game>()>>();
    }
    (*globalGameRegistry)[name] = fn;
    return 0;
}

// envpool patch, static funciton initialization order is undefined
std::shared_ptr<Game> make_bigfish(void);
std::shared_ptr<Game> make_bossfight(void);
std::shared_ptr<Game> make_caveflyer(void);
std::shared_ptr<Game> make_chaser(void);
std::shared_ptr<Game> make_climber(void);
std::shared_ptr<Game> make_coinrun(void);
std::shared_ptr<Game> make_dodgeball(void);
std::shared_ptr<Game> make_fruitbot(void);
std::shared_ptr<Game> make_heist(void);
std::shared_ptr<Game> make_jumper(void);
std::shared_ptr<Game> make_leaper(void);
std::shared_ptr<Game> make_maze(void);
std::shared_ptr<Game> make_miner(void);
std::shared_ptr<Game> make_ninja(void);
std::shared_ptr<Game> make_plunder(void);
std::shared_ptr<Game> make_starpilot(void);
