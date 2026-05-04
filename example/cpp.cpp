// C++ Example — keywords coverage for italic review
// Hotakus's Nocturne Theme Preview

#include <concepts>
#include <coroutine>
#include <iostream>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <vector>

// ============================================================
//  storage.type  → italic
//  storage.modifier → italic
//  typeParameter  → italic + amber
//  keyword.control → NO italic (should stay upright)
// ============================================================

// ─── Concepts (C++20) ───────────────────────────────────────
template <typename T>
concept Printable = requires(T v) {
    { std::cout << v } -> std::same_as<std::ostream&>;
};

// ─── Template with Constraints ─────────────────────────────
template <Printable T, typename Alloc = std::allocator<T>>
    requires(sizeof(T) <= 64)
class Repository {                          // class = italic
    static constexpr size_t kMaxSize = 64;  // static, constexpr = italic
    std::vector<T> items;

public:
    // storage.modifier 全部 italic
    explicit Repository(size_t cap = 0) noexcept : items(cap) {}

    virtual ~Repository() = default;        // virtual = italic

    // const 修饰符 = italic; inline 函数声明 = italic
    inline size_t size() const { return items.size(); }

    // noexcept = italic; 但 try catch = 不斜体
    auto find(size_t idx) const noexcept -> std::optional<T> {
        try {
            if (idx >= items.size()) throw std::out_of_range("bad index");
            return items[idx];                          // return = 不斜体
        } catch (const std::exception& e) {             // catch = 不斜体
            return std::nullopt;
        }
    }

protected:
    // protected: = italic
    virtual void on_modified() = 0;         // virtual = italic

private:
    // private: = italic
    auto* raw_data() { return items.data(); }
};

// ─── Inheritance ────────────────────────────────────────────
template <Printable T>
class ObservableRepo final : public Repository<T> {  // class, final, public = italic
public:
    using Repository<T>::Repository;        // using = italic (storage.modifier)

    void on_modified() override final {     // override, final = italic
        // keyword.control → 不斜体 ↓
        for (size_t i = 0; i < 5; ++i) {   // for = 不斜体
            if (i % 2 == 0) continue;       // if, continue = 不斜体
            if (i == 4) break;              // break = 不斜体
            std::cout << ".";
            false && std::cout << "unreachable\n";  // && = 不斜体
        }
    }
};

// ─── Enum ───────────────────────────────────────────────────
enum class Kind : uint8_t {                 // enum class = italic
    kAlpha, kBeta, kGamma, kDelta
};

// ─── Forward Decl ───────────────────────────────────────────
template <typename> class Future;           // class = italic, typename = italic

// ─── Free Function Templates ───────────────────────────────
template <typename T, typename... Args>     // typename = italic
inline auto make_repo(Args&&... args) -> ObservableRepo<T> {  // inline = italic
    return ObservableRepo<T>(std::forward<Args>(args)...);
}

template <typename T>
constexpr auto clamp(T val, T lo, T hi) noexcept -> T {  // constexpr, noexcept = italic
    // ↓ keyword.control 不斜体
    if (val < lo) return lo;               // if, return = 不斜体
    if (val > hi) return hi;
    return val;
}

// ─── Lambda ─────────────────────────────────────────────────
inline void demo_lambda() {                // inline = italic
    int x = 42;

    // capture 不斜体; mutable = italic
    auto inc = [&x]() mutable -> int {      // mutable = italic（storage.modifier）
        x += 1;                             // += 不斜体
        return x;                           // return = 不斜体
    };
    inc();
}


// ─── Switch ─────────────────────────────────────────────────
const char* describe(Kind k) noexcept {    // noexcept = italic
    switch (k) {                           // switch = 不斜体
        case Kind::kAlpha: return "Alpha"; // case = 不斜体; return = 不斜体
        case Kind::kBeta:  return "Beta";
        case Kind::kGamma: return "Gamma";
        default:           return "???";   // default = 不斜体
    }
}

// ─── Struct ─────────────────────────────────────────────────
// struct = italic; constexpr = italic
template <typename T>
struct Point {
    T x{}, y{};
    constexpr auto norm() const noexcept -> T { return x * x + y * y; }
};

// ─── Main: not much italic here ────────────────────────────
//        because main code is mostly keyword.control + calls
int main() {
    auto repo = make_repo<std::string>();               // auto = 不斜体
    repo.add("hello");
    repo.add("nocturne");

    // keyword.control → 全部不斜体 ↓
    if (auto item = repo.find(0); item.has_value()) {   // if = 不斜体
        std::cout << *item << "\n";
    } else {
        std::cout << "not found\n";                     // else = 不斜体
    }

    for (size_t i = 0; i < repo.size(); ++i) {
        std::cout << ".";
    }

    while (false) { break; }                            // while, break = 不斜体

    do { break; } while (false);                        // do, break, while = 不斜体

    return 0;                                           // return = 不斜体
}
