//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRSet.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "dnsseed.litecoinpool.org.", "seed-a.litecoin.loshan.co.uk.", "dnsseed.thrasher.io.",
    "dnsseed.koin-project.com.", "dnsseed.litecointools.com.", NULL};

static const char *BRTestNetDNSSeeds[] = {
    "testnet-seed.ltc.xurious.com.", "seed-b.litecoin.loshan.co.uk.", "dnsseed-testnet.thrasher.io.", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {       0, uint256("12a765e31ffd4059bada1e25190f6e98c99d9714d334efa41a195a7e7e04bfe2"), 1317972665, 0x1e0ffff0 },
    {   20160, uint256("633036c8df655531c2449b2d09b264cc0b49d945a89be23fd3c1a97361ca198c"), 1319798300, 0x1d055262 },
    {   40320, uint256("d148cdd2cf44069cef4b63f0feaf30a8d291ca9ea9ba7e83f226b9738c1d5e9c"), 1322522019, 0x1d018053 },
    {   60480, uint256("3250f0a560d55f039c34bfaee1b71297aa5104ac6641778f9a87d73232d12c6c"), 1325540574, 0x1d00e848 },
    {   80640, uint256("bedc0a090b740b1902d870aeb6caa89040a24e7d670d46f8ef035fd9d2e9ce80"), 1328779944, 0x1d00ab92 },
    {  100800, uint256("7b0b620d15f781faaaa73b43607a49d5becb2b803ef19b4010014646cc177a61"), 1331873688, 0x1d00ae9f },
    {  120960, uint256("dbd6249f30e5690890bc03dabcc0a526c46adcde572be06af4075b6ea28aa251"), 1334881566, 0x1d009e48 },
    {  141120, uint256("5d5e15a45cecf2b9528e36e63c407167423a2f9963a96bbce3b67b75fd10be2a"), 1338009318, 0x1d00d6a6 },
    {  161280, uint256("f595c754d0abcfe3616573bfabee01b230ec0ea6b2f2894c40214ea23d772b6c"), 1340918301, 0x1d008881 },
    {  181440, uint256("d7fa3152959f3c25e33edf825f7cbef75ee651d5f9183cc4ed8d19d57b8f35a4"), 1343534530, 0x1c1cd430 },
    {  201600, uint256("d481df8e8ce144fca9ae6b3157cc706e903c6ea161a13d2c421270354a02d6d0"), 1346567025, 0x1c1c89e8 },
    {  282240, uint256("8932095fba44bd6860fd71745c0dca908769221a47166ab1fb442b6cefcd53fb"), 1358801720, 0x1c0ced21 },
    {  342720, uint256("33f62e026a202be550e8a9df37d638d38991553544e279cb264123378bf46042"), 1367113967, 0x1c0095a5 },
    {  383040, uint256("5c0a443361c1356796a7db472c69433b6ce6108d61e4403fd9a9d91e01009ce3"), 1372971948, 0x1b481262 },
    {  443520, uint256("37d668803ed1efc24ffab4a2a90da9ac92679acf68370d7570f042c2bd6d651b"), 1382034998, 0x1b3f864f },
    {  504000, uint256("97db0624d3d5137bc085f0d731607314972bb4124b85b73420ef9aa5fc10d640"), 1390892377, 0x1b1aa868 },
    {  564480, uint256("c876276bf12754c2b265787d9e7ab83d429e59761dc63057f728529018db7834"), 1399724592, 0x1b099dce },
    {  624960, uint256("ccac71fafe98107b81ac3e0eed41190e4d47600962c93c49db8843b53f760bda"), 1408389228, 0x1b02552d },
    {  685440, uint256("29d2328990dda4c4870846d4e3d573785452bed68e6013930a83fc8d5fe89b09"), 1417289378, 0x1b01473b },
    {  745920, uint256("04809a35ff6e5054e21d14582072605b812b7d4ae11d3450e7c03a7237e1d35d"), 1426441593, 0x1b019b8c },
    {  806400, uint256("e2363e8b3e8f237b9b1bfc1c72ede80fef2c7bd1aabcd78afed82065a194b960"), 1435516150, 0x1b019268 },
    {  846720, uint256("6f5d94d7cfd01f1dbf4aa631b987f8e2ec9d0c57720604787b816bafe34192a8"), 1441561050, 0x1b0187a3 },
    {  901152, uint256("cfccdf8e3830ae4879e910051ac3dc583b4fb45b83be3a38019e5d9326dfa223"), 1449698771, 0x1b015b0e },
    {  953568, uint256("e46e01cf1239cffa69408ac162d517bac5a4899972e0328fd0ba4d93e8ad3764"), 1457542869, 0x1b013c91 },
    { 1058400, uint256("76ce37c66d449a4ffbfc35674cf932da701066a001dc223754f9250dd2bdbc62"), 1473296285, 0x1b013ca7 },
    { 1260000, uint256("85a22b528d805bf7a641d1d7c6d96ef5054beda3dcab6be7b83f2e3df24b33a8"), 1502976600, 0x1a25a0d3 },
    { 1411200, uint256("92c85b76f3d4bffca76b23717e4eb1b667c77c96fd52d4dd5dd843bbee64cd73"), 1524838967, 0x1a0203a7 },
	{ 1431360, uint256("a5480373ece83decc592f331c599cac73576be9666fae9cb5f75370be8082e5a"), 1527797819, 0x1a019af8 },
	{ 1451520, uint256("175c9f77ce667b80a3467974560b8b0c601c29593b772836509e53b311f5b765"), 1530861890, 0x1a01d132 },
	{ 1471680, uint256("488e6d36f3962d60763a1dbc0e06fa46591c6f69ba60210d243838a522a936bf"), 1533871757, 0x1a01b43f },
	{ 1491840, uint256("87e19789f30da635bcf07aea2c206d30beac6344260696aadc0712b325832903"), 1536932090, 0x1a01e815 },
	{ 1512000, uint256("e753082c797819a8d7d438626903bd2800676a00dde9d9c26987c66673b1c689"), 1539955474, 0x1a01e36d },
	{ 1532160, uint256("95ab1931e4113a0767e66354c8078dde6576ed49d869e2d72b91ebeb9e8ea12b"), 1543061044, 0x1a027259 },
	{ 1552320, uint256("f01f6cb064b9e1082223c5ffd01cf5bc5c6e5389d3cce4b285f04637b61e8318"), 1546141046, 0x1a02e08e },
	{ 1572480, uint256("20e3eb741a0622d4a90328c604df9b9773177c37c9cf14e27c30d09fcaef0449"), 1549112907, 0x1a02686f },
	{ 1592640, uint256("18d85592bb75e90e8115ae7a1020ec9c4bc8e6c23b40460d6921814fd9747dfc"), 1552072900, 0x1a01f08a },
	{ 1612800, uint256("f324fdc87f9f44ec1d05b3af94d856085378153638264bf2977bb27d65b68f26"), 1555013248, 0x1a017580 },
	{ 1632960, uint256("8e9313981432a4f352cef82dc45cc9f914588dd84529a57944ead9f1062d165e"), 1558020155, 0x1a015f03 },
	{ 1653120, uint256("8a3c90c12667ab1b1a2351c61a12575e305e1cdcf52eb14b7ae948f6f7c0d483"), 1561003137, 0x1a0130be },
	{ 1673280, uint256("4e2e630533782457a66d1cd315ddcdaf001c52b0dea4a180d14c7c9c43ad319c"), 1563999780, 0x1a0114a7 },
	{ 1693440, uint256("e00efe6b205969cf5183db9232f94674b840729ded6e0a24f83150b898d560d3"), 1567125033, 0x1a017b45 },
	{ 1713600, uint256("e5cb8b610baf1c7156a9a88ef73d09ae310bff56256c4a3f9988465fa4a602d1"), 1570198197, 0x1a01bbc2 },
	{ 1733760, uint256("0c51b8a8d5d78147c2e5f2fc118327171694f36217282986075cf828d60d6110"), 1573350522, 0x1a029a16 },
	{ 1753920, uint256("097e1246efc9c8f8a033f0f885276046f8acf20f9c620377a97ccdafdc5065c4"), 1576462914, 0x1a0372ba },
	{ 1774080, uint256("ebe233451e99ff20505f05484adddea11074cecdd8397baf3aa6b2eda37fed3a"), 1579449721, 0x1a03071d },
	{ 1794240, uint256("77882e9351f9094c1500a8c904a3a545cc04412722c48482c72e58e11c76ed61"), 1582454390, 0x1a02ceb9 },
	{ 1814400, uint256("e6869446f389dede0fffb15c56903bf9f1428b22708af8812d486fdba9fd745b"), 1585544448, 0x1a03638f },
	{ 1834560, uint256("a9eb37e4e43982396752d42be1f04f1d1a933f03aefe94917a68ed4e4dcf53b5"), 1588503738, 0x1a02b720 },
	{ 1854720, uint256("2b05fce64a4cc7ee91ecc5cca4799e4a036ab6236cd56219d0e691d4b4c02013"), 1591451143, 0x1a020f38 },
	{ 1874880, uint256("72d638a5f91b752e315a7e492815a2cb1bca31bee2f6f93b7c2329b734ed948c"), 1594463523, 0x1a01f4f0 },
	{ 1895040, uint256("e154b9b4f936ea865de016f8cfc4457e1123dd8be71bd15930406c7c64ff8fdb"), 1597466654, 0x1a01cd62 },
	{ 1915200, uint256("6512df5ad3ffd5099b870be58f05c650049c172040080f8c9bdbc77cb6c50046"), 1600474524, 0x1a01b1ae },
	{ 1935360, uint256("4fffd7f073bc206586ec737b6468a6ef5038d2efaa4f2e347264d11189a12e01"), 1603542553, 0x1a01f0ad },
	{ 1955520, uint256("a8ff4d215e37dcccff013b4228bbce89f3c455895adca37a7e7e5a93bfe9f7c3"), 1606626877, 0x1a0245ad },
	{ 1975680, uint256("083fbbde816554ffeeac3c4adfc31e4e6eab26bc09d4ea7778e86581400f832a"), 1609597781, 0x1a01e2fe },
	{ 1995840, uint256("0b9af0663fa987a499c4fa814ae8c997f071fa6f306c9a876d4d31ad24ff4d87"), 1612582334, 0x1a01a4ae },
	{ 2016000, uint256("eef80e94f486359dddff7347f91290244b43bc575dfe097fc61ec29cf2b01f96"), 1615625468, 0x1a01bc1d },
	{ 2036160, uint256("97ab7a0bf3cd7d694c1b369090aea9449e93f92763808de2a073cc8ab0657292"), 1618643881, 0x1a01ab48 }
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("4966625a4b2851d9fdee139e56211a0d88575f59ed816ff5e6a63deb4e3e29a0"), 1486949366, 0x1e0ffff0 }
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    // const BRMerkleBlock *previous, *b = NULL;
    // uint32_t i;

    // assert(block != NULL);
    // assert(blockSet != NULL);

    // // check if we hit a difficulty transition, and find previous transition block
    // if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
    //     for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
    //         b = BRSetGet(blockSet, &b->prevBlock);
    //     }
    // }

    // previous = BRSetGet(blockSet, &block->prevBlock);
    // return BRMerkleBlockVerifyDifficulty(block, previous, (b) ? b->timestamp : 0);
    return 1;
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    9333,       // standardPort
    0xdbb6c0fb, // magicNumber
    0,          // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints) / sizeof(*BRMainNetCheckpoints)};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    19335,      // standardPort
    0xf1c8d2fd, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints) / sizeof(*BRTestNetCheckpoints)};

#endif // BRChainParams_h
