# OASIS Core v3.0.0 (Leap)

## Summary
This major upgrade brings a large set of new features to OASIS Core; Users can now:
- see the USD value of their available XOS directly within OASIS Core.
- use the `burn` command to permanently embed custom data on-chain, or simply burn XOS from the circulating supply.
- use the `getblockchaininfo` or `getinfo` commands to see the total "burned" XOS.
- see burns within the GUI, displayed by a coloured "OASIS flame" icon, the TX list can also be 'filtered' by burns.
- use the `reloadmasternodeconfig` command to hot-reload their masternode.conf file, without restarting their wallet.

Additionally, this release contains a major patch for upstream exploit: CVE-2018-17145, also known as [INVDoS](https://invdos.net/), OASIS Core is also more stable, crash-resistant and hardened by a multitude of bugfixes.

## How to Upgrade

Steps to Upgrade:
1. Shutdown OASIS Core
2. (Optional) Delete "oasis-qt" from your device
3. [Download OASIS Core v3.0.0](https://github.com/gdiscord/oasis/releases)
4. Open "oasis-qt"
5. **Upgrade Complete!**


---
Starting with the latest changes (ending with the oldest), each commit has its own category.
# Changelog

**Highlighted** changes are deemed important / notable to the average user.
 - **Add currency displays (USD first)** (Your USD equivalent in XOS is now displayed in-wallet!)
 - Add Color Burn Images
 - Add Burned transaction type
 - Autocomplete help RPC commands
--
 - Guard wallet pointer in getEncryptionStatus
 - Guard isStakingStatusActive pointers
--
 - Allow zero-value burns for data relays
 - **Add ability to hot-reload Masternode config** (Masternodes can be added/removed without restarts!)
 - **Add scam protection to wallet commands** (The Debug Console is now safer for the average user!)
 - Ensure burn data doesnt exceed maximum relay
 - **Add burn RPC with optional string (OP_RETURN)** (Anyone can easily embed permanent data on-chain!)
---
---
- [DB] *()* - Simplify burn calculations and include TX fees
- [DB] *()* - **Introduce Burned XOS tracking** (You can now track the total amount of burned XOS)
---

---
# Credits
(ZENZO PROJECT)

**OASIS Core Team**