// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_TYPES_BLOCK)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_TYPES_BLOCK

#pragma once

#include <abc/fixed_hash.h>

namespace abc::hotstuff::types {

class block {
public:
    block() = default;

    ~block() = default;

private:
    hash256_t pre_hash_;
};

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_TYPES_BLOCK
