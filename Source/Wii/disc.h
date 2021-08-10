#pragma once
#include "type.h"

struct DiscHeader {
    uchar discId;
    ushort gameCode;
    uchar regionCode;
    ushort makerCode;
    uchar discNumber;
    uchar discVersion;
    uchar audioStreaming;
    uchar streamingBufferSize;
    uchar pad0[14];
    uint wiiMagicWord;
    uint gamecubeMagicWord;
    char title[64];
    uchar disableHashVerification;
    uchar disableDiscEncryption;
    uchar pad1[30];
} __attribute__((__packed__));

struct DiscPartitions {
    uint partitionsCount;
    uint partitionInfoTableOffset; // << 2
} __attribute__((__packed__));

struct DiscPartitionInfoTable {
    uint partitionOffset; // << 2
    uint type;
} __attribute__((__packed__));

struct DiscPartition {
    uchar ticket[0x284];
    uint titleMtdSize;
    uint titleMtdOffset; // << 2
    uint certChainSize;
    uint certChainOffset; // << 2
    uint h3TableOffset; // << 2
    uint dataOffset; // << 2
    uint dataSize; // << 2
    uchar pad[352];
} __attribute__((__packed__));