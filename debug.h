template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {

  ~debug() {}
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class a, class b, class c> debug &operator<<(tuple<a, b, c> t) {
    return *this << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t)
                 << ")";
  }
  template <class a, class b, class c, class d>
  debug &operator<<(tuple<a, b, c, d> t) {
    return *this << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t)
                 << ", " << get<3>(t) << ")";
  }
  template <class a> debug &operator<<(array<a, 2> t) {
    return *this << "(" << t[0] << ", " << t[1] << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "{";
    for (auto it = d.b; it != d.e; ++it)
      *this << ", " + 2 * (it == d.b) << *it;
    return *this << "}";
  }
};
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <typename Head, typename... Tail>
void debug_out(const char *name, Head H) {
  debug() << name << " == " << H;
  cerr << ";\n===========================\n";
}
template <typename Head, typename... Tail>
void debug_out(const char *names, Head H, Tail... T) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " == ";
  debug() << H << "; \n";
  debug_out(comma + 1, T...);
}
#define db(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
