#ifndef PICKER_RANDOM_H
#define PICKER_RANDOM_H
#include <iterator>

//temporary workaround
#include <string>
#include <vector>

namespace picker {
enum class RandomMethod {
	RANDOM_ORG = 0,
	MERSENNE = 1
};
//By Baum mit Augen, Deduplicator and Kurt M at https://codereview.stackexchange.com/questions/109260. CC BY-SA 3.0.
template<class T = std::mt19937, std::size_t N = (T::word_size + 31) / 32 * T::state_size>
auto seededEngine () -> typename std::enable_if<!!N, T>::type {
	typename T::result_type random_data[N];
	std::random_device source;
	std::generate(std::begin(random_data), std::end(random_data), std::ref(source));
	std::seed_seq seeds(std::begin(random_data), std::end(random_data));
	return T(seeds);
}
}
#endif // PICKER_RANDOM_H
