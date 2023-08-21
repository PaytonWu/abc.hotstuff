// Copyright(c) 2020 - present, Payton Wu (payton.wu@outlook.com) & contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(ABC_HOTSTUFF_HOTSTUFF)
#define ABC_HOTSTUFF_HOTSTUFF

#pragma once

#include <abc/byte.h>
#include <abc/hotstuff/message.h>

#include <asio.hpp>

namespace abc::hotstuff {

enum class phase {
    invalid = 0,
    new_view,
    prepare,
    pre_commit,
    commit,
    decide
};

class hotstuff_core {

private:
    void on_proposal() {

    }

    void on_vote() {

    }

    void leader_prepare() {

    }

    void replica_prepare() {
    }

    void leader_pre_commit() {

    }

    void replica_pre_commit() {

    }

    void leader_commit() {

    }

    void replica_commit() {

    }

    void leader_decide() {

    }

    void replica_decide() {

    }
};

}

#endif
