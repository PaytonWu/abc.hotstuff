// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_CONSENSUS)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_CONSENSUS

#pragma once

#include <abc/bytes.h>
#include <abc/fixed_hash.h>
#include <abc/hotstuff/replica.h>
#include <abc/hotstuff/types/block.h>
#include <abc/hotstuff/replica_config.h>

#include <limits>
#include <memory>
#include <unordered_set>

namespace abc::hotstuff {

inline namespace v1 {

class proposal {
private:
    static constexpr byte version{0x01};
    replica_id_t proposer_id{std::numeric_limits<replica_id_t>::max()};
    // block being proposed
    types::block block{};

public:
    proposal() = default;
    proposal(replica_id_t replica_id, types::block block) : replica_id{replica_id}, block{block} {
    }

    auto to_bytes() const {
        bytes raw{};
        raw.push_back(version);
        // serialize replica_id
        // serialize block
        return raw;
    }

    static proposal from_bytes(std::span<byte const> raw) {
        proposal p{};
        // deserialize replica_id
        // deserialize block
        return p;
    }
};

class vote {
private:
    static constexpr byte version{0x01};
    replica_id_t voter_id{std::numeric_limits<replica_id_t>::max()};
    // block being voted
    hash256_t block_hash{};
    // cert_t cert{cert_t::invalid};

    auto to_bytes() const {
        bytes raw{};
        raw.push_back(version);
        // serialize voter_id
        // serialize block_hash
        // serialize cert
        return raw;
    }

    static vote from_bytes(std::span<byte const> raw) {
        vote v{};
        // deserialize voter_id
        // deserialize block_hash
        // deserialize cert
        return v;
    }
};

}

class consensus_core {
private:
    std::shared_ptr<types::block> genesis_block_{}; // genesis block
    std::shared_ptr<types::block> locked_block_{}; // locked block
    std::shared_ptr<types::block> executed_block_{}; // executed block

    std::unordered_set<types::block> tails; // tails of the block DAG
    replica_config config;
};

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_CONSENSUS
