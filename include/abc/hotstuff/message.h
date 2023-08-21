// Copyright(c) 2020 - present, Payton Wu (payton.wu@outlook.com) & contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(ABC_HOTSTUFF_MESSAGE)
#define ABC_HOTSTUFF_MESSAGE

#pragma once

#include <abc/fixed_bytes.h>
#include <abc/hotstuff/message_type.h>

#include <cstdint>

namespace abc::hotstuff {

struct message {
    uint64_t view_number{ 0 };
    bytes32_t justification_hash{};
    bytes32_t signature{};
    message_type type{ message_type::invalid };
};

}

#endif