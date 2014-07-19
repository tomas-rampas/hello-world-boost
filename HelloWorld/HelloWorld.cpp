#include "stdafx.h"

#define BOOST_ALL_DYN_LINK
#define BOOST_LIB_DIAGNOSTIC
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
using namespace boost::python;

class World
{
public:
	void set(std::string msg) { this->msg = msg; }
	std::string greet() { return msg; }
	std::string msg;
	friend std::ostream &operator<<(std::ostream &o, World const &w) { o << w.msg ; return o; }
};


BOOST_PYTHON_MODULE(hello)
{
	class_<World>("World")
		.def("greet", &World::greet)
		.def("set", &World::set)
		.def(self_ns::str(self_ns::self))
		;
}