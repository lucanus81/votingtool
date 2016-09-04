#ifndef _PRINTER_H
#define _PRINTER_H

#include <tuple>
#include <iostream>
#include <utility>

namespace {

/*
 * A non-recursive way of priting a tuple
 */
template <typename Tuple, std::size_t... Sequence>
void print_tuple(std::ostream& out, Tuple const& t, std::index_sequence<Sequence...>)
{
    using swallow=int[];
    (void)swallow{0, ((out <<(Sequence == 0 ? "" : ",") <<std::get<Sequence>(t)),0)... };
}

}

template <typename... Params>
std::ostream& operator<<(std::ostream& out, std::tuple<Params...> const& arg)
{
    print_tuple(out, arg, std::index_sequence_for<Params...>{});
    return out;
}

#endif
