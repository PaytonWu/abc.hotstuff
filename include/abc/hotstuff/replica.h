// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_REPLICA)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_REPLICA

#pragma once

#include <abc/hotstuff/crypto.h>

#include <cstdint>
#include <limits>
#include <functional>

namespace abc::hotstuff {

using replica_id_t = uint64_t;

class replica {
private:
    replica_id_t id_{std::numeric_limits<replica_id_t>::max()};
    secp256k1_public_key public_key_;

public:
    replica() = default;
    replica(replica_id_t id, secp256k1_public_key public_key) : id_{id}, public_key_{public_key} {
    }

    constexpr auto id() const noexcept -> replica_id_t {
        return id_;
    }

    auto public_key() const -> secp256k1_public_key const & {
        return public_key_;
    }

    friend auto operator==(replica const & lhs, replica const & rhs) noexcept {
        return lhs.public_key() == rhs.public_key();
    }

    friend auto operator<=>(replica const & lhs, replica const & rhs) noexcept {
        return lhs.id_ <=> rhs.id_;
    }
};

}

namespace std {

template <>
struct hash<abc::hotstuff::replica> {
    auto operator()(abc::hotstuff::replica const & replica) const {
        return static_cast<size_t>(replica.id());
    }
};

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_REPLICA
