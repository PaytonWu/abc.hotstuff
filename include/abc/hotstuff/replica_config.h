// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_REPLICA_CONFIG)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_REPLICA_CONFIG

#pragma once

#include <abc/hotstuff/replica.h>

#include <unordered_set>

namespace abc::hotstuff {

class replica_config {
    std::unordered_set<replica> replica_set;

    auto add(replica replica) {
        replica_set.insert(std::move(replica));
    }

    auto majority_size() const noexcept {
        return (replica_set.size() * 2 + 3) / 3;
    }
};

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_REPLICA_CONFIG
