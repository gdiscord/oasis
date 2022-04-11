OASIS Core version v4.0.0 (Tropos) is now available from: <https://github.com/OasisCoinTeam/oasis/releases>

This is a new major version release that retains the features of v.3.0.0 (Leap). Notable in this release is that it is a fork of pivx v5.4, bringing along all the features but with zerocoin code completely refactored out of the codebase. This makes it relatively easier to set OASIS on a path of innovation - unencumbered by the baggage of zerocoin.

Summary

- Refactoring of codebase to completely remove zerocoin.
- use the `getsupplyinfo`, `getblockchaininfo` or `getinfo` commands to see the total "burned" XOS.

Please report bugs using the issue tracker at github: <https://github.com/OasisCoinTeam/oasis/issues>


How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down, then run the installer (on Windows) or just copy over /Applications/OASIS-Qt (on Mac) or oasisd/oasis-qt (on Linux).

Notable Changes
==============
Complete removal of zerocoin code.

## Credits

PIVX
ZENZO