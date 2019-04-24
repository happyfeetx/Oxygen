#include <cstdio>
#include <cstdlib>
#include <string>
#include <exception>
#include "oxygen.hpp"

namespace Discord::Utilities {
    enum TokenType {
        Bot = 0,
        User = 1,
        Bearer = 2
    };

    struct ClientConfiguration {
    public:
        std::string Token; // Login token of the bot. Used to identify and authenticate with Discord servers.
        TokenType TokenType; // Token type of the bot
        int Timeout; // Time disconnected before the bot will quit.
        int MessageCache; // The amount of user messages that the bot will hold in memory. Max 10,000 messages.
        bool AutomaticRetry; // Automatically attempts to reconnect the client to Discord servers.
        bool UseDefaultHelpResponse; // Use the default Help dialogue response. Enabled by default.
        bool EnableDMs; // Enable the bot to receive and respond to DMs from users. Disabled by default.

        ClientConfiguration() {
            Token = botToken;
            TokenType = TokenType::Bot;
            Timeout = 2500;
            MessageCache = 5000;
            AutomaticRetry = false;
            UseDefaultHelpResponse = true;
            EnableDMs = false;
        }

    private:
        std::string botToken;
    };

    struct CommandsConfiguration {
    public: 
        int CooldownPerUser;
        bool UseDefaultCommandHandler;

        CommandsConfiguration() {
            CooldownPerUser = 1;
            UseDefaultCommandHandler = true;
        }
    };
}