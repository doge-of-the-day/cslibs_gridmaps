#ifndef NORMALIZE_HPP
#define NORMALIZE_HPP

#include <cslibs_gridmaps/static_maps/gridmap.hpp>

namespace cslibs_gridmaps {
namespace static_maps {
namespace algorithms {

template<typename T>
void normalize(Gridmap<T> &map)
{
    double max = std::numeric_limits<T>::lowest();
    double min = std::numeric_limits<T>::max();
    for(std::size_t i = 0 ; i < map.getHeight() ; ++i) {
        for(std::size_t j = 0 ;  j < map.getWidth() ; ++j) {
            const T p = map.at(j,i);
            if(std::isnormal(p)) {
                max = std::max(max, p);
                min = std::min(min, p);
            }
        }
    }

    for(std::size_t i = 0 ; i < map.getHeight() ; ++i) {
        for(std::size_t j = 0 ;  j < map.getWidth() ; ++j) {
            T& p = map.at(j,i);
            p = static_cast<T>(p / max);
        }
    }
}
}
}
}

#endif // NORMALIZE_HPP
