- What is this folder for?

This folder contains configuration (.ini) files containing patterns and memory offsets necessary for IV-SDK.
The Patterns.ini file contains byte patterns for finding memory offsets in the game and the other .ini files contain the cached memory offsets for supported versions of the game.

To add support for a new GTA IV version, add a byte pattern for any Section/Key in the Patterns.ini file that do not result in the correct or any offset in the exe.
When exiting the game, the plugin will generate a config file for the active version of the game with the offsets found using the patterns which you can then put in this folder.

The configuration file is built up using section, keys and values which look like this:

[Section]
Key=Value

The name of a section matches the name of a header file e.g. "CPlayerInfo"
The name of a key matches the name of a member e.g. "FindPlayerPed"
The value of a key will be the memory pattern. You can add multiple patterns separated by a comma e.g. "8B 0D ? ? ? ? 8B 11 8B 52 60, 8B 0D ? ? ? ? 6A 00 8B 01 52"