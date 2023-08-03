// Copyright(c) 2020 - present, Payton Wu (payton.wu@outlook.com) & contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(ABC_HOTSTUFF_MESSAGE)
#define ABC_HOTSTUFF_MESSAGE

#pragma once

#include <message_type.h>

#include <cstdint>

namespace abc {

struct w_message_struct {
    uint64_t view_number{ 0 };
    message_type type{ message_type::invalid };

};
using wmessage_t = w_message_struct;

}

#endif
