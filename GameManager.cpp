//
// Created by rod_f on 19/04/2024.
//

#include "GameManager.h"

// Q4 - Assume all method calls work fine. Fix the memory leak issue in below method
void GameManager::addItemToPlayer(const std::string& recipient, uint16_t itemId)
{
    // Attempt to retrieve the player by name
    Player* player = g_game.getPlayerByName(recipient);
    bool isNewPlayer = false;

    // If player does not exist, load or create a new player
    if (!player) {
        player = new Player(nullptr);
        isNewPlayer = true;
        if (!IOLoginData::loadPlayerByName(player, recipient)) {
            // Delete the player if loading fails
            delete player;
            return;
        }
    }

    // Create the item to be added
    Item* item = Item::CreateItem(itemId);
    if (!item) {
        if (isNewPlayer) {
            // Delete the player if item creation fails and it's a new player
            delete player;
        }
        return;
    }

    // Add the item to the player's inbox
    g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREVER, FLAG_NOLIMIT);

    // Save player data if the player is offline
    if (player->isOffline()) {
        IOLoginData::savePlayer(player);
    }

    // Clean up resources if it's a new player and loading was successful
    if (isNewPlayer) {
        delete player;
    }
}