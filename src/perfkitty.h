#include <utility>
#include <iostream>
#include <type_traits>

//#ifdef DEBUG
constexpr bool enable_perfkitty = false;
//#else
//constexpr bool enable_perfkitty = false;
//#endif

template< bool EnableCode, typename unused_t = void >
struct perfkitty {
	void record() {}
};

template< bool EnableCode >
struct perfkitty< EnableCode, typename std::enable_if< (EnableCode == true) >::type > {
	void record() { printf("plop"); }
};

using perfkitty_t = perfkitty< enable_perfkitty >;

int main(int argc, char *argv[]) {
  	perfkitty_t pk;
	pk.record();
  
  	return 0;
}
