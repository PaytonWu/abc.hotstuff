// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_QUORUM_CERTIFICATE)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_QUORUM_CERTIFICATE

#pragma once

#include "abc/hotstuff/message_type.h"

namespace abc::hotstuff {

template <message_type MessageTypeValue>
struct quorum_certificate {
    uint64_t view_number{0};
    bytes32_t justification_hash{};
    bytes32_t signature{};
};

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_QUORUM_CERTIFICATE
