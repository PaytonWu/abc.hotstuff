// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_CRYPTO)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_CRYPTO

#pragma once

#include <abc/fixed_bytes.h>

#include <secp256k1.h>


namespace abc::hotstuff {

class secp256k1_context {
private:
    ::secp256k1_context * ctx{nullptr};

public:
    explicit secp256k1_context(bool sign) : ctx{::secp256k1_context_create(sign ? SECP256K1_CONTEXT_SIGN : SECP256K1_CONTEXT_VERIFY)} {
    }

    secp256k1_context(secp256k1_context const &) = delete;

    auto operator=(secp256k1_context const &) -> secp256k1_context & = delete;

    secp256k1_context(secp256k1_context && other) noexcept : ctx(other.ctx) {
        other.ctx = nullptr;
    }

    auto operator=(secp256k1_context && other) noexcept -> secp256k1_context & {
        if (ctx) {
            ::secp256k1_context_destroy(ctx);
        }
        ctx = other.ctx;
        other.ctx = nullptr;
        return *this;
    }

    ~secp256k1_context() noexcept {
        if (ctx) {
            ::secp256k1_context_destroy(ctx);
        }
    }
};

enum class crypto_key_type {
    invalid,
    pub,
    pri
};

enum class crypto_key_format {
    invalid,
    secp256k1,
};

template <crypto_key_format Format, crypto_key_type Type>
class crypto_key;

template <>
class crypto_key<crypto_key_format::secp256k1, crypto_key_type::pub> {
private:
     fixed_bytes<33, byte_numbering::none> key_{};

public:
    friend auto operator==(crypto_key const & lhs, crypto_key const & rhs) noexcept {
        return lhs.key_ == rhs.key_;
    }
};

using secp256k1_public_key = crypto_key<crypto_key_format::secp256k1, crypto_key_type::pub>;

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_CRYPTO
