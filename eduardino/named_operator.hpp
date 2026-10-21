#pragma once
#include <iterator>
#include <utility>
#include <iterator>
#include <type_traits>
#include <tuple>

namespace base {

template <typename F>
struct named_operator_wrapper {
  F f; };

template <typename T, typename F>
struct named_operator_lhs {
  F f;
  T &value; };

template <typename T, typename F>
inline named_operator_lhs<T, F> operator<(T &lhs, named_operator_wrapper<F> rhs) {
  return {rhs.f, lhs }; }

template <typename T, typename F>
inline named_operator_lhs<T const, F> operator<(T const &lhs, named_operator_wrapper<F> rhs) {
  return {rhs.f, lhs }; }

template <typename T1, typename T2, typename F>
inline auto operator>(named_operator_lhs<T1, F> const &lhs, T2 const &rhs)
-> decltype(lhs.f(std::declval<T1>(), std::declval<T2>())) {
  return lhs.f(lhs.value, rhs); }

template <typename T1, typename T2, typename F>
inline auto operator>=(named_operator_lhs<T1, F> const &lhs, T2 const &rhs)
-> decltype(lhs.value = lhs.f(std::declval<T1>(), std::declval<T2>())) {
  return lhs.value = lhs.f(lhs.value, rhs); }

template <typename F>
inline constexpr named_operator_wrapper<F> make_named_operator(F f) {
  return {f }; }

} // namespace base

namespace detail {

template <typename T>
class Range {
public:
  Range(const T &start, const T &stop, const T &step) : start_{start }, stop_{stop }, step_{step } {
    if (step_ == 0) {}
    else {
      if ((start_ > stop_ && step_ > 0) || (start_ < stop_ && step_ < 0)) {} } }

  class iterator {
  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;

    iterator(value_type value, value_type step, value_type boundary) : value_{value }, step_{step }, boundary_{boundary }, positive_step_(step_ > 0) {}
    iterator operator++() {
      value_ += step_;
      return *this; }

    reference operator*() {
      return value_; }

    const pointer operator->() {
      return &value_; }

    bool operator==(const iterator &rhs) {
      return positive_step_ ? (value_ >= rhs.value_ && value_ > boundary_) : (value_ <= rhs.value_ && value_ < boundary_); }
    bool operator!=(const iterator &rhs) {
      return positive_step_ ? (value_ < rhs.value_ && value_ >= boundary_) : (value_ > rhs.value_ && value_ <= boundary_); }

  private:
    value_type value_;
    const T step_;
    const T boundary_;
    const bool positive_step_; };

  iterator begin() const {
    return iterator(start_, step_, start_); }

  iterator end() const {
    return iterator(stop_, step_, start_); }

private:
  const T start_;
  const T stop_;
  const T step_; }; }

template <typename T>
detail::Range<T> range(const T &stop) {
  return detail::Range<T>(T{0 }, stop, T{1 }); }

template <typename T>
detail::Range<T> range(const T &start, const T &stop) {
  return detail::Range<T>(start, stop, T{1 }); }

template <typename T>
detail::Range<T> range(const T &start, const T &stop, const T &step) {
  return detail::Range<T>(start, stop, step); }

template <typename T,
          typename TIter = decltype(std::begin(std::declval<T>())),
          typename = decltype(std::end(std::declval<T>()))>
constexpr auto enumerate(T &&iterable) {
  struct iterator {
    size_t i;
    TIter iter;
    bool operator!=(const iterator &other) const {
      return iter != other.iter; }
    void operator++() {
      ++i;
      ++iter; }
    auto operator*() const {
      return std::tie(i, *iter); } };
  struct iterable_wrapper {
    T iterable;
    auto begin() {
      return iterator{0, std::begin(iterable) }; }
    auto end() {
      return iterator{0, std::end(iterable) }; } };
  return iterable_wrapper{std::forward<T>(iterable) }; }

namespace detail {
template <typename T>
struct range_iter_base : std::iterator<std::input_iterator_tag, T> {
  range_iter_base(T current) : current(current) {}

  T operator*() const {
    return current; }

  T const *operator->() const {
    return &current; }

  range_iter_base &operator++() {
    ++current;
    return *this; }

  range_iter_base operator++(int) {
    auto copy = *this;
    ++*this;
    return copy; }

  bool operator==(range_iter_base const &other) const {
    return current == other.current; }

  bool operator!=(range_iter_base const &other) const {
    return not(*this == other); }

protected:
  T current; }; }

template <typename T>
struct range_proxy {
  struct iterator : detail::range_iter_base<T> {
    iterator(T current) : detail::range_iter_base<T>(current) {} };

  struct step_range_proxy {
    struct iter : detail::range_iter_base<T> {
      iter(T current, T step) : detail::range_iter_base<T>(current), step(step) {}

      using detail::range_iter_base<T>::current;

      iter &operator++() {
        current += step;
        return *this; }

      iter operator++(int) {
        auto copy = *this;
        ++*this;
        return copy; }

      // Loses commutativity. Iterator-based ranges are simply broken. :-(
      bool operator==(iter const &other) const {
        return step > 0 ? current >= other.current : current < other.current; }

      bool operator!=(iter const &other) const {
        return not(*this == other); }

    private:
      T step; };

    step_range_proxy(T begin, T end, T step) : begin_(begin, step), end_(end, step) {}

    iter begin() const {
      return begin_; }

    iter end() const {
      return end_; }

  private:
    iter begin_;
    iter end_; };

  range_proxy(T begin, T end) : begin_(begin), end_(end) {}

  step_range_proxy step(T step) {
    return {*begin_, *end_, step }; }

  iterator begin() const {
    return begin_; }

  iterator end() const {
    return end_; }

private:
  iterator begin_;
  iterator end_; };

template <typename T>
struct infinite_range_proxy {
  struct iterator : detail::range_iter_base<T> {
    iterator(T current = T()) : detail::range_iter_base<T>(current) {}

    bool operator==(iterator const &) const {
      return false; }

    bool operator!=(iterator const &) const {
      return true; } };

  struct step_range_proxy {
    struct iter : detail::range_iter_base<T> {
      iter(T current = T(), T step = T()) : detail::range_iter_base<T>(current), step(step) {}

      using detail::range_iter_base<T>::current;

      iter &operator++() {
        current += step;
        return *this; }

      iter operator++(int) {
        auto copy = *this;
        ++*this;
        return copy; }

      bool operator==(iter const &) const {
        return false; }

      bool operator!=(iter const &) const {
        return true; }

    private:
      T step; };

    step_range_proxy(T begin, T step) : begin_(begin, step) {}

    iter begin() const {
      return begin_; }

    iter end() const {
      return iter(); }

  private:
    iter begin_; };

  infinite_range_proxy(T begin) : begin_(begin) {}

  step_range_proxy step(T step) {
    return step_range_proxy(*begin_, step); }

  iterator begin() const {
    return begin_; }

  iterator end() const {
    return iterator(); }

private:
  iterator begin_; };

template <typename T>
range_proxy<T> range(T begin, T end) {
  return {begin, end }; }

template <typename T>
infinite_range_proxy<T> range(T begin) {
  return {begin }; }

template <typename T>
range_proxy<T> range(T begin, T end, T step) {
  return {begin, end, step }; }

namespace traits {
template <typename C>
struct has_size {
  template <typename T>
  static auto check(
    T *) -> typename std::is_integral<decltype(std::declval<T const>().size())>::type;

  template <typename>
  static auto check(...) -> std::false_type;

  using type = decltype(check<C>(0));
  static constexpr bool value = type::value; }; }

template <typename C, typename = typename std::enable_if<
            traits::has_size<C>::value>>
auto indices(C const &cont) -> range_proxy<decltype(cont.size())> {
  return {0, cont.size() }; }

template <typename T, std::size_t N>
range_proxy<std::size_t> indices(T (&)[N]) {
  return {0, N }; }

template <typename T>
range_proxy<typename std::initializer_list<T>::size_type> indices(
  std::initializer_list<T> &&cont) {
  return {0, cont.size() }; }
