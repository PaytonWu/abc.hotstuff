// Copyright(c) 2020 - present, Payton Wu (payton.wu@outlook.com) & contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(ABC_HOTSTUFF_MESSAGE_TYPE)
#define ABC_HOTSTUFF_MESSAGE_TYPE

#pragma once

#include <cstdint>

namespace abc::hotstuff {

enum class message_type : uint8_t {
    invalid = 0,
    new_view,
    prepare,
    pre_commit,
    commit,
    decide
};

}

#endif
