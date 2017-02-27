#ifndef CRANBERRIES_INTERVAL_LIB_ROUNDING_CONTROL_HPP
#define CRANBERRIES_INTERVAL_LIB_ROUNDING_CONTROL_HPP 

#define ACCURACY_ASSURANCE(lower,upper) [&]{ DOWNWARD_POLICY; auto&& l = lower; UPWARD_POLICY; auto&& r = upper; return interval<T>{ l, r }; }()
#define ACCURACY_ASSURANCE_WITH_OVERFLOW_CHECK(lower,upper) [&]{ DOWNWARD_POLICY; auto&& l = lower; UPWARD_POLICY; auto&& r = upper; return interval<T>{ CRANBERRIES_OVERFLOW_ERROR_THROW_CONDITIONAL(cranberries_magic::is_overflow(l)):l, CRANBERRIES_OVERFLOW_ERROR_THROW_CONDITIONAL(cranberries_magic::is_overflow(r)):r }; }()

/*
workaround for MSVC below
[ Note : FE_DOWNWARD and FE_UPWARD are reverse defined in MSVC. - end note]
*/
#ifdef _MSC_VER
#define UPWARD_POLICY std::fesetround(FE_DOWNWARD)
#define DOWNWARD_POLICY std::fesetround(FE_UPWARD)
#else
#define UPWARD_POLICY std::fesetround(FE_UPWARD)
#define DOWNWARD_POLICY std::fesetround(FE_DOWNWARD)
#endif

#ifdef _MSC_VER
#define UPWARD_CALC(EXPR) [&] {std::fesetround(FE_DOWNWARD); auto&& tmp = EXPR; return tmp;}()
#define DOWNWARD_CALC(EXPR) [&] {std::fesetround(FE_UPWARD); auto&& tmp = EXPR; return tmp;}()
#else
#define UPWARD_CALC(EXPR) [&] {std::fesetround(FE_UPWARD); auto&& tmp = EXPR; return tmp;}()
#define DOWNWARD_CALC(EXPR) [&] {std::fesetround(FE_DOWNWARD); auto&& tmp = EXPR; return tmp;}()
#endif

#endif // ! SET_ROUND_HPP