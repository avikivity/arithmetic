#include <type_traits>

struct zero {};

template <typename N>
struct next {};

using one = next<zero>;
using two = next<one>;
using three = next<two>;
using four = next<three>;
using five = next<four>;
using six = next<five>;

template <typename A, typename B>
struct addition;

template <typename A, typename B>
struct addition<A, next<B>> {
	using result = next<typename addition<A, B>::result>;
};

template <typename A>
struct addition<A, zero> {
	using result = A;
};

template <typename A, typename B>
using sum = typename addition<A, B>::result;

template <typename A, typename B>
struct multiplication;

template <typename A, typename B>
struct multiplication<A, next<B>> {
	using result = sum<typename multiplication<A, B>::result, A>;
};

template <typename A>
struct multiplication<A, zero> {
	using result = zero;
};

template <typename A, typename B>
using product = typename multiplication<A, B>::result;

template <typename A, typename B>
using equals = std::is_same<A, B>;

static_assert(equals<sum<two, two>, four>::value, "two plus two equals four");
static_assert(equals<product<two, three>, six>::value, "two times three equals six");
