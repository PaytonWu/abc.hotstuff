// Copyright(c) 2023 - present, Payton Wu (payton.wu@outlook.com) & abc contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#if !defined(HOTSTUFF_INCLUDE_ABC_HOTSTUFF_VIEW_NUMBER)
#define HOTSTUFF_INCLUDE_ABC_HOTSTUFF_VIEW_NUMBER

#pragma once

namespace abc::hotstuff {

class view_number {
    uint64_t value_{0};

public:
    view_number() = default;
    view_number(view_number const &) = default;
    auto view_number(view_number const &) -> view_number & = default;
    view_number(view_number &&) = default;
    auto view_number(view_number &&) -> view_number & = default;
    ~view_number() = default;

    auto operator=(view_number const &) -> view_number & = default;
    auto operator=(view_number &&) -> view_number & = default;

    explicit view_number(uint64_t value) : value_{value} {}

    auto operator++() -> view_number & {
        ++value_;
        return *this;
    }

    auto operator++(int) -> view_number {
        auto result = *this;
        ++value_;
        return result;
    }

    auto operator--() -> view_number & {
        --value_;
        return *this;
    }

    auto operator--(int) -> view_number {
        auto result = *this;
        --value_;
        return result;
    }

    friend auto operator==(view_number const & lhs, view_number const & rhs) -> bool {
        return lhs.value_ == rhs.value_;
    }

    friend auto operator<=>(view_number const & lhs, view_number const & rhs) -> std::strong_ordering {
        return lhs.value_ <=> rhs.value_;
    }

    friend auto operator<<(std::ostream & os, view_number const & rhs) -> std::ostream & {
        return os << rhs.value_;
    }

    friend auto operator>>(std::istream & is, view_number & rhs) -> std::istream & {
        return is >> rhs.value_;
    }
};

}

#endif //HOTSTUFF_INCLUDE_ABC_HOTSTUFF_VIEW_NUMBER
