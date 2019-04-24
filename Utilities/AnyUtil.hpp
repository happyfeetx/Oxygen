#pragma region "INCLUDES"

#include <cstdio>
#include <cstdlib>
#include <exception>
#include "oxygen.hpp"
#include "Configurations.hpp"

#pragma endregion "INCLUDES"

namespace Discord::Utilities {
    class InvalidConfigurationException : std::exception {
    public:
        InvalidConfigurationException(const char* err_message) {
            HasInnerException = false;
            
            if (err_message != nullptr)
                HasMessage = true;

            if (HasMessage) {
                printf(err_message);

            } else {
                printf("There's an error with your configuration, but it looks like we can't pinpoint what it is. Sorry!");
            }
        }

        ~InvalidConfigurationException();

    private:
        bool HasInnerException;
        bool HasMessage;
    };

    class DiscordConfiguration {
    public: 
        void* Commands;
        void* Client;

        DiscordConfiguration(ClientConfiguration clientConfig, CommandsConfiguration commandsConfig) {
            Client = new ClientConfiguration();
            Commands = new CommandsConfiguration();
        }

        ~DiscordConfiguration() {
            Client = nullptr;
            Commands = nullptr;

            delete Commands;
            delete Client;
        }
    };
}