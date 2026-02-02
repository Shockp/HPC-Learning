#ifndef SEARCH_RESULT_H_
#define SEARCH_RESULT_H_

#include <vector>

namespace searchresult {
struct SearchResult {
  bool found = false;
  int index = -1;
};

SearchResult FindValue(const std::vector<int>& list, int target);

} // namespace searchresult

#endif