//
// Created by rod_f on 19/04/2024.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <cstdint>

class GameManager {
public:
    // Constructor and destructor
    GameManager();
    ~GameManager();

    // Function to add an item to a player
    void addItemToPlayer(const std::string& recipient, uint16_t itemId);

private:

};

#endif //GAMEMANAGER_H
