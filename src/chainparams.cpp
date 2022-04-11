// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2020 The PIVX developers
// Copyright (c) 2019-2022 The OASIS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "chainparamsseeds.h"
#include "consensus/merkle.h"
#include "tinyformat.h"
#include "utilstrencodings.h"

#include <assert.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);              // 504365040 ==> 0x1e0ffff0   // 486604799 ==> 0x1d00ffff
    txNew.vin[0].scriptSig = CScript() << 504365040 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.vtx.push_back(std::make_shared<const CTransaction>(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.nVersion = nVersion;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

void CChainParams::UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
{
    assert(IsRegTestNet()); // only available for regtest
    assert(idx > Consensus::BASE_NETWORK && idx < Consensus::MAX_NETWORK_UPGRADES);
    consensus.vUpgrades[idx].nActivationHeight = nActivationHeight;
}

/**
 * Build the genesis block. Note that the output of the genesis coinbase cannot
 * be spent as it did not originally exist in the database.
 *
 * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
 *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
 *   vMerkleTree: e0028e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "The GDiscord Experiment";
    const CScript genesisOutputScript = CScript() << ParseHex("04e8c123e2c17aef33b6a099c0846019f7819c7ffd24394f3b982faafab71846825c83d6ae9af0960e36596aa7e34a4db203bbdd2ddc54c61e75c84a17cdc33d14") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static MapCheckpoints mapCheckpoints = {   
    {      0, uint256S("0000006d47a381957bf0879cd46bb52663b8884a5e37c066e2f0c5628274d138")},
    {    100, uint256S("00000036e9af06d8f2ec74cc84aaf6d5455fd2cef38f7f596b05c1e9200966dd")},
    {    200, uint256S("00000005861cd768596bdf9fb52c881a2438bf79e3a3355e5f320d8765d8140b")},
    {    300, uint256S("0000003e0cb75b2482edb09a217a667388409b7c8a64951959ffdc9deb356547")},
    {    400, uint256S("0000000e1e6adf50deb01b4e3bc57d75702c23d60f5205b7a350ffa7bba5bc05")}, 
    {    500, uint256S("0000000853706c18b4d6890336844abf4c6ad0143ab07e7f8e15225fc7e26f15")},
    {    600, uint256S("0000000f0c8adc8f26e8c50ff7e1c14c15fca32d73e1b9ca8068f8a7d9235010")},
    {    700, uint256S("95a760bc687b9309222926c6093fe624bb8988abed16f9e27aa7776e6d4b728e")},
    {    800, uint256S("405c1b09fbe680c56144dfbd13ed6ba5c4338853fa9527abb2392aa300490f89")},
    {    900, uint256S("55c92cb3d763f960410005286bc3b9f66716761151fd86744226c9f87309d994")}, 
    {   1001, uint256S("79736890ae5b4cd819b7b17c2fbe69c20b60af0cb808a34fad26334ca7a014b1")},
    {   2498, uint256S("64b8bc492469a8a0112795a8277f39bbe30f93819ea061d486dd24123d0f8417")},
    {   2500, uint256S("5148fa8ad49fd60fd8a27317e60b690fc8a8aadb857e2f5202332fdfabd2b028")},
    {  25000, uint256S("f611c1a708ea45d0088f1ee8edfc31146dfab9c6ce83855ea04a5900b16a2d64")},
    {  50000, uint256S("746cdf1f6e67b2d4188aedbddd7599e636a25a49d835b41e6a06415d398659d0")},
    {  75000, uint256S("205b83b1ef644eb85e5742719687102cd74a06f978f35e156cbf8b4cef0ac2eb")},
    { 100000, uint256S("06a7d8ddb1dc6da38e0bed846f69b837b7477b44a83bd09f54a068ad7ec320e9")},
    { 125000, uint256S("80943b379ab180e74475a7bf191a562be4aa929c8a3d8c67da8ea7a02c5ed194")}, 
    { 150000, uint256S("bbafe3d94eea0b4add6628e78eb4cfedab2d1cd8577848075c3e6fa6638ae6d6")},
    { 175000, uint256S("42dead3a60a304bce95e3290af601a40e7ed55376450726d8496bbe2e8cec634")},
    { 200000, uint256S("8c310edbf39285a685a664597b3be90c84a017d9ba1413a74ef1e4b5c6b7c139")},
    { 250000, uint256S("c9aa88e4e22fade625f487a27a9151e0054778ec4096cffbfc14a8b08cd75439")},
    { 300000, uint256S("2ebf0b6879459e6f21c0aa4ef5dadd82fc28c9626e0cc254dbff190b6118edf0")}, 
    { 325000, uint256S("0f75949482e7d9a1d9c9e4a4ac7a44c2c7601c99724e42e49e773537a6c2b385")},
    { 350000, uint256S("8b6c9a2113f060f1c92d929cb825617dffbff4feb4da03adaa55321a59b803a0")},
    { 374575, uint256S("941b78342705a1a38f244afc65e6506256b1424ec68ff98d3c14b3f164aa61bc")},

};
static const CCheckpointData data = {
    &mapCheckpoints,
    1626571470, // * UNIX timestamp of last checkpoint block
    749875,     // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static MapCheckpoints mapCheckpointsTestnet = {
    {0, uint256S("0x001")},
};
static const CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1626368400,
    0,
    250};

static MapCheckpoints mapCheckpointsRegtest = {
    {0, uint256S("0x001")}
};
static const CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1626368400,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        strNetworkID = "main";

        genesis = CreateGenesisBlock(1626368400, 4897717, 0x1e0ffff0, 5, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x0000006d47a381957bf0879cd46bb52663b8884a5e37c066e2f0c5628274d138"));
        assert(genesis.hashMerkleRoot == uint256S("0xcf1b7b9662c67eb97b3215cda30f29cbb6242b9821381ea43fa2ac1cf3d2d73b"));

        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.powLimit   = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV1 = uint256S("0x000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV2 = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nBudgetCycleBlocks = 43200;       // approx. 1 every 30 days
        consensus.nBudgetFeeConfirmations = 6;      // Number of confirmations for the finalization fee
        consensus.nCoinbaseMaturity = 30;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMaxMoneyOut = 3000000 * COIN;
        consensus.nMNCollateralAmt = 285 * COIN;
        consensus.nMNBlockReward = 0.003125 * COIN;
        consensus.nProposalEstablishmentTime = 60 * 60 * 24;    // must be at least a day old to make it into a budget
        consensus.nStakeMinAge = 60 * 60;
        consensus.nStakeMinDepth = 480;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;
        consensus.nMaxProposalPayments = 6;

        // spork keys
        consensus.strSporkPubKey = "04b4b9cc5d7e6706df4cb666dea004ca384596eaad78d3ae97b634e5e0d78fcb6c5caae7e1284a3b182ed3071dde79531c9cbcad7e2b272337287b0d567afcd34e";
        //consensus.strSporkPubKeyOld = "";
        consensus.nTime_EnforceNewSporkKey = 1556925306;    //!> December 21, 2020 01:00:00 AM GMT
        consensus.nTime_RejectOldSporkKey = 1558823823;     //!> March 1, 2021 01:00:00 AM GMT

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight      =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight       = 601;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight    = 620;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight     = 620;
        consensus.vUpgrades[Consensus::UPGRADE_TIME_V2].nActivationHeight   = 620;
        consensus.vUpgrades[Consensus::UPGRADE_MESG_V2].nActivationHeight   = 620;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight      = 
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_VNEXT].nActivationHeight     =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;

       
        consensus.vUpgrades[Consensus::UPGRADE_POS].hashActivationBlock     =
                uint256S("8445b29edb877c364f9b99b05a77a0a363470632369d9f628770caeaaa8925b8");
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].hashActivationBlock  =
                uint256S("e7deb8dd396d9430ac6e15ba00ec6e69c4adbdbf226ad07add60ed8304534612");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock   =
                uint256S("e7deb8dd396d9430ac6e15ba00ec6e69c4adbdbf226ad07add60ed8304534612");
        consensus.vUpgrades[Consensus::UPGRADE_TIME_V2].hashActivationBlock =
                uint256S("e7deb8dd396d9430ac6e15ba00ec6e69c4adbdbf226ad07add60ed8304534612");
        consensus.vUpgrades[Consensus::UPGRADE_MESG_V2].hashActivationBlock =
                uint256S("0x001");
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].hashActivationBlock    =
                uint256S("0x001");

       

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x7a;
        pchMessageStart[1] = 0x51;
        pchMessageStart[2] = 0xb9;
        pchMessageStart[3] = 0xc4;
        nDefaultPort = 3358;

        // Note that of those with the service bits flag, most only support a subset of possible options
        vSeeds.emplace_back("seedone.oasisco.in", true);     //  Primary DNS Seeder 
        vSeeds.emplace_back("seedtwo.oasisco.in", true);    // Primary DNS Seeder 
        vSeeds.emplace_back("seedthree.oasisco.in", true);     // Primary DNS Seeder

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 115);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 15);
        base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 63);     // starting with 'S'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x28, 0x21, 0x38};
        base58Prefixes[EXT_SECRET_KEY] = {0x05, 0x27, 0x33, 0x22};
        //  BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = {0x80, 0x00, 0x00, 0x77};

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_main), std::end(chainparams_seed_main));

        // Reject non-standard transactions by default
        fRequireStandard = true;

        // Sapling
        bech32HRPs[SAPLING_PAYMENT_ADDRESS]      = "ps";
        bech32HRPs[SAPLING_FULL_VIEWING_KEY]     = "pviews";
        bech32HRPs[SAPLING_INCOMING_VIEWING_KEY] = "xosks";
        bech32HRPs[SAPLING_EXTENDED_SPEND_KEY]   = "p-secret-spending-key-main";
        bech32HRPs[SAPLING_EXTENDED_FVK]         = "pxviews";
    }

    const CCheckpointData& Checkpoints() const
    {
        return data;
    }

};

/**
 * Testnet (v5)
 */
class CTestNetParams : public CChainParams
{
public:
    CTestNetParams()
    {
        strNetworkID = "test";

        genesis = CreateGenesisBlock(1626368400, 3674104, 0x1e0ffff0, 5, 100000 * COIN); 
        consensus.hashGenesisBlock = genesis.GetHash();       
        assert(consensus.hashGenesisBlock == uint256S("0x000007c9dee186c036f6bc47dd5285ff7ad4fb7052ee7b01e1a3073fe577c65d"));
        assert(genesis.hashMerkleRoot == uint256S("0x20f03da45fe07827663146d71274db5c41daa16c9def245cb98a2462da178b98"));


        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        consensus.powLimit   = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV1 = uint256S("0x000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV2 = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nBudgetCycleBlocks = 144;         // approx 10 cycles per day
        consensus.nBudgetFeeConfirmations = 3;      // (only 8-blocks window for finalization on testnet)
        consensus.nCoinbaseMaturity = 15;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMaxMoneyOut = 1000000 * COIN;
        consensus.nMNCollateralAmt = 285 * COIN;
        consensus.nMNBlockReward = 0.2 * COIN;
        consensus.nProposalEstablishmentTime = 60 * 5;  // at least 5 min old to make it into a budget
        consensus.nStakeMinAge = 60 * 60;
        consensus.nStakeMinDepth = 100;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;
        consensus.nMaxProposalPayments = 20;

        // spork keys
        consensus.strSporkPubKey = "04677c34726c491117265f4b1c83cef085684f36c8df5a97a3a42fc499316d0c4e63959c9eca0dba239d9aaaf72011afffeb3ef9f51b9017811dec686e412eb504";
        consensus.strSporkPubKeyOld = "04E88BB455E2A04E65FCC41D88CD367E9CCE1F5A409BE94D8C2B4B35D223DED9C8E2F4E061349BA3A38839282508066B6DC4DB72DD432AC4067991E6BF20176127";
        consensus.nTime_EnforceNewSporkKey = 1608512400;    //!> December 21, 2020 01:00:00 AM GMT
        consensus.nTime_RejectOldSporkKey = 1614560400;     //!> March 1, 2021 01:00:00 AM GMT


        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight           = 201;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight        = 201;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight         = 201;
        consensus.vUpgrades[Consensus::UPGRADE_TIME_V2].nActivationHeight       = 201;
        consensus.vUpgrades[Consensus::UPGRADE_MESG_V2].nActivationHeight       = 201;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight          = 201;
        consensus.vUpgrades[Consensus::UPGRADE_VNEXT].nActivationHeight         = 262525;

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        nDefaultPort = 53474;

        // nodes with support for servicebits filtering should be at the top
        vSeeds.emplace_back("oasis-testnet.seed", true);
        vSeeds.emplace_back("oasis-testnet.seed2", true);

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet OASIS addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet OASIS script addresses start with '8' or '9'
        base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 73);     // starting with 'W'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)

        base58Prefixes[EXT_PUBLIC_KEY] = {0x3a, 0x80, 0x61, 0xa0};
        // Testnet oasis BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = {0x3a, 0x80, 0x58, 0x37};
        // Testnet oasis BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = {0x80, 0x00, 0x00, 0x01};

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_test), std::end(chainparams_seed_test));

        fRequireStandard = false;

        // Sapling
        bech32HRPs[SAPLING_PAYMENT_ADDRESS]      = "ptestsapling";
        bech32HRPs[SAPLING_FULL_VIEWING_KEY]     = "pviewtestsapling";
        bech32HRPs[SAPLING_INCOMING_VIEWING_KEY] = "xosktestsapling";
        bech32HRPs[SAPLING_EXTENDED_SPEND_KEY]   = "p-secret-spending-key-test";
        bech32HRPs[SAPLING_EXTENDED_FVK]         = "pxviewtestsapling";
    }

    const CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams
{
public:
    CRegTestParams()
    {
        strNetworkID = "regtest";

       genesis = CreateGenesisBlock(1626368400, 5448732, 0x1e0ffff0, 5, 25000 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();       
        assert(consensus.hashGenesisBlock == uint256S("0x00000bdc3b124871579123db71333bab71f21a21a080f984c8065ee91235b40b"));
        assert(genesis.hashMerkleRoot == uint256S("0xef7a8807b30159a4c33685916685e5856b811424ea7bae15954ecb2831365e38"));

        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.powLimit   = uint256S("0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV1 = uint256S("0x000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV2 = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nBudgetCycleBlocks = 144;         // approx 10 cycles per day
        consensus.nBudgetFeeConfirmations = 3;      // (only 8-blocks window for finalization on regtest)
        consensus.nCoinbaseMaturity = 100;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMaxMoneyOut = 43199500 * COIN;
        consensus.nMNCollateralAmt = 100 * COIN;
        consensus.nMNBlockReward = 0.2 * COIN;
        consensus.nProposalEstablishmentTime = 60 * 5;  // at least 5 min old to make it into a budget
        consensus.nStakeMinAge = 0;
        consensus.nStakeMinDepth = 20;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;
        consensus.nMaxProposalPayments = 20;

        /* Spork Key for RegTest:
        WIF private key: 932HEevBSujW2ud7RfB1YF91AFygbBRQj3de3LyaCRqNzKKgWXi
        private key hex: bd4960dcbd9e7f2223f24e7164ecb6f1fe96fc3a416f5d3a830ba5720c84b8ca
        Address: yCvUVd72w7xpimf981m114FSFbmAmne7j9
        */
        consensus.strSporkPubKey = "";
        consensus.strSporkPubKeyOld = "";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

      // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight =
                Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight =
                Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight           = 201;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight        = 201;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight         = 201;
        consensus.vUpgrades[Consensus::UPGRADE_TIME_V2].nActivationHeight          = 201;
        consensus.vUpgrades[Consensus::UPGRADE_MESG_V2].nActivationHeight          = 201;
        consensus.vUpgrades[Consensus::UPGRADE_V4_0].nActivationHeight          = 201;
        consensus.vUpgrades[Consensus::UPGRADE_VNEXT].nActivationHeight          = 262525;
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nDefaultPort = 53476;

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet oasis addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet oasis script addresses start with '8' or '9'
        base58Prefixes[STAKING_ADDRESS] = std::vector<unsigned char>(1, 73);     // starting with 'W'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet oasis BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = {0x3a, 0x80, 0x61, 0xa0};
        // Testnet oasis BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = {0x3a, 0x80, 0x58, 0x37};
        // Testnet oasis BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = {0x80, 0x00, 0x00, 0x01};

        // Reject non-standard transactions by default
        fRequireStandard = true;

        // Sapling
        bech32HRPs[SAPLING_PAYMENT_ADDRESS]      = "ptestsapling";
        bech32HRPs[SAPLING_FULL_VIEWING_KEY]     = "pviewtestsapling";
        bech32HRPs[SAPLING_INCOMING_VIEWING_KEY] = "xosktestsapling";
        bech32HRPs[SAPLING_EXTENDED_SPEND_KEY]   = "p-secret-spending-key-test";
        bech32HRPs[SAPLING_EXTENDED_FVK]         = "pxviewtestsapling";
    }

    const CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params()
{
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
{
    globalChainParams->UpdateNetworkUpgradeParameters(idx, nActivationHeight);
}
