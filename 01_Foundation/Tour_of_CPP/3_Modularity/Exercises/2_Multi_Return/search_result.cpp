#include "search_result.h"

searchresult::SearchResult searchresult::FindValue(const std::vector<int> &list,
                                                   int target) {
  int idx = 0;
  for (int number : list) {
    if (number == target) {
      return searchresult::SearchResult{true, idx};
    }

    idx++;
  }

  return searchresult::SearchResult{false, -1};
}